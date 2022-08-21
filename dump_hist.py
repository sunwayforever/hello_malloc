#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# 2022-08-19 20:21
import argparse
import numpy as np
import matplotlib.pyplot as plt
from collections import namedtuple, defaultdict

BIN_SIZES = [2, 4, 8, 16, 32, 64, 128, 256, 512]


def align(value, a):
    return ((value + a - 1) // a) * a


class Record:
    def __init__(self):
        self.curr = 0
        self.watermark = 0


def process():
    records = defaultdict(lambda: defaultdict(lambda: Record()))
    total_curr = 0
    total_watermark = 0
    with open(args.log, "r") as f:
        for line in f.readlines():
            _, action, size = line.split(":")
            size = int(size)
            if size == 0:
                continue
            if action == "ALLOC":
                total_curr += size
                if total_curr > total_watermark:
                    total_watermark = total_curr
            if action == "DEALLOC":
                total_curr -= size

            for bin in BIN_SIZES:
                a_size = align(size, bin)
                record = records[bin][a_size]
                if action == "ALLOC":
                    record.curr += a_size
                    if record.curr > record.watermark:
                        record.watermark = record.curr
                if action == "DEALLOC":
                    record.curr -= a_size

    print(f"watermark: {(total_watermark/1024):.1f} KB")
    for bin in BIN_SIZES:
        record = records[bin]
        watermark = sum([x.watermark for x in record.values()])
        bin_count = max(record.keys()) // bin
        print(f"bin_size: {bin:2}, watermark: {(watermark/1024):.1f} KB, bin_count: {(bin_count+1)/1024:.1f} K")

        buffer_declare = ""
        pool_declare = "void *POOLS[]={\n"
        pool_init = ""

        with open(f"/tmp/pool_config_{bin}.h", "w") as f:
            f.write(f"#ifndef POOL_CONFIG_{bin}_H\n")
            f.write(f"#define POOL_CONFIG_{bin}_H\n")
            f.write("#include <stddef.h>\n")
            f.write(f"size_t BIN_SIZE = {bin};\n")
            for i in range(bin_count + 1):
                key = i * bin
                if key in record:
                    buffer_declare += f"char buffer_{i}[{record[key].watermark+16}];\n"
                    pool_declare += f"    buffer_{i},\n"
                    pool_init += f"init_pool(buffer_{i}, sizeof(buffer_{i}), {key}, {record[key].watermark//key});\\\n"
                else:
                    pool_declare += "    0,\n"
            pool_declare += "};\n"

            f.write(buffer_declare)
            f.write(pool_declare)
            f.write(f"#define INIT_POOLS \\\n{pool_init[:-2]}\n")
            f.write(f"#endif //POOL_CONFIG_{bin}_H")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--log", type=str, required=True)
    args = parser.parse_args()
    process()

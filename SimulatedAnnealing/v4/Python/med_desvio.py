#!/usr/bin/env python3
#! coding: utf-8

import numpy as np

ys = []
for i in range(10):
	x, y = map(int, input().split())
	ys.append(y)

print("{} {}".format(np.mean(ys), np.std(ys)))
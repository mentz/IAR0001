#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

xar = [0]*250000
yar = [0]*250000
for i in range(250000):
	x, y = map(float, input().split())
	xar[i] = x
	yar[i] = y

pl.plot(xar, yar)
pl.ylim([yar[249999], yar[0]])
pl.xlim([0, 250000])
pl.show()

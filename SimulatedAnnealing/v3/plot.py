#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

NUM_ITERACOES = 250000

xar = [0]*NUM_ITERACOES
yar = [0]*NUM_ITERACOES
for i in range(NUM_ITERACOES):
	x, y = map(float, input().split())
	xar[i] = x
	yar[i] = y

pl.plot(xar, yar)
pl.ylim([min(yar), max(yar)])
pl.xlim([1, NUM_ITERACOES])
pl.show()

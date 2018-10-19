#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

NUM_ITERACOES = 250000

if (len(argv) < 2):
	print("Argumentos: <dados_entrada> <img_saida>")
	return 1

xar = [0]*NUM_ITERACOES
yar = [0]*NUM_ITERACOES
for i in range(NUM_ITERACOES):
	# TODO Trocar a linha abaixo para leitura do arquivo de entrada.
	#x, y = map(float, input().split())
	xar[i] = x
	yar[i] = y

pl.plot(xar, yar)
pl.ylim([min(yar), max(yar)])
pl.xlim([1, NUM_ITERACOES])

# TODO Trocar o trecho abaixo por impressão em arquivo.
"""
pl.show()
"""

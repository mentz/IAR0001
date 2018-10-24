#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

NUM_ITERACOES = 250000
'''
if (len(argv) < 2):
	print("Argumentos: <dados_entrada> <img_saida>")
	return 1
'''
tamanhos = ['20', '100', '250']
temp_inicial = '10.0'
temp_final = '0.00001'
for tam in tamanhos:
	for i in range(10):
		xar = [0]*NUM_ITERACOES
		yar = [0]*NUM_ITERACOES
		path = "../Saidas_Media/sa_media_" + tam + "_" + str(i) + "_" + temp_inicial + "_" + temp_final + ".dat"
		with open(path, 'r') as arq:
			for line in arq.readlines():
				x, y = map(int, line.split())
				xar[x - 1] = x
				yar[x - 1] = y

		pl.plot(xar, yar)
		pl.ylim([min(yar) - 10, max(yar) + 10])
		pl.xlim([1, NUM_ITERACOES])
		# TODO Trocar o trecho abaixo por impressão em arquivo.
		pl.savefig('sa_' + tam + "_" + str(i) + ".png")	
		pl.clf()

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
topos    = [  91,   430,  1065]
temp_inicial = '10.0'
temp_final = '0.00001'
# for tam in tamanhos:
for tam, topo in tamanhos, topos:
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
		# pl.ylim([min(yar) - 0.5, max(yar) + 0.5])
		pl.ylim([min(yar) - 0.5, topo + 0.5])
		pl.xlim([1, NUM_ITERACOES])
		pl.ylabel("Cláusulas satisfeitas")
		pl.xlabel("Iteração")
		pl.savefig('sa_' + tam + "_" + str(i) + ".png")	
		pl.clf()
	

	# Fazer gráfico do Random Search também ué °~°
	xar = [0]*NUM_ITERACOES
	yar = [0]*NUM_ITERACOES
	path = "../Saidas/rs_" + tam + ".dat"
	with open(path, 'r') as arq:
		for line in arq.readlines():
			x, y = map(int, line.split())
			xar[x - 1] = x
			yar[x - 1] = y

		pl.plot(xar, yar)
		# pl.ylim([min(yar) - 0.5, max(yar) + 0.5])
		pl.ylim([min(yar) - 0.5, topo + 0.5])
		pl.xlim([1, NUM_ITERACOES])
		pl.ylabel("Cláusulas satisfeitas")
		pl.xlabel("Iteração")
		pl.savefig('sa_' + tam + "_" + str(i) + ".png")	
		pl.clf()
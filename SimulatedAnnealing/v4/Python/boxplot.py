#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

# NUM_ITERACOES = 250000

tamanhos = ['20', '100', '250']
topos = {'20':91, '100':430, '250':1065}
# temp_inicial = '10.0'
# temp_final = '0.00001'
# for tam in tamanhos:
for tam in tamanhos:
	for i in range(10):
		# xar = [0]*NUM_ITERACOES
		yar = [0]*10
		path = "../Saidas/bp_data/sa_" + tam + "_cs" + str(i) + ".dat"
		with open(path, 'r') as arq:
			c = 0
			for line in arq.readlines():
				x, y = map(int, line.split())
				yar[c] = y
				c += 1

		pl.boxplot(yar, sym='', meanline=True)
		# pl.boxplot(yar)
		pl.ylim([min(yar) - 0.5, topos[tam] + 0.5])
		# pl.xlim([1, NUM_ITERACOES])
		# pl.ylabel("Cláusulas satisfeitas")
		# pl.xlabel("Iteração")
		pl.title('uf' + tam + '_' + str(topos[tam]) + ' com Simulated Annealing, função CS' + str(i))
		pl.savefig('Imagens/boxplot_sa_' + tam + "_cs" + str(i) + ".png")
		pl.clf()
	

	# Fazer gráfico do Random Search também ué °~°
	# xar = [0]*NUM_ITERACOES
	yar = [0]*10
	path = "../Saidas/bp_data/rs_" + tam + ".dat"
	with open(path, 'r') as arq:
		c = 0
		for line in arq.readlines():
			x, y = map(int, line.split())
			yar[c] = y
			c += 1
	

		pl.boxplot(yar, sym='', meanline=True)
		# pl.plot(xar, yar)
		pl.ylim([min(yar) - 0.5, topos[tam] + 0.5])
		# pl.xlim([1, NUM_ITERACOES])
		pl.ylabel("Cláusulas satisfeitas")
		# pl.xlabel("Iteração")
		pl.title('uf' + tam + '_' + str(topos[tam]) + ' com Random Search')
		pl.savefig('Imagens/boxplot_rs_' + tam + ".png")
		pl.clf()
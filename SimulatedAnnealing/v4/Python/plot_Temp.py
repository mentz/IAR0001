#!/usr/bin/env python3
#! coding: utf-8

from matplotlib import pyplot as pl

NUM_ITERACOES = 250000

temps = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
for temp in temps:
    xar = [0]*NUM_ITERACOES
    yar = [0]*NUM_ITERACOES
    path = "temp_" + temp
    with open(path, 'r') as arq:
        for x, line in enumerate(arq.readlines()):
            y = float(line)
            xar[x] = x + 1
            yar[x] = y

    pl.plot(xar, yar)
    pl.ylim([-0.1, 10.1])
    pl.xlim([0, NUM_ITERACOES])
    pl.xlabel("Iteração")
    pl.ylabel("Temperatura")
    # TODO Trocar o trecho abaixo por impressão em arquivo.
    pl.savefig('temp_' + temp + "_img.png")
    pl.clf()

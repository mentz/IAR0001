#!/bin/bash

t0="1.0"
t1="0.00001"

for entr in 20 100 250
do
	for cs in `seq 0 9`
	do
		for i in `seq 0 9`
		do
			printf "SA: "
			./sa Entradas/uf${entr}-01.cnf $cs $t0 $t1 Saidas/sa_${entr}_${cs}_${t0}_${t1}_${i}.dat
			printf "RS: "
			./rs Entradas/uf${entr}-01.cnf Saidas/rs_${entr}_${i}.dat
		done
		# python3 py/media.py Saidas/sa_${entr}_${cs}_${t0}_${t1}_ .dat Saidas/sa_${entr}_${cs}_${t0}_${t1}_media.dat
		# python3 py/plot.py Saidas/sa_${entr}_${cs}_${t0}_${t1}_media.dat Graficos/sa_${entr}_${cs}_${t0}_${t1}_media.png
		# python3 py/media.py Saidas/rs_${entr}_ .dat Saidas/rs_${entr}_media.dat
		# python3 py/plot.py Saidas/rs_${entr}_media.dat Graficos/rs_${entr}_media.png
	done
done

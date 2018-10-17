#!/bin/bash

t0="1.0"
t1="0.00001"

for entr in 20 100 250
do
	for cs in `seq 0 9`
	do
		for i in `seq 0 9`
		do
			./sa Entradas/uf${entr}-01.cnf $cs $t0 $t1 Saidas/sa_${entr}_${cs}_${t0}_${t1}_${i}.dat
			./rs Entradas/uf${entr}-01.cnf Saidas/rs_${entr}_${i}.dat
		done
done

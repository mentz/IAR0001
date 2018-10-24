tamanhos = ['20', '100', '250']
temp_inicial = '10.0'
temp_final = '0.00001'
for tam in tamanhos:
    for tipo_temperatura in range(10):
        vetor = [0 for _ in range(250000)]
        for i in range(10):
            path = '../Saidas/sa_' + tam + "_" + str(tipo_temperatura) + "_" + temp_inicial + "_" + temp_final + "_" + str(i) + '.dat'
            arq = open(path)
            for idx, line in enumerate(arq.readlines()):
                valor = int(line.split()[1])
                vetor[idx] += valor
        for i in range(250000):
            vetor[i] //= 10
        path_saida = "../Saidas_Media/sa_media_" + tam + "_" + str(tipo_temperatura) + "_" + temp_inicial + '_' + temp_final + ".dat"
        print("Fazendo a media do " + tam + "_" + str(tipo_temperatura))
        with open(path_saida, 'a') as arq_saida:
            for i in range(250000):
                arq_saida.write(str(i + 1) + " " + str(vetor[i]) + "\n")
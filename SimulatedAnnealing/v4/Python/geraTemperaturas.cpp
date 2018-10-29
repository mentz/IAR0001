#include <bits/stdc++.h>

using namespace std;

double TEMP_INICIAL = 10.0;
double TEMP_FINAL = 0.0001;
double NUM_ITERACOES = 250000;

double CS0 (int iteracao){
    return TEMP_INICIAL - iteracao * (TEMP_INICIAL - TEMP_FINAL)/(double)NUM_ITERACOES;
}
double CS1 (int iteracao){
    return (TEMP_INICIAL * pow(TEMP_FINAL / TEMP_INICIAL, iteracao / NUM_ITERACOES));
}

// COM PROBLEMA:
double CS2 (int iteracao){
    double A = (TEMP_INICIAL - TEMP_FINAL) * (NUM_ITERACOES + 1) / NUM_ITERACOES;
    double B = TEMP_INICIAL - A;
    return  ((A / (double)(iteracao + 1)) + B);
}

// COM PROBLEMA:
double CS3 (int iteracao){
    double A = log(TEMP_INICIAL - TEMP_FINAL)/log(NUM_ITERACOES);
    return (TEMP_INICIAL - pow(iteracao, A));
}

// COM PROBLEMA:
double CS4 (int iteracao){
    return ((TEMP_INICIAL - TEMP_FINAL) / (1.0 + exp(3 * (iteracao - NUM_ITERACOES / 2.0))) + TEMP_FINAL);
}

double CS5 (int iteracao){
    return (0.5 * (TEMP_INICIAL - TEMP_FINAL) * (1 + cos((iteracao * acos(-1)) / NUM_ITERACOES)) + TEMP_FINAL);
}
double CS6 (int iteracao){
    return (0.5 * (TEMP_INICIAL - TEMP_FINAL) * (1 - tanh((10.0 * iteracao) / NUM_ITERACOES - 5.0)) + TEMP_FINAL);
}
double CS7 (int iteracao){
    return ((TEMP_INICIAL - TEMP_FINAL) / (cosh((10.0 * iteracao) / NUM_ITERACOES)) + TEMP_FINAL);
}
double CS8 (int iteracao){
    double A = (1 / NUM_ITERACOES) * (log(TEMP_INICIAL / TEMP_FINAL));
    return (TEMP_INICIAL * exp(-A * iteracao));
}
double CS9 (int iteracao){
    double A = (1 / pow(NUM_ITERACOES, 2)) * (log(TEMP_INICIAL / TEMP_FINAL));
    return (TEMP_INICIAL * exp(-A * pow(iteracao, 2)));
}

main(int argc, char const *argv[]){
    
    for(int i = 0; i <= 9; i++){
        if(!i){
            ofstream saida("temp_0");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS0(j) << endl;
            }
        } else if(i == 1){
            ofstream saida("temp_1");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS1(j) << endl;
            }
        } else if(i == 2){
            ofstream saida("temp_2");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS2(j) << endl;
            }
        } else if(i == 3){
            ofstream saida("temp_3");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS3(j) << endl;
            }
        } else if(i == 4){
            ofstream saida("temp_4");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS4(j) << endl;
            }
        } else if(i == 5){
            ofstream saida("temp_5");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS5(j) << endl;
            }
        } else if(i == 6){
            ofstream saida("temp_6");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS6(j) << endl;
            }
        } else if(i == 7){
            ofstream saida("temp_7");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS7(j) << endl;
            }
        } else if(i == 8){
            ofstream saida("temp_8");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS8(j) << endl;
            }
        } else {
            ofstream saida("temp_9");
            for(int j = 0; j < NUM_ITERACOES; j++){
                saida << CS9(j) << endl;
            }
        }
    }

    return 0;
}

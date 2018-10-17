#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int NUM_ITERACOES = 250000;

struct Clausula {
    vector<int> variaveis;

    Clausula(){}
    Clausula(vector<int> &_variaveis){
        variaveis = _variaveis;
    }

	int satisfeito(vector<bool> &conf){
		int sol = 0;
		for(int v : variaveis){
			if(v < 0){
				sol = sol || (not conf[abs(v) - 1]);
			} else {
				sol = sol || conf[abs(v) - 1];
			}
		}
		return sol;
	}
};

struct Solucao {
    vector<bool> conf;
    int num_Sat;

    Solucao(){
        num_Sat = 0;
    }
};

random_device rd;
mt19937 engine{rd()};
uniform_real_distribution<double> dist{0.0, 1.0};

vector<bool> init(int num_X){
    vector<bool> vet;
    for(int i = 0; i < num_X; i++){
        double tmp = dist(engine);
        vet.push_back(tmp >= 0.5);
    }
    return vet;
}

int eval(vector<Clausula> &SAT, vector<bool> &conf){
	int res = 0;
	for(Clausula c : SAT){
		if(c.satisfeito(conf)){
			res++;
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {
	string s, fpath;
    int num_X, num_Clausulas;
	ifstream entrada;
	ofstream saida;
	if (argc <= 2){
		printf("argumentos: entrada saida\n");
		return 1;
	}

	//
	// INICIO leitura da entrada
	entrada.open(argv[1]);
	if (!entrada.is_open()){
		printf("Erro ao abrir arquivo \"%s\" para entrada\n", argv[1]);
	}

	saida.open(argv[2]);
	if (!saida.is_open()){
		printf("Erro ao abrir arquivo \"%s\" para saída\n", argv[2]);
	}

	// cin >> s >> s;
	entrada >> s >> s;
	// cin >> num_X >> num_Clausulas;
	entrada >> num_X >> num_Clausulas;
	vector<Clausula> SAT;
    for(int i = 0; i < num_Clausulas; i++){
        vector<int> vet;
        for(int j = 0; j < 3; j++){
            int x;
			// cin >> x;
            entrada >> x;
            vet.push_back(x);
        }
		int t;
		// cin >> t; // ler o trailing zero
        entrada >> t; // ler o trailing zero
		SAT.push_back(Clausula(vet));
    }
	entrada.close();
	// FIM leitura da entrada
	//

    vector<bool> conf = init(num_X);
	int retT = eval(SAT, conf);

    Solucao solucaoFinal;
	solucaoFinal.num_Sat = retT;
	solucaoFinal.conf = conf;

    for(int i = 1; i <= NUM_ITERACOES; i++){
		vector<bool> n_conf = init(num_X);
        int ret = eval(SAT, n_conf);
		if(ret > retT){
			conf = n_conf;
			retT = ret;
		}
		if(retT > solucaoFinal.num_Sat){
			solucaoFinal.conf = conf;
			solucaoFinal.num_Sat = retT;
		}
		saida << i << " " << ret << "\n";
		// if(ret == num_Clausulas) break;
    }

	// cerr << "####################################################\n" << endl;
	// cerr << "Melhor solucao encontrada: " << solucaoFinal.num_Sat << endl;
	// for (int i = 0; i < solucaoFinal.conf.size(); i++){
	// 	cerr << (solucaoFinal.conf[i] ? "_":"1");
	// } cerr << endl;
	cout << "Satisfeito " << solucaoFinal.num_Sat << " de " << num_Clausulas << " clausulas.\n";
// */

    return 0;
}

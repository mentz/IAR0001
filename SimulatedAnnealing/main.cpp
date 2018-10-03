#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

double TEMP_INICIAL = 1;
double TEMP_FINAL = 0.0001;
double NUM_ITERACOES = 250000;

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

double CS0 (int iteracao){
    return TEMP_INICIAL - iteracao * (TEMP_INICIAL - TEMP_FINAL)/(double)NUM_ITERACOES;
}
double CS1 (int iteracao){
    return (TEMP_INICIAL * pow(TEMP_FINAL / TEMP_INICIAL, iteracao / NUM_ITERACOES));
}
double CS2 (int iteracao){
    double A = (TEMP_INICIAL - TEMP_FINAL) * (NUM_ITERACOES + 1) / NUM_ITERACOES;
    double B = TEMP_INICIAL - A;
    return  (A / (iteracao + 1) + B);
}
double CS3 (int iteracao){
    double A = log(TEMP_INICIAL - TEMP_FINAL)/log(NUM_ITERACOES);
    return (TEMP_INICIAL - pow(iteracao, A));
}
double CS4 (int iteracao){
    return ((TEMP_INICIAL - TEMP_INICIAL) / (1 + exp(3 * (iteracao - NUM_ITERACOES / 2.0))) + TEMP_FINAL);
}
double CS5 (int iteracao){
    return (0.5 * (TEMP_INICIAL - TEMP_FINAL) * (1 + cos(iteracao * acos(-1) / NUM_ITERACOES)) + TEMP_FINAL);
}
double CS6 (int iteracao){
    return (0.5 * (TEMP_INICIAL - TEMP_FINAL) * (1 - tanh(10 * iteracao / NUM_ITERACOES - 5)) + TEMP_FINAL);
}
double CS7 (int iteracao){
    return ((TEMP_INICIAL - TEMP_FINAL) / (cosh(10 * iteracao / NUM_ITERACOES)) + TEMP_FINAL);
}
double CS8 (int iteracao){
    double A = (1 / NUM_ITERACOES) * (log(TEMP_INICIAL / TEMP_FINAL));
    return (TEMP_INICIAL * exp(-A * iteracao));
}
double CS9 (int iteracao){
    double A = (1 / pow(NUM_ITERACOES, 2)) * (log(TEMP_INICIAL / TEMP_FINAL));
    return (TEMP_INICIAL * exp(-A * pow(iteracao, 2)));
}

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

vector<bool> nova_Conf(vector<bool> &conf, int iteracao, double temp){
	//double temp = CS0(iteracao);
	vector<bool> ret;
	for(int i = 0; i < conf.size(); i++){
		double randi = dist(engine);
		// if(randi < 0.05){
		if(randi < temp * 0.015){
			//double aux = dist(engine);
			//ret.push_back((bool)(aux >= 0.5));
			ret.push_back(!conf[i]);
		} else {
			ret.push_back(conf[i]);
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s >> s;
    int num_X, num_Clausulas;
    cin >> num_X >> num_Clausulas;

	vector<Clausula> SAT;
	//
	// for(int i = 1; i <= 10; i++){
	// 	cout << CS0(i) << endl;
	// }
	// return 0;
    for(int i = 0; i < num_Clausulas; i++){
        vector<int> vet;
        for(int j = 0; j < 3; j++){
            int x;
            cin >> x;
            vet.push_back(x);
        }
		int t;
        cin >> t; // ler o trailing zero
        SAT.push_back(Clausula(vet));
    }
    vector<bool> conf = init(num_X);
	int ret = eval(SAT, conf);

	double temp = TEMP_INICIAL;

    Solucao solucaoFinal;
	solucaoFinal.num_Sat = ret;
	solucaoFinal.conf = conf;
	int melhormelhor = 0;

    for(int i = 1; i <= NUM_ITERACOES; i++){
		temp = CS6(i);
		vector<bool> n_conf = nova_Conf(solucaoFinal.conf, i, temp);
		// for (auto e : n_conf)
		// {
		// 	printf("%d ", (int)e);
		// } printf("\n");
        int ret = eval(SAT, n_conf);
		if(ret > solucaoFinal.num_Sat){
			solucaoFinal.conf = n_conf;
			solucaoFinal.num_Sat = ret;
		} else {
			// double prob = CS0(i);
			double prob = temp;
			double randi = dist(engine);
			if(randi < prob){
				solucaoFinal.conf = n_conf;
				solucaoFinal.num_Sat = ret;
			}
		}
    }

	cout << solucaoFinal.num_Sat << endl;

    return 0;
}

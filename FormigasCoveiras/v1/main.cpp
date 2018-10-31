#include <bits/stdc++.h>

using namespace std;

#define NUM_FORMIGAS 5
#define TAM_MAPA 10
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

// Variáveis globais
random_device g_rd;
mt19937 g_e(g_rd());
uniform_real_distribution<> g_dist(0, 1);

int visao = 1;
int alcance = (2 * visao + 1) * (2 * visao + 1) - 1;
void updateAlcance(){ alcance = (2 * visao + 1) * (2 * visao + 1) - 1; }
void setVisao(int v){visao = v; updateAlcance();}
// Fim variáveis globais

class Mapa {
    private:
        int n, m;
        vector<vector<int> > mapa;
        map<pair<int, int>, int> ff;
    public:
        Mapa(int n, int m){
            this -> n = n;
            this -> m = m;
            mapa.assign(n + 1, vector<int>(m + 1, 0));
        }

        int getN(){
            return this -> n;
        }
        int getM(){
            return this -> m;
        }
        void initMapa(int numFormigasMortas){
            while(numFormigasMortas > 0){
                int y = rand() % this -> n;
                int x = rand() % this -> m;
                while(this -> mapa[y][x]){
                    y = rand() % this -> n;
                    x = rand() % this -> m;
                }
                this -> mapa[y][x] = 1;
                numFormigasMortas--;
            }
        }
        int getPos(int i, int j){
            return this -> mapa[i][j];
        }
        void setPos(int i, int j, int v){
            this -> mapa[i][j] = v;
        }

        // Para imprimir o mapa na main com menos perda de performance
        vector<vector<int> > &getMapa(){
            return mapa;
        }

        int valid(int y, int x){
            return (y >= 0 && x >= 0 && y < this -> n && x < this -> m);
        }
        int getVizinhanca(int i, int j){
            int cnt = 0;
            for(int y = -visao; y <= visao; y++){
                for(int x = -visao; x <= visao; x++){
                    int yy = y + i;
                    int xx = x + j;
                    if(valid(yy, xx) && this -> mapa[yy][xx] == 1) cnt++;
                }
            }
            return cnt;
        }

        void setFF(vector<pair<int,pair<int,int> > > &pos){
            this -> ff.clear();
            for(pair<int,pair<int, int> > p : pos){
                if(p.first == true){
                    ff[p.second] = 2;
                } else {
                    ff[p.second] = 1;
                }
            }
        }

        void printMapa(){
            for(int i = 0; i < this -> n; i++){
                if(!i){
                    for(int k = 0; k < this -> n + 2; k++) cout << "*";
                    cout << endl;
                }
                for(int j = 0; j < this -> m; j++){
                    if(!j) cout << "*";
                    if(ff.count({i, j}) > 0){
                        if(ff[{i,j}] == 2) cout << 3;
                        else cout << 2;
                    } else {
                        if(mapa[i][j] == 0) cout << " ";
                        else cout << mapa[i][j];
                    }
                }
                cout << "*\n";
            }
            for(int k = 0; k < this -> n + 2; k++)
                cout << "*";
            cout << endl;
        }
};

Mapa *mapa;

class Formiga
{
private:
    int x, y;
    bool carry;
public:

    Formiga()
    {
        this->x = rand() % mapa -> getN();
        this->y = rand() % mapa -> getM();
        this->carry = false;
    }


    void setPos(int y, int x){
        this -> y = y;
        this -> x = x;
    }
    void setCarry(bool state){
        this -> carry = state;
    }
    bool getCarry(){
        return this -> carry;
    }

    double getRandom();
    pair<int,int> getPos(){
        return {this -> y, this -> x};
    }
    void validatePos();
    void move();
    void runStep();
};

double Formiga::getRandom(){
    return g_dist(g_e);
}

void Formiga::validatePos(){
    this->y = MAX(MIN(this->y, mapa->getN() - 1), 0);
    this->x = MAX(MIN(this->x, mapa->getM() - 1), 0);
}

void Formiga::move()
{
    // Mover-se em qualquer direção (se for para fora do alcance
    //  apenas fica na mesma posição do quadro)
    int dir = int(this->getRandom() * 4);
    // 0,1,2,3 -> Cima,Direita,Baixo,Esquerda
    switch (dir) {
        case 0: this->setPos(y-1, x); break;
        case 1: this->setPos(y, x+1); break;
        case 2: this->setPos(y+1, x); break;
        case 3: this->setPos(y, x-1); break;
    }
    this->validatePos();
}

void Formiga::runStep()
{
    // Lógica para pegar
    // Se (não carrego) E (estou sobre formiga morta)
    if (!this->carry)
    {
        if (mapa -> getPos(y, x) == 1)
        {
            // obter vizinhança para cálculo de probabilidade
            int viz = mapa -> getVizinhanca(y, x);
            double prob = viz/(double) alcance - 0.01;
            if (this -> getRandom() > prob)
            {
                setCarry(true);
                mapa -> setPos(y, x, 0);
            }
        }
    }

    // Lógica para largar
    // Se (não carrego) E (estou sobre formiga morta)
    else if (this->carry)
    {
        if (mapa -> getPos(y, x) == 0)
        {
            // obter vizinhança para cálculo de probabilidade
            int viz = mapa->getVizinhanca(y, x);
            double prob = viz/(double) alcance + 0.01;
            if (this -> getRandom() < prob)
            {
                setCarry(false);
                mapa -> setPos(y, x, 1);
            }
        }
    }

    // Sempre se move após sua decisão, qualquer tenha sido.
    this->move();
}

// Descrição e análise do cenário:
// https://drive.google.com/open?id=18H2shg9uhS-mFW55CrwX-s6RQRUVXITYbvIdNhsiTkM
int main() {
    srand(time(NULL));

    setVisao(1);
    mapa = new Mapa(TAM_MAPA, TAM_MAPA);
    mapa -> initMapa(30);

    vector<Formiga *> formigas;
    for(int i = 0; i < NUM_FORMIGAS; i++){
        formigas.push_back(new Formiga());
    }

    vector<pair<int,pair<int, int> > > vet;
    // for(int i = 0; i < NUM_FORMIGAS; i++){
    //     vet.push_back(formigas[i] -> getPos());
    // }
    // mapa -> setFF(vet);
    // mapa -> printMapa();
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < NUM_FORMIGAS; j++){
            formigas[j] -> runStep();
        }
        vet.clear();
        for(int i = 0; i < NUM_FORMIGAS; i++){
            vet.push_back({formigas[i] -> getCarry(), formigas[i] -> getPos()});
        }
        mapa -> setFF(vet);
        mapa -> printMapa();
    }
    // vet.clear();
    // for(int i = 0; i < NUM_FORMIGAS; i++){
    //     vet.push_back(formigas[i] -> getPos());
    // }
    // mapa -> setFF(vet);
    // mapa -> printMapa();

    return 0;
}

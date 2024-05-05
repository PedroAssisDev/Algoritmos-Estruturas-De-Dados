#include <iostream>
#include <vector>

using namespace std;

struct TabelaHash {
    vector<int>* tabela;
    int capacidade;
    int tamanho;
    float fatorCargaLimite;
};
void inicializar(TabelaHash& th, int capacidade, float fatorCargaLimite);
void redimensionar(TabelaHash& th);
int funcaoHash(const TabelaHash& th, int chave);
void inserir(TabelaHash& th, int chave);
void exibir(const TabelaHash& th);

int funcaoHash(const TabelaHash& th, int chave) {
    return chave % th.capacidade;
}

void redimensionar(TabelaHash& th) {
    TabelaHash thNova;
    thNova.capacidade = th.capacidade* 2;
    thNova.tamanho = 0; 
    thNova.tabela = new vector<int>[thNova.capacidade];


    for (int i = 0; i < th.capacidade; ++i) {
        for (int j = 0; j < th.tabela[i].size(); ++j) {
            inserir(th, th.tabela[i][j]);
        }
    }
    th = thNova;
}

void inserir(TabelaHash& th, int chave) {
    if ((float)th.tamanho / th.capacidade > th.fatorCargaLimite) {
        cout << "redimensionar: " << endl;
        exibir(th);
        redimensionar(th); 
        cout << "redimensionado: " << endl;
        exibir(th);
        cout << "-----------------------" << endl;

    }

    int indice = funcaoHash(th, chave);
    th.tabela[indice].push_back(chave);
    th.tamanho++;
}
void exibir(const TabelaHash& th) {
    for (int i = 0; i < th.capacidade; ++i) {
        cout << i << ": ";
        for (int j = 0; j < th.tabela[i].size(); ++j) {
            cout << th.tabela[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    TabelaHash th;
    th.capacidade = 7;
    th.tamanho = 0;
    th.fatorCargaLimite = 0.5;
    th.tabela = new vector<int>[th.capacidade];

    inserir(th, 10);
    inserir(th, 20);
    inserir(th, 30);
    inserir(th, 40);
    inserir(th, 50);
    inserir(th, 60);
    inserir(th, 70);
    inserir(th, 11);
    inserir(th, 22);
    inserir(th, 33);
    inserir(th, 44);
    inserir(th, 55);
    inserir(th, 66);
    inserir(th, 77);

    cout << "Tabela Hash após inserção:" << endl;
    exibir(th);

    delete[] th.tabela;

    return 0;
}

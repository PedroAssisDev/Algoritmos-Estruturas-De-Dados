#include <iostream>
#include <cmath>

using namespace std;

const int Tsize = 15; // Tamanho da tabela hash

struct HashTabela {
    int tHash[Tsize];
};

int fhash(int val){
    return log2(val -1);
}

void inserir(HashTabela &tabela, int local, int valor){
    tabela.tHash[local] = valor;
}

int main() {
    HashTabela tabela;
    int valores[15] = {16385, 2, 17, 3, 33, 513, 8193, 1025, 65, 5, 129, 2049, 9, 257, 4097};
    for(int i = 0; i < 15; i++ ){
        inserir(tabela, fhash(valores[i]), valores[i]);
    }
    for(int i = 0; i < 15; i++ ){
        cout << tabela.tHash[i] <<", ";
    }  
}

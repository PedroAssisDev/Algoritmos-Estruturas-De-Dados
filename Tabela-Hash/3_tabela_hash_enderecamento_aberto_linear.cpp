#include <iostream>
using namespace std;

const int Tsize = 10; // Tamanho da tabela hash

struct HashTabela {
    int tHash[Tsize];
};

// Função de hash simples que retorna o resto da divisão
int funcao_hashing(int num) {
    return num % Tsize;
}

// Função para buscar um elemento na tabela hash
int buscar(HashTabela tabela, int n) {
    int i = 0;
    int pos = funcao_hashing(n);
    while (i < Tsize && tabela.tHash[(pos + i) % Tsize] != -1 && tabela.tHash[(pos + i) % Tsize] != n) {
        i = i + 1;
    }
    if (tabela.tHash[(pos + i) % Tsize] == n) {
        return (pos + i) % Tsize;
    } else {
        return Tsize; // Não encontrado
    }
}

// Função para inserir um elemento na tabela hash
void inserir(HashTabela &tabela, int n) {
    int i = 0;
    int pos = funcao_hashing(n);
    while (i < Tsize && tabela.tHash[(pos + i) % Tsize] > -1) {
        i = i + 1;
    }
    if (i < Tsize) {
        tabela.tHash[(pos + i) % Tsize] = n;
    } else {
        cout << "\nTabela cheia!";
    }
}

// Função para remover um elemento da tabela hash
void remover(HashTabela &tabela, int n) {
    int posicao = buscar(tabela, n);
    if (posicao < Tsize) {
        tabela.tHash[posicao] = -2;
    } else {
        cout << "\nElemento não está presente.";
    }
}

// Função para exibir a tabela hash
void mostrar_hash(HashTabela tabela) {
    for (int i = 0; i < Tsize; i++) {
            cout << "\nEntrada " << i << ": " << tabela.tHash[i];
        }
}

int main() {
    HashTabela tabela;
    // Inicializando a tabela hash com valores inválidos
    for (int i = 0; i < Tsize; i++) {
        tabela.tHash[i] = -1;
    }

    inserir(tabela,12); // Inserindo um elemento
    inserir(tabela,18);
    inserir(tabela,71);
    inserir(tabela,15);
    inserir(tabela,16);
    inserir(tabela,181);
    inserir(tabela,712);
    inserir(tabela,153);
    inserir(tabela,165);
    mostrar_hash(tabela); // Exibindo a tabela após inserção
    remover(tabela, 12); // Removendo um elemento
    mostrar_hash(tabela); // Exibindo a tabela após remoção
    return 0;
}

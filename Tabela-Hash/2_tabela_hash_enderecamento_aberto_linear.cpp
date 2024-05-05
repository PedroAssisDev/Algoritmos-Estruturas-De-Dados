#include <iostream>
using namespace std;

const int Tsize = 10; // Tamanho da tabela hash

struct hash {
    <t> tHash[Tsize]
    int chave;
    char livre;  // 'L' - Livre, 'O' - Ocupado, 'R' - Removido
};

// Função de hash simples que retorna o resto da divisão
int funcao_hashing(int num) {
    return num % tam;
}

// Função para exibir a tabela hash
void mostrar_hash(hash tabela[]) {
    for (int i = 0; i < tam; i++) {
        if (tabela[i].livre == 'O') {
            cout << "\nEntrada " << i << ": " << tabela[i].chave;
        }
    }
}

// Função para inserir um elemento na tabela hash
void inserir(hash tabela[], int pos, int n) {
    int i = 0;
    while (i < tam && tabela[(pos + i) % tam].livre != 'L' && tabela[(pos + i) % tam].livre != 'R') {
        i = i + 1;
    }
    if (i < tam) {
        tabela[(pos + i) % tam].chave = n;
        tabela[(pos + i) % tam].livre = 'O';
    } else {
        cout << "\nTabela cheia!";
    }
}

// Função para buscar um elemento na tabela hash
int buscar(hash tabela[], int n) {
    int i = 0;
    int pos = funcao_hashing(n);
    while (i < tam && tabela[(pos + i) % tam].livre != 'L' && tabela[(pos + i) % tam].chave != n) {
        i = i + 1;
    }
    if (tabela[(pos + i) % tam].chave == n && tabela[(pos + i) % tam].livre != 'R') {
        return (pos + i) % tam;
    } else {
        return tam; // Não encontrado
    }
}

// Função para remover um elemento da tabela hash
void remover(hash tabela[], int n) {
    int posicao = buscar(tabela, n);
    if (posicao < tam) {
        tabela[posicao].livre = 'R';
    } else {
        cout << "\nElemento não está presente.";
    }
}

int main() {
    hash tabela[tam];
    // Inicializando a tabela hash como livre
    for (int i = 0; i < tam; i++) {
        tabela[i].livre = 'L';
    }
    inserir(tabela, 2, 12); // Inserindo um elemento
    inserir(tabela, 5, 15);
    inserir(tabela, 2, 12); // Inserindo um elemento
    inserir(tabela, 5, 15);
    inserir(tabela, 2, 12); // Inserindo um elemento
    inserir(tabela, 5, 15);
    mostrar_hash(tabela); // Exibindo a tabela após inserção
    remover(tabela, 12); // Removendo um elemento
    mostrar_hash(tabela); // Exibindo a tabela após remoção
    return 0;
}

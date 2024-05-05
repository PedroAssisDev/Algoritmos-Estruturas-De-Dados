#include <iostream>

using namespace std;

const int m = 5; // Tamanho da tabela

struct No {
    int x;
    No *prox;
};

struct HTable {
    No *table[m];
};

// Função de dispersão simples (exemplo)
int fhash(int chave) {
    return chave % m;
}

// Função para inserir um elemento na tabela utilizando encadeamento exterior
void inserir(HTable& tabela, int chave) {
    // Calcula o endereço base usando a função de hash
    int enderecoBase = fhash(chave);
    // Cria um novo nó para armazenar a chave
    No *novo = new No;
    novo->x = chave; // Define o valor da chave no novo nó
    // O novo nó aponta para o atual primeiro nó da lista correspondente ao endereço base
    novo->prox = tabela.table[enderecoBase];
    // O ponteiro do início da lista no endereço base é atualizado para apontar para o novo nó
    tabela.table[enderecoBase] = novo;
}


// Função para buscar um elemento na tabela
bool buscar(const HTable& tabela, int chave) {
    int enderecoBase = fhash(chave);
    No *atual = tabela.table[enderecoBase];
    while (atual != nullptr) {
        if (atual->x == chave) {
            return true; // Elemento encontrado
        }
        atual = atual->prox;
    }
    return false; // Elemento não encontrado
}

// Função para remover um elemento da tabela
void remover(HTable& tabela, int chave) {
    int enderecoBase = fhash(chave);
    No *atual = tabela.table[enderecoBase];
    No *anterior = nullptr;

    while (atual != nullptr && atual->x != chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != nullptr) {
        if (anterior == nullptr) {
            tabela.table[enderecoBase] = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        delete atual;
    }
}

int main() {
    HTable tabela = {nullptr};

    inserir(tabela, 5);
    inserir(tabela, 15);
    inserir(tabela, 25);
    inserir(tabela, 35);
    inserir(tabela, 45);
    inserir(tabela, 55);
    inserir(tabela, 26);
    inserir(tabela, 6);
    inserir(tabela, 36);


    cout << "Busca 5: " << (buscar(tabela, 5) ? "Encontrado" : "Não encontrado") << endl;
    cout << "Busca 10: " << (buscar(tabela, 10) ? "Encontrado" : "Não encontrado") << endl;

    remover(tabela, 15);

    cout << "Busca 15: " << (buscar(tabela, 15) ? "Encontrado" : "Não encontrado") << endl;

    return 0;
}

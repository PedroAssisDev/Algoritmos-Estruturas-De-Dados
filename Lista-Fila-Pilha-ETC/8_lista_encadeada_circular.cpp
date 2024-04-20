#include <iostream>

// Definição da estrutura do nó da lista encadeada
struct No {
    int info;     // Informação armazenada no nó
    No* prox;     // Ponteiro para o próximo nó
};

// Função para inserir um elemento no final da lista
void inserirElemento(No*& ptLista, int valor) {
    No* novoNo = new No;           // Cria um novo nó
    novoNo->info = valor;          // Atribui o valor ao novo nó

    if (ptLista == nullptr) {      // Se a lista estiver vazia
        novoNo->prox = novoNo;     // O próximo nó aponta para ele mesmo (lista circular)
        ptLista = novoNo;          // O novo nó é o primeiro da lista
    } else {
        novoNo->prox = ptLista->prox;  // O próximo nó do novo nó aponta para o primeiro nó da lista
        ptLista->prox = novoNo;        // O próximo nó do último nó da lista aponta para o novo nó
    }
}

// Função para imprimir os elementos da lista
void imprimirListaCircular(No* ptLista) {
    if (ptLista != nullptr) {     // Se a lista não estiver vazia
        No* temp = ptLista;       // Ponteiro temporário para percorrer a lista
        do {
            std::cout << temp->info << " ";   // Imprime o valor do nó atual
            temp = temp->prox;     // Move para o próximo nó
        } while (temp != ptLista); // Enquanto não voltar ao primeiro nó da lista
        std::cout << std::endl;
    }
}

// Função para buscar um elemento na lista circular
bool buscaElementoCircular(No* ptLista, int valor, No*& ant, No*& pont) {
    if (ptLista == nullptr) {   // Se a lista estiver vazia
        ant = nullptr;
        pont = nullptr;
        return false;
    }

    ant = ptLista;             // Inicializa o nó anterior como o primeiro nó da lista
    pont = ptLista->prox;      // Inicializa o nó ponteiro como o segundo nó da lista

    // Percorre a lista circular até encontrar o elemento ou voltar ao início da lista
    while (pont != ptLista && pont->info < valor) {
        ant = pont;
        pont = pont->prox;
    }

    // Se encontrou o elemento
    if (pont != ptLista && pont->info == valor) {
        return true;
    } else {  // Se não encontrou o elemento
        return false;
    }
}

int main() {
    No* ptLista = nullptr;  // Ponteiro para o primeiro nó da lista

    // Inserindo elementos na lista
    inserirElemento(ptLista, 10);
    inserirElemento(ptLista, 20);
    inserirElemento(ptLista, 30);

    // Imprimindo a lista circular
    std::cout << "Lista circular: ";
    imprimirListaCircular(ptLista);  // Saída: 10 20 30

    // Buscando elementos na lista circular
    No* ant = nullptr;
    No* pont = nullptr;
    int valorBusca = 20;
    if (buscaElementoCircular(ptLista, valorBusca, ant, pont)) {
        std::cout << "Elemento " << valorBusca << " encontrado!" << std::endl;
    } else {
        std::cout << "Elemento " << valorBusca << " não encontrado!" << std::endl;
    }

    return 0;
}

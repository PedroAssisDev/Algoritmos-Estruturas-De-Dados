#include <iostream>
#include <queue>

// Definição da estrutura do nó
struct NoArvore {
    int chave;              // Chave do nó
    NoArvore* filhos;       // Ponteiro para o primeiro filho
    NoArvore* listaIrmaos;  // Ponteiro para o próximo irmão
};

// Função para criar um novo nó
NoArvore* criarNo(int chave) {
    NoArvore* novoNo = new NoArvore;  // Aloca memória para um novo nó
    novoNo->chave = chave;            // Define a chave do nó
    novoNo->filhos = nullptr;         // Inicializa o ponteiro filhos como nullptr
    novoNo->listaIrmaos = nullptr;    // Inicializa o ponteiro listaIrmaos como nullptr
    return novoNo;                    // Retorna o ponteiro para o novo nó
}

// Função para adicionar um filho a um nó pai
void adicionarFilho(NoArvore* pai, int chaveFilho) {
    NoArvore* novoFilho = criarNo(chaveFilho);  // Cria um novo nó filho
    if (pai->filhos == nullptr) {
        // Se o pai não tem filhos, adiciona o novo filho diretamente
        pai->filhos = novoFilho;
    } else {
        // Se o pai já tem filhos, encontra o último filho e adiciona o novo filho como irmão
        NoArvore* temp = pai->filhos;
        while (temp->listaIrmaos != nullptr) {
            temp = temp->listaIrmaos;  // Percorre até o último irmão na lista
        }
        temp->listaIrmaos = novoFilho;  // Adiciona o novo filho como o último irmão
    }
}

// Função para buscar um nó com uma chave específica (busca em profundidade)
NoArvore* buscarNo(NoArvore* raiz, int chave) {
    if (raiz == nullptr) return nullptr;  // Se a árvore está vazia, retorna nullptr
    if (raiz->chave == chave) return raiz;  // Se encontrou o nó, retorna o ponteiro para ele

    // Percorre os filhos do nó atual recursivamente
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        NoArvore* resultado = buscarNo(temp, chave);  // Busca recursiva no filho atual
        if (resultado != nullptr) return resultado;   // Se encontrou o nó, retorna o ponteiro para ele
        temp = temp->listaIrmaos;  // Move para o próximo irmão
    }
    return nullptr;  // Se não encontrou o nó, retorna nullptr
}

// Função para percorrer e imprimir a árvore (em profundidade)
void percorrerArvore(NoArvore* raiz, int nivel = 0) {
    if (raiz == nullptr) return;  // Se a árvore está vazia, retorna

    // Imprime a chave do nó com indentação baseada no nível do nó
    for (int i = 0; i < nivel; ++i) {
        std::cout << "  ";
    }
    std::cout << raiz->chave << std::endl;

    // Percorre recursivamente os filhos do nó atual
    NoArvore* temp = raiz->filhos;
    while (temp != nullptr) {
        percorrerArvore(temp, nivel + 1);  // Chamada recursiva para o próximo nível
        temp = temp->listaIrmaos;          // Move para o próximo irmão
    }
}

int main() {
    // Cria a árvore e adiciona nós
    NoArvore* raiz = criarNo(1);        // Cria o nó raiz com chave 1
    adicionarFilho(raiz, 2);            // Adiciona filho com chave 2 à raiz
    adicionarFilho(raiz, 3);            // Adiciona filho com chave 3 à raiz
    NoArvore* filho2 = buscarNo(raiz, 2);  // Busca o nó com chave 2
    adicionarFilho(filho2, 4);          // Adiciona filho com chave 4 ao nó com chave 2
    adicionarFilho(filho2, 5);          // Adiciona filho com chave 5 ao nó com chave 2
    NoArvore* filho3 = buscarNo(raiz, 3);  // Busca o nó com chave 3
    adicionarFilho(filho3, 6);          // Adiciona filho com chave 6 ao nó com chave 3
    adicionarFilho(filho3, 7);          // Adiciona filho com chave 7 ao nó com chave 3

    // Percorre e imprime a árvore
    std::cout << "Árvore n-ária:" << std::endl;
    percorrerArvore(raiz);  // Chama a função para percorrer e imprimir a árvore

    return 0;
}

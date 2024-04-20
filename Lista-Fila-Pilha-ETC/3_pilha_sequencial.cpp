#include <iostream>

// Tamanho máximo da pilha
const int MAX_TAMANHO = 5;

// Estrutura da pilha
struct Pilha {
    int itens[MAX_TAMANHO];
    int topo;
};

// Função para inicializar a pilha
void inicializarPilha(Pilha& pilha) {
    pilha.topo = -1;
}

// Função para verificar se a pilha está vazia
bool pilhaVazia(Pilha& pilha) {
    return (pilha.topo == -1);
}

// Função para verificar se a pilha está cheia
bool pilhaCheia(Pilha& pilha) {
    return (pilha.topo == MAX_TAMANHO - 1);
}

// Função para inserir um elemento na pilha
void inserirPilha(Pilha& pilha, int valor) {
    if (!pilhaCheia(pilha)) {
        pilha.itens[++pilha.topo] = valor;
    } else {
        std::cout << "Overflow - A pilha está cheia!" << std::endl;
    }
}

// Função para remover um elemento da pilha
int removerPilha(Pilha& pilha) {
    if (!pilhaVazia(pilha)) {
        return pilha.itens[pilha.topo--];
    } else {
        std::cout << "Underflow - A pilha está vazia!" << std::endl;
        return -1; // Valor inválido para indicar erro
    }
}

// Função principal
int main() {
    Pilha minhaPilha;
    inicializarPilha(minhaPilha);

    // Inserindo elementos na pilha
    inserirPilha(minhaPilha, 1);
    inserirPilha(minhaPilha, 2);
    inserirPilha(minhaPilha, 3);
    inserirPilha(minhaPilha, 4);
    inserirPilha(minhaPilha, 5);

    // Tentando inserir mais um elemento (vai causar overflow)
    inserirPilha(minhaPilha, 6);

    // Removendo elementos da pilha
    std::cout << "Elementos removidos da pilha: ";
    while (!pilhaVazia(minhaPilha)) {
        std::cout << removerPilha(minhaPilha) << " ";
    }
    std::cout << std::endl;

    // Tentando remover mais um elemento (vai causar underflow)
    removerPilha(minhaPilha);

    return 0;
}

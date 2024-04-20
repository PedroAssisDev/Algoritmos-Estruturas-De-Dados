#include <iostream>
using namespace std;

// Definição do struct Nó
struct No {
    int digito;
    No* proximo;
};

// Função para inserir um dígito no início de uma lista encadeada
void inserirInicio(int digito, No*& lista) {
    No* novo = new No;
    novo->digito = digito;
    novo->proximo = lista;
    lista = novo;
}

// Função para somar dois números representados por listas encadeadas
No* somaListas(No* L1, No* L2) {
    No* resultado = nullptr;
    int carry = 0;

    // Enquanto houver dígitos em ambas as listas ou houver um carry
    while (L1 != nullptr || L2 != nullptr || carry) {
        int soma = carry;
        if (L1 != nullptr) {
            soma += L1->digito;
            L1 = L1->proximo;
        }
        if (L2 != nullptr) {
            soma += L2->digito;
            L2 = L2->proximo;
        }

        carry = soma / 10; // Determina se há carry para o próximo dígito
        soma %= 10; // Mantém apenas o dígito menos significativo

        inserirInicio(soma, resultado);
    }

    return resultado;
}

// Função para imprimir uma lista encadeada
void imprimirLista(No* lista) {
    while (lista != nullptr) {
        cout << lista->digito;
        lista = lista->proximo;
    }
    cout << endl;
}

int main() {
    // Exemplo de números grandes representados por listas encadeadas
    No* L1 = nullptr;
    No* L2 = nullptr;

    // Inserindo dígitos para representar os números (inseridos na ordem inversa)
    inserirInicio(3, L1);
    inserirInicio(2, L1);
    inserirInicio(1, L1);

    inserirInicio(6, L2);
    inserirInicio(5, L2);
    inserirInicio(4, L2);

    // Realizando a soma
    No* resultado = somaListas(L1, L2);

    // Imprimindo o resultado
    cout << "Soma dos números:" << endl;
    imprimirLista(resultado);

    return 0;
}

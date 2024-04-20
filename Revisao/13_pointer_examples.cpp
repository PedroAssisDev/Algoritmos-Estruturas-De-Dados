#include <iostream>

// Função para demonstrar alocação e desalocação de memória dinâmica
void alocaMemoria() {
    // Aloca memória para um inteiro
    int* ptr = new int;
    *ptr = 10;
    printf("Valor armazenado na memória alocada dinamicamente: %d\n", *ptr);

    // Libera a memória alocada dinamicamente
    delete ptr;
}

// Função para demonstrar passagem de parâmetros usando ponteiros
void alteraValor(int* ptr) {
    // Altera o valor apontado pelo ponteiro
    *ptr = 20;
}

// Função para demonstrar uso de ponteiros e arrays
void manipulaArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr_arr = arr;

    printf("Elementos do array: \n");
    for(int i = 0; i < 5; ++i) {
        printf("Elemento %d (array): %d, (ponteiro): %d, (endereço): %p\n", i + 1, arr[i], *(ptr_arr + i), ptr_arr + i);

    }
    printf("\n");
}

// Função para demonstrar ponteiros para funções
void func() {
    printf("Hello, world!\n");
}

int main() {
    // Exemplo de declaração de ponteiro
    int* ptr;

    // Alocação e desalocação de memória dinâmica
    printf("Exemplo de alocação e desalocação de memória dinâmica:\n");
    alocaMemoria();
    printf("\n");

    // Passagem de parâmetros para funções usando ponteiros
    printf("Exemplo de passagem de parâmetros para funções usando ponteiros:\n");
    int num = 10;
    printf("Valor antes da função: %d\n", num);
    alteraValor(&num);
    printf("Valor depois da função: %d\n", num);
    printf("\n");

    // Uso de ponteiros e arrays
    printf("Exemplo de uso de ponteiros e arrays:\n");
    manipulaArray();
    printf("\n");

    // Ponteiros para funções
    printf("Exemplo de ponteiros para funções:\n");
    void (*ptr_func)() = &func;
    (*ptr_func)();
    printf("\n");

    return 0;
}

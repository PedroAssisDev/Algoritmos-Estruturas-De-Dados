#include <stdio.h>

// Função recursiva para calcular o n-ésimo termo da sequência de Fibonacci
unsigned long long fibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned int termos;

    // Solicita ao usuário o número de termos da sequência de Fibonacci
    printf("Digite o número de termos da sequência de Fibonacci: ");
    scanf("%u", &termos);

    // Calcula e exibe o n-ésimo termo da sequência de Fibonacci
    printf("Fibonacci: %llu \n", fibonacci(termos));

    // Exibe a sequência de Fibonacci até o n-ésimo termo
    printf("Sequência de Fibonacci:\n");
    for (unsigned int i = 0; i <= termos; ++i) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

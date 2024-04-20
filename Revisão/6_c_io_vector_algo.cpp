#include <cstdio>   // Para entrada e saída em formato C
#include <vector>   // Para contêineres
#include <algorithm> // Para algoritmos

int main() {
    // Exemplo de entrada e saída usando printf e scanf
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    printf("Você digitou: %d\n", numero);

    // Exemplo de uso de contêineres (vector)
    std::vector<int> numeros = {5, 2, 8, 3, 1};
    printf("Conteúdo do vetor:");
    for (int num : numeros) {
        printf(" %d", num);
    }
    printf("\n");

    // Exemplo de uso de algoritmos com contêineres
    std::sort(numeros.begin(), numeros.end()); // Ordena os números
    printf("Números ordenados:");
    for (int num : numeros) {
        printf(" %d", num);
    }
    printf("\n");

    return 0;
}

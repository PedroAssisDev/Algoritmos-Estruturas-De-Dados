#include <iostream>

using namespace std;

int main() {
    const int tamanho = 5; // Tamanho do vetor

    // Aloca dinamicamente memória para o vetor
    int *vetor = new int[tamanho];

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == nullptr) {
        cout << "Erro ao alocar memória!" << endl;
        return 1;
    }

    // Preenche o vetor com valores genéricos
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = i * 10; // Preenche o vetor com valores múltiplos de 10
    }

    // Imprime os valores e os endereços de memória dos elementos do vetor
    cout << "Valores do vetor e endereços de memória dos elementos:" << endl;
    for (int i = 0; i < tamanho; ++i) {
        cout << "Valor: " << vetor[i] << ", Endereço: " << &vetor[i] << endl;
    }

    // Libera a memória alocada dinamicamente
    delete[] vetor;

    return 0;
}

#include <iostream>
#include <fstream>
#include <memory> // Para ponteiros inteligentes
#include <vector>
#include <algorithm> // Para algoritmos STL

// Função para calcular a média de um vetor de inteiros
double calcularMedia(const std::vector<int>& numeros) {
    if (numeros.empty()) {
        return 0.0; // Retorna 0 se o vetor estiver vazio
    }

    int soma = 0;
    for (int num : numeros) {
        soma += num;
    }
    return static_cast<double>(soma) / numeros.size();
}

int main() {
    // Alocação dinâmica de memória para armazenar os números lidos do arquivo
    std::unique_ptr<std::vector<int>> numeros(new std::vector<int>);

    // Abertura do arquivo de entrada
    std::ifstream arquivo("data_folder/example_5.txt");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1; // Encerra o programa com código de erro
    }

    // Leitura dos números do arquivo e armazenamento no vetor dinâmico
    int num;
    while (arquivo >> num) {
        numeros->push_back(num);
    }

    // Fechamento automático do arquivo quando o objeto arquivo sai de escopo
    // Isso é um exemplo de gestão de recursos

    // Cálculo da média dos números
    double media = calcularMedia(*numeros);

    // Impressão da média calculada
    printf("A média dos números lidos é: %.2f\n", media);

    // Ordenação dos números em ordem crescente
    std::sort(numeros->begin(), numeros->end());

    // Impressão dos números ordenados
    printf("Números em ordem crescente: ");
    for (int num : *numeros) {
        printf("%d ", num);
    }
    printf("\n");

    // Busca binária por um número específico
    int alvo = 77;
    auto it = std::lower_bound(numeros->begin(), numeros->end(), alvo);
    if (it != numeros->end() && *it == alvo) {
        printf("O número %d foi encontrado.\n", alvo);
    } else {
        printf("O número %d não foi encontrado.\n", alvo);
    }

    // Liberação automática da memória alocada para o vetor dinâmico
    // Isso é um exemplo de alocação dinâmica de memória com liberação automática

    return 0; // Programa encerrado com sucesso
}

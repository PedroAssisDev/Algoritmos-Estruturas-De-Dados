#include <cstdio>
#include <stdexcept> // Para exceções padrão

// Função para dividir dois números
double dividir(double a, double b) {
    // Verifica se o divisor é zero
    if (b == 0) {
        // Lança uma exceção se b for zero
        throw std::invalid_argument("Divisão por zero");
    }
    // Retorna o resultado da divisão
    return a / b;
}

int main() {
    try {
        // Exemplo de divisão com valores válidos
        double resultado_valido = dividir(10.0, 2.0);
        // Imprime o resultado da divisão
        printf("Resultado da divisão válida: %.2f\n", resultado_valido);

        // Tentativa de divisão por zero
        double resultado_invalido = dividir(10.0, 0.0);
        // Imprime o resultado da divisão (não será alcançado devido à exceção)
        printf("Resultado da divisão inválida: %.2f\n", resultado_invalido);
    } catch (const std::invalid_argument& e) { // Captura de exceção específica
        // Imprime a mensagem de erro da exceção
        fprintf(stderr, "Erro durante a divisão: %s\n", e.what());
    } catch (const std::exception& e) { // Captura de exceção genérica
        // Imprime uma mensagem de erro genérica se a exceção não for especificamente tratada
        fprintf(stderr, "Erro desconhecido: %s\n", e.what());
    }

    return 0;
}

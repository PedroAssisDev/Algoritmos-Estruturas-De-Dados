#include <iostream>   // Inclui a biblioteca iostream para usar std::cout
#include <cstring>    // Inclui a biblioteca cstring para manipulação de strings
#include <string>     // Inclui a biblioteca string para usar std::string

// Definição de uma estrutura (struct) para representar uma pessoa
struct Pessoa {
    // Membros da estrutura
    char nome[50];  // Armazena o nome da pessoa
    int idade;      // Armazena a idade da pessoa

    // Método para exibir os detalhes da pessoa
    void exibirDetalhes() {
        std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
    }
};

int main() {
    // Arrays unidimensionais
    int array_unidimensional[5]; // Declara um array unidimensional de tamanho 5
    array_unidimensional[0] = 10; // Inicializa o primeiro elemento do array
    array_unidimensional[1] = 20; // Inicializa o segundo elemento do array
    array_unidimensional[2] = 30; // Inicializa o terceiro elemento do array
    array_unidimensional[3] = 40; // Inicializa o quarto elemento do array
    array_unidimensional[4] = 50; // Inicializa o quinto elemento do array

    // Acesso aos elementos do array unidimensional e impressão na tela
    std::cout << "Elementos do array unidimensional:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Elemento " << i + 1 << ": " << array_unidimensional[i] << std::endl;
    }

    // Arrays multidimensionais
    int array_multidimensional[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Declara e inicializa um array multidimensional 3x3

    // Acesso aos elementos do array multidimensional e impressão na tela
    std::cout << "\nElementos do array multidimensional:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Elemento [" << i << "][" << j << "]: " << array_multidimensional[i][j] << std::endl;
        }
    }

    // Relação entre ponteiros e arrays
    int array[5] = {10, 20, 30, 40, 50}; // Declara e inicializa um array
    int *ptr = array; // Declara um ponteiro que aponta para o primeiro elemento do array

    // Acesso aos elementos do array usando ponteiros e impressão na tela
    std::cout << "\nElementos do array acessados via ponteiro:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Elemento " << i + 1 << " (array): " << array[i] << ", (ponteiro): " << *(ptr + i) << ", (endereço): " << (ptr + i) << std::endl;
    }

    // Strings
    char c_string[20]; // Declara uma C string
    strcpy(c_string, "Hello, World!"); // Inicializa a C string

    // Impressão da C string na tela
    std::cout << "\nC String: " << c_string << std::endl;

    // C++ strings
    std::string cpp_string = "Hello, C++!"; // Declara e inicializa uma C++ string

    // Impressão da C++ string na tela
    std::cout << "C++ String: " << cpp_string << std::endl;

    // Manipulação básica de strings
    cpp_string += " Welcome to C++ Programming!"; // Concatenação de strings
    std::cout << "C++ String (após concatenação): " << cpp_string << std::endl;

    // Estruturas (structs) e classes
    
    Pessoa pessoa1; // Declara uma variável do tipo Pessoa
    strcpy(pessoa1.nome, "João"); // Inicializa o nome da pessoa
    pessoa1.idade = 30; // Inicializa a idade da pessoa

    // Método para exibir os detalhes da pessoa
    std::cout << "\nDetalhes da Pessoa 1:" << std::endl;
    pessoa1.exibirDetalhes();

    // Programação Orientada a Objetos (POO)
    // Definição de uma classe
    class Carro {
    public:
        // Membros da classe
        std::string marca;
        std::string modelo;
        int ano;

        // Método para exibir os detalhes do carro
        void exibirDetalhes() {
            std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: " << ano << std::endl;
        }
    };

    // Criando um objeto da classe Carro
    Carro carro1;
    carro1.marca = "Toyota";
    carro1.modelo = "Corolla";
    carro1.ano = 2022;

    // Exibindo os detalhes do carro
    std::cout << "\nDetalhes do Carro 1:" << std::endl;
    carro1.exibirDetalhes();

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}

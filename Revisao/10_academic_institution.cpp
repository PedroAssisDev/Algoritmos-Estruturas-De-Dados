#include <iostream>
#include <string>
#include <vector>

// Classe Universidade
class Universidade {
private:
    std::string nome;
    std::vector<Estudante*> estudantes;

public:
    Universidade(std::string nome) : nome(nome) {}

    // Método para adicionar estudante à universidade
    void adicionarEstudante(Estudante* estudante) {
        estudantes.push_back(estudante);
    }

    // Método para listar todos os estudantes da universidade
    void listarEstudantes() {
        std::cout << "Estudantes da Universidade " << nome << ":\n";
        for (Estudante* estudante : estudantes) {
            std::cout << " - " << estudante->getNome() << std::endl;
        }
    }
};

// Classe Pessoa (classe base para Estudante)
class Pessoa {
protected:
    std::string nome;

public:
    Pessoa(std::string nome) : nome(nome) {}

    // Método para obter o nome da pessoa
    std::string getNome() const {
        return nome;
    }
};

// Classe Estudante, derivada da classe Pessoa
class Estudante : public Pessoa {
private:
    int matricula;
    Universidade* universidade;

public:
    Estudante(std::string nome, int matricula, Universidade* universidade)
        : Pessoa(nome), matricula(matricula), universidade(universidade) {}

    // Método para obter a matrícula do estudante
    int getMatricula() const {
        return matricula;
    }

    // Método para obter a universidade do estudante
    Universidade* getUniversidade() const {
        return universidade;
    }

    // Método para matricular o estudante na universidade
    void matricular() {
        universidade->adicionarEstudante(this);
    }
};

int main() {
    // Criação de uma universidade
    Universidade ufabc("UFABC");

    // Criação de alguns estudantes
    Estudante estudante1("Joao", 1234, &ufabc);
    Estudante estudante2("Maria", 5678, &ufabc);

    // Matricular os estudantes na universidade
    estudante1.matricular();
    estudante2.matricular();

    // Listar todos os estudantes matriculados na universidade
    ufabc.listarEstudantes();

    return 0;
}

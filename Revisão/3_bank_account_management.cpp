#include <iostream>
#include <string>

// Classe base para Conta Bancária
class ContaBancaria {
protected:
    std::string titular;
    double saldo;

public:
    static int numContas; // Atributo estático para contar o número total de contas

    // Construtor
    ContaBancaria(const std::string& _titular, double _saldo) : titular(_titular), saldo(_saldo) {
        numContas++; // Incrementa o número total de contas ao criar uma nova conta
    }

    // Destrutor virtual
    virtual ~ContaBancaria() {
        numContas--; // Decrementa o número total de contas ao destruir uma conta
    }

    // Método virtual para depositar dinheiro na conta
    virtual void depositar(double valor) {
        saldo += valor;
    }

    // Método virtual para sacar dinheiro da conta
    virtual void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
            printf("Saque de %.2f realizado com sucesso.\n", valor);
        } else {
            printf("Saldo insuficiente para realizar o saque.\n");
        }
    }

    // Método virtual para exibir o saldo da conta
    virtual void exibirSaldo() const {
        printf("Saldo de %s: %.2f\n", titular.c_str(), saldo);
    }

    // Método virtual puro para calcular a taxa de juros
    virtual double calcularTaxaJuros() const = 0;
};

// Inicializando o atributo estático
int ContaBancaria::numContas = 0;

// Classe para Conta Corrente, derivada de ContaBancaria
class ContaCorrente : public ContaBancaria {
public:
    // Construtor
    ContaCorrente(const std::string& _titular, double _saldo) : ContaBancaria(_titular, _saldo) {}

    // Método para exibir o saldo da conta corrente
    void exibirSaldo() const override {
        printf("Saldo da Conta Corrente de %s: %.2f\n", titular.c_str(), saldo);
    }

    // Método para calcular a taxa de juros (não há taxa de juros para conta corrente)
    double calcularTaxaJuros() const override {
        return 0.0;
    }
};

// Classe para Conta Poupança, derivada de ContaBancaria
class ContaPoupanca : public ContaBancaria {
private:
    static double taxaJuros;

public:
    // Construtor
    ContaPoupanca(const std::string& _titular, double _saldo) : ContaBancaria(_titular, _saldo) {}

    // Método para exibir o saldo da conta poupança
    void exibirSaldo() const override {
        printf("Saldo da Conta Poupança de %s: %.2f\n", titular.c_str(), saldo);
    }

    // Método para calcular a taxa de juros
    double calcularTaxaJuros() const override {
        return saldo * taxaJuros;
    }

    // Método estático para definir a taxa de juros
    static void setTaxaJuros(double taxa) {
        taxaJuros = taxa;
    }
};

// Inicializando o atributo estático
double ContaPoupanca::taxaJuros = 0.05;

int main() {
    // Criando instâncias de Conta Corrente e Conta Poupança
    ContaCorrente cc("João", 1000.0);
    ContaPoupanca cp("Maria", 2000.0);

    // Realizando operações nas contas
    cc.depositar(500.0);
    cp.depositar(1000.0);

    cc.sacar(200.0);
    cp.sacar(500.0);

    // Exibindo o saldo e a taxa de juros das contas
    cc.exibirSaldo();
    cp.exibirSaldo();

    printf("Taxa de juros da Conta Poupança: %.2f\n", cp.calcularTaxaJuros());
    printf("Número total de contas bancárias: %d\n", ContaBancaria::numContas);

    return 0;
}

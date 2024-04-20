#include <iostream>

using namespace std;

// Abordagem 1: Valor alocado na memória (passagem por valor)
void valor_alocado_memoria(int* p) {
    p = new int;
    *p = 7;
    cout << "Dentro de função valor_alocado_memoria(int* p)- Endereço: " << p << ", Valor: " << *p << endl;

}

// Abordagem 2: Valor modificado na memória (passagem por valor)
void valor_modificandomemoria(int* p) {
    *p = 8;
    cout << "Dentro de função valor_modificandomemoria(int* p)- Endereço: " << p << ", Valor: " << *p << endl;

}

// Abordagem 3: Referência à memória (passagem por referência)
void referencia(int*& p) {
    p = new int;
    *p = 9;
    cout << "Dentro de função referencia(int*& p)- Endereço: " << p << ", Valor: " << *p << endl;

}

int main() {
    // Ponteiro para um inteiro
    int* ptr = new int;
    *ptr = 5;

    // Abordagem 1: Valor alocado na memória (passagem por valor)
    cout << "Abordagem 1: Valor alocado na memória (passagem por valor)" << endl;
    cout << "Antes de chamar função valor_alocado_memoria(int* p) - Endereço: " << ptr << ", Valor: " << *ptr << endl;
    valor_alocado_memoria(ptr);
    cout << "Depois de chamar função valor_alocado_memoria(int* p)- Endereço: " << ptr << ", Valor: " << *ptr << endl;
    cout << endl;

    // Abordagem 2: Valor modificado na memória (passagem por valor)
    cout << "Abordagem 2: Valor modificado na memória (passagem por valor)" << endl;
    cout << "Antes de chamar função valor_modificandomemoria(int* p) - Endereço: " << ptr << ", Valor: " << *ptr << endl;
    valor_modificandomemoria(ptr);
    cout << "Depois de chamar função valor_modificandomemoria(int* p)- Endereço: " << ptr << ", Valor: " << *ptr << endl;

    cout << endl;

    // Abordagem 3: Referência à memória (passagem por referência)
    cout << "Abordagem 3: Referência à memória (passagem por referência)" << endl;
    cout << "Antes de chamar função referencia(int*& p) - Endereço: " << ptr << ", Valor: " << *ptr << endl;
    referencia(ptr);
    cout << "Depois de chamar função referencia(int*& p)- Endereço: " << ptr << ", Valor: " << *ptr << endl;
    cout << endl;

    delete ptr; // Liberar a memória alocada

    return 0;
}

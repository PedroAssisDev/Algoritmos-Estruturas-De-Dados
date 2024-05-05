# Tabelas de Dispersão - Tabela Hash

## 1 – Introdução

As tabelas de dispersão são estruturas de dados fundamentais em ciência da computação, projetadas para armazenar e recuperar informações de forma eficiente. Elas são amplamente utilizadas em diversas aplicações, como bancos de dados, sistemas de gerenciamento de arquivos e compiladores.

## 2 – Princípio de Funcionamento

O princípio básico por trás das tabelas de dispersão é o uso de uma função de dispersão (hash function) que mapeia chaves para posições em uma tabela. Esta função calcula um índice com base na chave, permitindo acesso direto aos dados armazenados naquela posição. O objetivo é minimizar o tempo de busca, inserção e exclusão de elementos.

## 3 – Funções de Dispersão

As funções de dispersão são essenciais para o funcionamento eficiente das tabelas de dispersão. Existem diferentes métodos para implementar essas funções:

### 3.1 – Método da divisão

Neste método, o índice é calculado usando a operação de módulo (%). Seja `h(k) = k % m`, onde `k` é a chave e `m` é o tamanho da tabela hash.

Exemplo:
```python
def hash_divisao(key, size):
    return key % size

index = hash_divisao(42, 10)  # Exemplo de hashing com chave 42 e tamanho de tabela 10
print(index)  # Saída: 2
```

### 3.2 – Método da dobra
Neste método, a chave é dividida em partes e essas partes são somadas para gerar o índice.

Exemplo:
```python
def hash_dobra(key, size):
    key_str = str(key)
    sum_parts = sum(int(part) for part in key_str)
    return sum_parts % size

index = hash_dobra(123456, 10)  # Exemplo de hashing com chave 123456 e tamanho de tabela 10
print(index)  # Saída: 6
```

### 3.3 – Método da multiplicação
Neste método, a chave é multiplicada por um número real entre 0 e 1 e, em seguida, a parte fracionária é usada para calcular o índice.

Exemplo:
```python
def hash_multiplicacao(key, size):
    A = (5 ** 0.5 - 1) / 2  # Constante recomendada para distribuição uniforme
    return int(size * ((key * A) % 1))

index = hash_multiplicacao(98765, 10)  # Exemplo de hashing com chave 98765 e tamanho de tabela 10
print(index)  # Saída: 4
```

### 3.4 – Método da análise dos dígitos
Neste método, os dígitos da chave são somados para calcular o índice.

Exemplo:
```python
def hash_digitos(key, size):
    key_str = str(key)
    sum_digits = sum(int(digit) for digit in key_str)
    return sum_digits % size

index = hash_digitos(87654, 10)  # Exemplo de hashing com chave 87654 e tamanho de tabela 10
print(index)  # Saída: 7
```

## 4 – Tratamento de Colisões por Encadeamento

O tratamento de colisões é uma preocupação importante ao lidar com tabelas de dispersão, pois diferentes chaves podem ser mapeadas para o mesmo índice. O método de encadeamento é uma abordagem comum para lidar com colisões, e pode ser implementado de duas maneiras principais: encadeamento exterior e encadeamento interior.

### 4.1 – Encadeamento exterior

Neste método, cada entrada da tabela hash contém uma lista encadeada de elementos que têm o mesmo índice. Quando ocorre uma colisão, os elementos com chaves diferentes, mas que mapeiam para o mesmo índice, são armazenados em uma lista encadeada naquela posição da tabela.

#### Exemplo em C++:

```cpp
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class HashTable {
private:
    static const int tableSize = 10;
    Node* table[tableSize];

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << " --> ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(42);
    ht.insert(7);
    ht.insert(23);
    ht.insert(15);
    ht.display();
    return 0;
}
```
``` sql
+-------+    +-------+
| Index | -> |  Data |
+-------+    +-------+
|   0   | -> |  42   | -> NULL
+-------+    +-------+
|   1   | -> |  23   | -> NULL
+-------+    +-------+
|   2   | -> |  15   | -> NULL
+-------+    +-------+
|   3   | -> |   7   | -> NULL
+-------+    +-------+
...
```


### 4.2 – Encadeamento interior
No encadeamento interior, a própria tabela hash é uma estrutura de dados que permite várias entradas em cada posição. Cada posição da tabela contém uma lista encadeada na qual os elementos com chaves colididas são armazenados.

Exemplo em C++:

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class HashTable {
private:
    static const int tableSize = 10;
    Node* table[tableSize];

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << " --> ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(42);
    ht.insert(7);
    ht.insert(23);
    ht.insert(15);
    ht.display();
    return 0;
}

```
## 5 – Tratamento de Colisões por Endereçamento Aberto

O tratamento de colisões por endereçamento aberto é outra abordagem para lidar com colisões em tabelas de dispersão. Nesse método, quando uma colisão ocorre, a busca por um slot vazio (ou "aberto") é feita dentro da própria tabela, em vez de usar estruturas adicionais de dados, como listas encadeadas. Existem várias estratégias comuns para implementar o endereçamento aberto, incluindo tentativa linear, tentativa quadrática e dispersão dupla.

### 5.1 – Tentativa Linear

Na tentativa linear, quando ocorre uma colisão, a tabela de dispersão é percorrida sequencialmente até que um slot vazio seja encontrado.

### Exemplo em C++:

```cpp
#include <iostream>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    int table[tableSize];

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = -1; // -1 indica que a posição está vazia
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % tableSize] != -1) {
            i++;
        }
        table[(index + i) % tableSize] = key;
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << " --> " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(42);
    ht.insert(7);
    ht.insert(23);
    ht.insert(15);
    ht.display();
    return 0;
}
```
### 5.2 – Tentativa Quadrática

Na tentativa quadrática, quando ocorre uma colisão, são feitas tentativas em intervalos quadráticos para encontrar um slot vazio.

### Exemplo em C++:

(O exemplo em C++ para tentativa quadrática seria semelhante ao exemplo da tentativa linear, mas com o cálculo do próximo índice de maneira diferente.)

### 5.3 – Dispersão Dupla

Na dispersão dupla, é usada uma segunda função de hash para calcular o próximo índice quando ocorre uma colisão.

### Exemplo em C++:

(O exemplo em C++ para dispersão dupla seria semelhante aos exemplos anteriores, mas com uma segunda função de hash.)

## 6 – Tabela de Dimensão Dinâmica

Uma tabela de dimensão dinâmica é uma tabela de dispersão que pode aumentar ou diminuir dinamicamente de tamanho à medida que novos elementos são adicionados ou removidos. Isso é útil para evitar colisões excessivas e para otimizar o uso de memória.

### Exemplo em C++:

(O exemplo em C++ para uma tabela de dimensão dinâmica seria mais complexo e envolveria alocação dinâmica de memória e realocação da tabela conforme necessário.)



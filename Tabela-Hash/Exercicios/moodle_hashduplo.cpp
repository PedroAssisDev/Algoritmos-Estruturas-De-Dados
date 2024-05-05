#include <iostream>
#include <vector>

using namespace std;

// Função de hash h1
int hash_function(char c, int m) {
    if (c == 'A')
        c = 65;
    else if (c == 'C')
        c = 67;
    else if (c == 'E')
        c = 69;
    else if (c == 'H')
        c = 72;
    else if (c == 'L')
        c = 76;
    else if (c == 'O')
        c = 79;
    else if (c == 'T')
        c = 84;
    return (int)(c - 64) % m;
}

// Função h2
int hash_function2(char c) {
    return 8 - ((c - 64) % 8);
}

// Função para tratamento de colisões por hash duplo
int double_hash_probe(int index, int h2_value, int m) {
    return (index + h2_value) % m; // Próxima posição na tabela hash
}

int main() {
    // Tamanho da tabela hash
    const int m = 11;
    
    // Tabela hash inicialmente vazia
    vector<char> hash_table(m, '\0');
    
    // Chaves a serem inseridas na tabela hash
    string keys = "CHOCOLATE";

    // Inserindo chaves na tabela hash
    for (char key : keys) {
        int index = hash_function(key, m);
        int h2_value = hash_function2(key);
        while (hash_table[index] != '\0') {
            // Se houver colisão, use hash duplo
            cout << "Colisão detectada ao inserir elemento '" << key << "' na posição " << index << " da tabela hash. Procurando próxima posição..." << endl;
            index = double_hash_probe(index, h2_value, m);
        }
        hash_table[index] = key;
        cout << "Elemento '" << key << "' inserido na posição " << index << " da tabela hash." << endl;
    }
    
    // Imprimindo a tabela hash após inserção
    cout << "\nTabela Hash após inserção:" << endl;
    for (int i = 0; i < m; ++i) {
        if (hash_table[i] != '\0') {
            cout << "[" << i << "]: " << hash_table[i] << endl;
        } else {
            cout << "[" << i << "]: Vazio" << endl;
        }
    }
    
    return 0;
}

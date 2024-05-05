#include <iostream>
#include <cmath>

using namespace std;

struct No { 
    No *prox; 
    int x; 
};

struct HTable { 
    No **table;
    int capacidade;
    float fator_de_carga; 
    int cont;
};

void inserir(HTable& tabelaHash, int valor);
void imprime(HTable tabelaHash);

void inicializar(HTable& tabelaHash, int capacidade, float fator_de_carga) {
    tabelaHash.capacidade = capacidade;
    tabelaHash.table = new No*[tabelaHash.capacidade]; 
    for (int i = 0; i < tabelaHash.capacidade; ++i) {
        tabelaHash.table[i] = nullptr;
    }
    tabelaHash.fator_de_carga = fator_de_carga;
    tabelaHash.cont = 0; 
}

int h(HTable& tabelaHash, int k){
    return k % tabelaHash.capacidade;
}

void rehasing(HTable& tabelaHash){
    HTable tabelaHashNova;
    inicializar(tabelaHashNova, tabelaHash.capacidade*2, 0.5);
    for(int i = 0; i < tabelaHash.capacidade; i++){
        No *aux = tabelaHash.table[i];
        while (aux != nullptr)
        {
            inserir(tabelaHashNova, aux->x); 
            aux = aux->prox;
        }        
    }
    tabelaHash = tabelaHashNova;   
}

void inserir(HTable& tabelaHash, int valor){

    if ((float(tabelaHash.cont) / tabelaHash.capacidade) > tabelaHash.fator_de_carga){ 
        cout << "redimensionar: " << endl; 
        imprime(tabelaHash); 
        rehasing(tabelaHash); 
        cout << "redmencionada:" << endl;
    }
    int indice = h(tabelaHash, valor);
    No* novoValor = new No;
    novoValor->x = valor;
    novoValor->prox = tabelaHash.table[indice];
    tabelaHash.table[indice] = novoValor;
    tabelaHash.cont++;
}

void remover(HTable& tabelaHash, int valor) {
    int indice = h(tabelaHash, valor);
    No* atual = tabelaHash.table[indice];
    No* anterior = nullptr;

    // Procurando o valor na lista encadeada
    while (atual != nullptr && atual->x != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o valor não foi encontrado, não há nada para fazer
    if (atual == nullptr) {
        cout << "Valor não encontrado na tabela." << endl;
        return;
    }

    // Removendo o valor da lista encadeada
    if (anterior == nullptr) { // O valor está no início da lista
        tabelaHash.table[indice] = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual; // Liberando a memória do nó removido
    tabelaHash.cont--;
}

void destroiHash(HTable& tabelaHash){
    for(int i = 0; i < tabelaHash.capacidade; i++){
        No *aux = tabelaHash.table[i];
        while (aux != nullptr)
        {
            No *atual = aux;
            aux = aux->prox;
            delete atual;
        }
        tabelaHash.table[i] = nullptr;        
    }
}

int contaValor(HTable tabelaHash, int valor){ 
    int contador = 0;
    for(int i = 0; i < tabelaHash.capacidade; i++){
        No *aux = tabelaHash.table[i];
        while (aux != nullptr)
        {
            if (aux->x > valor){         
                contador++;                
            }
            aux = aux->prox;
        }
    }
    return contador;
}

void imprime(HTable tabelaHash){ 
    for(int i = 0; i < tabelaHash.capacidade; i++){
        No *aux = tabelaHash.table[i];
        cout << "Indice [" << i << "] --- ";
        while(aux != nullptr){
            cout << "[" << aux->x << "]->";
            aux = aux->prox;
        }
        cout << endl;
    }
    cout << "$ --- $" << endl;
}

int main(){
    HTable tabelaHash;
    inicializar(tabelaHash, 5, 0.9);
    inserir(tabelaHash, 0);
    inserir(tabelaHash, 2);
    inserir(tabelaHash, 5);
    inserir(tabelaHash, 7);
    inserir(tabelaHash, 10);
    inserir(tabelaHash, 12); 
    inserir(tabelaHash, 14);
    inserir(tabelaHash, 22);
    inserir(tabelaHash, 31);
    inserir(tabelaHash, 17);
    inserir(tabelaHash, 19);  
    inserir(tabelaHash, 18);
    inserir(tabelaHash, 29);   
    cout << "Existe " << contaValor(tabelaHash, 7) << " valores maior que 7." << endl;
    cout << "Existe " << contaValor(tabelaHash, 70) << " valores maior que 70." << endl;
    imprime(tabelaHash); 
    destroiHash(tabelaHash);
    imprime(tabelaHash); 
}

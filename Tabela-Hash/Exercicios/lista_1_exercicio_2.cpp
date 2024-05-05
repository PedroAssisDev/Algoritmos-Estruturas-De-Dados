#include <iostream>
#include <cmath>

using namespace std;

const int m = 5;

struct No { 
    No *prox; 
    int x; 
    };
struct HTable { 
    No *table[m]; 
    };
    
int h(int k){
    return k%m;
};

void inserir(HTable& tabelaHash, int valor){// O(1)
    int indice = h(valor);
    No* novoValor = new No;
    novoValor->x = valor;
    novoValor->prox = tabelaHash.table[indice];
    tabelaHash.table[indice] = novoValor;
}

void inserir_final(HTable& tabelaHash, int val){// O(n)
         int indice = h(val);
         No *novoValor = new No;
         novoValor->x = val;
         novoValor->prox = nullptr;
         if(tabelaHash.table[indice] == nullptr){
            tabelaHash.table[indice] = novoValor;
         }else{
           No *aux = tabelaHash.table[indice];
           while(aux->prox != nullptr){
            aux = aux->prox;
           }
           aux->prox = novoValor;
         }
    }

void remover(HTable& tabelaHash, int valor) {
    int indice = h(valor);
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
}

void destroiHash(HTable& tabelaHash){// O(n)
    for(int i = 0; i<m; i++){
        No *aux = tabelaHash.table[i];
        while (aux->prox != nullptr)
        {
            No *atual = aux;
            aux = aux->prox;
            delete atual;
        }
        tabelaHash.table[i] = nullptr;        
    }
}

int contaValor(HTable tabelaHash, int valor){// O(n)
    int contador = 0;
    for(int i = 0; i<m; i++){
        No *aux = tabelaHash.table[i];
        while (aux->prox != nullptr)
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

     for(int i=0; i<m; i++){
        No *aux = tabelaHash.table[i];
        cout<<"Indice ["<<i<<"] --- ";
        while(aux!=NULL){
            cout<<"["<<aux->x<<"]->";
            aux = aux->prox;
        }
        cout<<endl;
       }
       cout<<"$ --- $" << endl;
    }

int main(){
    HTable tabelaHash;
    for(int i=0; i<m;i++){
        tabelaHash.table[i] = nullptr;
    }
    inserir(tabelaHash, 0);
    inserir(tabelaHash, 2);
    inserir(tabelaHash, 5);
    inserir(tabelaHash, 7);
    inserir(tabelaHash, 10);
    inserir(tabelaHash, 12); 
    inserir(tabelaHash, 14);
    inserir(tabelaHash, 22);
    inserir(tabelaHash, 31);
    imprime(tabelaHash); 
    remover(tabelaHash, 31);
    remover(tabelaHash, 12);
    imprime(tabelaHash);
    inserir_final(tabelaHash, 17);
    inserir_final(tabelaHash, 19);  
    inserir_final(tabelaHash, 18);
    inserir_final(tabelaHash, 19);   
    imprime(tabelaHash); 
    cout<<"Existe "<< contaValor(tabelaHash, 7)<< " valores maior que 7." << endl;
    cout<<"Existe "<< contaValor(tabelaHash, 70)<< " valores maior que 70." << endl; 
    destroiHash(tabelaHash);
    imprime(tabelaHash); 
}
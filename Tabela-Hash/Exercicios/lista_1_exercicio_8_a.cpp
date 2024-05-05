#include <iostream>

using namespace std;
int tam = 5;


int* somaIgualX(int* vet, int x){
 int i = 0;
 int j = tam -1;
 int total = 0;
 while(i!=j){
    total = vet[i] + vet[j];
    if(total == x){
        int *resposta = new int[2];
        resposta[0] = vet[i];
        resposta[1] = vet[j];
        return resposta;
    }else{
    if(total > x){
        j = j-1;
    }else{
       i = i+1;
    }
    }
 }
 return nullptr;

}
int main()
{
    int *vet1 = new int[tam] {10, 20, 30, 40, 50}; 
    int *vet2 = new int[tam] {5, 15, 25, 35, 45};
    int x;

    cout<<"Digite o valor de x:"<<endl;
    cin>>x;

    cout<<"Os valores somados para a saida x são:"<<endl;
    int *resposta = somaIgualX(vet1,x);
    cout<<resposta[0]<<endl;
    cout<<resposta[1]<<endl;
    cout<<"Os valores somados para a saida x são:"<<endl;
    int *resposta2 = somaIgualX(vet2,x);
    cout<<resposta2[0]<<endl;
    cout<<resposta2[1]<<endl;

}
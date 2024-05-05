#include <iostream>

using namespace std;
#define tam 4


int* somaIgualX(int* vet, int x){
    int *vistos = new int[tam];
    int complemento;

    for(int i=0; i<tam; i++){
        complemento = x - vet[i];
        for(int j=0; j<4; j++){
            if(complemento == vistos[j]){
                int *resultado = new int[2];
                resultado[0] = complemento;
                resultado[1] = vet[i];
                return resultado;
            }
        }
        vistos[i] = vet[i];
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
    int *resposta = somaIgualX(vet2,x);
    cout<<resposta[0]<<endl;
    cout<<resposta[1]<<endl;

}
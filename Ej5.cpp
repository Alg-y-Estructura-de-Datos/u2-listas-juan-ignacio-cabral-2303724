//Crear un programa que pida al usuario dar elementos a una Lista de números enteros. Luego
//        cree una función que reciba una lista int L1 y devuelva otra lista int L2 conteniendo los
//elementos repetidos de L1. Por ejemplo, si L1 almacena los valores 5->2->7-> 2->5->5->1, debe
//        construirse una lista L2 con los valores 5->2. Si en L1 no hay elementos repetidos se debe
//        indicar al usuario que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.
#include <iostream>
#include "Lista/Lista.h"
Lista<int> listaRepetida(Lista<int>& l1);
int main(){
    Lista<int> L1;
    int n,d;
    std::cout<<"Ingrese el tamanio de la lista\n";
    std::cin>>n;
    for (int i = 0; i < n; i++) {
        std::cout<<"Ingrese el elemento de la lista en la posicion: "<<i<<"\n";
        std::cin>>d;
        L1.insertarUltimo(d);
    }
    Lista<int> L2 = listaRepetida(L1);
    if(L2.esVacia()){
        std::cout<<"No hay elementos repetidos\n";
    }else{
        L1.print();
        L2.print();
    }
}
Lista<int> listaRepetida(Lista<int>& l1){
    Lista<int> L2;
    for (int i = 0; i < l1.getTamanio(); ++i) {
        int valoractual = l1.getDato(i);
        int contadorRepetidos=0;
        for (int j = 0; j < l1.getTamanio(); ++j) {
            if(l1.getDato(j) == valoractual){
                contadorRepetidos++;
            }
        }
        if(contadorRepetidos>1){
            bool yaAgregado = false;
            for (int k = 0; k < L2.getTamanio(); ++k) {
                if(L2.getDato(k) == valoractual){
                    yaAgregado = true;
                    break;
                }
            }
            if(!yaAgregado){
                L2.insertarUltimo(valoractual);
            }
        }
    }
    return L2;
}
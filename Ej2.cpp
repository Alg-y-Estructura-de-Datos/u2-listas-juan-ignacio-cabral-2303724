/*Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe
pasar con la función a 1->2->4->5->7->8.*/
#include <iostream>
#include "Lista/Lista.h"
using namespace std;
void listaeliminandoelemento(Lista<int>& lista, int n);
int main() {

    cout << "Ejercicio N° 2" << endl;

    Lista<int> lista;
    int n,size,e;

    cout<<"Ingrese el tamanio de la lista\n";
    cin>>size;
    cout<<"Ingrese la lista\n";
    for (int i = 0; i < size; ++i) {
        cin>>e;
        lista.insertarUltimo(e);
    }
    cout<<"Ingrese el numero que quiere eliminar de la lista\n";
    cin>>n;
    cout<<"Lista sin remover "<<n<<endl;
    lista.print();
    cout<<"Lista con "<<n<<" eliminado\n";
    listaeliminandoelemento(lista,n);
    return 0;
}
void listaeliminandoelemento(Lista<int>& lista, int n){
    int size = lista.getTamanio();

    for (int i = 0; i < size; ++i) {
        if(lista.getDato(i) == n){
            lista.remover(i);
            size-=1;
            i--;
        }
    }
    lista.print();
}

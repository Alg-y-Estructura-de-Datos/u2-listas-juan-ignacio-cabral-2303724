/*Implementar una función que intercambie los elementos entre 2 listas de números enteros
que recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los
datos y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y
lista2= 3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y
lista2=15->1->8->35->40->25->12.
*/
#include <iostream>
#include "Lista/Lista.h"
using namespace std;
void intercambiarListas(Lista<int>& lista1,Lista<int>& lista2);
int main() {

    cout << "Ejercicio N° 3" << endl;
    Lista<int> lista1,lista2;
    int n,size1,size2,e;

    cout<<"Ingrese el tamanio de la lista 1\n";
    cin>>size1;
    cout<<"Ingrese la lista 1\n";
    for (int i = 0; i < size1; ++i) {
        cin>>e;
        lista1.insertarUltimo(e);
    }
    cout<<"Ingrese el tamanio de la lista 2\n";
    cin>>size2;
    cout<<"Ingrese la lista\n";
    for (int i = 0; i < size2; ++i) {
        cin>>e;
        lista2.insertarUltimo(e);
    }
    intercambiarListas(lista1,lista2);
cout<<"Listas intercambiadas:\n";
    cout<<"Lista 1 nueva:\n";
    lista1.print();
    cout<<"Lista 2 nueva\n";
    lista2.print();
    return 0;
}
void intercambiarListas(Lista<int>& lista1,Lista<int>& lista2){
    int size1 = lista1.getTamanio();
    int size2 = lista2.getTamanio();
    Lista<int> lista1m;
    Lista<int> lista2m;
    for (int i = 0; i < size1; ++i) {
        lista1m.insertarUltimo(lista1.getDato(i));
    }
    for (int i = 0; i < size2; ++i) {
        lista2m.insertarUltimo(lista2.getDato(i));
    }

    if(size1 == size2){
    for (int i = 0; i < size1; ++i) {
        lista2.reemplazar(i,lista1.getDato(i));
        lista1.reemplazar(i,lista2m.getDato(i));
    }
    }else{
    lista2.vaciar();
    lista1.vaciar();
    for (int i = 0; i < size1; ++i) {
        lista2.insertar(i,lista1m.getDato(i));
    }
    for (int i = 0; i < size2; ++i) {
        lista1.insertar(i,lista2m.getDato(i));
    }
}
}


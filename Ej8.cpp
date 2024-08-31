/*Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
circular simplemente enlazada.
Requisitos:
1. Frases de Anuncios:
○ Cada frase de anuncio será un texto simple que el monitor debe mostrar por
vez.
2. Mostrar Circularmente:
○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
mostrado la última frase, el monitor debe volver a mostrar la primera y así
infinitamente.
3. Implementación:
○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
y la visualización de las frases. La lista circular debe permitir el recorrido
continuo de los elementos.
4. Operaciones Básicas:
○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
○ Mostrar Frases: Implementa una función para mostrar las frases en el monitor
de manera continua, recorriendo circularmente la lista e infinitamente*/

#include <iostream>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

void mostrarFrases(CircList<std::string>& lista){
    if(lista.esVacia()){
        std::cout<<"La lista esta vacia, no se puede mostrar nada en el monitor\n";
        return;
    }
    int pos=0;
        do{
            std::cout << lista.getDato(pos) <<"\n";
            pos = (pos + 1) % lista.getTamanio();
            std::this_thread::sleep_for(std::chrono::seconds(3));

    }while(pos>=0);
}
int main() {
    CircList<std::string> lista;

    // Agregar frases a la lista
    lista.insertarUltimo("Gran venta de fin de temporada!");
    lista.insertarUltimo("50% de descuento en toda la tienda.");
    lista.insertarUltimo("Compra uno y llevate el segundo a mitad de precio.");
    lista.insertarUltimo("Visitanos hoy y obten un regalo sorpresa.");

    std::cout << "Mostrando frases de anuncios en el monitor:" << std::endl;

    // Mostrar las frases en el monitor de manera circular
    mostrarFrases(lista);

    return 0;
}
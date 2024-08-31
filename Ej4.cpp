//Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
//separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
//debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
//frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea
//una vocal.
#include <iostream>
#include "Lista/Lista.h"
#include <cctype>
bool esVocal(char c);
int contadorVocales(Lista<char> cadena, char c);

int main(){
    Lista<char> chain;
    char v;
    std::string palabra;
    std::cout<<"Ingrese una palabra o frase\n";
    getline(std::cin,palabra);

    for (int i = 0; i < palabra.length(); ++i) {
        chain.insertarUltimo(palabra[i]);
    }
    if (chain.esVacia()) {
        std::cout << "La lista está vacía. No hay nada que contar.\n";
        return 0;
    }
    std::cout<<"Ingrese la vocal que quiere contar\n";
    std::cin>>v;

    if (!esVocal(v)) {
        std::cout << "El carácter ingresado no es una vocal.\n";
        return 0;
    }
    if (esVocal(v)) {
        std::cout << "Lista:";
        chain.print();
        int cant = contadorVocales(chain, v);
        std::cout << "La vocal " << v << " se encuentra " << cant << " veces en la palabra/frase\n";
        return 0;
    }
}
bool esVocal(char c){
    char minuscula = tolower(c);
    if(minuscula == 'a' || minuscula == 'e' || minuscula == 'i' || minuscula == 'o' || minuscula == 'u')
    {
        return true;
    }
    return false;
}

int contadorVocales(Lista<char> cadena, char c){
int cont = 0;
    for (int i = 0; i < cadena.getTamanio(); ++i) {
        if(tolower(cadena.getDato(i)) == tolower(c)){
            cont++;
        }
    }
    return cont;
}
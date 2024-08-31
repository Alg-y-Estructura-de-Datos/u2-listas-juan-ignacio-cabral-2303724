/*Utiliza la clase ListaDoble para gestionar una lista de estudiantes, donde cada estudiante
tiene un nombre (cadena de caracteres) y una edad (entero). Implementa las siguientes
funcionalidades:
1. Agregar Estudiantes:
○ Usa los métodos de ListaDoble para agregar varios estudiantes a la lista.
Debes insertar al menos cinco estudiantes con nombres y edades diferentes.
2. Mostrar Estudiantes:
○ Implementa una función que recorra la lista y muestre todos los estudiantes en
orden. Utiliza el método imprimir() de ListaDoble.
3. Buscar un Estudiante por Nombre:
○ Implementa una función que busque un estudiante por su nombre. Utiliza el
método getDato(int pos) para acceder a los datos de los nodos y busca al
estudiante en la lista.
4. Eliminar un Estudiante por Nombre:
○ Implementa una función que elimine un estudiante por su nombre. Utiliza los
métodos getDato(int pos) y remover(int pos) para encontrar y
eliminar al estudiante de la lista.
5. Contar Estudiantes:
○ Usa el método getTamanio() para contar el número de estudiantes en la lista
y muestra el resultado*/
#include <iostream>
#include "Lista/ListaDoble.h"
#include <string>
class Estudiante{
private:
    std::string nombre_m;
    int edad_m;
public:
    Estudiante()
    :nombre_m{""}
    ,edad_m{}
    {

    }
    Estudiante(std::string nombre, int edad)
    :nombre_m{nombre}
    ,edad_m{edad}
    {

    }
    std::string getNombre() const
    {
        return nombre_m;
    }
    int getEdad() const
    {
        return edad_m;
    }

};
std::ostream& operator<<(std::ostream &os, const Estudiante &estudiante) {
    os << "Nombre: " << estudiante.getNombre() << ", Telefono: " << estudiante.getEdad()<<"\n";
    return os;
}

void mostrarEstudiantes(ListaDoble<Estudiante>& listaEstudiantes)
{
    if(listaEstudiantes.esVacia()){
        std::cout<<"La lista esta vacia\n";
        return;
    }
    std::cout<<"Lista de estudiantes: \n";
    listaEstudiantes.imprimir();
}
Estudiante* buscarNombre(ListaDoble<Estudiante>& listaEstudiantes, std::string& nombre){
    for (int i = 0; i < listaEstudiantes.getTamanio(); ++i) {
        if(listaEstudiantes.getDato(i).getNombre() == nombre) {
            return new Estudiante(listaEstudiantes.getDato(i));
        }
    }
    return nullptr;
}

void eliminarEstudiante(ListaDoble<Estudiante>& listaEstudiantes, std::string& nombre){
    for (int i = 0; i < listaEstudiantes.getTamanio(); ++i) {
        if(listaEstudiantes.getDato(i).getNombre() == nombre){
            listaEstudiantes.remover(i);
            return;
        }
    }
        std::cout<<"El estudiante no esta en la lista\n";
}
int cantidadEstudiantes(ListaDoble<Estudiante>& lista){
    int resp = lista.getTamanio();
    return resp;
}
int main(){
    ListaDoble<Estudiante> lista;
    int opcion,edad;
    std::string nombre;
    do {

        std::cout << "\n1- Agregar estudiante\n";
        std::cout << "2- Mostrar lista de Estudiantes\n";
        std::cout << "3- Buscar estudiante en la lista por su nombre\n";
        std::cout << "4- Eliminar studiante de la lista por su nombre\n";
        std::cout << "5- Cantidad de Estudiantes en la lista\n";
        std::cout << "0- Cerrar programa\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese nombre del estudiante: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del estudiante: ";
                std::cin >> edad;
                lista.insertarUltimo(Estudiante{nombre, edad});
                break;
            case 2:
                mostrarEstudiantes(lista);
                break;
            case 3:
                std::cout << "Ingrese el nombre que quiere buscar en la lista: ";
                std::cin >> nombre;
                std::cout<<buscarNombre(lista, nombre);
                break;
            case 4:
                std::cout << "Ingrese el nombre del estudiante que quiere eliminar de la lista: ";
                std::cin >> nombre;
                eliminarEstudiante(lista, nombre);
                break;
            case 5:
                std::cout << "Cantidad de estudiantes en la lista: " << cantidadEstudiantes(lista) << "\n";
                break;
            case 0:
                std::cout << "Cerrando programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Inténtelo de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}





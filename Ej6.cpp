/*Crea un programa que gestione una lista circular de contactos. Cada contacto contiene un
nombre (cadena de caracteres) y un número de teléfono (cadena de caracteres).
Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.
2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.
3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.
4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).
5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado.
*/
#include <iostream>
#include "Lista/CircList.h"
#include <string>
class Contacto{
private:
    std::string nombre_m;
    std::string telefono_m;
public:

    Contacto()
            : nombre_m{""}
            , telefono_m{""}
    {

    }
    Contacto(std::string nombre, std::string telefono)
            : nombre_m{nombre}
            ,telefono_m{telefono}
    {

    }
    bool operator==(const Contacto& otro) const {
        return (nombre_m == otro.nombre_m && telefono_m == otro.telefono_m);
    }
    std::string getNombre() const
    {
        return nombre_m;
    }
    std::string getTelefono() const
    {
        return telefono_m;
    }

};
std::ostream& operator<<(std::ostream &os, const Contacto &contacto) {
    os << "Nombre: " << contacto.getNombre() << ", Telefono: " << contacto.getTelefono()<<"\n";
    return os;
}

void MostrarContactos(CircList<Contacto>& listaContactos)
{
    if(listaContactos.esVacia()){
        std::cout<<"La lista de contactos esta vacia\n";
        return;
    }
    std::cout<<"Lista de contactos: \n";
    listaContactos.imprimir();
}
void BuscarPorNombre(CircList<Contacto>& lista, std::string& nombre)
{
    for (int i = 0; i < lista.getTamanio(); ++i) {
        if(lista.getDato(i).getNombre() == nombre){
            std::cout<<"El nombre ingresado si se encuentra en la lista de contactos \n";
            std::cout<<"\n";
            return;
        }
    }
    std::cout<<"El nombre ingresado no esta en la lista de contactos\n";
}
void eliminarContacto(CircList<Contacto>& lista, std::string& nombre) {
    for (int i = 0; i < lista.getTamanio(); ++i) {
        if (lista.getDato(i).getNombre() == nombre) {
            lista.eliminarPorValor(lista.getDato(i));
            std::cout<<"Lista despues de eliminar el contacto\n";
            lista.imprimir();
            return;
        }
    }
    std::cout<<"El contacto ingresado no se encuentra en la lista\n";
}

int main(){
    CircList<Contacto> lista;
    int opcion;
    std::string nombre,telefono;
    do {

        std::cout << "\n1- Agregar Contacto\n";
        std::cout << "2- Mostrar lista de contactos\n";
        std::cout << "3- Buscar contacto en la lista por su nombre\n";
        std::cout << "4- Eliminar contacto de la lista por su nombre\n";
        std::cout << "5- Cantidad de contactos en la lista\n";
        std::cout << "0- Cerrar programa\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese nombre del contacto: ";
                std::cin >> nombre;
                std::cout << "Ingrese teléfono del contacto: ";
                std::cin >> telefono;
                lista.insertarUltimo(Contacto{nombre, telefono});
                break;
            case 2:
                MostrarContactos(lista);
                break;
            case 3:
                std::cout << "Ingrese el nombre que quiere buscar en la lista: ";
                std::cin >> nombre;
                BuscarPorNombre(lista, nombre);
                break;
            case 4:
                std::cout << "Ingrese el nombre del contacto que quiere eliminar de la lista: ";
                std::cin >> nombre;
                eliminarContacto(lista, nombre);
                break;
            case 5:
                std::cout << "Cantidad de contactos en la lista: " << lista.getTamanio() << "\n";
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



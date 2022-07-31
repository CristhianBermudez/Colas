/**
 * & Programa de colas
 */
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * & Creamos la estructura del nodo
 * & Int nodo -> es el tipo de dato a guardar
 * & Nodo *siguiente -> es el espacio en memoria donde apunta el nodo
 */
struct Nodo {
    int dato;
    Nodo *siguiente;
};

/**
 * & Estructura para guardar la opción del menu
 */
struct Opcion {
    string opcion;
};

/**
 * & Prototipo de la función Menu
 * & Nos muestra un menu de opciones a elegir
 * & no retorna algún dato
 */
void Menu();

/**
 * & Prototipo de la función para insertar elementos a una cola
 * @param frente -> Nodo que apunta al inicio
 * @param fin -> Nodo que apunta al final
 * @param n -> Dato a insertar
 */
void insertarCola(Nodo *&frente, Nodo *&fin, int dato);

/**
 * & Prototipo para eliminar el primer elemento ingresado de la cola
 * @param frente -> Inicio de la cola
 * @param fin -> Fin de la cola
 * @param dato -> Dato a eliminar
 */
void eliminarCola(Nodo *&frente, Nodo *&fin, int &dato);

/**
 * & Prototipo de la función para mostrar los datos de la cola
 * @param frente -> Cola que se desea mostrar
 */
void mostarDatos(Nodo *frente);

/**
 * & Prototipo de la función para determinar si la cola esta vacía
 * @param frente -> Cola que recibimos  para verificar
 * @return -> si la lista es igual a NULL retornamos un true de lo contrario retornamos un false
 */
bool colaVacia(Nodo *frente);

int main() {
    //&Creamos dos punteros frente y fin
    Nodo *frente = nullptr;  // & Nodo frente igualado a NULL
    Nodo *fin = nullptr;     // & Nodo fin igualado a NULL

    int dato; //& Dato que deseamos guardar
    Opcion opcion1[1];//& Creamos la estructura de la opción con un tamaño de 1
    int salir = 1; //& Valor predeterminado para salir
    char op[1000];//& Opción tiene un tamaño de 1000 caracteres

    //& Ciclo que termina hasta (salir == 0) que el usuario quiera
    do {
        //& Función de Menu (Muestra un menu de opciones)
        Menu();
        cin.getline(op, 1000, '\n'); //& Leemos la opción ingresada
        opcion1[0].opcion = op; //& Guardamos la opción en la estructura (opcion[1].opcion)
        if (opcion1[0].opcion == "1") { //& si la opción ingresada es 1 vamos a ingresar datos a la cola
            int exit = 1;//& Valor predeterminado para salir del ciclo
            string opc; //& Valor a ingresar
            cout << "Opción uno" << endl; //& Mensaje que muestra la opción seleccionada
            //&Ciclo que termina hasta (exit ==0) cuando el usuario ingrese una opción válida
            do {
                cout << "Ingresa el dato a guardar en la cola" << endl;//&Mensaje para que el usuario ingrese un valor
                cout << "del siguiente rango (2147483647 y -2147483647)"
                     << endl; //&Mensaje al usuario de valores permitidos
                getline(cin, opc);//& Leemos el string o flujo de entrada (getline(cin, opc)
                if (istringstream(opc)
                        >> dato) {//& Convertimos el string en un dato de tipo entero omitiendo los caracteres
                    /**
                     * & Comparamos el tamaño del string ingresado
                     * & y el del dato que acabamos de convertir
                     */
                    if (opc.size() == to_string(dato).size()) {//& si los tamaños son iguales insertamos en la cola
                        insertarCola(frente, fin, dato);//& Función para insertar en la cola
                        exit = 0;//& Exit = 0 para salir del ciclo
                    } else {//& Si los tamaños son distintos Mostramos un mensaje Para que el usuario ingrese un dato válido
                        cout << "Ingresa un Numero valido c:" << endl;
                    }
                } else {//& Si no se logra convertir el string a entero Mostramos un mensaje Para que el usuario ingrese un dato valido
                    cout << "Ingresa un Numero valido c:" << endl;
                }
            } while (exit == 1);//& exit == 1 el cicLo se repite, si exit ==0 el ciclo termina

        } else if (opcion1[0].opcion =="2") {//& Si la opción ingresada es 2 vamos a eliminar el primer dato ingresado en la cola
            cout << "Eliminando el primer dato ingresado a la cola..."
                 << endl;//& Mensaje que muestra la opción seleccionada
            eliminarCola(frente, fin, dato);//& Función para eliminar el primer dato agregado a la cola
        } else if (opcion1[0].opcion == "3") { //& Si la opción ingresada es 3 vamos a mostrar los datos de la cola
            //& del primero al ultimo (primer dato agregado -> ultimo dato agregado)
            cout << "Mostrar cola" << endl; //& Mensaje que muestra la opción seleccionada
            mostarDatos(frente);//& Función que muestra la cola
        } else if (opcion1[0].opcion == "9") {//& Si la opción ingresada es 9 vamos a salir del programa sin guardar datos en memoria
            salir = 0;//& salir =0 para salir del ciclo
            cout << "Gracias por usar c:" << endl;//& Mensaje de agradecimiento por usar
        } else {//& Si no existe la opción seleccionada Mostrar mensaje de Opción inválida y pedir al usuario que
            //& ingrese otra opción
            cout << "Ingresa una opción valida c:" << endl;
        }
    } while (salir == 1);//& Salir == 1 el ciclo se repite, si Salir == 0 el ciclo termina

    return 0;
}

/**
 * &Función Que muestra un menu de opciones
 */
void Menu() {
    cout << "Menu\n" << endl;
    cout << "Elige la opción correspondiente" << endl;
    cout << "1) Agregar elementos" << endl;
    cout << "2) Eliminar elementos" << endl;
    cout << "3) Mostrar elementos" << endl;
    cout << "9) Salir" << endl;
}

/**
 * & Funcion para insertar elementos a una cola
 * @param frente -> Nodo que apunta(*) al inicio y con referencia(&)
 * @param fin -> Nodo que apunta(*) al final y con referencia (&)
 * @param n -> Dato a insertar
 */
void insertarCola(Nodo *&frente, Nodo *&fin, int dato) {
    //& Creamos un espacio en memoria para almacenar el nodo
    Nodo *nuevoNodo = new Nodo(); //& Creamos un nuevo nodo y le asignamos un espacio en memoria

    //& Le asignamos el dato que deseamos insertar y que apunte a NULL
    nuevoNodo->dato = dato; //& Le asignamos al nuevo nodo el dato que deseamos insertar
    nuevoNodo->siguiente = nullptr;//& Hacemos que el nodo apunte a NULL
    /**
     * & Verificamos si el nodo esta vacío si lo esta igualamos el nodo frente y el nodo fin al nuevo nodo
     * & De lo contrario solo fin apuntara a nuevo nodo
     */
    if (colaVacia(frente))
        frente = nuevoNodo; //& Cola vacía entonces frente es igual al nuevo nodo
    else
        fin->siguiente = nuevoNodo; //& hay mas de un nodo, entonces fin apunta al nuevo nodo (Ultimo nodo de la lista)

    fin = nuevoNodo; //& Fin se iguala al nuevo nodo por que siempre apunta al ultimo nodo

    cout << "Elemento insertado a cola de manera exitosa -> " << dato << endl; //& Mensaje de elemento insertado
}

/**
 * & Función para determinar si la cola esta vacía
 * @param frente -> Cola que recibimos  para verificar
 * @return -> si la lista es igual a NULL retornamos un true de lo contrario retornamos un false
 */
bool colaVacia(Nodo *frente) {
    return (frente == nullptr); //& Si la lista es igual a NULL retornamos un true de lo contrario retornamos un false
}

/**
 * & Funcion que elimina el primer dato ingresado
 * @param frente -> Nodo que apunta(*) al inicio y con referencia(&)
 * @param fin -> Nodo que apunta(*) al final y con referencia (&)
 * @param dato -> Dato a eliminar con referencia (&)
 */
void eliminarCola(Nodo *&frente, Nodo *&fin, int &dato) {
    if (frente != nullptr) { //& Verificamos que la cola tenga datos
        dato = frente->dato; //& Obtenemos el valor del nodo donde (dato = frente -> dato)
        Nodo *Aux = frente; //&Creamos el nodo auxiliar y le asignamos el frente (Nodo *Aux = frente) ("Frente es el valor a eliminar")
        //& Eliminamos el nodo frente de la cola
        if (frente == fin) { //& Si hay un solo nodo en la cola frente y fin serán igual a NULL
            frente = nullptr;//& frente = NULL
            fin = nullptr; //& fin = NULL
        } else {//& Si hay más de un nodo frente apuntara al siguiente nodo
            frente = frente->siguiente; //& frente = frente->siguiente;
        }
        delete Aux; //&Borramos la variale auxiliar (delete Aux)
    } else {//& Si la cola no tiene datos mandamos un mensaje para que el usuario agregue datos
        cout << "Lista vacía, agregue datos en la opción 1";
    }
    cout << endl;
}

void mostarDatos(Nodo *frente) {
    if (frente != nullptr) {
        Nodo *actual;
        actual = frente;
        while (actual != nullptr) {
            cout << actual->dato << "->";
            actual = actual->siguiente;
        }
    } else {
        cout << "Lista vacía, agregue datos en la opción 1";
    }
    cout << endl;
}
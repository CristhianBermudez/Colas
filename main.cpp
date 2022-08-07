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
 *& Prototipo para eliminar el ultimo dato de la cola
 * @param lista
 */
void eliminarUltimoDato(Nodo *&lista);

/**
 * & Prototipo de la función Menu2
 * & Nos muestra un menu de opciones a elegir
 * & no retorna algún dato
 */
void Menu2();

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
void eliminarCola(Nodo *&frente);

/**
 * & Prototipo de la función para mostrar los datos de la cola
 * @param frente -> Cola que se desea mostrar
 */
void mostarDatos(Nodo *frente);

/**
 * & Prototipo para eliminar ceros de mas ejemplo "004 y 00005"
 * @param dato -dato a eliminar los ceros
 * @return -> retorna numeros sin ceros enfrente
 */
string EliminarCeros(string dato);

/**
 * & Prototipo de la función para determinar si la cola esta vacía
 * @param frente -> Cola que recibimos  para verificar
 * @return -> si la lista es igual a NULL retornamos un true de lo contrario retornamos un false
 */
bool colaVacia(Nodo *frente);
/**
 * & Prototipo para dar un espaciado
 * @param n -> Numero de espacios
 */
void espacio(int n);

int main() {
    setlocale(LC_ALL, "Spanish");
    //&Creamos dos punteros para el nodo 1 (frente y fin)
    Nodo *frente = nullptr;  // & Nodo frente igualado a NULL
    Nodo *fin = nullptr;     // & Nodo fin igualado a NULL
    //&Creamos dos punteros para el nodo 2 (frente y fin)
    Nodo *frente2 = nullptr;  // & Nodo frente igualado a NULL
    Nodo *fin2 = nullptr;     // & Nodo fin igualado a NULL
    //&Creamos dos punteros para el nodo 3 (frente y fin)
    Nodo *frente3 = nullptr;  // & Nodo frente igualado a NULL
    Nodo *fin3 = nullptr;     // & Nodo fin igualado a NULL

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
            espacio(2);
            cout << "Opción uno" << endl; //& Mensaje que muestra la opción seleccionada
            //&Ciclo que termina hasta (exit ==0) cuando el usuario ingrese una opción válida
            do {
                cout << "Ingresa el dato a guardar en la cola" << endl;//&Mensaje para que el usuario ingrese un valor
                cout << "del siguiente rango (2147483647 y -2147483647)\nSin espacios"
                     << endl; //&Mensaje al usuario de valores permitidos
                getline(cin, opc);//& Leemos el string o flujo de entrada (getline(cin, opc)
                opc = EliminarCeros(opc);
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
                    cout << "Ingresa un Numero valido y sin espacios c:" << endl;
                }
            } while (exit == 1);//& exit == 1 el cicLo se repite, si exit ==0 el ciclo termina

        } else if (opcion1[0].opcion == "2") { //& si la opción ingresada es 2 vamos a ingresar datos a la cola
            int exit = 1;//& Valor predeterminado para salir del ciclo
            string opc; //& Valor a ingresar
            espacio(2);
            cout << "Opción dos" << endl; //& Mensaje que muestra la opción seleccionada
            //&Ciclo que termina hasta (exit ==0) cuando el usuario ingrese una opción válida
            do {
                cout << "Ingresa el dato a guardar en la cola" << endl;//&Mensaje para que el usuario ingrese un valor
                cout << "del siguiente rango (2147483647 y -2147483647)"
                     << endl; //&Mensaje al usuario de valores permitidos
                getline(cin, opc);//& Leemos el string o flujo de entrada (getline(cin, opc)
                opc = EliminarCeros(opc);
                if (istringstream(opc)
                        >> dato) {//& Convertimos el string en un dato de tipo entero omitiendo los caracteres
                    /**
                     * & Comparamos el tamaño del string ingresado
                     * & y el del dato que acabamos de convertir
                     */
                    if (opc.size() == to_string(dato).size()) {//& si los tamaños son iguales insertamos en la cola
                        insertarCola(frente2, fin2, dato);//& Función para insertar en la cola
                        exit = 0;//& Exit = 0 para salir del ciclo
                    } else {//& Si los tamaños son distintos Mostramos un mensaje Para que el usuario ingrese un dato válido
                        cout << "Ingresa un Numero valido c:" << endl;
                    }
                } else {//& Si no se logra convertir el string a entero Mostramos un mensaje Para que el usuario ingrese un dato valido
                    cout << "Ingresa un Numero valido c:" << endl;
                }
            } while (exit == 1);//& exit == 1 el cicLo se repite, si exit ==0 el ciclo termina

        } else if (opcion1[0].opcion == "3") { //& si la opción ingresada es 3 vamos a ingresar datos a la cola
            int exit = 1;//& Valor predeterminado para salir del ciclo
            string opc; //& Valor a ingresar
            espacio(2);
            cout << "Opción tres" << endl; //& Mensaje que muestra la opción seleccionada
            //&Ciclo que termina hasta (exit ==0) cuando el usuario ingrese una opción válida
            do {
                cout << "Ingresa el dato a guardar en la cola" << endl;//&Mensaje para que el usuario ingrese un valor
                cout << "del siguiente rango (2147483647 y -2147483647)"
                     << endl; //&Mensaje al usuario de valores permitidos
                getline(cin, opc);//& Leemos el string o flujo de entrada (getline(cin, opc)
                opc = EliminarCeros(opc);
                if (istringstream(opc)
                        >> dato) {//& Convertimos el string en un dato de tipo entero omitiendo los caracteres
                    /**
                     * & Comparamos el tamaño del string ingresado
                     * & y el del dato que acabamos de convertir
                     */
                    if (opc.size() == to_string(dato).size()) {//& si los tamaños son iguales insertamos en la cola
                        insertarCola(frente3, fin3, dato);//& Función para insertar en la cola
                        exit = 0;//& Exit = 0 para salir del ciclo
                    } else {//& Si los tamaños son distintos Mostramos un mensaje Para que el usuario ingrese un dato válido
                        cout << "Ingresa un Numero valido c:" << endl;
                    }
                } else {//& Si no se logra convertir el string a entero Mostramos un mensaje Para que el usuario ingrese un dato valido
                    cout << "Ingresa un Numero valido c:" << endl;
                }
            } while (exit == 1);//& exit == 1 el cicLo se repite, si exit ==0 el ciclo termina

        } else if (opcion1[0].opcion ==
                   "4") {//& Si la opción ingresada es 4 vamos a eliminar el primer dato ingresado en la cola
            int exit = 1;//& Valor predeterminado para salir del ciclo
            do {
                espacio(2);
                Menu2();
                cin.getline(op, 1000, '\n'); //& Leemos la opción ingresada
                opcion1[0].opcion = op; //& Guardamos la opción en la estructura (opcion[1].opcion)
                if (opcion1[0].opcion == "1") {
                    cout << "Eliminando el primer dato ingresado a la cola..."
                         << endl;//& Mensaje que muestra la opción seleccionada
                    eliminarCola(frente);//& Función para eliminar el primer dato agregado a la cola
                    exit = 0;
                } else if (opcion1[0].opcion == "2") {
                    cout << "Eliminando el primer dato ingresado a la cola..."
                         << endl;//& Mensaje que muestra la opción seleccionadaA
                    eliminarCola(frente2);//& Función para eliminar el primer dato agregado a la cola
                    exit = 0;
                } else if (opcion1[0].opcion == "3") {
                    cout << "Eliminando el primer dato ingresado a la cola..."
                         << endl;//& Mensaje que muestra la opción seleccionada
                    eliminarCola(frente3);//& Función para eliminar el primer dato agregado a la cola
                    exit = 0;
                } else {
                    espacio(2);
                    cout << "Ingresa una opción valida c:" << endl;
                }
            } while (exit == 1);
        } else if (opcion1[0].opcion == "5") { //& Si la opción ingresada es 5 vamos a mostrar los datos de la cola
            espacio(2);
            //& del primero al ultimo (primer dato agregado -> ultimo dato agregado)
            cout << "Mostrar cola1" << endl; //& Mensaje que muestra la opción seleccionada
            mostarDatos(frente);//& Función que muestra la cola
            cout << "Mostrar cola2" << endl; //& Mensaje que muestra la opción seleccionada
            mostarDatos(frente2);//& Función que muestra la cola
            cout << "Mostrar cola3" << endl; //& Mensaje que muestra la opción seleccionada
            mostarDatos(frente3);//& Función que muestra la cola
        } else if (opcion1[0].opcion ==
                   "9") {//& Si la opción ingresada es 9 vamos a salir del programa sin guardar datos en memoria
            salir = 0;//& salir =0 para salir del ciclo
            cout << "Gracias por usar c:" << endl;//& Mensaje de agradecimiento por usar
        } else {//& Si no existe la opción seleccionada Mostrar mensaje de Opción inválida y pedir al usuario que
            //& ingrese otra opción
            espacio(2);
            cout << "Ingresa una opción valida c:" << endl;
        }
    } while (salir == 1);//& Salir == 1 el ciclo se repite, si Salir == 0 el ciclo termina

    return 0;
}

void espacio(int n) {
    for (int i = 0; i < n; i++) {//& Ciclo que se recorre hasta el numero de espacios recibidos
        cout << endl;//& Salto de linea
    }
}

string EliminarCeros(string dato) {
    string tem, opcion, opcion2;
    int contador = 0;
    int primd;
    for (int i = 0; i < dato.size(); i++) {//& Recorremos el tamaño del dato
        if (contador >= 1 & dato[i] != 48) {//& Si el contador es mayor o igual a 1 y dato[i] es distinto a un 0
            for (int j = i; j < dato.size(); j++) {//& Recorremos desde i todo el dato donde j es igual a i
                opcion += dato[j];//& Guardamos todos los datos en la variable opcion
            }
            break;//& Salimos del ciclo
        } else if (dato[i] == 48) {//& si dato es igual a 0
            if (contador == 0) {//& si el contador es igual a 0
                opcion = dato[i];//& opcion sea igual al dato
                primd = 0;//& el primed sera 0
            }
        } else {//& de lo contrario
            if (contador == 0) {//& si el contador es igual a 0
                primd = 1; //& primed sera igual a 1
                opcion = dato;//& opcion sera igual al dato
                break;//Salimos del ciclo
            } else {//& si no se cumple contador igual a o
                opcion += dato[i];//& A la opcion le sumamos el siguiente caracter
            }
        }
        contador++;//& Le sumamos uno al contador
    }
    if (opcion.size() >= 2 && primd == 0) {//& verificamos si el tamaño resultante de la opcion es igual o mayor a 2
                                           //& y si primd es igual a 0
        for (int i = 0; i < opcion.size(); i++) {//& Recorremos toda la opcion
            if (i >= 1) {//& si i es igual o mayor a 1
                opcion2 += opcion[i];//& le sumamos a la opcion 2 el caracter correspondiente
            }
        }
        tem = opcion2;//& tem sera igual a opcion2
    } else {//& si no se cumplen las condiciones
        tem = opcion;//& tem sera igual a la opcion
    }
    return tem; //&  retornamos tem "String sin ceros enfrente"
}

/**
 * &Función Que muestra un menu de opciones
 */
void Menu() {
    cout << "Menu\n" << endl;
    cout << "Elige la opción correspondiente" << endl;
    cout << "1) Agregar elementos cola 1" << endl;
    cout << "2) Agregar elementos cola 2" << endl;
    cout << "3) Agregar elementos cola 3" << endl;
    cout << "4) Eliminar elementos" << endl;
    cout << "5) Mostrar elementos" << endl;
    cout << "9) Salir" << endl;
}

void Menu2() {
    cout << "Menu Eliminar\n" << endl;
    cout << "Elige la opción correspondiente" << endl;
    cout << "1) Eliminar elemento cola 1" << endl;
    cout << "2) Eliminar elemento cola 2" << endl;
    cout << "3) Eliminar elemento cola 3" << endl;
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
    espacio(5);
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
 */
void eliminarCola(Nodo *&frente) {
    if (frente != nullptr) {//& si la cola existe
        Nodo *auxActual;// & Creamos un nodo
        Nodo *auxAnterior = nullptr;//& Creamos otro nodo que sera igual a NULL
        Nodo *auxSiguiente;//& Creamos otro nodo
        auxActual = frente;//& igualamos el nodo actual al nodo recibido
        auxSiguiente = auxActual;//& igualamos el nodo siguiente al nodo actual
        int contador = 0;//& Contador = 0
        while (auxSiguiente != nullptr) {//& Ciclo while de aux siguiente sea distinto a null
            contador++;//& Contador +1
            auxAnterior = auxActual;////& Anterior igual a actual
            auxActual = auxActual->siguiente;//& Actual apuntara a siguiente
            if (contador <= 1 && auxActual == nullptr) {//& si contador es igual a 0 y actual es iguala  null
                eliminarUltimoDato(frente);//& Llamamos a la funcion elminar ultimo dato
                break;//& salimos del ciclo
            }
            auxSiguiente = auxActual;//& siguiente sera igual a actual
            auxSiguiente = auxSiguiente->siguiente;//& siguiente apuntara al siguiente nodo
            if (auxSiguiente == nullptr) {//& si siguiente es igual a null
                auxAnterior->siguiente = auxActual->siguiente;//& anterior apuntara a siguiente
                delete auxActual;//& borramos el nodo actual
                espacio(5);
                cout << "Dato eliminado" << endl;
                break;//& salimos del ciclo
            }
        }
    } else {//& Si no Existe la cola
        espacio(5);
        //& Mandamos un mensaje
        cout << "Lista vacia, agregue datos en la opcion correspondiente" << endl;
    }
    cout << endl;
}

void eliminarUltimoDato(Nodo *&lista) {
    if (lista != nullptr) {//& si la cola existe
        Nodo *auxBorrar;//& Creamos un nodo
        auxBorrar = lista;//& Igualamos el nodo al nodo recibido
        lista = lista->siguiente;//& El nodo recibido apuntara al siguiente nodo
        delete auxBorrar;//& borramos el nodo borrar
        espacio(5);
        cout << "Dato eliminado" << endl;
    } else {//& Si no Existe la cola
        espacio(5);
        //& Mandamos un mensaje
        cout << "Lista vacia, agregue  datos en la opcion correspondiente" << endl;
    }
}

void mostarDatos(Nodo *frente) {
    if (frente != nullptr) {//& si la cola existe
        Nodo *actual; //& Creamos el nodo actual
        actual = frente;//& actual sera igual al nodo recibido
        while (actual != nullptr) {//& ciclo que termina hasta que actual sea igual a null
            cout << actual->dato << "->";
            actual = actual->siguiente;//& Actual apuntara al siguiente nodo
        }
    } else {//& Si no Existe la cola
        cout << "Lista vacía, agregue datos en la opcion correspondiente";
    }
    espacio(2);
}
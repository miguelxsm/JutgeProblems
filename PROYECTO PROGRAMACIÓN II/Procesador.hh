/** @file Procesador.hh
    @brief Especificación de la clase Procesador
*/

#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_

#include "Proceso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <set> //para la memoria
#include <map>
#endif
using namespace std;

/** @class Procesador
    @brief Un procesador tiene un límite de memoria y sirve para ejecutar procesos. */

class Procesador {
    private:
/** @brief Representa la capacidad del Procesador. Es constante */
    int memoria_total;

/** @brief Representa la cantidad de memoria libre del Procesador */
    int memoria_libre;

/** @brief Representa la profundidad del Procesador en el árbol del Cluster */
    int profundidad;
    
/** @brief Estructura de posiciones ordenado por identificador */
    map<int,int> posiciones; // (identificador, posicion)
    
/** @brief Estructura de Procesos ordenado por posicion */
    map<int, Proceso> procesos; // (posicion, proceso)
    
/** @brief Estructura de la posicion de los huecos ordenado por tamaño */
    set< pair<int,int> > huecos; // set<tamaño_hueco, posicion>

/** @briefModificadora que indica si hay un hueco en la posición pos_hueco y si lo hay, lo elimina
    \pre <em>Cierto</em>
    \post Devuelve true si hay un hueco en la posición pos_hueco y lo elimina <br>
          False en caso contrario */

    bool hueco_abajo(int pos_hueco, int pos_p, int& peso_hueco_final);


/** @brief Modificadora que indica si hay un hueco en la posición anterior a pos y si lo hay lo elimina
    \pre <em>Cierto</em>
    \post Devuelve true si hay un hueco en la posición anterior a pos y lo elimina <br>
          False en caso contrario */

    bool hueco_arriba(int pos, int& peso_hueco_final, int& pos_hueco);

/** @brief La funcion elimina el proceso apuntado por los iteradores
    \pre <em> it != posicione.end() <br> it2 != procesos.end() </em>
    \post El resultado es el parámetro implícito sin el proceso apuntado por los iteradores */

    void eliminar(map<int,int>::iterator& it, map<int,Proceso>::iterator& it2);
    
/** @brief Consultora de la posición de memoria ideal para un proceso con tamaño = peso 
    \pre <em>Cierto</em>
    \post Si no hay espacio suficiente la función retorna -2 <br>
          En caso contrario el resultado es la posición de memoria para un proceso con tamaño = peso */

    int pos_memoria(int peso, int& peso_hueco) const;

    public:

    //CONSTRUCTORAS

/** @brief Constructora por defecto
    \pre <em>Cierto</em>
    \post El resultado es un Procesador vacío */

    Procesador();

/** @brief Constructora que crea un Procesador con los parámetros seleccionados
    \pre <em>Cierto</em>
    \post El resultado es un Procesador con memoria_total = memoria_libre = memoria y profundidad = p
          <br> Se inserta un hueco de tamaño memoria en la posición 0 */

    Procesador(int memoria, int p);

    //MODIFICADORAS

/** @brief Modificadora que cambia la profundidad del procesador
    \pre <em>Cierto</em>
    \post El resultado es el parámetro implícito con profundidad = p */

    void cambiar_profundidad(int p);


/** @brief Modificadora que avanza el tiempo t unidades
    \pre <em>Cierto</em>
    \post El resultado es el parámetro implícito con el tiempo avanzado t unidades */

    void avanzar_tiempo(int t);

/** @brief Modificadora que elimina el proceso con identificador = id
    \pre <em>Cierto</em>
    \post Si no existe un proceso con identificador == id la funcion retorna -2 <br>
          En caso contrario, el resultado es el parámetro implícito sin el proceso con identificador = id y la función devuelve 0 */
    
    int eliminar_proceso(int id);

/** @brief Modificadora que añade el proceso p al parámetro implícito
    \pre <em>Cierto</em>
    \post Si existe un proceso con identificador == p.identificador la función retorna -2 <br>
          Si no hay memoria suficiente la función retorna -3 <br>
          Si no tiene los errores previamente mencionados el resultado es el parámetro implícito con el proceso p añadido */

    int anadir_proceso(const Proceso& p);

/** @brief Modificadora que compacta la memoria del procesador
    \pre <em>Cierto</em>
    \post El resultado es el parámetro implícito con la memoria compactada, es decir, sin huecos entre procesos */

    int compactar_memoria();

    //CONSULTORAS

/** @brief Consultora que indica si cabe un proceso de tamaño = peso
    \pre <em>Cierto</em>
    \post Devuelve true si existe algun hueco que sea mayor o igual a peso, false en caso contrario */

    bool cabe_proceso(int peso, int& peso_hueco);

/** @brief Consultora de memoria libre
    \pre <em>Cierto</em>
    \post Devuelve la memoria libre del parámetro implícito */

    int consultar_memoria_libre() const;

/** @brief Consultora de profundidad
    \pre <em>Cierto</em>
    \post Devuelve la profundidad del parámetro implícito */

    int consultar_profundidad() const;

/** @brief Consultora de si hay procesos pendientes
    \pre <em>Cierto</em>
    \post Devuelve true si tiene procesos pendientes <br>
          False en caso contrario */
    bool hay_procesos_pendientes() const;

/** @brief Consultora de si existe un proceso con identificador = id
    \pre <em>Cierto</em>
    \post Devuelve true si existe un proceso con identificador = id <br>
          False en caso contrario */

    bool existe_proceso(int id) const;

    //ENTRADA-SALIDA

/** @brief Operación de escritura
    \pre <em>Cierto</em>
    \post Se han escrito los valores del parámetro implícito */

    void escribe_procesador() const;
    
};
#endif
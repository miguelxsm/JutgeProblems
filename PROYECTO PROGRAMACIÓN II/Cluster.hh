/** @file Cluster.hh
    @brief Especificación de la clase Cluster
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_
#include "Proceso.hh"
#include "Procesador.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include "BinTree.hh"
#include <string>
#endif
using namespace std;

/** @class Cluster
    @brief Representa el conjunto de características y operaciones del Cluster. */

class Cluster {
    private:
/** @brief Representa la estructura Arborescente del Cluster */
    BinTree<string> c;
    
/** @brief Estructura de procesadores ordenado por identificador */
    map<string, Procesador> m; //(id procesador, procesador)
    
/** @brief Acción de inmersion a leer_cluster
    \pre <em>Cierto</em>
    \post Se ha leído la estructura del Cluster */

    void i_lee_cluster(BinTree<string>& aux, int profundidad);

/** @brief Acción de inmersion a escribir_cluster
    \pre <em>Cierto</em>
    \post El resultado es el árbol escrito */

    static void i_escribe_cluster_arbol(const BinTree<string>& a);

/** @brief Consultora de si tiene procesadores auxiliares
    \pre <em>Cierto</em>
    \post Devuelve true si el procesador tiene procesadores auxiliares y false en caso contrario */
    
    static bool procesador_con_auxiliares(const BinTree<string>& a, const string& id);

/** @brief Modificadora que  amplia el árbol b con la estructura y nodos del árbol a
    \pre <em>Cierto</em>
    \post El resultado es el árbol b ampliado con la estructura y nodos del árbol a con su respectiva altura p */
    
    void copiar_arbol(BinTree<string>& b, const BinTree<string>& a, const map<string,Procesador>& am, int p);

/** @brief Modificadora que  busca el mejor procesador para enviar el proceso p según los criterios establecidos
    \pre itmejor = m.end()
    \post Si no existe ningun procesador que pueda ejecutar el proceso p, b = false <br>
          Si existe un procesador que pueda ejecutar el proceso p, b = true e itmejor apunta a dicho procesador 
          mejor_hueco pasa a ser el tamaño del mejor hueco encontrado */

    void i_enviar_proceso(const Proceso& p, bool& b, const BinTree<string>& a, int& mejor_hueco, map<string,Procesador>::iterator& itmejor);

/** @brief Modificadora que busca el nodo con identificador == id en el árbol del Cluster y llama a otra funcion para sustituir esa raiz por el árbol b
    \pre <em>Cierto</em>
    \post El resultado es el árbol del Cluster con la raíz con identificador == id sustituida por el árbol b */

    int busqueda_y_cambio(Cluster& a, const string& id, BinTree<string>& b, int p);

    public:
    
    //CONSTRUCTORAS
    
/** @brief Constructora por Defecto
    \pre <em>Cierto</em>
    \post El resultado es un cluster vacío */
    
    Cluster();

    //MODIFICADORAS

/** @brief Modificadora que añade el procesador p en el mejor procesador encontrado en su función de inmersión
    \pre <em>Cierto</em>
    \post Si no se encuentra ningun procesador, b = false
          En caso contrario, b = true y el procesador p se ha añadido al mejor procesador encontrado */
    
    void enviar_proceso(const Proceso& p, bool& b);

/** @brief Modificadora que añade el cluster a en la posición del procesador id si solo si existe
    \pre <em>Cierto</em>
    \post Si no existe el procesador "id", la función devuelve -1 <br>
          Si el procesador está ejecutando procesos, la función devuelve -2 <br>
          Si el procesador tiene procesadores auxiliares, la función devuelve -3 <br>
          Si no tiene ninguno de los errores previamente mencionados, Cluster a
          se coloca en la posición donde se encuentra el procesador con identificador = id
          y devuelve 0. También se elimina el nodo con identificador = id */

    int modificar_procesador_cluster(Cluster& a, const string& id);

/** @brief Modificadora que avanza el tiempo en todos los procesadores del cluster
    \pre <em>Cierto</em>
    \post Se ha avanzado el tiempo de todos los procesadores */

    void avanzar_tiempo(int t);

/** @brief Modificadora que añade el proceso p en el procesador con identificador id si solo si existe
    \pre <em>Cierto</em>
    \post Si no existe ningun procesador con identificador == id, devuelve -1 <br>
          Si existe un proceso en el procesador con identificador == p.identificador devuelve -2 <br>
          Si no hay espacio en el procesador para poner el proceso devuelve -3 <br>
          Si no tiene los errores previamente mencionados, el proceso p se ha añadido
          al procesador con identificador = id y la funcion devuelve 0  */

    int alta_proceso_procesador(const string& id, const Proceso& p);


/** @brief Modificadora que elimina el proceso id_proceso del procesador id_procesador si solo si ambos existen
    \pre <em>Cierto</em>
    \post Si no existe ningun procesador con identificador == id_procesador devuelve -1 <br>
          Si no existe ningun proceso con identificador == id_proceso dentro del procesador <br>
          con identificador = id_procesador, devuelve -2 <br>
          Si no tiene ninguno de los errores previamente mencionados, el proceso con 
          identificador = id_proceso deja de existir en el procesador con identificador = id_procesador y la función devuelve 0 */

    int baja_proceso_procesador(const string& id_procesador, int id_proceso);

/** @brief Modificadora que compacta la memoria del procesador = id si solo si existe, o bien, de todos los procesadores del cluster
    \pre <em>Cierto</em>
    \post Si no existe el procesador con identificador == id la función devuelve -1 <br>
          Si id == "-", se compacta la memoria de todo el cluster <br>
          Si id != "-" se compacta la memoria del procesador con identificador = id si solo si existe */

    int compactar_memoria_procesador(const string& id);

    //ENTRADA/SALIDA

/** @brief Operacion de lectura
    \pre <em>Cierto</em>
    \post Se han leido los valores y se han guardado en el parámetro implícito  */
    void lee_cluster(); 

/** @brief Operación de escritura
    \pre <em>Cierto</em>
    \post Se han escrito los valores del parámetro implícito */
    void escribe_cluster() const;

/** @brief Operación de escritura en formato de árbol
    \pre <em>Cierto</em>
    \post Se ha escrito la estructura del parámetro implícito */
    void escribe_cluster_arbol() const;

/** @brief Operación de escritura del procesador con identificador id
    \pre <em>Cierto</em>
    \post Si no existe ningun procesador con identificador == id devuelve -1 <br>
          En caso contrario, se imprime el procesador y la función devuelve 0.*/
    int imprimir_procesador(const string& id) const;
};
#endif


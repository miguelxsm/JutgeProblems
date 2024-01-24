/** @file Proceso.hh
    @brief Especificación de la clase Proceso
*/

#ifndef _PROCESO_HH_
#define _PROCESO_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Proceso
    @brief Un proceso está compuesto de su identificador, el peso que ocupa en memoria y el tiempo que tarda en ejecutarse. */
class Proceso {

    private:
    
      int id_proceso; // identificador del proceso
      int peso; // cantidad de memoria que ocupa el proceso
      int tiempo_restante; // tiempo restante que le queda al proceso para ejecutarse

    public:

    //CONSTRUCTORAS
    
/** @brief Constructora por Defecto
    \pre <em>Cierto</em>
    \post El resultado es un proceso vacío */

    Proceso();

    //CONSULTORAS

/** @brief Consultora del tiempo restante
    \pre <em>Cierto</em> 
    \post Devuelve el tiempo restante del parámetro implícito */
  
    int consultar_tiempo_restante() const;


/** @brief Consultora del identificador
    \pre <em>Cierto</em>
    \post Devuelve el id_proceso del parámetro implícito */

    int consultar_id_proceso() const;


/** @brief Consultora del peso
    \pre <em>Cierto</em>
    \post Devuelve el peso en memoria del parámetro implícito  */
    
    int consultar_peso() const;

    //MODIFICADORAS
    
/** @brief Modificadora que avanza el tiempo t unidades
    \pre t >= 0
    \post El resultado es el parámetro implícito con t unidades avanzadas en tiempo_restante */
    void avanzar_tiempo(int t);

    //ENTRADA/SALIDA

/** @brief Operacion de lectura
    \pre <em>Cierto</em>
    \post Se han leido los valores y se han guardado en el parámetro implícito  */
  
     void leer_proceso();
     

/** @brief Operacion de escritura
    \pre <em>Cierto</em> 
    \post Se han escrito los valores del parámetro implícito */
    
    void escribe_proceso() const;
};
#endif
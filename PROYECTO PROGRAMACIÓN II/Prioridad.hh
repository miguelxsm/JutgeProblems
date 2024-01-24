/** @file Prioridad.hh
    @brief Especificación de la clase Prioridad
*/

#ifndef _PRIORIDAD_HH_
#define _PRIORIDAD_HH_

#include "Proceso.hh"
#include "Cluster.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <list>
#include <set>
#include <string>
#endif
using namespace std;

/** @class Prioridad
    @brief Representa una cola formada por procesos que están en espera de ser ejecutados */

class Prioridad  {
    private:

/** @brief Representa la prioridad, una estructura de Procesos ordenados por antigüedad */
    list<Proceso> q;

/** @brief Conjunto de identificadores de procesos que están en la cola ordenados por identificador */
    set<int> set_prioridad;

/** @brief Número de procesos aceptados en el Cluster */
    int aceptados;

/** @brief Número de procesos rechazados en el Cluster */
    int rechazados;

    public:

    //CONSTRUCTORAS

/** @brief Constructora por defecto
    \pre <em>Cierto</em>
    \post El resultado es una prioridad vacía */

    Prioridad();    

    //CONSULTORAS

/** @brief Consultora de si existen procesos pendientes
    \pre <em>Cierto</em>
    \post Devuelve true si la Prioridad no está vacía, false en caso contrario */
    bool tiene_procesos_pendientes() const;    
    
    //MODIFICADORAS


/** @brief Modificadora que añade el Proceso p a la prioridad
    \pre <em>Cierto</em>
    \post Si existe un proceso con el mismo identificador devuelve -1 <br>
          En caso contrario lo añade a la prioridad y devuelve 0 */

    int anadir_proceso(const Proceso& p);

/** @brief Modificadora que envía hasta n procesos al Cluster
    \pre <em>Cierto</em>
    \post Se han enviado hasta n procesos al Cluster */

    void enviar_procesos_priodidad(int& n, Cluster& c);

    //ENTRADA/SALIDA

/** @brief Modificadora que escribe los valores de la prioridad  
    \pre <em>Cierto</em>
    \post Se han escrito los valores del parámetro implícito */
    void escribir_prioridad() const;
};
#endif
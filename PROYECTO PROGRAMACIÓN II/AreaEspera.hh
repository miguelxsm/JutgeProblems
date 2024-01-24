/** @file AreaEspera.hh
    @brief Especificación de la clase AreaEspera */

#ifndef _AREAESPERA_HH_
#define _AREAESPERA_HH_

#include "Prioridad.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;


/** @class AreaEspera
    @brief En el área de espera se almacena un conjunto de colas ordenadas alfabéticamente en la que hay procesos a la espera de ser ejecutados. 
    
    Ofrece una gran variedad de operaciones para la gestión de los procesos que están a la espera de ser ejecutados */

class AreaEspera {

    private:

/** @brief Estructura de Prioridades ordenado por identificador */
    
    map<string,Prioridad> m;

    public:

    //CONSTRUCTORAS

/** @brief Constructora por defecto
    \pre <em>Cierto</em>
    \post El resultado es un área de espera vacío */

    AreaEspera();

    //MODIFICADORAS

/** @brief Modificadora que intenta mandar los n primeros procesos del Area de Espera segun su prioridad
   \pre <em>Cierto</em>
   \post Se han mandado hasta n procesos al Cluster */
    void enviar_procesos_cluster(int n, Cluster& c);    

/** @brief Modificadora que elimina la prioridad id
    \pre <em>Cierto</em>
    \post Si no existe ninguna prioridad con identificador == id devuelve -1 <br>
          Si la prioridad tiene procesos pendientes, devuelve -2 <br>
          Si no tiene los errores previamente mencionados, se ha eliminado
          la prioridad con identificador = id del parámetro implícito y la función devuelve 0 */
          
    int eliminar_prioridad(const string& id);

/** @brief Modificadora que añade una prioridad vacía con identificador = id 
    \pre <em>Cierto</em>
    \post Si ya existe una prioridad con identificador == id, devuelve -1 <br>
          Si no existe la prioridad, se ha añadido una prioridad vacía con
          identificador == id y la función devuelve 0 */
    
    int anadir_prioridad(const string& id);

/** @brief Modificadora que añade el proceso p a la priorida id;
    \pre <em>Cierto</em>
    \post Si no existe ninguna prioridad con identificador == id, devuelve -1 <br>
          Si ya existe un proceso con el mismo identificador que p en la prioridad
          con identificador = id, devuelve -2 <br>
          Si no tiene ninguno de los errores previamente mencionados, el proceso
          se ha añadido a la prioridad y la función devuelve 0 */
   
    int anadir_proceso_en_prioridad(const string& id, Proceso& p);

    //ENTRADA/SALIDA

/** @brief Operación de lectua
    \pre <em>Cierto</em>
    \post Se han leído los valores del parámetro implícito */

    void lee_area_espera();

/** @brief Operación de escritura
    \pre Si se quiere imprimir el Area de Espera completo se ha de escribir "-" como id
         Si se quiere imprimir una prioridad solamente, se ha de escribir su identificador
    \post Se ha escrito el Area de Espera o una Prioridad */

    int escribe_area_espera(const string& id) const;
};
#endif

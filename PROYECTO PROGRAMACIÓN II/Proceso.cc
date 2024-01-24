#include "Proceso.hh"

    //CONSTRUCTORAS
    

      Proceso::Proceso() {
        id_proceso = -1;
        peso = 0;
        tiempo_restante = 0;
      }

    //CONSULTORAS

   int Proceso::consultar_tiempo_restante() const {
      return tiempo_restante;
   }

   int Proceso::consultar_id_proceso() const {
      return id_proceso;
   }

   int Proceso::consultar_peso() const {
      return peso;
   }

    //MODIFICADORAS

  void Proceso::avanzar_tiempo(int t) {
      tiempo_restante -= t;
    }

    //ENTRADA/SALIDA


   void Proceso::leer_proceso() {
      cin >> id_proceso >> peso >> tiempo_restante;
      cout << id_proceso << endl;
   }

   void Proceso::escribe_proceso() const {
      cout << id_proceso << " " << peso << " " << tiempo_restante << endl;
   }

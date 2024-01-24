#include "Prioridad.hh"
using namespace std;

    //CONSTRUCTORAS

    Prioridad::Prioridad() {
        aceptados = 0;
        rechazados = 0;
    }
    
    //CONSULTORAS

    bool Prioridad::tiene_procesos_pendientes() const {
        return (not q.empty());
    }   

    //MODIFICADORAS

    int Prioridad::anadir_proceso(const Proceso& p) {
        set<int>::iterator it = set_prioridad.find(p.consultar_id_proceso());
        if (it != set_prioridad.end()) return -1;
        else {
            q.insert(q.end(), p);
            set_prioridad.insert(p.consultar_id_proceso());
            return 0;
        }
    }

    void Prioridad::enviar_procesos_priodidad(int& n, Cluster& c) {
        list<Proceso>::iterator it = q.begin();
        int i = 0;
        int size = q.size(); 
        while(n > 0 and i < size){
            bool b = false; //bool para comprobar si ha sido aceptado o rechazado
            c.enviar_proceso((*it), b);
            if (b) {
                ++aceptados;
                set_prioridad.erase((*it).consultar_id_proceso());
                --n;
            }
            else {
                ++rechazados;
                q.insert(q.end(),(*it));
            }
            it = q.erase(it);
            ++i;
        }
    }

    //ENTRADA/SALIDA

    void Prioridad::escribir_prioridad() const {
        list<Proceso>::const_iterator it = q.begin();
        while (it != q.end()) {
            (*it).escribe_proceso();
            ++it;
        }
        cout << aceptados << " " << rechazados << endl;
    }


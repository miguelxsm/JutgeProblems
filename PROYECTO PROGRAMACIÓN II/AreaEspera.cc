#include "AreaEspera.hh"

    //CONSTRUCTORAS

    AreaEspera::AreaEspera() {
        
    } 

    //MODIFICADORAS

    void AreaEspera::enviar_procesos_cluster(int n, Cluster& c) {
        map<string, Prioridad>::iterator it = m.begin();
        while (n > 0 and it != m.end()) {
            (*it).second.enviar_procesos_priodidad(n, c);
            ++it;
        }
    }

    int AreaEspera::eliminar_prioridad(const string& id) {
        map<string, Prioridad>::iterator it = m.find(id);
        if (it == m.end()) return -1;
        else if ((*it).second.tiene_procesos_pendientes()) return -2;
        else {
            m.erase(it);
            return 0;
        }
    }

    int AreaEspera::anadir_prioridad(const string& id) {
        map<string, Prioridad>::iterator it = m.find(id);
        if (it != m.end()) return -1; 
        else {
            Prioridad p;
            m.insert(make_pair(id, p));
            return 0;
        }
    }

    int AreaEspera::anadir_proceso_en_prioridad(const string& id, Proceso& p) {
        map<string, Prioridad>::iterator it = m.find(id);
        if (it == m.end()) return -2;
        return (*it).second.anadir_proceso(p);
    }

    void AreaEspera::lee_area_espera() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string id;
            cin >> id;   
            m.insert(make_pair(id, Prioridad()));
        }
    }

    int AreaEspera::escribe_area_espera(const string& id) const {
        if (id == "-") {
            map<string, Prioridad>::const_iterator it = m.begin();
            while (it != m.end()) {
                cout << (*it).first << endl;
                (*it).second.escribir_prioridad();
                ++it;
            }
            return 0;
        }
        else {
            map<string, Prioridad>::const_iterator it = m.find(id);
            if (it == m.end()) return -1;
            else {
                (*it).second.escribir_prioridad();
                return 0;
            } 
        }
    }

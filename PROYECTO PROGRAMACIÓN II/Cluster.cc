#include "Cluster.hh"
    
    //FUNCIONES PRIVADAS

    void Cluster::i_lee_cluster(BinTree<string>& aux, int a) {
        string id;
        int memoria;
        cin >> id;
        if (id != "*") {
            BinTree<string> e,d;
            cin >> memoria;
            Procesador p(memoria, a);
            ++a; //se incrementa la altura antes de llamar recursivamente
            m.insert(make_pair(id,p));
            i_lee_cluster(e,a);
            i_lee_cluster(d,a);
            aux = BinTree<string> (id, e, d);
        }
    }

    void Cluster::i_escribe_cluster_arbol(const BinTree<string>& bt) {
        if (bt.empty()) cout << " ";
        
        else {
            cout << "(" << bt.value();
            i_escribe_cluster_arbol(bt.left());
            i_escribe_cluster_arbol(bt.right());
            cout << ")";
        }
    }

    bool Cluster::procesador_con_auxiliares(const BinTree<string>& a, const string& id) {
        if (a.value() == id) return not a.left().empty() or not a.right().empty();
        else {
            bool b = procesador_con_auxiliares(a.left(), id);
            if (not b) b = procesador_con_auxiliares(a.right(), id);
            return b;
        }
    }

    void Cluster::copiar_arbol(BinTree<string>& b, const BinTree<string>& a, const map<string,Procesador>& am, int p){
        if(not a.empty()){
            BinTree<string> i,d;
            BinTree<string> ai,ad;
            map<string, Procesador>::const_iterator it = am.find(a.value());
            pair<map<string, Procesador>::iterator, bool> r = m.insert((*it));
            (*r.first).second.cambiar_profundidad(p);
            ++p;
            copiar_arbol(i,a.left(),am,p);
            copiar_arbol(d,a.right(),am,p);
            b = BinTree<string>(a.value(),i,d);
        }
    }

    void Cluster::i_enviar_proceso(const Proceso& p, bool& b, const BinTree<string>& a, int& mejor_hueco, map<string,Procesador>::iterator& itmejor) {
        if (not a.empty()) {
            int peso_hueco;
            map<string,Procesador>::iterator it = m.find(a.value());
            if ((*it).second.cabe_proceso(p.consultar_peso(), peso_hueco) and not (*it).second.existe_proceso(p.consultar_id_proceso())) { //si no cabe el proceso o ya existe un proceso dentro de ese procesador con el mismo identificador, se descarta totalmente
                b = true; //significa que hay mínimo 1 procesador en el que se puede poner el proceso
                if (itmejor == m.end()) {
                    itmejor = it;
                    mejor_hueco = peso_hueco;
                }

                if (peso_hueco < mejor_hueco) {
                    itmejor = it;
                    mejor_hueco = peso_hueco;
                }

                else if (peso_hueco == mejor_hueco) {
                    if ((*it).second.consultar_memoria_libre() > (*itmejor).second.consultar_memoria_libre()) {
                        itmejor = it;
                    }

                    else if ((*it).second.consultar_memoria_libre() == (*itmejor).second.consultar_memoria_libre() and (*it).second.consultar_profundidad() < (*itmejor).second.consultar_profundidad()) {
                        itmejor = it;
                    }
                }
            }
            i_enviar_proceso(p,b,a.left(), mejor_hueco, itmejor);
            i_enviar_proceso(p,b,a.right(), mejor_hueco, itmejor);
        }
    }

    int Cluster::busqueda_y_cambio(Cluster& a, const string& id, BinTree<string>& b, int p) {
        if (not b.empty()) {
            if (b.value() == id) {
                if (not b.left().empty() or not b.right().empty()) return -3; // si tiene hijos
                map<string, Procesador>::iterator it = m.find(id);
                m.erase(it);
                copiar_arbol(b,a.c,a.m,p);
            
                return 0;
            }
            else {
                BinTree<string> e = b.left();
                BinTree<string> d = b.right();
                ++p;
                int res = busqueda_y_cambio(a, id, e, p);
                if (res == -4) res = busqueda_y_cambio(a, id, d, p);
                b = BinTree<string>(b.value(),e,d);
                return res;
            }
        }
        else return -4;
    }


    //CONSTRUCTORAS

    Cluster::Cluster(){

    } 
    


    //MODIFICADORAS

    void Cluster::enviar_proceso(const Proceso& p, bool& b) {
        map<string,Procesador>::iterator itmejor = m.end();
        int diferencia;
        i_enviar_proceso(p, b, c, diferencia, itmejor);
        if (b) (*itmejor).second.anadir_proceso(p);
    }

    int Cluster::modificar_procesador_cluster(Cluster& a, const string& id) {
        map<string, Procesador>::iterator it = m.find(id);
        if (it == m.end()) return -1;
        if ((*it).second.hay_procesos_pendientes()) return -2;
        return busqueda_y_cambio(a, id, c, 0);
    }


    void Cluster::avanzar_tiempo(int t) {
        map<string, Procesador>::iterator it = m.begin();
        while (it != m.end()) {
            (*it).second.avanzar_tiempo(t);
            ++it;
        }
    }

    int Cluster::alta_proceso_procesador(const string& id_procesador, const Proceso& p) {

        map<string, Procesador>::iterator it = m.find(id_procesador);
        if (it == m.end()) return -1;
        return (*it).second.anadir_proceso(p);
    }

    int Cluster::baja_proceso_procesador(const string& id_procesador, int id_proceso)  {
        map<string, Procesador>::iterator it = m.find(id_procesador);
        if (it == m.end()) return -1;
        return (*it).second.eliminar_proceso(id_proceso);
    }

    int Cluster::compactar_memoria_procesador(const string& id_procesador) {
        if (id_procesador == "-") {     //si recibe un id == '-' se interpreta que se quiere compactar la memoria de todos los procesadores
            map<string, Procesador>::iterator it = m.begin();
            while (it != m.end()) {
                (*it).second.compactar_memoria();
                ++it;
            }
            return 0;
        }
        else {
            map<string, Procesador>::iterator it = m.find(id_procesador);
            if (it == m.end()) return -1;
            else {
                (*it).second.compactar_memoria();
                return 0;
            }
        }
    }

    //ENTRADA / SALIDA

    void Cluster::lee_cluster() {
        m.clear();
        i_lee_cluster(c, 0);
    }

    void Cluster::escribe_cluster() const {
        map<string, Procesador>::const_iterator it = m.begin();
        while (it != m.end()) {
            cout << (*it).first << endl;
            (*it).second.escribe_procesador();
            ++it;
        }
    }

    void Cluster::escribe_cluster_arbol() const {
        i_escribe_cluster_arbol(c);
        cout << endl;
    }

    int Cluster::imprimir_procesador(const string& id) const {
        map<string, Procesador>::const_iterator it = m.find(id);
        if (it == m.end()) return -1;
        else {
            (*it).second.escribe_procesador();
            return 0;
        }
    }








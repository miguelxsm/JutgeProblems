#include "Procesador.hh"

//Funciones Privadas

bool Procesador::hueco_abajo(int pos_hueco, int pos_p, int& peso_hueco_final) { 
    map<int,Proceso>::const_iterator it = procesos.find(pos_hueco);
    if (it != procesos.end()) return false;
    else {
        map<int,Proceso>::const_iterator it2 = procesos.find(pos_p);
        ++it2;
        int peso_hueco;
        if (it2 != procesos.end()) {
            peso_hueco = (*it2).first - pos_hueco;
        }
        else peso_hueco = memoria_total - pos_hueco;
        set < pair<int,int> >::iterator it3 = huecos.find(make_pair(peso_hueco, pos_hueco));

        if (it3 != huecos.end()) {
            huecos.erase(it3);
            peso_hueco_final = peso_hueco;
            return true;
        }
        return false;
    }
}

bool Procesador::hueco_arriba(int pos, int& peso_hueco_final, int& pos_hueco) {
    map<int,Proceso>::const_iterator it = procesos.find(pos);
    if (it != procesos.begin()) {
        --it;
        int posicion_anterior = (*it).first;
        int peso_anterior = (*it).second.consultar_peso();
        if (posicion_anterior + peso_anterior == pos) return false;
        else {
            peso_hueco_final = pos - posicion_anterior - peso_anterior;
            pos_hueco = posicion_anterior + peso_anterior;
            set< pair<int,int> >::const_iterator it2 = huecos.find(make_pair(peso_hueco_final,pos_hueco));
            if (it2 != huecos.end()) huecos.erase(it2);
            return true;    
        }
    }

    else {
        if ((*it).first == 0) return false;
        else {
            peso_hueco_final = (*it).first;
            pos_hueco = 0;
            set< pair<int,int> >::const_iterator it2 = huecos.find(make_pair(peso_hueco_final,pos_hueco));
            huecos.erase(it2);
        }
        return true;
    }
}

void Procesador::eliminar(map<int,int>::iterator& it, map<int,Proceso>::iterator& it2){
    int peso = (*it2).second.consultar_peso();
    memoria_libre += peso; 
    int peso_hueco = peso; //de momento se quiere insertar un hueco de tamaño el peso del proceso que se va a eliminar
    int peso_hueco2;
    int pos = (*it).second;
    bool abajo = hueco_abajo(peso + pos, pos, peso_hueco2); //peso_hueco2 pasado por referencia para sumarlo con el total de tamaño que se va a insertar
    if (abajo) peso_hueco += peso_hueco2;
    int pos_hueco;
    bool arriba = hueco_arriba(pos, peso_hueco2, pos_hueco);
    if (arriba) {
        pos = pos_hueco; // si hay un hueco arriba entonces la posicion del hueco será esa
        peso_hueco += peso_hueco2;
    }
    huecos.insert(make_pair(peso_hueco, pos)); 
    it2 = procesos.erase(it2);
    posiciones.erase(it);    
}

int Procesador::pos_memoria(int peso, int& peso_hueco) const {
    set< pair<int,int> >::iterator it = huecos.lower_bound(make_pair(peso,0));
    if (it == huecos.end()) return -2;
    else {
        peso_hueco = (*it).first;
        return (*it).second;
    }
}

//CONSTRUCTORAS

Procesador::Procesador() {
    
}

Procesador::Procesador(int memoria, int p) {
    memoria_total = memoria_libre = memoria;
    huecos.insert(make_pair(memoria, 0));
    profundidad = p;
}

//MODIFICADORAS

void Procesador::cambiar_profundidad(int p) {
    profundidad = p;
}

void Procesador::avanzar_tiempo(int t) {
     map<int,Proceso>::iterator it = procesos.begin();
    while (it != procesos.end()) {
        int id = (*it).second.consultar_id_proceso();
        (*it).second.avanzar_tiempo(t);
        if ((*it).second.consultar_tiempo_restante() <= 0) { //si la resta del tiempo es menor o igual a 0, el proceso ha terminado y se ha de eliminar
            ++it;
            eliminar_proceso(id);
         } 
        else ++it;
    }
}

int Procesador::eliminar_proceso(int id) {
        map<int,int>::iterator it = posiciones.find(id); 
        if (it == posiciones.end()) return -2; 
        else {
            map<int,Proceso>::iterator it2 = procesos.find((*it).second); 
            eliminar(it,it2);
            return 0;
        }
}

int Procesador::anadir_proceso(const Proceso& p) {
    map<int,int>::iterator it = posiciones.find(p.consultar_id_proceso());
    if (it != posiciones.end()) return -2;
    else {
        int peso = p.consultar_peso();
        int peso_hueco;
        int pos = pos_memoria(peso, peso_hueco); //posicion con el hueco más ajustado
        if (pos == -2) return -3;
        else { 
            posiciones.insert(make_pair(p.consultar_id_proceso(), pos));
            procesos.insert(make_pair(pos, p));
            if (peso == peso_hueco) huecos.erase(make_pair(peso, pos)); //si el hueco es lo mas ajustado posible no hace falta crear un hueco
            else {
                huecos.insert(make_pair(peso_hueco - peso, pos + peso)); 
                huecos.erase(make_pair(peso_hueco, pos));
                }
        memoria_libre -= peso;
        return 0;
        }
    }
}

int Procesador::compactar_memoria() {
    int pos = 0;
    map<int,Proceso>::iterator it = procesos.begin();
    map<int,int>::iterator itpos;
    if (huecos.empty()) return 0;
    if (it == procesos.end()) return 0; //si no hay huecos o no hay procesos no hay nada que compactar
    int peso = (*it).second.consultar_peso();
    huecos.clear();
    pos = (*it).second.consultar_peso();
    if ((*it).first != 0) { // si en la posicion 0 no hay un proceso, se mueve el primer proceso
        itpos = posiciones.find((*it).second.consultar_id_proceso());
        (*itpos).second = 0;
        procesos.insert(make_pair(0, (*it).second));
        it = procesos.erase(it);
    }
    else ++it;  
    while (it != procesos.end()) {
        peso = (*it).second.consultar_peso();
        if (pos != (*it).first) { //si no coincide significa que habia un hueco de por medio
                procesos.insert(make_pair(pos, (*it).second));
                map<int,int>::iterator it2 = posiciones.find((*it).second.consultar_id_proceso());
                (*it2).second = pos;
                it = procesos.erase(it);   
        }
        else ++it;    
        pos += peso;    
    }
    huecos.insert(make_pair(memoria_libre, memoria_total - memoria_libre));
    
    return 0;
}


//CONSULTORAS

bool Procesador::cabe_proceso(int peso, int& peso_hueco) {
    set< pair<int,int> >::iterator it = huecos.lower_bound(make_pair(peso,0));
    if (it == huecos.end()) return false;
    else {
        peso_hueco = (*it).first;
        return true;
    }
}

int Procesador::consultar_memoria_libre() const {
    return memoria_libre;
}

int Procesador::consultar_profundidad() const {
    return profundidad;
}

bool Procesador::hay_procesos_pendientes() const {
    return not procesos.empty();
}

bool Procesador::existe_proceso(int id) const {
    map<int,int>::const_iterator it = posiciones.find(id);
    return it != posiciones.end();
}

//ENTRADA / SALIDA;

void Procesador::escribe_procesador() const {
    map<int,Proceso>::const_iterator it = procesos.begin();
    while (it != procesos.end()) {
        cout << (*it).first << " " << (*it).second.consultar_id_proceso() << " " << (*it).second.consultar_peso() << " " << (*it).second.consultar_tiempo_restante() << endl;
        ++it;
    }
}
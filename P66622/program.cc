#include "Player.hh"
#include <algorithm>
#include <list>


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME XSMILEIGOD


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }
    //variables globales:
  const int casillas_maximas = 8;
  const double dist_maxima = 5 + sqrt(2);
  const int factor_maximo_casillas = 45;
  map<int,list<Pos>> historial;
  set<Pos> elevators;

  /*
  [0] Vas al ascensor
  [1] Siendo 'd' la distancia que hay hasta el ascensor más cercano y 'ds' la distancia que hay desde el jugador hasta el sol,
      en esta fase pues, se está siempre y cuando 2*d + 2 < ds
  [2] Esta es la fase en la que 2*d + 2 > ds y se trata en ir hacia el ascensor más cercano
  */
  map<int,vector<bool>> mision_gemas;
  map<int,int> rondas_restantes;

  /*int factor_casilla(Pos p) {
        Pos start = p;
        queue<Pos> q;
        set<Pos> visited;
        q.push(p);
        visited.insert(start);
        while (!q.empty()) {
            Pos actualpos = q.front();
            q.pop();
            for (int dir = Bottom; dir != Up; ++dir) {
                Pos siguientepos = actualpos + static_cast<Dir>(dir);
                if (pos_ok(siguientepos) && distancia(siguientepos, start) <= sqrt(13) && cell(siguientepos).type != Rock && visited.find(siguientepos) == visited.end()) {
                    visited.insert(siguientepos);
                    q.push(siguientepos);
                }
            
            }
        }
        return visited.size();
    }*/

  //funciones auxiliares:
    /*double evaluar_casilla(Pos p, double dist, int qt) {
		int casillas_adyacentes_libres = casillas_adyacentes_correctas(p);
        double factor_distancia = dist / dist_maxima;
		double no_enemigos = 1;
		if (casillas_adyacentes_libres != 0) no_enemigos = (casillas_adyacentes_libres - qt) / casillas_adyacentes_libres;
		return 0.60 * factor_distancia + 0.30 * factor_casilla(p)/factor_maximo_casillas;
  }*/

    int casillas_adyacentes_correctas(Pos p) {
        int casillas = 0;
        for (int dir = 0; dir != None; ++dir) {
        Pos aux = p + static_cast<Dir>(dir);
        if (pos_ok(aux) && cell(aux).type != Rock && cell(aux).id == -1) ++casillas;
        }
        return casillas;
    }

    bool hay_ascensor_alrededor(Pos actual, Pos& ascensor, Dir& direccion) {
        for (int i = 0; i < 8; ++i) {
            Pos mirando = actual + Dir(i);
            if (cell(mirando).type == Elevator) {
                ascensor = mirando;
                direccion = Dir(i);
                return true;
            }
        }
        return false;
    }

    //Pre: cierto
    //Post: devuelve cierto si la p y p2 son adyacentes
    bool es_adyacente(Pos p, Pos p2) {
        Pos aux;
        aux.i = abs(p.i - p2.i);
        aux.j = abs(p.j - p2.j);
        aux.k = abs(p.k - p2.k);
        return aux.i <= 1 && aux.j <= 1 && aux.k == 0;
    }

    double distancia(Pos p1, Pos p2) {
        return sqrt(pow(p1.i - p2.i, 2) + pow(p1.j - p2.j, 2));
    }

    bool hay_unidad_adyacente(Pos p, Dir& d) {
      for (int dir = 0; dir != None; ++dir) {
        Pos aux = p + static_cast<Dir>(dir);
        if (cell(aux).id != -1 && unit(cell(aux).id).player != me()) {
          d = static_cast<Dir>(dir);
          return true;
        }
      }
      return false;
    }

    bool hay_casilla_reclamada_adyacente(Pos p, Dir& d) { //FIXME: NECESARIA LA FUNCION???????
        d = None;
        for (int dir = 0; dir != None; ++dir) {
            Pos aux = p + static_cast<Dir>(dir);
            if (cell(aux).owner != -1 && cell(aux).owner != me() && cell(aux).id == -1) {
                if (cell(aux).owner == jugador_con_mas_casillas()) {
                    d = static_cast<Dir>(dir);
                    return true;
                }
                d = static_cast<Dir>(dir);
            }
        }
        return d != None ? true : false;
    }

    Dir find_nearest_claimed_cell(Pos start, bool tryhard) {
        queue<pair<Pos, vector<Dir>>> q;
        set<Pos> visited;
        q.push(make_pair(start, vector<Dir>()));

        while (!q.empty()) {
            pair<Pos, vector<Dir>> front = q.front();
            Pos currentPos = front.first;
            vector<Dir> path = front.second;
            q.pop();
            Cell currentCell = cell(currentPos);
            if (currentCell.owner != -1 && currentCell.owner != me() && currentCell.id == -1) {
                int aux;
                if (!tryhard) return path[0]; // Casilla reclamada encontrada, devolver camino
                else if (currentCell.owner == primer_jugador(aux)) return path[0];
                
            }
            for (int dir = Bottom; dir != DirSize; ++dir) {
                Pos nextPos = currentPos + static_cast<Dir>(dir);
                if (pos_ok(nextPos) && visited.find(nextPos) == visited.end() && cell(nextPos).type != Rock) {
                    vector<Dir> newPath = path;
                    visited.insert(nextPos);    
                    newPath.push_back(static_cast<Dir>(dir));
                    q.push(make_pair(nextPos, newPath));
                }
            }
        }

        return {}; // No se encontró ninguna casilla, devolver camino vacío
    }

    Dir huir_outside(int id, Unit u) {
        priority_queue<pair<int,Dir>> q;
        for (int dir = 0; dir != None; ++dir) {
            Dir d = static_cast<Dir>(dir);
            if (d == Left || d == LB || d == TL || d == Bottom || d == Top) continue;
            Pos posicion_mirando = unit(id).pos + d;
            double dist = distancia(posicion_mirando, u.pos);
            q.push({dist, d});
        }
        return q.top().second;
    }

    bool peligro_outside_necromongers(int id, Unit& u) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        vector<int> N = necromongers();
        for (int i : N) {
            double dist = distancia(unit(id).pos, unit(i).pos);
            q.push({dist, i});
        }
        if (q.top().first <= 5) {
            u = unit(q.top().second);
            return true;
        }
        else return false;
    }
   
    bool peligro_celda_pioneers(Pos p, Unit& u, int d, double dist1, double dist2, int& qt) {
        u.id = -100;
        qt = 0;
        vector<int> H = hellhounds();
        for (int i : H) {
            if (p.k == 1) break;
            if (i != d && distancia(p, unit(i).pos) <= dist1) {
                if (u.id == -100) u = unit(i);
                ++qt;
            }
        }

        for (int t = 0; t < 4 && t != me(); ++t) {
            vector<int> F = furyans(t);
            for (int i : F) {
                if (p.k != unit(i).pos.k) continue;
                if (i != d && distancia(p, unit(i).pos) <= dist2) { //hay que poner 4 por huevos
                    if (u.id == -100) u = unit(i);
                    u = unit(i);
                    ++qt;
                }
            }
        }
        return qt != 0;
    }

    bool peligro_celda_furyans(Pos p, Unit& u, int d, double dist1, double dist2, int& qt) {
        u.id = -100;
        qt = 0;
        vector<int> H = hellhounds();
        for (int i : H) {
            if (i != d && distancia(p, unit(i).pos) <= dist1) {
                if (u.id == -100) u = unit(i);
                ++qt;
            }
        }

        for (int t = 0; t < 4 && t != me(); ++t) {
            vector<int> F = furyans(t);
            for (int i : F) {
                if (i != d && distancia(p, unit(i).pos) <= dist2 && unit(i).health > unit(cell(p).id).health) { //hay que poner 4 por huevos
                    if (u.id == -100) u = unit(i);
                    u = unit(i);
                    ++qt;
                }
            }
        }
        return u.id != -100;
        }

    int jugador_con_mas_casillas() {
        int maximo = 0;
        int k = me();
        for (int i = 0; i < 4 && i != me(); ++i) {
            vector<int> P = pioneers(i);
            if (nb_cells(i) > maximo) {
                maximo = nb_cells(i);
                k = i;
            }
        }
        return k;
    }

    Dir encontrar_pioneer_enemigo_mas_cercano(int id, bool tryhard) {
        Pos start = unit(id).pos;
        queue<pair<Pos, vector<Dir>>> q;
        set<Pos> visited;
        q.push(make_pair(start, vector<Dir>()));

        while (!q.empty()) {
            pair<Pos, vector<Dir>> front = q.front();
            Pos currentPos = front.first;
            vector<Dir> path = front.second;
            q.pop();

            Cell c = cell(currentPos);
            if (c.id != -1) {
                Unit u = unit(c.id);
                if (!tryhard) {
                    if (u.type == Pioneer && u.player != me()) return path[0];  // Encontrado un Pioneer enemigo, devolver el camino
                    else if (u.type == Furyan && u.player != me() && u.health >= unit(id).health) return path[0]; 
                }
                else {
                    int aux;
                    if (u.type == Pioneer && u.player == primer_jugador(aux)) return path[0];
                    else if (u.type == Furyan && u.player == primer_jugador(aux) && u.health >= unit(id).health) return path[0];
                }
            }

            for (int dir = Bottom; dir != None; ++dir) {
                Pos nextPos = currentPos + static_cast<Dir>(dir);
                if (pos_ok(nextPos) && visited.find(nextPos) == visited.end() && cell(nextPos).type != Rock) {
                    vector<Dir> newPath = path;
                    visited.insert(nextPos);
                    newPath.push_back(static_cast<Dir>(dir));
                    q.push(make_pair(nextPos, newPath));
                }
            }
        }

        return {};  // No se encontró un Pioneer enemigo, devolver camino vacío
    }
    

    int distancia_del_sol(Pos p, int res) {
        if (daylight(p)) return res;
        else return distancia_del_sol(p + Left, res+1);        
    }

    //pre: actualpos es un ascensor
    bool vale_la_pena(Pos actualpos) {
        Pos ascensor;
        Pos arriba = actualpos;
        arriba.k = 1;
        //if (daylight(arriba)) return false;
        vector<Dir> path_to_ascensor = encontrar_ascensor_mas_cercano_outside(cell(actualpos).id, ascensor, arriba);
        return int(path_to_ascensor.size()) + 2 < distancia_del_sol(arriba, 0)/2;
    }

    Dir huir(Pos pioneerpos, Unit u) {
        if (cell(pioneerpos).type == Elevator && vale_la_pena(pioneerpos) && unit(cell(pioneerpos).id).type != Furyan) {
            vector<bool> v(3, false);
            v[1] = true;
            mision_gemas.insert({cell(pioneerpos).id, v});
            return Up;
        }
        Dir direccion_ascensor; Pos aux;
        if (hay_ascensor_alrededor(pioneerpos,aux,direccion_ascensor) && unit(cell(pioneerpos).id).type != Furyan) {
            aux = pioneerpos + direccion_ascensor;
            if (distancia(aux,u.pos) > sqrt(18)) {
                return direccion_ascensor;
            } 
        }
        priority_queue<pair<double, Dir>> q;
        q.push({-1, None});
        for (int dir = 0; dir != Up; ++dir) {
            Pos posicion_mirando = pioneerpos + static_cast<Dir>(dir);
            if (cell(posicion_mirando).type != Rock && pos_ok(posicion_mirando) && cell(posicion_mirando).id == -1) {
                //if (!historial[cell(pioneerpos).id].empty() && historial[cell(pioneerpos).id].back() == posicion_mirando) continue;
                q.push({distancia(posicion_mirando, u.pos), static_cast<Dir>(dir)});
            }   
        }

        return q.top().second;
    }

    bool unidad_que_ataca(Pos p) {
        Cell mirando = cell(p);
        if (mirando.id != -1) {
            vector<int> H = hellhounds();
            for (int i : H) {
                if (i == mirando.id) return true;
            }
            for (int p = 0; p < 4 && p != me(); ++p) {
                vector<int> F = furyans(p);
                for (int i : F) {
                    if (i == mirando.id) return true;
                }
            }
        }
        return false;

    }

    double distancia_necromonger_mas_cercano(Pos p) {
        int min_pos = cols() + rows();
        int dist = min_pos;
        for (int i : necromongers()) {
            dist = distancia(p, unit(i).pos);
            if (dist < min_pos) min_pos = dist;
        }
        return dist;
    }

    vector<Dir> encontrar_ascensor_mas_cercano(int id, Pos& ascensor) {
        Pos start = unit(id).pos;
        queue<pair<Pos, vector<Dir>>> q;
        set<Pos> visited;
        q.push(make_pair(start, vector<Dir>()));

        while (!q.empty()) {
            pair<Pos, vector<Dir>> front = q.front();
            Pos currentPos = front.first;
            vector<Dir> path = front.second;
            q.pop();
            Cell c = cell(currentPos);
            if (c.type == Elevator) {
                Pos auxpos = currentPos;
                auxpos.k = 1;
                if (!daylight(auxpos)) {
                    ascensor = currentPos;
                    return path;
                }
                /*if (!daylight(auxpos) && distancia_del_sol(auxpos, 0) > 2 && distancia_necromonger_mas_cercano(auxpos) > 4) {
                    ascensor = currentPos;
                    return path;
                } ANTERIOR VERSION FIXME:*/ 
            }

            for (int dir = Bottom; dir != DirSize; ++dir) {
                Pos nextPos = currentPos + static_cast<Dir>(dir);
                if (pos_ok(nextPos) && visited.find(nextPos) == visited.end() && cell(nextPos).type != Rock) {
                    vector<Dir> newPath = path;
                    visited.insert(nextPos);
                    newPath.push_back(static_cast<Dir>(dir));
                    q.push(make_pair(nextPos, newPath));
                }
            }
        }
        return {}; 
    }

    vector<Dir> encontrar_ascensor_mas_cercano_outside(int id, Pos& ascensor, Pos EsteNo) {
        Pos start = unit(id).pos;
        queue<pair<Pos, vector<Dir>>> q;
        set<Pos> visited;
        visited.insert(start);
        q.push(make_pair(start, vector<Dir>()));

        while (!q.empty()) {
            pair<Pos, vector<Dir>> front = q.front();
            Pos currentPos = front.first;
            vector<Dir> path = front.second;
            q.pop();
            Cell c = cell(currentPos);
            if (c.type == Elevator && currentPos != EsteNo) {
                ascensor = currentPos;
                return path;
            }

            for (int dir = Bottom; dir != DirSize && dir != Up && dir != Down; ++dir) {
                Pos nextPos = currentPos + static_cast<Dir>(dir);
                if (pos_ok(nextPos) && visited.find(nextPos) == visited.end() && !daylight(nextPos) && cell(nextPos).id == -1) {
                    vector<Dir> newPath = path;
                    visited.insert(nextPos);
                    newPath.push_back(static_cast<Dir>(dir));
                    q.push(make_pair(nextPos, newPath));
                }
            }
        }
        return {Down}; 
    }

    int pioneers_arriba(int& mios) {
        int total = 0;
        for (int p = 0; p < 4; ++p)  {
            vector<int> P = pioneers(p);
            for (int i : P) {
                if (unit(i).pos.k == 1) {
                    if (p == me()) ++ mios;
                    ++total;
                }
            }
        }
        return total;
    }

    vector<Dir> encontrar_gema_mas_cercana(Pos start, Pos& gema) {
        queue<pair<Pos, vector<Dir>>> q;
        set<Pos> visited;
        visited.insert(start);
        q.push(make_pair(start, vector<Dir>()));
        while (!q.empty()) {
            pair<Pos, vector<Dir>> front = q.front();
            Pos currentPos = front.first;
            vector<Dir> path = front.second;
            q.pop();
            if (int(path.size()) > 30) continue; // muy lejos

            Cell c = cell(currentPos);
            if (c.gem) {
                gema = currentPos;
                return path;
            }

            for (int dir = Bottom; dir != None && dir != Down; ++dir) {
                Pos nextPos = currentPos + static_cast<Dir>(dir);
                if (pos_ok(nextPos) && visited.find(nextPos) == visited.end() && cell(nextPos).id == -1) {
                    vector<Dir> newPath = path;
                    visited.insert(nextPos);
                    newPath.push_back(static_cast<Dir>(dir));
                    q.push(make_pair(nextPos, newPath));
                }
            }
        }

        return {Right};
    }

    void actualizar_lista() {
        auto it2 = rondas_restantes.begin();
        while (it2 != rondas_restantes.end()) {
            it2->second--;
            if (it2->second == 0) it2 = rondas_restantes.erase(it2);
            else ++it2;
        }   

        map<int,vector<bool>> aux = mision_gemas;
        for (int i : pioneers(me())) {
            auto it = aux.find(i);
            if (it != aux.end()) {
                aux.erase(it);
            }
        }
        auto it = aux.begin();
        while (it != aux.end()) {
            mision_gemas.erase(it->first);
            it = aux.erase(it);
        }
    }

    int primer_jugador(int& puntos) {
        int max_points = -1; int player = -1;
        for (int i = 0; i < 4; ++i) {
            if (nb_cells(i) + 30*nb_gems(i) > max_points) {
                max_points = nb_cells(i) + 30*nb_gems(i);
                player = i;
                puntos = max_points;
            }
        }
        return player;
    }

   virtual void play() {
    bool tryhard = false; int puntos;
    //if (round() > 50 && primer_jugador(puntos) != me() && abs(puntos - 30*nb_gems(me()) - nb_cells(me())) < 20) tryhard = true;
    vector<int> F = furyans(me());
    for (int id : F) {
        Unit yo = unit(id);
        Dir wtg = None;
        Unit u;
        int qt = 0;
        if (peligro_celda_furyans(yo.pos, u, -99, sqrt(32), sqrt(18), qt)) {
            wtg = huir(yo.pos, u);
            command(id, wtg);
            continue;
        }

        else if (hay_unidad_adyacente(yo.pos, wtg)) {
          command(id, wtg);
          continue;
        }
        else {
          wtg = encontrar_pioneer_enemigo_mas_cercano(id, tryhard);
          command(id, wtg);
    }
  }

    vector<int> P = pioneers(me());
    int mios = 0;
    actualizar_lista();
    for (int i = 0; i < int(P.size()) && (int(P.size()) > 23) &&
         int(mision_gemas.size()) < 4 && rondas_restantes.find(P[i]) == rondas_restantes.end(); ++i) {
        vector<bool> v(3,false);
        v[0] = true;
        mision_gemas.insert({P[i], v});
    }

    for (int id : P) {
        if (historial.find(id) == historial.end()) historial.insert({id, list<Pos>()});

        if (cell(unit(id).pos).type == Elevator) elevators.insert(unit(id).pos);
        Unit yo = unit(id);
        Dir wtg = None;
        Unit u;
        int qt = 0;
        if (peligro_celda_pioneers(yo.pos, u, -99, sqrt(32), sqrt(18), qt)) {
            command(id, huir(yo.pos,u));
            continue;
        }

        else if (mision_gemas.find(id) != mision_gemas.end()) {
            if (mision_gemas[id][0]) {
                if (cell(unit(id).pos).type == Elevator) {
                    mision_gemas[id][0] = false; mision_gemas[id][1] = true;
                    command(id, Up);
                }
                else {
                    Pos aux;
                    command(id, encontrar_ascensor_mas_cercano(id, aux)[0]);
                }
            }
        
            else if (mision_gemas[id][1] && unit(id).pos.k == 1) {
                Pos pos_ascensor, aux;
                aux = Pos(-1,-1,-1);
                vector<Dir> path_para_ascensor = encontrar_ascensor_mas_cercano_outside(id, pos_ascensor, aux);
                if (path_para_ascensor.empty()) path_para_ascensor.push_back(Down); // NECESARIO
                int rondas_para_que_el_sol_alcance_la_posicion = distancia_del_sol(pos_ascensor, 0) / 2;
                if ((int(path_para_ascensor.size()) + 2 ) >= rondas_para_que_el_sol_alcance_la_posicion) {
                    mision_gemas[id][1] = false; mision_gemas[id][2] = true;
                    command(id, path_para_ascensor[0]);
                }
                else {
                    Pos aux;
                    wtg = encontrar_gema_mas_cercana(unit(id).pos,aux)[0];
                    command(id, wtg);
                }

            }
            else {
                if (cell(unit(id).pos).type == Elevator) {
                    mision_gemas.erase(id);
                    rondas_restantes.insert({id, 10});
                    command(id, Down);
                }
                else {
                    Pos aux, aux2;
                    aux2 = Pos(-1,-1,-1);
                    vector<Dir> path_para_ascensor = encontrar_ascensor_mas_cercano_outside(id, aux, aux2);
                    command(id, path_para_ascensor[0]);
                }
            }
        }

        else if (hay_casilla_reclamada_adyacente(yo.pos, wtg)) {
            command(id, wtg);
            continue;
        }

        else {
            wtg = find_nearest_claimed_cell(yo.pos, tryhard);
            command(id, wtg);
        }
        historial[id].push_back(unit(id).pos);
    }
};

};
/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);

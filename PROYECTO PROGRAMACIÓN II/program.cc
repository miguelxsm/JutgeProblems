/** @mainpage Práctica PRO2: Simulacióin del rendimiento de procesadores interconectados
    @file program.cc
    @brief Programa principal para ejecutar instrucciones
*/

#include "Cluster.hh"
#include "AreaEspera.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

/** @brief La función escribe un mensaje de error según el error que se haya producido
    \pre <em>Cierto</em>
    \post Se ha escrito el mensaje de error en función de 'a' */

void errores(char a) {
    if (a == '1') cout << "error: prioridad con procesos" << endl;
    else if (a == '2') cout << "error: procesador con auxiliares" << endl;
    else if (a == '3') cout << "error: procesador con procesos" << endl;
    else if (a == '4') cout << "error: ya existe prioridad" << endl;
    else if (a == '5') cout << "error: no existe prioridad" << endl;
    else if (a == '6') cout << "error: ya existe proceso" << endl;
    else if (a == '7') cout << "error: no existe procesador" << endl;
    else if (a == '8') cout << "error: no cabe proceso" << endl;
    else if (a == '9') cout << "error: no existe proceso" << endl;
}
/** @brief Función principal en la que se tratan todas las instrucciones */

int main() {
    Cluster c;
    AreaEspera ae;
    c.lee_cluster();
    ae.lee_area_espera();
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {
            cout << '#' << comando << endl;
            c.lee_cluster();
        }

        else if (comando == "modificar_cluster" or comando == "mc") {
            string id; cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            Cluster c2;
            c2.lee_cluster();
            int error = c.modificar_procesador_cluster(c2, id);
            if (error == -1) errores('7');
            else if (error == -2) errores('3');
            else if (error == -3) errores('2');
        } 

        else if (comando == "alta_prioridad" or comando == "ap") {
            string id;
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            int error = ae.anadir_prioridad(id);
            if (error == -1) errores('4');
        }

        else if (comando == "baja_prioridad" or comando == "bp") {            
            string id;
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            int error = ae.eliminar_prioridad(id);
            if (error == -1) errores('5');
            else if (error == -2) errores('1');
        }

        else if (comando == "alta_proceso_espera" or comando == "ape") {
            string id;
            cin >> id;
            Proceso p;
            cout << '#' << comando << ' ' << id << ' ';
            p.leer_proceso(); 
            int error = ae.anadir_proceso_en_prioridad(id, p);
            if (error == -2) errores('5');
            else if (error == -1) errores('6');
        }

        else if (comando == "alta_proceso_procesador" or comando == "app") {
            string id; 
            cin >> id;
            cout << '#' << comando << ' ' << id << ' ';
            Proceso proc;
            proc.leer_proceso();
            int error = c.alta_proceso_procesador(id, proc);
            if (error == -1) errores('7');
            else if (error == -2) errores('6');
            else if (error == -3) errores('8');
        }

        else if (comando == "baja_proceso_procesador" or comando == "bpp") {
                string id_p;
                cin >> id_p;
                int id_proc;
                cin >> id_proc;
                cout << '#' << comando << ' ' << id_p << ' ' << id_proc << endl;
                int error = c.baja_proceso_procesador(id_p, id_proc);
                if (error == -1) errores('7');
                else if (error == -2) errores('9');
        }

        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            int n;
            cin >> n;
            cout << '#' << comando << ' ' << n << endl;
            ae.enviar_procesos_cluster(n,c);
        }

        else if (comando == "avanzar_tiempo" or comando == "at") {
            int t;
            cin >> t;
            cout << '#' << comando << ' ' << t << endl;
            c.avanzar_tiempo(t);
        }

        else if (comando == "imprimir_prioridad" or comando == "ipri") {
            string id;
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            int error = ae.escribe_area_espera(id);
            if (error == -1) errores('5');
        }

        else if (comando == "imprimir_area_espera" or comando == "iae") {
            cout << '#' << comando << endl;
            int aux = ae.escribe_area_espera("-");
            if (aux == -1) cout << "";
        }

        else if (comando == "imprimir_procesador" or comando == "ipro") {
            string id; 
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            int error = c.imprimir_procesador(id);
            if (error == -1) errores('7');
        }

        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {
            cout << '#' << comando << endl;
            c.escribe_cluster();
        }

        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {
            cout << '#' << comando << endl;
            c.escribe_cluster_arbol();
        }

        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {
            string id; 
            cin >> id;
            cout << '#' << comando << ' ' << id << endl;
            int error = c.compactar_memoria_procesador(id);
            if (error == -1) errores('7');
        }

        else if (comando == "compactar_memoria_cluster" or comando == "cmc") { //else {}
        cout << '#' << comando << endl;
        int error = c.compactar_memoria_procesador("-");
        if (error == -1) return 0;
        }
        cin >> comando;
    }
}
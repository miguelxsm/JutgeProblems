OPCIONS = -std=c++11
OPCIONS1 = -std=c++11 -D_GLIBCXX_DEBUG
OPCIONS2 = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Proceso.o Procesador.o Cluster.o Prioridad.o AreaEspera.o
	g++ -o program.exe program.o Proceso.o Procesador.o Cluster.o Prioridad.o AreaEspera.o

Proceso.o:  Proceso.cc Proceso.hh
	g++ -c Proceso.cc $(OPCIONS2)

Procesador.o:  Procesador.cc Procesador.hh
	g++ -c Procesador.cc $(OPCIONS2)

Cluster.o:  Cluster.cc Cluster.hh
	g++ -c Cluster.cc $(OPCIONS2)

Prioridad.o:  Prioridad.cc Prioridad.hh
	g++ -c Prioridad.cc $(OPCIONS2)

AreaEspera.o: AreaEspera.cc AreaEspera.hh
	g++ -c AreaEspera.cc $(OPCIONS2)

program.o: program.cc
	g++ -c program.cc $(OPCIONS2)

clean:
	rm *.o
	rm *.exe

OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Especie.o Poblacion.o Individuo.o
	g++ -o program.exe *.o 

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS) 

Poblacion.o: Poblacion.cc Poblacion.hh Individuo.hh Especie.hh
	g++ -c Poblacion.cc $(OPCIONS) 

Individuo.o: Individuo.cc Individuo.hh Especie.hh
	g++ -c Individuo.cc $(OPCIONS) 

program.o: program.cc Especie.hh Poblacion.hh Individuo.hh
	g++ -c program.cc $(OPCIONS) 

clean:
	rm *.o
	rm *.exe

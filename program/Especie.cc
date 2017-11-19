/** @file Especie.cc
    @brief Codigo de la clase Especie
*/

#include "Especie.hh"

using namespace std;

Especie::Especie() 
{
  // Inicializa una especie con todos sus valores a 0
	N = 0;
	l0 = 0;
	lx = 0;
	ly = 0;
}

int Especie::consultar_l0() {
	return l0;
}

int Especie::consultar_lx() {
	return lx;
}

int Especie::consultar_ly() {
	return ly;
}

int Especie::consultar_N() {
	return N;
}

vector<int> Especie::consultar_ln() {
	return ln;
}

void Especie::leer() {
    // Leemos los datos del p.i.
    
	cin >> N >> l0;
	int i=0;
	ln = vector<int> (N);
	while (i < N) {
		cin >> ln[i];
		++i;
	}
	cin >> lx >> ly;
}

/** @file Individuo.cc
    @brief Codigo de la clase Individuo
*/

#include "Individuo.hh"

Individuo::Individuo() 
{
  // Inicializa un individuo
	nombre.clear();
	madre.clear();
	padre.clear();
}

void Individuo::modificar_nombre(string& s) {
	nombre = s;
}

void Individuo::modificar_crom_s(pair<vector<int>, vector<int> > p) {
	crom_s = p;
}

void Individuo::modificar_crom_n(vector<pair<vector<int>, vector<int> > > v) {
	crom_n = v;
}

void Individuo::modificar_madre(string& s) {
	madre = s;
}

void Individuo::modificar_padre(string& s) {
	padre = s;
}

void Individuo::modificar_xy(char& c) {
	xy = c;
}

string Individuo::consultar_nombre() {
	return nombre;
}

string Individuo::consultar_madre() {
	return madre;
}

string Individuo::consultar_padre() {
	return padre;
}

char Individuo::consultar_crom_sex() {
	return xy;
}

pair<vector<int>, vector<int> > Individuo::consultar_par_crom_sex() {
	return crom_s;
}

vector<pair<vector<int>, vector<int> > > Individuo::consultar_pares_crom_n() {
	return crom_n;
}

void Individuo::leer(Especie& e) {
    // Leemos un individuo que lo dimensionaremos a partir de los datos de e
    
	cin >> nombre >> xy;
	if (xy == 'X') { // Leemos vector cromosomas sexuales XX
		crom_s = make_pair(vector<int> (e.consultar_lx()), vector<int> (e.consultar_lx()));
		vector<int> aux1 (e.consultar_lx());
		vector<int> aux2 (e.consultar_lx());
		for (int i=0; i < e.consultar_lx(); ++i) {
			cin >> aux1[i];
		}
		for (int i=0; i < e.consultar_lx(); ++i) {
			cin >> aux2[i];
		}
		crom_s = make_pair(aux1, aux2);
	}
	else { // Leemos vector cromosomas sexuales XY
		crom_s = make_pair(vector<int> (e.consultar_lx()), vector<int> (e.consultar_ly()));
		vector<int> aux1 (e.consultar_lx());
		vector<int> aux2 (e.consultar_ly());
		for (int i=0; i < e.consultar_lx(); ++i) {
			cin >> aux1[i];
		}
		for (int i=0; i < e.consultar_ly(); ++i) {
			cin >> aux2[i];
		}
		crom_s = make_pair(aux1, aux2);	
	}
	crom_n = vector<pair<vector<int>, vector<int> > > (e.consultar_N());
	vector<int> v = e.consultar_ln();
	for (int i=0; i < v.size(); ++i) { // Leemos vector cromosomas normales
		int longitud = v[i];
		crom_n[i] = make_pair(vector<int> (longitud), vector<int> (longitud));
		vector<int> aux1 (longitud);
		vector<int> aux2 (longitud);
		for (int j=0; j < longitud; ++j) {
			cin >> aux1[j];
		}
		for (int j=0; j < longitud; ++j) {
			cin >> aux2[j];
		}
		crom_n[i] = make_pair(aux1, aux2);
	}
	
}

void Individuo::escribir_genotipo(Especie& e) {
    // Escribimos el genotipo del p.i.
    
	pair<vector<int>, vector<int> > p = crom_s;
	vector<int> aux1 = p.first;
	vector<int> aux2 = p.second;
	cout << "  X:";  // Primer cromosoma sexual (siempre es X)
	for (int j=0; j < e.consultar_lx(); ++j) {
		cout << " " << aux1[j];
	}
	cout << endl;
	char c = consultar_crom_sex(); // Segundo cromosoma sexual (X o Y)
	if (c == 'X') { // Si es X
		cout << "  X:";
		for (int j=0; j < e.consultar_lx(); ++j) {
			cout << " " << aux2[j];
		}
		cout << endl;
	}
	else { // Si es Y
		cout << "  Y:";
		for (int j=0; j < e.consultar_ly(); ++j) {
			cout << " " << aux2[j];
		}
		cout << endl;
	}
	vector<pair<vector<int>, vector<int> > > v = crom_n; // Cromosomas no sexuales
	for (int j=0; j < v.size(); ++j) { // Para cada par de cromosomas
		pair<vector<int>, vector<int> > p = v[j];
		vector<int> aux1 = p.first;
		vector<int> aux2 = p.second;
		cout << "  " << j+1 << ".1:";
		for (int k=0; k < aux1.size(); ++k) { // Cromosoma (j+1).1
			cout << " " << aux1[k];
		}
		cout << endl;
		cout << "  " << j+1 << ".2:";
		for (int k=0; k < aux2.size(); ++k) { // Cromosoma (j+1).2
			cout << " " << aux2[k];
		}
		cout << endl;
	}
}

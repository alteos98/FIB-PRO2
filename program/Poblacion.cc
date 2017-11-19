/** @file Poblacion.cc
    @brief Codigo de la clase Poblacion
*/

#include "Poblacion.hh"

using namespace std;

Poblacion::Poblacion() 
{
  // Inicializa una poblacion formada por un map, con el nombre del individuo como first y el individuo como second
    
}

map<string, Individuo> Poblacion::consultar_poblacion() {
    // Devuelve el conjunto de la poblacion completo
    
	return m_ind;
}

Individuo Poblacion::consultar_individuo(string s) {
    // Devuelve el individuo pedido a partir del campo del nombre
    
	return m_ind.find(s)->second;
}

void Poblacion::anadir_individuo(Individuo& i) {
    // Añadimos un individuo a la poblacion
    
	string s = i.consultar_nombre();
	m_ind[s] = i;
}

bool Poblacion::existe(string s) {
    // Comprueba si un indiviudo existe en la poblacion dado su nombre
    
	map<string, Individuo>::iterator it = m_ind.find(s);
	if (it != m_ind.end()) return true;
	else return false;
}

void Poblacion::escribir_poblacion() {
    // Sacamos todos los individuos que forman el p.i.
    
	map<string, Individuo> m = consultar_poblacion();
	for (map<string, Individuo>::iterator it = m.begin(); it != m.end(); it++) {
		Individuo i = it->second;
		string s1 = i.consultar_padre();
		string s2 = i.consultar_madre();
		cout << "  " << i.consultar_nombre() << " X" << i.consultar_crom_sex() << " " << "(";
		if (s1.empty()) { // si no tiene madre, entonces tampoco tiene padre
			cout << "$,$)" << endl;
		}
		else {
			cout << s1 << "," << s2 << ")" << endl;
		}
	}
}

void Poblacion::crear_arbol(Arbre<string>& a, Individuo& i) {
    // Creamos el arbol de un individuo a partir de los datos que tenemos registrados
    
	string n_hijo = i.consultar_nombre();
	string n_padre = i.consultar_padre();
	string n_madre = i.consultar_madre();
	Arbre<string> ap, am;
	if (not n_padre.empty()) { // Mientras el individuo tenga padres, hemos de volver a llamar recursivamente dos veces, una para la madre y otra para el padre
		Individuo i_padre = consultar_individuo(n_padre);
		crear_arbol(ap, i_padre);
		Individuo i_madre = consultar_individuo(n_madre);
		crear_arbol(am, i_madre);
	}
	a.plantar(n_hijo, ap, am);
}

bool Poblacion::encontrado_arbol(Arbre<string>& a, string& s) {
    // Es para ver si esta un individuo de nombre s en a
    
	bool b;
	if (a.es_buit()) b=false;
	else if (a.arrel() == s) b=true;
		else{
			Arbre<string> a1;
			Arbre<string> a2;
			a.fills(a1,a2);
			b = encontrado_arbol(a1,s);
			if (not b) b = encontrado_arbol(a2,s);
		}
	return b;
}

Individuo Poblacion::reproduccion_sexual(Especie& e, Individuo& i1, Individuo& i2, string hijo) {
    // Ya se ha comprobado previamente que i1 e i2 se puedan reproducir
    
	Individuo i;
	int n = e.consultar_N();
	int par1, par2, p_corte;

	cin >> par1 >> par2 >> p_corte; // Par sexual
	int l0 = e.consultar_l0();
	pair<vector<int>, vector<int> > p1 = i1.consultar_par_crom_sex();
	pair<vector<int>, vector<int> > p2 = i2.consultar_par_crom_sex();
	vector<int> v_p1; // Cromosoma escogido de i1
	vector<int> v_p2; // Cromosoma escogido de i2
	vector<int> v_i_par_s1 (e.consultar_lx()); // Cromosoma resultante 1
	vector<int> v_i_par_s2 (e.consultar_ly()); // Cromosoma resultante 2
	if (par1 == 0) {
		v_p1 = p1.first;
	}
	else {
		v_p1 = p1.second;
	}
	if (par2 == 0) {
		v_p2 = p2.first;
		v_i_par_s2.resize(e.consultar_lx());
		char c1 = i1.consultar_crom_sex();
		i.modificar_xy(c1);
	}
	else {
		v_p2 = p2.second;
		char c2 = i2.consultar_crom_sex();
		i.modificar_xy(c2);
	}
	// En v_p1 tengo el cromosoma de i1 que necesito y en v_p2 el de i2
	for (int j=0; j < p_corte; ++j) { // De 0 a punto de corte
		v_i_par_s1[j] = v_p1[j];
	}
	for (int j=p_corte; j < l0; ++j) { // De punto de corte a l0
		v_i_par_s1[j] = v_p2[j];
	}
	for (int j=l0; j < v_i_par_s1.size(); ++j) { // De l0 a v.size()-1
		v_i_par_s1[j] = v_p1[j];
	}
	for (int j=0; j < p_corte; ++j) { // De 0 a punto de corte
		v_i_par_s2[j] = v_p2[j];
	}
	for (int j=p_corte; j < l0; ++j) { // De punto de corte a l0
		v_i_par_s2[j] = v_p1[j];
	}
	for (int j=l0; j < v_i_par_s2.size(); ++j) { // De l0 a v.size()-1
		v_i_par_s2[j] = v_p2[j];
	}
	i.modificar_crom_s(make_pair(v_i_par_s1, v_i_par_s2));
    
	// No sexuales
	vector<pair<vector<int>, vector<int> > > v (n);
	vector<pair<vector<int>, vector<int> > > v1 = i1.consultar_pares_crom_n();
	vector<pair<vector<int>, vector<int> > > v2 = i2.consultar_pares_crom_n();
	vector<int> v_i1;
	vector<int> v_i2;
	for (int j=0; j < n; ++j) {
		cin >> par1 >> par2 >> p_corte;
		if (par1 == 0) {
			v_i1 = v1[j].first;
		}
		else {
			v_i1 = v1[j].second;
		}
		if (par2 == 0) {
			v_i2 = v2[j].first;
		}
		else {
			v_i2 = v2[j].second;
		}
		vector<int> v_i_par1 (v_i1.size());
		vector<int> v_i_par2 (v_i2.size());
		for (int k=0; k < p_corte; ++k) { // Rellenar v_i_par1 desde 0 hasta el punto de corte
			v_i_par1[k] = v_i1[k];
		}
		for (int k=p_corte; k < v_i_par1.size(); ++k) { // Rellenar v_i_par1 desde (punto de corte + 1) hasta el final
			v_i_par1[k] = v_i2[k];
		}
		for (int k=0; k < p_corte; ++k) { // Rellenar v_i_par2 hasta el punto de corte
			v_i_par2[k] = v_i2[k];
		}
		for (int k=p_corte; k < v_i_par2.size(); ++k) { // Rellenar v_i_par2 desde (punto de corte + 1) hasta el final
			v_i_par2[k] = v_i1[k];
		}
		v[j] = make_pair(v_i_par1, v_i_par2);
	}
	i.modificar_crom_n(v);
	i.modificar_nombre(hijo);
	string nombre_madre = i1.consultar_nombre();
	string nombre_padre = i2.consultar_nombre();
	i.modificar_madre(nombre_madre);
	i.modificar_padre(nombre_padre);
	return i;
}

bool Poblacion::comprobar_reproduccion(Individuo madre, Individuo padre) {
    // Comprobamos todos los casos en los cuales no podrian reproducirse los dos individuos
    
	if (madre.consultar_crom_sex() == 'X' and padre.consultar_crom_sex() == 'Y') { // Primero, la madre tiene que tener de segundo cromosoma, X, y el padre, Y
		string madre_i1 = madre.consultar_madre();
		string madre_i2 = padre.consultar_madre();
		string padre_i1 = madre.consultar_padre();
		string padre_i2 = padre.consultar_padre();
		if (madre_i1.empty() and madre_i2.empty()) { // Si ninguno tiene padres ya no pueden ser antecesores
			return true;
		}
		else { // Creamos el árbol de cada individuo y vemos que ninguno esta en el del otro
			Arbre<string> a_madre;
			Arbre<string> a_padre;
			crear_arbol(a_madre, madre);
			crear_arbol(a_padre, padre);
			string n_madre = madre.consultar_nombre();
			string n_padre = padre.consultar_nombre();
			if ((madre_i1 != madre_i2) and (padre_i1 != padre_i2) and not encontrado_arbol(a_padre, n_madre) and not encontrado_arbol(a_madre, n_padre)) {
				return true;	
			}
			else return false;
		}
	}
	else return false;
}

void Poblacion::completar_arbol(list<string>& l, Arbre<string>& a) {
    // Añadimos a l los nombres de los individuos de a en preorden con los asteriscos, que simbolizan que no estaban en el arbol parcial
    
	if (a.es_buit()) { // Si a es vacio insertamos $
		l.insert(l.end(), "$");
	}
	else { // Si no lo es, insertamos a la lista el nombre correspondiente pero con dos asteriscos
		string raiz = a.arrel();
		raiz = "*" + raiz + "*";
		l.insert(l.end(), raiz);
		Arbre<string> a1, a2;
		a.fills(a1, a2);
		completar_arbol(l, a1); // Llamamos recursivamente hasta que a sea vacio
		completar_arbol(l, a2);
	}
}

void Poblacion::escribir_arbol_genealogico(Individuo& i) {
    // Escribimos el arbol genealogico de i por niveles
    
	string s = i.consultar_nombre();
	queue <string> q;
	q.push(s);
	int faltan = 0;
	double n = 0, contador_nivel = 0, aux = 0;
	cout << "  Nivel 0:";
	while (!q.empty()) { // Mientras la cola no este vacia entramos
		Individuo i_aux = consultar_individuo(q.front());
		string s1 = i_aux.consultar_padre(); // Consultar padre
		string s2 = i_aux.consultar_madre(); // Consultar madre
		if (!s1.empty()) { // Si tiene padres los añadimos a la cola
			q.push(s1);
			q.push(s2);
		}
		else { // Si no tienen sumamos uno al contador de ascendientes que faltan
            faltan += 1;
        }
		cout << " " << q.front();
		q.pop();
		++n;
		if (n + aux == pow(2, contador_nivel)) { // Si la suma de individuos de este nivel con los que faltan*2 es igual a 2^(contador_nivel) entonces quiere decir que hemos de cambiar de nivel
            n = 0; // Reiniciamos el contador de individuos
            aux = faltan * 2; // Multiplicamos los inidividuos que faltan por 2, esto lo hacemos porque por cada individuo que falta, en el siguiente nivel faltaran el doble, referentes a los respectivos padre y madre de ese individuo
            faltan = aux;
			++contador_nivel;
			cout << endl;
			if (!q.empty()) { // Si la cola no es vacía cambiamos de nivel
				cout << "  Nivel " << contador_nivel << ":";
			}
		}
	}
}

bool Poblacion::es_parcial(list<string>& l, Arbre<string>& a_parcial, Arbre<string>& a_individuo) {
    // Comprueba que a_parcial sea arbol parcial de a_individuo y lo coloca en una lista ya con los nombres modificados entre asteriscos
    
	if(a_parcial.es_buit() and a_individuo.es_buit()) { // los dos son vacios
		l.insert(l.end(), "$"); // Insertamos $ porque coinciden los dos y ademas son vacios
		return true; // Devolvemos true ya que por el momento es a_parcial es arbol parcial de a_individuo
	}
	else {
		if(a_parcial.es_buit() and not a_individuo.es_buit()) { // a_parcial vacio pero a_individuo no
			completar_arbol(l, a_individuo); // Mandamos la lista y a_individuo a la funcion completar_arbol para rellenar la lista con los individuos que faltaban en a_parcial
			return true; // Devolvemos true ya que por el momento es a_parcial es arbol parcial de a_individuo
		}
		else {
			if(not a_parcial.es_buit() and a_individuo.es_buit()) { // a_parcial no vacio pero a_individuo si
				return false; // Devolvemos false ya que a_parcial ya no es arbol parcial de a_individuo
			}
			else {
				string raiz_parcial = a_parcial.arrel();
				string raiz_individuo = a_individuo.arrel();
				if(raiz_parcial == raiz_individuo) { // Si las raices de los dos arboles coinciden entonces la insertamos en la lista y llamamos recursivamente a es_parcial
					Arbre<string> a_parcial1, a_parcial2, a_individuo1, a_individuo2;
					l.insert(l.end(), raiz_individuo);
					a_parcial.fills(a_parcial1, a_parcial2);
					a_individuo.fills(a_individuo1,a_individuo2);
					return es_parcial(l, a_parcial1, a_individuo1) and es_parcial(l, a_parcial2, a_individuo2);
				}	
				else return false;
			}	
		}
	}
}

void Poblacion::escribir_lista(list<string>& l) {
    // Escribimos por el canal estandar de salida una escribir_lista
    // Esta lista contiene el arbol completo y modificado para que los individuos que no estaban anteriormente aparezcan entre asteriscos
    // Contiene el arbol en preorden
    
    cout << " ";
	for (list<string>::const_iterator it = l.begin(); it != l.end(); ++it) {
		cout << " " << *it;
	}
	cout << endl;
}

void Poblacion::leer_arbol(Arbre<string>& a, string s) {
    // Leemos un arbol por el canal estandar de entrada
    
	if (s != "$") {
    	Arbre<string> fe, fd;
    	string s1, s2;
  		cin >> s1;
    	leer_arbol(fe, s1);
    	cin >> s2;
    	leer_arbol(fd, s2);
    	a.plantar(s,fe,fd); 
  	}
}

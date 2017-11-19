/**
 * @mainpage Practica de PRO2: Experimentos geneticos en laboratorio
 
En este main tenemos un menu de opciones para gestionar individuos. Se introducen las clases <em>Individuo</em>, <em>Poblacion</em> y <em>Especie</em>.
*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Experimentos geneticos en laboratorio</em>.
*/

#include "Individuo.hh"
#include "Poblacion.hh"
#include "Especie.hh"

#ifndef NO_DIAGRAM // son las estandar
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Arbre.hh"
#endif

using namespace std;

/** @brief Programa principal para el ejercicio <em>Experimentos geneticos en laboratorio</em>.
*/
int main ()
{
    Especie e;
    e.leer();
    Poblacion p;
    int numero_inicial;
    cin >> numero_inicial;
    for (int j=0; j<numero_inicial; ++j) { //lees los individuos iniciales
        Individuo i;
        i.leer(e);
        p.anadir_individuo(i);
    }
    string orden;
    cin >> orden;
    while (orden != "acabar") { //mientras no sea acabar, hacemos la accion que se nos pida
        if (orden == "anadir_individuo") {
            Individuo i;
            i.leer(e);
            string nombre = i.consultar_nombre();
            cout << "anadir_individuo " << nombre << endl;
            bool e = p.existe(nombre);
            if (not e) {
            	p.anadir_individuo(i);
			}
            else {
            	cout << "  error" << endl;
			}
        }
        else if (orden == "reproduccion_sexual") {
            string n_madre, n_padre, hijo;
            cin >> n_madre >> n_padre >> hijo;
            cout << "reproduccion_sexual " << n_madre << " " << n_padre << " " << hijo << endl;
            if (p.existe(n_madre) and p.existe(n_padre) and not p.existe(hijo)) {
            	Individuo i1 = p.consultar_individuo(n_madre);
            	Individuo i2 = p.consultar_individuo(n_padre);
            	if (p.comprobar_reproduccion(i1, i2)) {
            		Individuo i3 = p.reproduccion_sexual(e, i1, i2, hijo);
            		p.anadir_individuo(i3);
				}
				else {
					cout << "  no es posible reproduccion" << endl;
				}
			}
			else cout << "  error" << endl;
        }
        else if (orden == "escribir_arbol_genealogico") {
            string nombre_individuo;
            cin >> nombre_individuo;
            cout << "escribir_arbol_genealogico " << nombre_individuo << endl;
            if (p.existe(nombre_individuo)) {
            	Individuo i_arbol = p.consultar_individuo(nombre_individuo);
            	p.escribir_arbol_genealogico(i_arbol);
			}
			else {
				cout << "  error" << endl;
			}
        }
        else if (orden == "completar_arbol_genealogico") {
            Arbre<string> a_individuo, a_parcial;
            string n_individuo;
            cin >> n_individuo;
            cout << "completar_arbol_genealogico " << n_individuo << endl;
            if (p.existe(n_individuo)) {
            	Individuo i_aux = p.consultar_individuo(n_individuo);
            	p.leer_arbol(a_parcial, n_individuo);
            	p.crear_arbol(a_individuo, i_aux);
            	list<string> l;
            	if (p.es_parcial(l, a_parcial, a_individuo)) {
            		p.escribir_lista(l);
				}
				else cout << "  no es arbol parcial" << endl;
			}
			else {
				cout << "  no es arbol parcial" << endl;
			}
        }
        else if (orden == "escribir_poblacion") {
            cout << "escribir_poblacion" << endl;
            p.escribir_poblacion();
        }
        else if (orden == "escribir_genotipo") {
            string nombre_individuo;
            cin >> nombre_individuo;
            cout << "escribir_genotipo " << nombre_individuo << endl;
            if (p.existe(nombre_individuo)) {
            	Individuo i = p.consultar_individuo(nombre_individuo);
            	i.escribir_genotipo(e);
			}
			else {
				cout << "  error" << endl;
			}
    	}
    	cin >> orden;
    }
    cout << "acabar" << endl;
}

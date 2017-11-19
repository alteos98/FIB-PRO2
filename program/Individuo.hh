/** @file Individuo.hh
    @brief Especificacion de la clase Individuo
*/


#ifndef _INDIVIDUO_HH_
#define _INDIVIDUO_HH_

#include "Especie.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include "Arbre.hh"
#endif

/** @class Individuo
    @brief Representa un individuo

    Todas las operaciones son de <b>coste constante</b>
*/
class Individuo
{

private:
	/** @brief  Nombre del individuo */
	string nombre;
	/** @brief  Nombre de la madre */
	string madre;
	/** @brief  Nombre del padre */
	string padre;
	/** @brief  Valor del segundo cromosoma sexual */
	char xy;
	/** @brief  Cromosomas sexuales */
	pair<vector<int>, vector<int> > crom_s;
	/** @brief  Cromosomas no sexuales */
	vector<pair<vector<int>, vector<int> > > crom_n;

public:
  //Constructoras 

  /** @brief Crea un individuo

      \pre <em>cierto</em>
      \post El resultado es un individuo vacio
  */   
  Individuo();
  
  //Modificadoras
  
  /** @brief Modifica el nombre de un individuo

      \pre <em>cierto</em>
      \post Se ha actualizado el nombre del individuo
  */
	void modificar_nombre(string& s);
  
  /** @brief Modifica los cromosomas sexuales de un individuo

      \pre <em>cierto</em>
      \post Se han actualizado los cromosomas sexuales del individuo
  */
	void modificar_crom_s(pair<vector<int>, vector<int> > p);
  
  /** @brief Modifica los cromosomas no sexuales de un individuo

      \pre <em>cierto</em>
      \post Se han actualizado los cromosomas no sexuales del individuo
  */
	void modificar_crom_n(vector<pair<vector<int>, vector<int> > > v);
	
	/** @brief Modifica la madre de un individuo

      \pre <em>cierto</em>
      \post Se ha actualizado la madre del individuo
  */
	void modificar_madre(string& s);
	
	/** @brief Modifica el padre de un individuo

      \pre <em>cierto</em>
      \post Se ha actualizado el padre del individuo
  */
	void modificar_padre(string& s);
	
	/** @brief Modifica el segundo cromosoma sexual (si es X o Y) de un individuo

      \pre <em>cierto</em>
      \post Se ha actualizado el carácter del segundo cromosoma sexual del individuo
  */
	void modificar_xy(char& c);
  
  //Consultoras
  
	/** @brief Consultar el nombre del individuo

      \pre <em>cierto</em>
      \post Devuelve el nombre del individuo
  */
	string consultar_nombre();

	/** @brief Consultar el nombre de la madre

      \pre <em>cierto</em>
      \post Devuelve el nombre de la madre
  */
	string consultar_madre();

	/** @brief Consultar el nombre del padre

      \pre <em>cierto</em>
      \post Devuelve el nombre del padre
  */
	string consultar_padre();

	/** @brief Consultar el segundo cromosoma sexual

      \pre <em>cierto</em>
      \post Devuelve si el segundo cromosoma sexual del individuo es X o Y
  */
	char consultar_crom_sex();
	
	/** @brief Consultar el par de cromosomas sexuales

      \pre <em>cierto</em>
      \post Devuelve los genes del par de cromosomas sexuales
  */
	pair<vector<int>, vector<int> > consultar_par_crom_sex();
	
	/** @brief Consultar todos los pares de cromosomas normales o no sexuales

      \pre <em>cierto</em>
      \post Devuelve los genes de todos los pares de cromosomas normales o no sexuales
  */
	vector<pair<vector<int>, vector<int> > > consultar_pares_crom_n();

  //Acciones

  /** @brief Lectura del individuo

      \pre <em>cierto</em>
      \post Se ha leido un indivduo con sus atributos
  */
  void leer(Especie& e);
  
  /** @brief Escribir genotipo

      \pre <em>cierto</em>
      \post Se ha escrito el genotipo del individuo por el canal estandar de salida
  */
  void escribir_genotipo(Especie& e);
};

#endif

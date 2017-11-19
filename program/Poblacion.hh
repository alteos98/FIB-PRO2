/** @file Poblacion.hh
    @brief Especificacion de la clase Poblacion
*/


#ifndef _POBLACION_HH_
#define _POBLACION_HH_

#include "Individuo.hh"
#include "Especie.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include "Arbre.hh"
#endif

/** @class Poblacion
    @brief Representa una poblacion, un conjunto de individuos

    Todas las operaciones son de <b>coste constante</b>
*/
class Poblacion
{

private:
	/** @brief Contiene a todos los individuos ordenados alfabeticamente */
	map<string,Individuo> m_ind;

public:
  //Constructoras
  
  /** @brief Crea una poblacion

      \pre <em>cierto</em>
      \post Se ha creado la poblacion
  */
  Poblacion();
    
  //Consultoras
  
  /** @brief Consultar el conjunto de la poblacion

      \pre Tiene que contener al menos un individuo
      \post Devuelve la agrupacion de individuos de una misma especie, o lo que es lo mismo, a la poblacion
  */
  map<string, Individuo> consultar_poblacion();
  
  /** @brief Devuelve al individuo pedido

      \pre El individuo tiene que existir
      \post Devuelve al individuo que hemos pedido
  */
  Individuo consultar_individuo(string nombre);

  //Acciones

  /** @brief Añadir individuo a la poblacion

      \pre <em>cierto</em>
      \post Se ha añadido el individuo a la poblacion
  */
  void anadir_individuo(Individuo& i);
  
  /** @brief Nos dice si existe ese individuo o no

      \pre <em>cierto</em>
      \post Devuelve cierto si existe y falso si no existe
  */
  bool existe(string s);

  /** @brief Escribir poblacion

      \pre <em>cierto</em>
      \post Se ha escrito la poblacion por el canal estandar de salida
  */
  void escribir_poblacion();
  
  /** @brief Crea el arbol genalogico de un individuo

      \pre <em>cierto</em>
      \post Se ha devuelto el arbol del individuo
  */
  void crear_arbol(Arbre<string>& a, Individuo& i);
  
  /** @brief Nos devuelve si el individuo esta en el arbol

      \pre <em>cierto</em>
      \post Cierto si lo encontramos, falso si no lo encontramos
  */
  bool encontrado_arbol(Arbre<string>& a, string& s);
  
  /** @brief Reproduccion sexual entre dos individuos

      \pre El supuesto nuevo individuo no puede existir. Los padres del nuevo individuo tienen que existir. Ademas, el primer individuo ha de tener cromosomas XX y el segundo XY. Tampoco pueden ser hermanos ni ser ascendientes el uno del otro
      \post Se ha creado un nuevo individuo a partir de otros dos
  */
  Individuo reproduccion_sexual(Especie& e, Individuo& i1, Individuo& i2, string hijo);

  /** @brief Comprobar si se pueden reproducir dos individuos

      \pre <em>cierto</em>
      \post Cierto si se pueden reproducir, falso si no pueden
  */
  bool comprobar_reproduccion(Individuo madre, Individuo padre);
  
  /** @brief Completar el árbol genealógico de un individuo

      \pre Se ha tenido que comprobar si el árbol es parcial previamente
      \post Se ha completado el árbol genealógico.
  */
  void completar_arbol(list<string>& l, Arbre<string>& a);
  
  /** @brief Escribir el arbol genealogico de un individuo

      \pre <em>cierto</em>
      \post Se ha escrito por el canal estandar de salida el arbol genealogico en preorden, si el individuo no existe, se escribe "error"
  */
  void escribir_arbol_genealogico(Individuo& i);
  
  /** @brief Nos dice si un arbol es arbol parcial de otro

      \pre <em>cierto</em>
      \post Cierto si el primer arbol es parcial del segundo, falso si no lo es
  */
  bool es_parcial(list<string>& l, Arbre<string>& a_parcial, Arbre<string>& a_individuo);
  
  /** @brief Escribe una lista

      \pre <em>cierto</em>
      \post Se ha escrito por el canal estandar de salida una lista
  */
  void escribir_lista(list<string>& l);
  
  /** @brief Lee un arbol

      \pre <em>cierto</em>
      \post Se ha leido un arbol en preorden por el canal estandar de entrada
  */
  void leer_arbol(Arbre<string>& a, string s);
};

#endif

/** @file Especie.hh
    @brief Especificacion de la clase Especie
*/


#ifndef _ESPECIE_HH_
#define _ESPECIE_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#endif

using namespace std;

/** @class Especie
    @brief Representa una especie, sus caracteristicas
    En esta clase guardaremos todos los parametros de la especie

    Todas las operaciones son de <b>coste constante</b>
*/
class Especie
{

private:

  /** @brief Numero de pares de cromosomas no sexuales */
  int N;
  /** @brief Numero de genes alineables de los cromosomas sexuales */
  int l0;
  /** @brief Longitudes de los pares de cromosomas no sexuales */
  vector<int> ln;
  /** @brief Longitud del cromosoma X */
  int lx;
  /** @brief Longitud del cromosoma Y */
  int ly;

public:
  //Constructoras
  
  /** @brief Crea una especie

      \pre <em>cierto</em>
      \post Se ha creado la especie
  */
  Especie();
  
  //Consultoras
  
  /** @brief Consulta el valor de genes alineables de los cromosomas sexuales

      \pre <em>cierto</em>
      \post Devuelve el valor de genes alineables de los cromosomas sexuales
  */
  int consultar_l0();
  
  /** @brief Consulta la longitud del cromosoma X

      \pre <em>cierto</em>
      \post Devuelve la longitud del cromosoma X de esta especie
  */
  int consultar_lx();
  
  /** @brief Consulta la longitud del cromosoma Y

      \pre <em>cierto</em>
      \post Devuelve la longitud del cromosoma Y de esta especie
  */
  int consultar_ly();
  
  /** @brief Consulta el numero de pares de cromosomas no sexuales

      \pre <em>cierto</em>
      \post Devuelve el numero de pares de cromosomas no sexuales de esta especie
  */
  int consultar_N();
  
  /** @brief Consulta las longitudes de los cromosomas no sexuales

      \pre <em>cierto</em>
      \post Devuelve las longitudes de los cromosomas no sexuales de esta especie
  */
  vector<int> consultar_ln();

  //Acciones

  /** @brief Leer caracteristicas de una especie

      \pre <em>cierto</em>
      \post Se han leido las caracteristicas de una espacie
  */
  void leer();
};

#endif

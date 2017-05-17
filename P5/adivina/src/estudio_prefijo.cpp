/*
 *
 *	José Fidel Ariza Álvarez <jfariza1997@correo.ugr.es>
 * 	Juan José Serrano Gutiérrez <juanjoguti@correo.ugr.es>
 *
 * -------------------------------------------------------
 *
 * 	Grado en Ingeniería Informática
 * 	ED - Estructura de Datos
 *
 * -------------------------------------------------------
 *
 * 	T.D.A. Refranes
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "refranes.h"

using namespace std;

int main(int argc, char * argv[]) {

	if ( (argc != 3) && (argc != 2) ) {

		cerr << "Los parametros son:" << endl;
		cerr << "1.Dime el nombre del fichero los refranes" << endl;
		cerr << "2.Dime el nombre del fichero csv" << endl;
		return -1;
  	}

	ofstream os(argv[2]);
	if ( !os ) {

		cerr << "No puedo abrir el fichero " << argv[2] << endl;
		return -1;
  	}

	for (int i = 2; i <= 14; ++i) {

		ifstream fin(argv[1]);

  		if ( !fin ) {

      		cerr << "No puedo abrir el fichero " << argv[1] << endl;
      		return -1;
  		}

		Refranes refs(i);
		fin >> refs;

		double Car_Total = refs.Caracteres_Refranes();
		double Car_Arb 	 = refs.Caracteres_Almacenados();
		double Red 		 = 100*(Car_Total - Car_Arb)/Car_Total;
		double Nodos 	 = refs.Numero_Nodos();
		double Red_Nodos = Red/Nodos;

		os << i << "; ";
		os << Car_Total << "; ";
		os << Car_Arb << "; ";
		os << Red << "; ";
		os << Nodos << "; ";
		os << Red_Nodos << "; ";
		os << endl;
	}
}

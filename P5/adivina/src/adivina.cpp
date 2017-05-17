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

string TodoMinuscula(const string &cad) {

	string caux;
	for (unsigned char i = 0; i < cad.size(); ++i) {

		caux.push_back(tolower(cad[i]));
	}
	return caux;
}

int adivina(const string &cad, string &cad_guiones, char c) {

	int contador = 0;
	for (unsigned i = 0; i < cad.size(); ++i) {

		if ( (cad[i] == c) && (cad_guiones[i] == '-') ) {
			cad_guiones[i] = c;
			contador++;
		}
	}
	return contador;
}

bool victoria(const string &cad, const string &cad_guiones) {

	if ( cad == cad_guiones ) {

		return true;

	} else {

		return false;
	}
}

int main(int argc, char * argv[]) {

	if ( (argc != 3) && (argc != 2) ) {

  		cerr << "Los parametros son:" << endl;
      	cerr << "1.Dime el nombre del fichero los refranes" << endl;
      	cerr << "2.-[Opcional] Porcentaje de letras que se muestran" << endl;
      	return -1;
  	}

	ifstream fin(argv[1]);
	if ( !fin ) {

		cerr << "No puedo abrir el fichero " << argv[1] << endl;
		return -1;
	}

	int len = 3;
	int porcentaje;
	if ( argc == 3 ) {

		porcentaje = atoi(argv[2]);

	} else {

		porcentaje = 50;
	}

	Refranes refs(len);
	cout << "Creado los refranes" << endl;
	fin >> refs;

	bool volver = true;
	while ( volver ) {

		srand(time(NULL));
		int ref_aleatorio = 1+rand()%(refs.size()-2);

		Refranes::iterator it = refs.begin();
		int i = 0;
		string refran;
		for (; it != refs.end(); ++it) {

			i++;
			if ( i == ref_aleatorio ) {

				refran = *it;
			}
		}

		int tam_refran = 0;
		string ref_aux = refran;
		for (unsigned i = 0; i < ref_aux.size(); i++) {

			if ( ref_aux[i] != ' ' ) {

				++tam_refran;
			}
		}

		int letras_ocultas = tam_refran*porcentaje/100;
		int barras = 0;

		while ( barras != letras_ocultas ) {

			int num = rand()%refran.size();
			if ( (ref_aux[num] != '-') && (ref_aux[num] != ' ') ) {

				ref_aux[num] = '-';
				barras++;
			}
		}

		bool salir = false;
		int pos;
		char letra;
		string sol;
		int sol_long;

		cout << endl << "********************************* COMIENZA EL JUEGO *********************************" << endl;
		cout << ref_aux << endl;

		while ( !salir ) {

			int option;
			cout << endl << "Menu:";
			cout << "\t0 para ayuda";
			cout << "\t1 para adivinar letra" << endl;
			cout << "\t2 para adivinar refran" << endl;
			cout << "\t-1 para salir" << endl;
			cout << endl << "Elige: ";
			cin >> option;

			switch ( option ) {

				case 0:

					pos = rand()%(ref_aux.size());
					while ( ref_aux[pos] != '-' ) {

						pos = rand()%(ref_aux.size());
					}
					cout << endl << "Descubiertas: " << adivina(refran,ref_aux,refran[pos]) << endl;
					cout << endl << ref_aux << endl;
					if ( victoria(refran,ref_aux) ) {

						cout << endl << "YOU WIN!!" << endl;
						salir = true;
					}

				break;

				case 1:

					cout << endl << "Introduzca una letra: ";
					cin >> letra;
					cout << endl << "Encontradas: " << adivina(refran,ref_aux,letra) << endl;
					cout << endl << ref_aux << endl;
					if ( victoria(refran,ref_aux) ) {

						cout << endl << "YOU WIN!!" << endl;
						salir = true;
					}

				break;

				case 2:

					cout << endl << "Introduzca un refran: ";

					do {

						getline(cin,sol);
						sol_long = sol.size();

					} while ( sol_long == 0 );

					cout << sol << endl;
					if ( victoria(refran,sol) ) {

						cout << endl << "YOU WIN!!" << endl;
						salir = true;

					} else {

						cout << endl << "FALLASTE :(" << endl;
					}

				break;

				case -1:

					exit(0);

				break;
			}
		}

		cout << endl << "¿Quieres volver a jugar? :D [S/N]: ";
		char resp;
		cin >> resp;
		if ( (resp == 'N') || (resp == 'n') ) {

			volver = false;
		}
	}
}

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

#include "refranes.h"
#include <utility>

Refranes::Refranes() {

	len_prefijo 	   = 3;
	caracteres_totales = 0;
	n_ref 			   = 0;
	ab 				   = ArbolGeneral<string>();
}

Refranes::Refranes(int lpre) {

	len_prefijo 	   = lpre;
	caracteres_totales = 0;
	n_ref 			   = 0;
	ab 				   = ArbolGeneral<string>();
}

int Refranes::size() const {

	return n_ref;
}

void Refranes::Insertar(const string & refran,int i,ArbolGeneral<string>::Nodo n) {

	string pref;
	pref = refran[i];

	ArbolGeneral<string>::Nodo aux, nuevo_nodo;
	aux = ab.hijomasizquierda(n);
	bool salir = false;
	while ( (aux != 0) && !salir ) {

		if ( aux->etiqueta == pref ) {

			salir = true;

		} else {

			aux = ab.hermanoderecha(aux);
		}
	}

	if ( salir ) {

		Insertar(refran,++i,aux);

	} else {

		if ( i == len_prefijo ) {

			ArbolGeneral<string> nuevo(refran);
			ab.insertar_hijomasizquierda(n, nuevo);
			n_ref++;
			caracteres_totales += refran.size();

		} else {

			pref = refran[i];
			ArbolGeneral<string> nuevo(pref);
			ab.insertar_hijomasizquierda(n, nuevo);
			nuevo_nodo = ab.hijomasizquierda(n);
			Insertar(refran,++i,nuevo_nodo);
		}
	}
}

void Refranes::BorrarRefran(const string &refran)
{
	pair<bool,Refranes::iterator> result;
	result = Esta(refran);

	if ( result.first ) {

		ArbolGeneral<string>::iter_preorden it = result.second.it;
		ArbolGeneral<string>::Nodo n = it.GetNodo();
		ArbolGeneral<string> arb(refran);
		ab.podar_hijomasizquierda(n,arb);
	}
}

std::pair<bool,Refranes::iterator> Refranes::Esta(const string &refran) {

	std::pair<bool,Refranes::iterator> result;
	Refranes::iterator iter = begin();
	for (; iter != end(); ++iter) {

		if ( refran == *iter ) {

			result.first = true;
			result.second = iter;
			return result;
		}
	}
	result.first  = false;
	result.second = iter;
	return result;
}

void Refranes::clear() {

	ab.clear();
	n_ref 			   = 0;
	caracteres_totales = 0;
}

std::istream & operator>>(istream &is, Refranes &R)
{
	string refran;
	while ( getline(is, refran) ) {

		R.Insertar(refran,0,R.ab.raiz());
	}
	return is;
}

std::ostream & operator<<(ostream &os,const Refranes &R) {

	Refranes::const_iterator it = R.begin();
	for(; it != R.end(); ++it) {

		os << (*it) << endl;
	}
	return os;
}

int Refranes::Caracteres_Refranes() const {

	return caracteres_totales;
}

int Refranes::Caracteres_Almacenados() {

	return (Numero_Nodos() - 1 - size() + Caracteres_Refranes() - size()*len_prefijo);
}

int Refranes::Numero_Nodos() const {

	return ab.size();
}

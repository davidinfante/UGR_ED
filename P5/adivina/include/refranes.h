#ifndef __REFRANES__H
#define __REFRANES__H

#include "ArbolGeneral.h"
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

/**
 * @file Refranes.h: TDA Refranes
 *
 *
 *
 */

/**
   @brief T.D.A.Refranes

   \b Definición:
   Una instancia \e a del tipo de dato abstracto Refranes es una
   colección de frases tipicas de un idioma, dispuestas de forma
   ordenada en las que no hay refranes repetidos.

   <tt>\#include Refranes.h</tt>

   @author
   @date
*/

class Refranes {

  /**
	* @page repRefranes Rep del TDA Refranes
	*
	* @section invRefranes Invariante de la representación
	*
	* Añadir el invariante de la representación
	*
	* @section faRefranes Función de abstracción
	*
	* Añadir la función de abstracción
	*/
	private:

		ArbolGeneral<string> ab; // arbol para almacenar los refranes
		int len_prefijo; // la longitud del prefijo para construir el arbol
		int n_ref; // numero de refranes
		int caracteres_totales; // caracteres totales a lo largo de todos los refranes

    public:

	  /**
		* @brief Constructor por defecto. Inicia len_prefijo a 3
		*/
		Refranes();

	  /**
		* @brief Constructor por defecto. Inicia len_prefijo a  un valor
		*/
		Refranes(int lpre);

	  /**
		* @brief devuelve el numero de refranes alamacenados
		*/
		int size()const;

	   /**
	   	 * @brief Inserta un refran en el conjunto
		 * @param r: refran a insertar
		 * @note el numero de refranes se incrementa en uno mas
		 */
		void Insertar(const string & refran,int i,  ArbolGeneral<string>::Nodo n);

	  /**
	 	* @brief Borra un refrán en el conjunto
		* @param r: refran a borrar
		* @note el numero de refranes se decrementa en uno mas
		*/
		void BorrarRefran(const string &refran);

		class iterator;
		class const_iterator; //declaracion adelantada de los iteradores de refranes

	  /**
		* @brief Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
		* @param r: refran a buscar
		* @return una pareja que contiene si el refran esta y en caso afirmativo un iterador a el
		*/
		pair<bool,Refranes::iterator> Esta(const string &refran);

		iterator DondeEsta(const string &refran);

	  /**
		* @brief Elimina todos los refranes
		*/
		void clear();

	  /**
	    * @brief Lectura/Escritura de un conjunto de refranes
		*/
		friend istream & operator>>(istream &is, Refranes &R);
		friend ostream & operator<<(ostream &is,const Refranes &R);

	  /**
		* @brief Devuelve el numero total de los caracteres en todos los refranes
		*/
		int Caracteres_Refranes() const;

	  /**
	    * @brief Devuelve el numero de caracteres usados
		*  @note que no tiene que conincidir con el numero de caracteres de todos los refranes almancenados
		*/
		int Caracteres_Almacenados();

	  /**
		* @brief Numero de nodos necesarios para la configuración
		*/
		int Numero_Nodos() const;

		/****************************************/
		class iterator {

			private:

				ArbolGeneral<string>::iter_preorden it;
				string cad;

			public:

				iterator() {

					cad = "";
				}

				string & operator *() {

					return *it;
				}

				bool operator==(const iterator &i) const {

					return (it == i.it);
				}

				bool operator!=(const iterator &i) const {

					return (it != i.it);
				}

				iterator &operator ++() {

					++it;
					if ( it.getlevel() != -1 ) {

						while ( !it.Hoja() ) {

							++it;
						}
					}
					return *this;
				}

			friend class Refranes;
			friend class const_iterator;
		};

		class const_iterator {

			private:

				ArbolGeneral<string>::const_iter_preorden it;
				string cad; // al introducir el refrán entero en las hojas no usamos cad

			public:

				const_iterator() {

					cad = "";
				}

				const_iterator(const iterator &i) {

					cad = "";
					it  = i.it;
				}
				string & operator *() {

					cad = *it;
					return cad;
				}

				bool operator==(const const_iterator &i) const {

					return (it == i.it);
				}

				bool operator!=(const const_iterator &i) const {

					return (it != i.it);
				}

				const_iterator &operator ++() {

					++it;
					if ( it.getlevel() != -1 ) {

						while ( !it.Hoja() ) {

							++it;
						}
					}
					return *this;
				}

			 friend class Refranes;
		};

		/***************BEGIN y END*************/
		iterator begin() {

			iterator i;
			i.it = ab.begin();
			return i;
		}

		iterator end() {

			iterator i;
			i.it = ab.end();
			return i;
		}

		const_iterator begin() const {

			const_iterator i;
			i.it = ab.begin();
			return i;
		}

		const_iterator end() const {
			
			const_iterator i;
			i.it = ab.end();
			return i;
		}
};

#endif

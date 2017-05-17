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
 * 	T.D.A. ArbolGeneral
 *
 */

template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo *n) {

	if ( !Nulo(n) ) {

		// Destruimos recursivamente a su hijo a la izquierda
		// y a su hermano a la derecha
		destruir(n->izqda);
		destruir(n->drcha);
		delete n;
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig) {

	if ( Nulo(orig) ) {

		dest = 0;

	} else {

		dest = new nodo;
		dest->etiqueta 	= orig->etiqueta;
		dest->padre 	= orig->padre;
		dest->izqda 	= orig->izqda;
		dest->drcha 	= orig->drcha;
		// Copiamos recursivamente a su hijo a la izquierda
		// y a su hermano a la derecha
		copiar(dest->izqda, orig->izqda);
		copiar(dest->drcha, orig->drcha);
	}
}

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const {

	if ( n == 0 ) {

		return 0;

	} else {

		return (1 + contar(n->izqda) + contar(n->drcha));
	}
}

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const {

	if ( Nulo(n1) && Nulo(n2) ) {

		return true;

	} else if ( Nulo(n1) || Nulo(n2) ) {

		return false;

	} else if ( n1->etiqueta != n2->etiqueta ) {

		return false;
	}
 	// Comprueba si todos sus hijos a la izquierda son iguales
	else if ( !soniguales(n1->izqda,n2->izqda) ) {

		return false;
	}
	// Comprueba si todos sus hermanos a la derecha son iguales
	else if(!soniguales(n1->drcha,n2->drcha)) {

		return false;

	} else {

		return true;
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const {

	if ( nod == 0 ) {

		out << "x";

	} else {

		out << "n " << nod->etiqueta << " ";
		// Pintamos recursivamente sus hijos
		escribe_arbol(out,nod->izqda);
		escribe_arbol(out,nod->drcha);
	}
}

template <class Tbase>
void ArbolGeneral <Tbase>::lee_arbol(std::istream& in, nodo *& nod) {

	char c;
    Nodo aux;
    in >> c;

    if ( in ) {

        if ( c == 'x' ) {

			nod = 0;

		} else {

            if ( c == 'n' ) {

                Tbase e;
                in >> e;
                nod = new nodo;
				nod->etiqueta = e;
                lee_arbol(in, nod->izqda);

                if ( !Nulo(nod->izqda) ) {

					nod->izqda->padre = nod;
				}

                if ( nod != raiz() ) {

					lee_arbol(in, nod->drcha);
				}

                if ( !Nulo(nod->izqda) ) {

                    aux = nod->izqda->drcha;
                    while ( !Nulo(aux) ) {

                        aux->padre = nod;
                        aux = aux->drcha;
                    } // while (línea 147)
                } // if (línea 144)
            } // if (línea 126)
        } // else (línea 124)
    } // if (línea 118)
}

template <class Tbase>
inline ArbolGeneral<Tbase>::ArbolGeneral() {

	laraiz 		  = new nodo;
	laraiz->padre = 0;
	laraiz->izqda = 0;
	laraiz->drcha = 0;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e) {

	laraiz 			 = new nodo;
	laraiz->padre 	 = 0;
	laraiz->izqda 	 = 0;
	laraiz->drcha 	 = 0;
	laraiz->etiqueta = e;
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v) {

	copiar(laraiz,v.laraiz);
	if ( !Nulo(laraiz) ) {

		laraiz->padre = 0;
	}
}

template <class Tbase>
inline ArbolGeneral<Tbase>::~ArbolGeneral() {

	destruir(laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase> & ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase>&v) {

	if ( this != &v ) {

		destruir(laraiz);
		copiar(laraiz,v.laraiz);
		if ( !Nulo(laraiz) ) {

			laraiz->padre = 0;
		}
	}

	return *this;
}

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e) {

	destruir(laraiz);
	laraiz 			 = new nodo;
	laraiz->padre	 = 0;
	laraiz->izqda 	 = 0;
	laraiz->drcha 	 = 0;
	laraiz->etiqueta = e;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const {

	return laraiz;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const {

	assert(!Nulo(n));
	return (n->izqda);
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const {

	assert(!Nulo(n));
	return (n->drcha);
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const {

	assert(!Nulo(n));
	return (n->padre);
}

template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) {

	assert(!Nulo(n));
	return (n->etiqueta);
}

template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const {

	assert(!Nulo(n));
	return (n->etiqueta);
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod) {

	if ( laraiz != nod ) {

        destruir(laraiz);
        copiar(laraiz, nod);
        laraiz->drcha = 0;
        laraiz->padre = 0;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest) {

	destruir(dest.laraiz);
    if ( !Nulo(n->izqda) ) {

        dest.laraiz = n->izqda;
        if ( !Nulo(n->izqda) ) {

			n->izqda = n->izqda->drcha;
		}

        dest.laraiz->drcha = 0;
        dest.laraiz->padre = 0;
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest) {

	destruir(dest.laraiz);
    dest.laraiz 	   = n->drcha;
    n->drcha 		   = n->drcha->drcha;
    dest.laraiz->padre = 0;
    dest.laraiz->drcha = 0;
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama) {

	Nodo aux 		= n->izqda;
    n->izqda 		= rama.laraiz;
    n->izqda->padre = n;
    n->izqda->drcha = aux;
    rama.laraiz 	= 0;
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama) {

	Nodo aux 		= n->drcha;
    n->drcha 		= rama.laraiz;
    n->drcha->padre = n->padre;
    n->drcha->drcha = aux;
	rama.laraiz 	= 0;
}

template <class Tbase>
void ArbolGeneral<Tbase>::clear() {

	destruir(laraiz);
	laraiz = 0;
}

template <class Tbase>
int ArbolGeneral<Tbase>::size() const {

	return contar(laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const {

	return Nulo(laraiz);
}

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const {

	return soniguales(this->laraiz,v.laraiz);
}

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator != (const ArbolGeneral<Tbase>& v) const {

	return !soniguales(laraiz,v.laraiz);
}

template <class Tbase>
inline istream& operator>> (istream& in, ArbolGeneral<Tbase>& v) {

	v.lee_arbol(in,v.laraiz);
	return in;
}

template <class Tbase>
inline ostream& operator << (ostream& out, const ArbolGeneral<Tbase>& v) {
	
	v.escribe_arbol(out,v.laraiz);
	return out;
}

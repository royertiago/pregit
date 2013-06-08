/* ElementoB.h
 * Os objetos dessa classe contém uma chave do tipo Chave e um ponteiro
 * para um elemento do tipo T.
 *
 * Como as chaves costumam ser pequenas, é viável manter as chaves internas ao elemento
 * do que apontar para uma chave.
 *
 * Supor-se-á que a classe Chave sobrecarregará os operadores relacionais <, > e ==. 
 *
 * O construtor de cópia e o operador de atribuição ambos irão "roubar" a referência
 * para o elemento do objeto copiado.
 * */

#ifndef ELEMENTOB_H
#define	ELEMENTOB_H

template <typename T, typename Chave = int>
class ElementoB {
	friend class NodoB;
public:
    // Cria um nodo nulo.
    ElementoB();
    ElementoB( ElementoB<T, Chave>& );
	ElementoB( T* dado, Chave chave );
    ElementoB( T& dado, Chave chave );
	~ElementoB();
    ElementoB<T, Chave>& operator=( ElementoB<T, Chave>& );
	inline bool operator<( ElementoB< T, Chave > ) const;
	inline bool operator>( ElementoB< T, Chave > ) const;
	inline bool operator==( ElementoB< T, Chave > ) const;

private:
	T* _dado ;
	Chave _chave;
};

template <typename T, typename Chave>
ElementoB<T, Chave>::ElementoB():
    _dado(0)
{}

template <typename T, typename Chave>
ElementoB<T, Chave>::ElementoB( Elemento<T, Chave>& alce ):
    _dado( alce._dado ),
    _chave( alce._chave ) {
    alce._dado = 0;
}

template <typename T, typename Chave>
ElementoB<T, Chave>::ElementoB( T* dado , int chave ):
	_dado( dado )
	_chave( chave )
{}

template <typename T, typename Chave>
ElementoB<T, Chave>::ElementoB( T& dado , int chave ):
	_dado( &dado )
	_chave( chave )
{}

template <typename T, typename Chave>
ElementoB<t, Chave>::operator=( ElementoB<T, Chave>& alce ) {
    _chave = alce._chave;
    _dado = alce._dado;
    alce._dado = 0;
}

template <typename T, typename Chave>
ElementoB<T, Chave>::~ElementoB() {
	delete _dado ;
}

template <typename T, typename Chave>
inline bool ElementoB<T, Chave>::operator<( ElementoB< Chave, T > alce ) {
	return(_chave < alce._chave ) ;
}

template <typename T, typename Chave>
inline bool ElementoB<T, Chave>::operator>( ElementoB< Chave, T > alce ) {
	return(_chave > alce._chave ) ;
}

template <typename T, typename Chave>
inline bool ElementoB<T, Chave>::operator==( ElementoB< Chave, T > alce ) {
	return(_chave == alce._chave ) ;
}

#endif	/* ELEMENTOB_H */

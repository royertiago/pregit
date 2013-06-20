/* ElementoHash;
 * Os objetos meramente apontam para um objeto via void*, e armazenam um inteiro
 * que representa o tipo do objeto apontado.
 *
 * A semântica do tipo deve ser definida pelo usuário do hash. */
#ifndef ELEMENTOHASH_H
#define	ELEMENTOHASH_H

template <typename T>
class ElementoHash {
public:
    ElementoHash( T chave, void* valor = 0, int tipo = 0 );
    const void* valor;
    const int tipo;
    T chave;
};

template< typename T>
ElementoHash<T>::ElementoHash( T chave, void* valor, int tipo ): 
    chave( chave ),
    valor( valor ),
    tipo( tipo )
{}

#endif	/* ELEMENTOHASH_H */

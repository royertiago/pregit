/* Tabela de hash genérica.
 * Esta tabela de hash é capaz de armazenar valores de diversos tipos; T
 * é a chave a ser usada para a função de hash.
 *  
 * Como esse armazenamento é feito via void*, não há como saber qual é o tipo
 * do objeto armazenado, então é armazenado, junto com ele, um inteiro (fornecido
 * pelo usuário do hash) que pode ser usado para identificar o tipo do dado.
 *
 * A função de hash é fornecida pelo usuário na construção; essa função de hash
 * deve produzir valores entre 0 (inclusive) e tamanho (exclusive). 
 *
 * Caso a chave seja um ponteiro, ao ser destruído o ElementoHash, o ponteiro também o é. */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "ElementoHash.h"
#include "TypeUtils.h"
#include "CabecaDeLista.h"
#include "Iterador.h"

template <typename T, int tamanho>
class HashTable {
public:
    HashTable( int (*hash)(T) );

    /* Retorna o elemento referido. Caso não exista, um ponteiro nulo será retornado.
     * Note que, como o ElementoHash retornado é um ponteiro para o elemento armazenado,
     * deletá-lo tornaria a tabela de hash inconsistente. */
    ElementoHash<T>* get( T chave );

    // Similar a antes, mas usa o comparador provido para testar comparação.
    ElementoHash<T>* get( T chave, bool (*equal)( T, T ) );
    
    // Insere o valor no hash com o tipo passado.
    void put( T chave, void* valor, int tipo );

    // Insere o valor no hash e usa o tipo obtido em TypeUtils.h.
    template <typename U> void put( T chave, U* valor ) {
        _tabela[hash( chave )].adiciona( new ElementoHash<T>( chave, valor, getTypeValue( *valor ) ) );
    }

    // Imprime todas as chaves, usando as funções de TypeUtils.h.
    void print();

private:
    int (*const hash)( T );
    CabecaDeLista<ElementoHash<T>> _tabela[tamanho];
};

template <typename T, int tamanho>
HashTable<T, tamanho>::HashTable( int (*hash)(T) ):
    hash(hash)
{}

template <typename T, int tamanho>
ElementoHash<T>* HashTable<T, tamanho>::get( T chave ) {
    for( auto i = _tabela[hash( chave )].iterador(); !i.volta(); ++i )
        if( i->chave == chave )
            return i.operator->();

    return 0;        
}

template <typename T, int tamanho>
ElementoHash<T>* HashTable<T, tamanho>::get( T chave, bool (*equal)( T, T ) ) {
    for( auto i = _tabela[hash( chave )].iterador(); !i.volta(); ++i )
        if( equal( i->chave, chave ) )
            return i.operator->();

    return 0;        
}

template <typename T, int tamanho>
void HashTable<T, tamanho>::put( T chave, void* valor, int tipo ) {
    _tabela[hash( chave )].adiciona( new ElementoHash<T>( chave, valor, tipo ) );
}

template <typename T, int tamanho>
void HashTable<T, tamanho>::print() {
    for( int i = 0; i < tamanho; i++ )
        for( auto j = _tabela[i].iterador(); !j.volta(); ++j )
            getPrintUtility( j->tipo )( j->valor );
}

#endif	/* HASHTABLE_H */

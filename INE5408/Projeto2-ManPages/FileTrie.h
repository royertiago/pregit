/* Árvore de prefixos em arquivo.
 *
 * Baseia-se na implementação da serialização de MemoryTrie.h
 */

#ifndef FILE_TRIE_H
#define FILE_TRIE_H

#include "TrieIndex.h"
#include "NodoTrie.h" // para NODE_SERIAL_SIZE

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

// Árvore de prefixos que está num arquivo.
template <typename T>
class FileTrie {
public:
    /* Cria um navegador da árvore de prefixos localizada no arquivo
     * passado, e que usará da função d toda vez que for necessário
     * recuperar algum dado. */
    FileTrie( ifstream& , T* (*d)( ifstream&, int ) );

    /* Retorna o T serializado com a chave passada, caso exista;
     * é retornado um ponteiro nulo, caso contrário. */
    T* recuperar( const char* chave );

    // Informa se a chave desejada existe no arquivo.
    bool contem( const char* chave );
private:
    ifstream& _file;
    T* (*_des)( ifstream&, int );
};

template <typename T>
FileTrie<T>::FileTrie( ifstream& file, T* (*d)( ifstream&, int ) ):
    _file( file ), _des(d)
{}

template <typename T>
T* FileTrie<T>::recuperar( const char* chave ) {
    int pos = 0;
    for( int i = 0; chave[i] != 0; i++ ) {
        pos += 1 + sizeof(int)*trieIndex( chave[i] );
        _file.seekg( pos );
        // Agora, estamos em condição de ler _filhos[i]
        _file.read( reinterpret_cast<char*>( &pos ), sizeof( int ) );
        if( pos == 0 )
            return 0;
    }
    _file.seekg( pos );
    bool terminal;
    _file.read( reinterpret_cast<char*>( &terminal ), sizeof(bool) );
    if( !terminal )
        return 0;

    pos += NODE_SERIAL_SIZE;
    _file.seekg( pos );
    int tam;
    _file.read( reinterpret_cast<char*>( &tam ), sizeof(int) );
    return _des( _file, tam );
}

template <typename T>
bool FileTrie<T>::contem( const char* chave ) {
    int pos = 0;
    for( int i = 0; chave[i] != 0; i++ ) {
        pos += 1 + sizeof(int)*trieIndex( chave[i] );
        _file.seekg( pos );
        // Agora, estamos em condição de ler _filhos[i]
        _file.read( reinterpret_cast<char*>( &pos ), sizeof( int ) );
        if( pos == 0 )
            return false;
    }
    _file.seekg( pos );
    bool terminal;
    _file.read( reinterpret_cast<char*>( &terminal ), sizeof(bool) );
    return terminal;
}

#endif // TRIE_H

/* Árvore de prefixos em memória
 *
 * Todas as inserções terminar-se-ão ao encontrar o caractere nulo.
 */

#ifndef TRIE_H
#define TRIE_H

#include "NodoTrie.h"
#include "TrieIndex.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

template <typename T>
MemoryTrie<T> desserializar( ifstream& in, T* (*d)( ifstream&, int ) );

// Árvore de prefixos que reside na memória.
template <typename T>
class MemoryTrie {
public:
    // Cria uma árvore de prefixos vazia.
    MemoryTrie();

    // Destroi inclusive os T* armazenados.
    ~MemoryTrie();

    /* Isere dado na árvore, com chave c; supor-se-á que 
     * a chave é única - sobrescreveremos o dado armazenado
     * caso já exista algum com a mesma chave. */
    void adiciona( const char* c, T* dado );

    // Retorna true se e somente se a chave passada existir na árvore.
    bool contem( const char* c );

    /* Devolve o ponteiro armazenado pela chave c, caso exista.
     * Caso contrário, um ponteiro nulo será retornado. */
    T* recuperar( const char* c );

    /* Serializa o trie na stream out.
     *
     * A serialização se dará a partir da posição atual, em out.
     * Para cada objeto armazenado, o trie invocará a função s,
     * passando como parâmetro um ponteiro para o objeto armazenado
     * e o próprio out.
     *
     * A função s deve escrever, na stream passada, apenas na posição
     * atual em diante. Modificar bytes anteriores à posição atual
     * pode corromper o trie.
     *
     * A função s deve retornar a quantidade de bytes escritos na
     * stream; por exemplo, se s escrever "Algo" (incluindo o caracter
     * nulo), voltar 3 bytes e escrever "ce", s deve retornar 5. */
    void serializar( ofstream& out, int (*s)( const T*, ofstream& ) );

private:
    friend MemoryTrie<T> desserializar<T>( 
            ifstream& in, T* (*d)( ifstream&, int ) );

    NodoTrie<T>* nodo;
};

/* Desserializa o trie passado.
 * Se baseia na implementação de NodoTrie.h da serialização.
 *
 * Para cada objeto a ser desserializado, o método chamará a função d
 * com a stream in na posição correta, junto com o número de bytes a
 * serem lidos; é como uma inversa à função passada à
 * CabecaDeLista::serializar. Bytes além do limite serão lixo, do ponto
 * de vista da função. */
template <typename T>
MemoryTrie<T> desserializar( ifstream& in, T* (*d)( ifstream&, int ) );

// Implementações

template <typename T>
MemoryTrie<T>::MemoryTrie(): nodo(0) {}

template <typename T>
void MemoryTrie<T>::adiciona( const char* c, T* dado ) {
    if( nodo == 0 )
        nodo = new NodoTrie<T>( c, dado );
    else
        nodo->adiciona( c, dado );
}

template <typename T>
bool MemoryTrie<T>::contem( const char* c ) {
    return nodo->contem( c );
}

template <typename T>
T* MemoryTrie<T>::recuperar( const char* c ) {
    if( nodo == nullptr ) {
        T* r = new T();
        nodo = new NodoTrie<T>( c, r );
        return r;
    }
    return nodo->recuperar( c );
}

template <typename T>
MemoryTrie<T>::~MemoryTrie() {
    delete nodo;
}

template <typename T>
void MemoryTrie<T>::serializar( ofstream& out, 
        int (*s)( const T*, ofstream& ) ) {
    nodo->serializar( out, s );
}

// Todo o trabalho braçal será feito aqui.
template <typename T>
NodoTrie<T>* desserializarNodo (
        ifstream& in, T* (*d)( ifstream&, int ) ) {
    NodoTrie<T>* n = new NodoTrie<T>();
    in.read( reinterpret_cast<char*>( &n->_terminal ), sizeof(bool) );

    int base = in.tellg();
    for( int i = 0; i < TRIE_SIZE; i++, base += sizeof(int) ) {
        int pos;
        in.read( reinterpret_cast<char*>( &pos ), sizeof(int) );
        if( pos == 0 )
            n->_filhos[i] = 0;
        else {
            int restore = in.tellg();
            in.seekg( pos );
            n->_filhos[i] = desserializarNodo( in, d );
            in.seekg( restore );
        }
    }

    if( n->_terminal ) {
        int tam;
        in.read( reinterpret_cast<char*>( &tam ), sizeof(int) );
        n->_dado = d( in, tam );
    } else
        n->_dado = 0;
}

template <typename T>
MemoryTrie<T> desserializar( ifstream& in, T* (*d)( ifstream&, int ) ){
    MemoryTrie<T> mem;
    mem.nodo = desserializarNodo( in, d );
    return mem;
}

#endif // MEMORY_TRIE_H

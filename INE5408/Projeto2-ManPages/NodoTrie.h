/* Nodo de uma árvore de prefixos.
 * Caso haja algum caractere não reconhecido, uma exceção
 * char* será lançada. */

#ifndef NODO_TRIE_H
#define NODO_TRIE_H

#include "TrieIndex.h"

#define NODE_SERIAL_SIZE sizeof(int)*TRIE_SIZE + sizeof(bool)

#include <fstream>
using std::ofstream;
using std::ifstream;

template <typename T> class MemoryTrie;
template <typename T> class NodoTrie;
template <typename T>
NodoTrie<T>* desserializarNodo(
                ifstream& in, T* (*d)( ifstream&, int ) );

template <typename T>
class NodoTrie {
public:
    // Cria um nodo inútil.
    NodoTrie() {}

    /* Cria o nodo com a chave c e o dado passado.
     * Caso *c == '\0', o nodo armazenará o dado passado.
     * Caso contrário, o nodo criará mais um nodo e proseguirá
     * a cadeia de construtores, um caractere à frente. */
    NodoTrie( const char* c, T* dado );

    // Destroi inclusive os T* armazenados.
    ~NodoTrie();

    /* Insere o dado passado com a chave c.
     * Nodos adicionais serão criados conforme a necessidade. */
    void adiciona( const char* c, T* dado );

    /* Devolve o ponteiro armazenado pela chave c, caso exista.
     * Caso contrário, será criado um novo ramo com um T* vazio. */
    T* recuperar( const char* c );

    // Retorna true se e somente se a chave existir na árvore
    bool contem( const char* c );

    /* Serializa o nodo na stream out.
     *
     * A serialização se dará a partir da posição atual, em out.
     * Para cada objeto armazenado, o nodo invocará a função s,
     * passando como parâmetro um ponteiro para o objeto armazenado
     * e o próprio out.
     *
     * A função s deve escrever, na stream passada, apenas na posição
     * atual em diante. Modificar bytes anteriores à posição atual
     * pode corromper o trie.
     *
     * A função s deve retornar a quantidade de bytes escritos na
     * stream; por exemplo, se s escrever "Algo" (incluindo o caracter
     * nulo), voltar 3 bytes e escrever "ce", s deve retornar 5.
     *
     * O método retorna o local em que iniciou-se a escrita do nodo. */
    int serializar( ofstream& out, int (*s)( const T*, ofstream& ) );

private:
    friend class MemoryTrie<T>;
    friend NodoTrie<T>* desserializarNodo<T>(
                ifstream& in, T* (*d)( ifstream&, int ) );

    NodoTrie<T>* _filhos[TRIE_SIZE];
    T* _dado;
    bool _terminal; // true sse houver um dado armazenado.
};

template <typename T>
NodoTrie<T>::NodoTrie( const char* c, T* dado ) {
    _terminal = (*c == '\0');
    _dado = (_terminal) ? dado : 0;
    for( int i = 0; i < TRIE_SIZE; i++ )
        _filhos[i] = 0;

    if( !_terminal )
        _filhos[trieIndex( *c )] = new NodoTrie<T>( c+1, dado );
}

template <typename T>
NodoTrie<T>::~NodoTrie() {
    for( int i = 0; i < TRIE_SIZE; i++ )
        delete _filhos[i];
    delete _dado;
}

template <typename T>
void NodoTrie<T>::adiciona( const char* c, T* dado ) {
    if( *c == '\0' ) {
        _terminal = true;
        _dado = dado;
        return;
    }
    if( _filhos[trieIndex( *c )] == 0 )
        _filhos[trieIndex( *c )] = new NodoTrie<T>( c+1, dado );
    else
        _filhos[trieIndex( *c )]->adiciona( c+1, dado );
}

template <typename T>
T* NodoTrie<T>::recuperar( const char* c ) {
    if( *c == '\0' ) {
        if( _dado == 0 )
            return _dado = new T();
        return _dado;
    }

    if( _filhos[trieIndex( *c )] == 0 ) {
        T* r = new T();
        _filhos[trieIndex( *c )] = new NodoTrie<T>( c+1, r );
        return r;
    }

    return _filhos[trieIndex( *c )]->recuperar( c+1 );
}

template <typename T>
bool NodoTrie<T>::contem( const char* c ) {
    if( *c == '\0' )
       return _terminal;

    if( _filhos[trieIndex( *c )] == 0 )
        return false;

    return _filhos[trieIndex( *c )]->contem( c+1 );
}

/*      Anatomia da serialização
 *
 * O primeiro byte será o booleano _terminal. Os próximos TRIE_SIZE *
 * sizeof(int) bytes corresponderão, em blocos de sizeof(int), às
 * posições dos filhos deste nodo -- ou zero, caso não existam.
 * Após isso, caso o nodo seja terminal, teremos a quantidade
 * de bytes gastos pelo objeto armazenado, seguido do próprio objeto.
 *
 * Podemos determinar se esses dois últimos campos existem, baseando-
 * nos no valor-verdade de _terminal.
 *
 * Temos:
 * Campo: _terminal|_filhos|[tamanho do objeto]|[objeto serializado]
 * Bytes:     0     1   113 114             117 118 ---
 */

template <typename T>
int NodoTrie<T>::serializar( ofstream& out, 
        int (*s)( const T*, ofstream& ) ) {
    int inicio = out.tellp();
    out.write( reinterpret_cast<char*>( &_terminal ), sizeof( bool ) );

    int base = inicio + sizeof(bool); //Posição base do vetor de filhos

    // Posição atual; útil apenas até o início do laço.
    int atual = base + TRIE_SIZE * sizeof(int);

    if( _terminal ) {
        out.seekp( atual + sizeof(int) );
        int tamanho = s( _dado, out );
        out.seekp( atual );
        out.write( reinterpret_cast<char*>( &tamanho ), sizeof(int ) );
        atual += tamanho + sizeof(int);
    }
    out.seekp( atual );

    /* Agora, para cada filho, chamaremos serializar recursivamente
     * e gravaremos a posição escrita, ou simplesmente
     * escreveremos 0. */
    int filhos[TRIE_SIZE];
    for( int i = 0; i < TRIE_SIZE; i++ ) {
        if( _filhos[i] != 0 ) 
            filhos[i] = _filhos[i]->serializar( out, s );
        else
            filhos[i] = 0;
    }
    int restore = out.tellp();
    out.seekp( base );
    out.write( reinterpret_cast<char*>(filhos), TRIE_SIZE*sizeof(int));
    out.seekp( restore );
    // Graças ao restore, estamos, agora, logo após os bytes escritos.
    return inicio;
}

#endif //NODO_TRIE_H

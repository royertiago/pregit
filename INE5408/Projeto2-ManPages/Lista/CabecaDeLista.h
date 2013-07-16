/* Representa a cabeça de uma lista circular duplamente encadeada.
 * Sob polimorfismo, a própria cabeça da lista é o nodo sentinela.
 *
 * As funções retiraEspecifico, contem e posicao supõe sobrecarga do
 * operador == para o tipo T.
 *
 * Várias funções de inserção possuem duas versões: com ponteiros e
 * com referências. A versão com referência meramente extrai o endereço
 * da referência e redireciona para a outra versão.
 *
 * Não é um bom exemplo de orientação à objetos, alguns códigos são
 * baseados na implementação Elemento.h.
 *
 * O construtor de cópia e o operador de atribuição usam o construtor
 * de cópia do tipo T.
 *
 * O operador de atribuição de transferência e construtor de 
 * transferência "zeram" o estado do objeto fonte; isto é, esvaziam o
 * fonte, e este fica como que recém-construído.
 */

#ifndef CABECADELISTA_H
#define CABECADELISTA_H

#include "ElementoDuplamenteEncadeado.h"
#include "Elemento.h"
#include "Iterador.h"
#include "IteradorConstante.h"

#include <fstream>
using std::ofstream;

template <typename T>
class CabecaDeLista: public ElementoDE<T> {
public:
    // Cria uma cabeça de lista vazia.
    CabecaDeLista();

    /* Copia todos os elementos da cabeça passada.
     * Vale-se do construtor de cópia do tipo T. */
    CabecaDeLista( const CabecaDeLista<T>& );

    /* Construtor de transferência.
     * O objeto fonte terminará como se estivesse recém-construído. */
    CabecaDeLista( CabecaDeLista<T>&& );

    /* Limpa esta cabeça de lista e copia todos os elementos da cabeça
     * passada.
     * Vale-se do construtor de cópia do tipo T. */
    CabecaDeLista& operator=( const CabecaDeLista<T>& );

    /* Operador de atribuição de transferência.
     * O objeto fonte terminará como se estivesse recém-construído.
     * O objeto destino destruirá todos os elementos que estão
     * armazenados. */
    CabecaDeLista& operator=( CabecaDeLista<T>&& );

    /* Destrói a lista inteira, chamando destrutores dos objetos
     * armazenados recursivamente. */
    ~CabecaDeLista();

    // Insere dado no fim da lista.
    void adiciona( T& dado );
    void adiciona( T* dado );

    // Insere dado no início da lista.
    void adicionaInicio( T& dado );
    void adicionaInicio( T* dado );

    /* Insere dado na posição pos. Caso a posição exista, true é
     * retornado;  Caso a posição referida não exista, false é
     * retornado e dado não é alterado.
     * Note que a lista é indexada em zero. */
    bool adicionaPosicao( T& dado, int pos );
    bool adicionaPosicao( T* dado, int pos );

    /* Armazena em dado um ponteiro para o dado armazenado na última
     * posição da lista, e o remove. Caso a lista esteja vazia, false
     * é retornado e dado não é alterado. */
    bool retira( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado na primeira
     * posição, e o remove. Caso a lista esteja vazia, false é
     * retornado e dado não é alterado. */
    bool retiraInicio( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado na posição
     * pos da lista, e o remove. Caso a posição referida não exista,
     * false é retornado e dado não é alterado.
     * Note que a lista é indexada em zero. */
    bool retiraPosicao( T*& dado, int pos );

    /* Remove a primeira ocorrência de dado da lista e retorna true, 
     * caso ele seja encontrado, e false caso contrário. Um ponteiro
     * para o dado encontrado é posto em retorno;
     * caso o dado não seja encontrado, retorno não é alterado.
     *
     * Esta função assume que o operador == está sobrecarregado para
     * os objetos do tipo T. 
     *
     * O elemento encontrado não é destruído, apenas perde-se a
     * referência a ele na lista; caso queira destruí-lo, use o método
     * destroiEspecífico */
    bool retiraEspecifico( const T& dado, T*& retorno );
    bool retiraEspecifico( const T* dado, T*& retorno );

    /* Remove a primeira ocorrência de dado da lista e retorna true,
     * caso ele seja encontrado, e false caso contrário. A ocorrência
     * encontrada é destruída.
     *
     * Essa função assume que o operador == está sobrecarregado para os
     * objetos da classe T.
     *
     * Note que a ocorrência encontrada é destruída; caso queira
     * preservá-la, use o método retiraEspecifico. */
    bool destroiEspecifico( const T& dado );
    bool destroiEspecifico( const T* dado );

    /* Armazena em dado um ponteiro para o dado armazenado pela última
     * posição da lista.
     * Retorna false caso a lista esteja vazia; neste caso, dado não é
     * alterado. */
    bool ler( T*& dado );
    bool ler( const T*& dado ) const;

    /* Armazena em dado um ponteiro para o dado armazenado pela
     * primeira posição da lista.
     * Retorna false caso a lista esteja vazia; neste caso, dado não é 
     * alterado. */
    bool lerInicio( T*& dado );
    bool lerInicio( const T*& dado ) const;

    /* Armazena em dado um ponteiro para o dado armazenado na posição
     * pos da lista.
     * Retorna false caso a posição não exista; neste caso, dado não é 
     * alterado.
     *
     * Note que a lista é indexada em zero. */
    bool lerPosicao( T*& dado, int pos );
    bool lerPosicao( const T*& dado, int pos ) const;

    // Retorna true, caso a lista esteja vazia, e false caso contrário.
    bool vazia() const;

    /* Retorna a posição da primeira ocorrência de dado na lista, ou -1
     *  caso não seja encontrado. */
    int posicao( const T& dado ) const;
    int posicao( const T* dado ) const;

    /* Retorna true caso a lista contenha o dado, 
     * e false caso contrário. */
    bool contem( const T& dado ) const;
    bool contem( const T* dado ) const;

    // Retorna o tamanho da lista.
    int tamanho() const;

    // Retorna um iterador para o início da lista.
    Iterador<T> iterador();
    IteradorConstante<T> iterador() const;

    // Retorna um iterador para o fim da lista.
    Iterador<T> iteradorFim();
    IteradorConstante<T> iteradorFim() const;

    /* Exclui toda a lista, chamando destrutores dos objetos
     * armazenados. */
    void limpar();

    /* Retorna true caso todos os elementos sejam iguais, 
     * na mesma ordem. */
    bool operator==( const CabecaDeLista<T>& ) const;

    /* Serializa a lista duplamente encadeada, na stream out.
     *
     * A serialização se dará a partir da posição atual, em out.
     * Para cada objeto armazenado, a lista invocará a função s,
     * passando como parâmetro um ponteiro para o objeto armazenado
     * e o próprio out.
     *
     * A função s deve escrever, na stream passada, apenas na posição
     * atual em diante. Modificar bytes anteriores à posição atual
     * pode corromper a lista.
     *
     * A função s deve retornar a quantidade de bytes escritos na
     * stream; por exemplo, se s escrever "Algo" (incluindo o caracter
     * nulo), voltar 3 bytes e escrever "ce", s deve retornar 5.
     *
     * O método retorna a quantidade de bytes escritos na stream. */
    int serializar( ofstream& out, 
                int (*s)( const T*, ofstream& ) ) const;

private:
    // Métodos herdados
    virtual bool _obterDado( T*& );
    virtual bool _obterDado( const T*& ) const;
    using ElementoDE<T>::_adicionarPosicao;
    using ElementoDE<T>::_retiraPosicao;
    using ElementoDE<T>::_retiraEspecifico;
    using ElementoDE<T>::_posicao;
    using ElementoDE<T>::_lerPosicao;
    virtual bool _ultimo() const;

    // Quantos elementos a lista possui.
    int tam;
};

/* Construtor - CabecaDeLista
 * A cabeça da lista funciona como sentinela; então, início e próximo
 * são a mesma coisa, assim como anterior e fim.
 * Valer-nos-emos dessa propriedade para otimizar inserção e remoção
 * de elementos no fim da lista. */
template <typename T>
CabecaDeLista<T>::CabecaDeLista() {
    tam = 0;
    this->_proximo = this->_anterior = this;
}

template <typename T>
CabecaDeLista<T>::CabecaDeLista( const CabecaDeLista<T>& l ) {
    tam = 0;
    this->_proximo = this->_anterior = this;
    for( IteradorConstante<T> it = l.iterador(); !it.volta(); ++it )
        this->adiciona( new T(*it) );
}

template <typename T>
CabecaDeLista<T>::CabecaDeLista( CabecaDeLista<T>&& l ) {
    tam = l.tam;
    this->_proximo = l._proximo;
    this->_anterior = l._anterior;
    l.tam = 0;
    l._proximo->_anterior = this;
    l._anterior->_proximo = this;
    l._proximo = l._anterior = &l;
}

template <typename T>
CabecaDeLista<T>& CabecaDeLista<T>::operator=( 
                        const CabecaDeLista<T>& l ) {
    this->limpar();
    for( IteradorConstante<T> it = l.iterador(); !it.volta(); ++it )
        this->adiciona( new T(*it) );
}

template <typename T>
CabecaDeLista<T>& CabecaDeLista<T>::operator=( CabecaDeLista<T>&& l ) {
    if( ! this->vazia() )
        delete this->_proximo;

    tam = l.tam;
    this->_proximo = l._proximo;
    this->_anterior = l._anterior;
    l._proximo->_anterior = this;
    l._anterior->_proximo = this;
    l.tam = 0;
    l._proximo = l._anterior = &l;
}

/* Destrutor da lista.
 * Os elementos armazenados na lista são destruídos também. */
template <typename T>
CabecaDeLista<T>::~CabecaDeLista() {
    if ( !this->vazia() ) 
        delete this->_proximo;
        // Se ela estiver vazia, this->_proximo == this. 
}

// Exclui toda a lista, chamando destrutores dos objetos armazenados.
template <typename T>
void CabecaDeLista<T>::limpar() {
    if( this->vazia() )
        return;

    delete this->_proximo;
    this->_proximo = this->_anterior = this;
    this->tam = 0;
}

// Insere dado no fim da lista.
template <typename T>
inline void CabecaDeLista<T>::adiciona( T& dado ) {
    this->adicionaPosicao( &dado, tam );
}

template <typename T>
inline void CabecaDeLista<T>::adiciona( T* dado ) {
    this->adicionaPosicao( dado, tam );
}

// Insere dado no início da lista.
template <typename T>
inline void CabecaDeLista<T>::adicionaInicio( T& dado ) {
    this->adicionaPosicao( &dado, 0 );
}

template <typename T>
inline void CabecaDeLista<T>::adicionaInicio( T* dado ) {
    this->adicionaPosicao( dado, 0 );
}

/* Insere dado na posição pos. Caso a posição exista, true é retornado;
 * Caso a posição referida não exista, false é retornado e dado não é 
 * alterado.
 * Note que a lista é indexada em zero. */
template <typename T>
inline bool CabecaDeLista<T>::adicionaPosicao( T& dado, int pos ) {
    return adicionaPosicao( &dado, pos );
}

template <typename T>
bool CabecaDeLista<T>::adicionaPosicao( T* dado, int pos ) {
    if ( pos < 0 || pos > tam )
        return false;
    
    ElementoDE<T>* elem = new Elemento<T>(dado);
    this->_adicionarPosicao( elem, pos );
                // Função herdada de ElementoDE.
    tam++;
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado na última
 * posição da lista, e o remove.
 * Caso a lista esteja vazia, false é retornado e dado não é alterado. 
 */
template <typename T>
inline bool CabecaDeLista<T>::retira( T*& dado ) {
    return this->retiraPosicao( dado, tam - 1 );
}

/* Armazena em dado um ponteiro para o dado armazenado na primeira 
 * posição, e o remove.
 * Caso a lista esteja vazia, false é retornado e dado não é alterado. 
 */
template <typename T>
inline bool CabecaDeLista<T>::retiraInicio( T*& dado ) {
    return this->retiraPosicao( dado, 0 );
}

/* Armazena em dado um ponteiro para o dado armazenado na posição pos
 * da lista, e o remove. Caso a posição referida não exista, false é
 * retornado e dado não é alterado.
 * Note que a lista é indexada em zero.
 *
 * Para reduzir pela metade o tempo esperado de deleção, a função
 * exclui "de trás para frente" caso o elemento esteja depois da
 * metade da lista. */
template <typename T>
bool CabecaDeLista<T>::retiraPosicao( T*& dado, int pos ) {
    if( pos < 0 || pos >= tam )
        return false;

    ElementoDE<T>* elem;
    if( 2*pos < tam )
        this->_retiraPosicao( elem, pos );
    else
        this->_retiraPosicao( elem, pos - tam - 1);

    elem->_obterDado( dado );
    operator delete( elem );
    tam--;
    return true;
}

/* Remove a primeira ocorrência de dado da lista e retorna true, caso 
 * ele seja encontrado, e false caso contrário. Um ponteiro para o dado
 * encontrado é posto em retorno; caso o dado não seja encontrado,
 * retorno não é alterado.
 *
 * Esta função assume que o operador == está sobrecarregado para os
 * objetos da classe T. 
 *
 * O elemento encontrado não é destruído, apenas perde-se referência a
 * ele na lista; caso queira destruí-lo, use o método 
 * destroiEspecífico */
template <typename T>
inline bool CabecaDeLista<T>::retiraEspecifico(
                const T& dado, T*& retorno ) {
    return this->retiraEspecifico( &dado, retorno );
}

template <typename T>
bool CabecaDeLista<T>::retiraEspecifico( const T* dado, T*& retorno ) {
    if( this->vazia() )
        return false;

    if( this->_retiraEspecifico( dado, retorno ) ) {
        tam--;
        return true;
    }
    
    return false;
}

/* Remove a primeira ocorrência de dado da lista e retorna true, caso
 * ele seja encontrado, e false caso contrário. A ocorrência encontrada
 * é destruída.
 *
 * Essa função assume que o operador == está sobrecarregado para os
 * objetos da classe T.
 *
 * Note que a ocorrência encontrada é destruída; caso queira preservá-
 * -la, use o método retiraEspecifico. */
template <typename T>
inline bool CabecaDeLista<T>::destroiEspecifico( const T& dado ) {
    return this->destroiEspecifico( &dado );
}

template <typename T>
bool CabecaDeLista<T>::destroiEspecifico( const T* dado ) {
    T* del;
    if( this->retiraEspecifico( dado, del ) ) {
        delete del;
        return true;
    }

    return false;
}

/* Armazena em dado um ponteiro para o dado armazenado pela última
 * posição da lista.
 * Retorna false caso a lista esteja vazia; neste caso, dado não é
 * alterado. */
template <typename T>
inline bool CabecaDeLista<T>::ler( T*& dado ) {
    return this->lerPosicao( dado, tam - 1 );
}

template <typename T>
inline bool CabecaDeLista<T>::ler( const T*& dado ) const {
    return this->lerPosicao( dado, tam - 1 );
}

/* Armazena em dado um ponteiro para o dado armazenado pela primeira 
 * posição da lista.
 * Retorna false caso a lista esteja vazia; neste caso, dado não é 
 * alterado. */
template <typename T>
inline bool CabecaDeLista<T>::lerInicio( T*& dado ) {
    return this->lerPosicao( dado, 0 );
}

template <typename T>
inline bool CabecaDeLista<T>::lerInicio( const T*& dado ) const {
    return this->lerPosicao( dado, 0 );
}

/* Armazena em dado um ponteiro para o dado armazenado na posição pos 
 * da lista.
 * Retorna false caso a posição não exista; neste caso, dado não é 
 * alterado.
 * 
 * Note que a lista é indexada em zero. */
template <typename T>
bool CabecaDeLista<T>::lerPosicao( T*& dado, int pos ) {
    if( pos < 0 || pos >= tam )
        return false;

    ElementoDE<T>* elem;
    this->_proximo->_lerPosicao( elem, pos );
    elem->_obterDado( dado );
    return true;
}

template <typename T>
bool CabecaDeLista<T>::lerPosicao( const T*& dado, int pos ) const {
    if( pos < 0 || pos >= tam )
        return false;

    ElementoDE<T>* elem;
    this->_proximo->_lerPosicao( elem, pos );
    elem->_obterDado( dado );
    return true;
}

// Retorna true, caso a lista esteja vazia, e false caso contrário.
template <typename T>
bool CabecaDeLista<T>::vazia() const {
    return tam == 0;
}

/* Retorna a posição da primeira ocorrência de dado na lista, ou -1 
 * caso não seja encontrado. */
template <typename T>
inline int CabecaDeLista<T>::posicao( const T& dado ) const {
    return this->_posicao( &dado );
}

template <typename T>
inline int CabecaDeLista<T>::posicao( const T* dado ) const {
    return this->_posicao( dado );
}

// Retorna true caso a lista contenha o dado, e false caso contrário.
template <typename T>
inline bool CabecaDeLista<T>::contem( const T& dado ) const {
    return this->posicao( dado ) != -1;
}

template <typename T>
inline bool CabecaDeLista<T>::contem( const T* dado ) const {
    return this->posicao( dado ) != -1;
}

// Retorna um iterador para o início da lista.
template <typename T>
inline Iterador<T> CabecaDeLista<T>::iterador() {
    return Iterador<T>(this);
}

template <typename T>
inline IteradorConstante<T> CabecaDeLista<T>::iterador() const {
    return IteradorConstante<T>(this);
}

// Retorna um iterador para o fim da lista.
template <typename T>
inline Iterador<T> CabecaDeLista<T>::iteradorFim() {
    return Iterador<T>( this, 0 );
}

template <typename T>
inline IteradorConstante<T> CabecaDeLista<T>::iteradorFim() const {
    return IteradorConstante<T>( this, 0 );
}

template <typename T>
inline int CabecaDeLista<T>::tamanho() const {
    return tam;
}

template <typename T>
bool CabecaDeLista<T>::operator==( 
                const CabecaDeLista<T>& alce ) const {
    IteradorConstante<T> i = alce.iterador(), j = this->iterador();
    for ( ;
         !(i.volta() && j.volta());
         ++i, ++j )
        if( !(*j == *i) )
            return false;

    if( !( i.volta() && j.volta() ) )
        return false;

    return true;
}

/* Serializa a lista duplamente encadeada, na stream out.
 *
 * A serialização se dará a partir da posição atual, em out.
 * Para cada objeto armazenado, a lista invocará a função s,
 * passando como parâmetro um ponteiro para o objeto armazenado
 * e o próprio out.
 *
 * A função s deve escrever, na stream passada, apenas na posição
 * atual em diante. Modificar bytes anteriores à posição atual
 * pode corromper a lista.
 *
 * A função s deve retornar a quantidade de bytes escritos na
 * stream; por exemplo, se s escrever "Algo" (incluindo o caracter
 * nulo), voltar 3 bytes e escrever "ce", s deve retornar 5.
 *
 * O método retorna a quantidade de bytes escritos na stream.
 *
 *      Anatomia da serialização:
 *
 * O primeiro item escrito na stream é o tamanho da lista.
 * 
 * Os demais itens são os elementos armazenados, divididos em dois
 * campos: o primeiro, um short dizendo quantos bytes tem o próximo 
 * elemento, e a própria serialização do elemento, obtida através
 * da função s.
 *
 * Serão feitas escritas em sequência, enfileirando os elementos;
 * escreveremos apenas a quantidade de elementos necessária. */
template <typename T>
int CabecaDeLista<T>::serializar(
        ofstream& out, int (*s)( const T*, ofstream& ) ) const {
    int inicio = out.tellp();

    // Escrever o tamanho da lista
    out.write( reinterpret_cast<const char*>( &tam ), sizeof(int));
    int atual = inicio + sizeof(int);

    for( auto it = iterador(); !it.volta(); ++it ) {
        out.seekp( atual + sizeof(short) );
        int tamanho = s( it.obter(), out );

        out.seekp( atual );
        out.write( reinterpret_cast<char*>( &tamanho ), sizeof(short));
        atual += tamanho + sizeof(short);
    }

    return atual - inicio;
}

/* Funções herdadas de ElementoDE<T>.
 * Estas implementações são apenas para tornar consistente o uso da
 * cabeça de lista como nodo sentinela. */

template <typename T>
bool CabecaDeLista<T>::_obterDado( T*& ) {
    return false;
}

template <typename T>
bool CabecaDeLista<T>::_obterDado( const T*& ) const {
    return false;
}

template <typename T>
bool CabecaDeLista<T>::_ultimo() const {
    return true;
}

#endif /* CABECADELISTA_H */

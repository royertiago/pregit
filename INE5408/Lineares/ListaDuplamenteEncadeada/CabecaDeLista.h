/* Representa a cabeça de uma lista circular duplamente encadeada.
 * Sob polimorfismo, a própria cabeça da lista é o nodo sentinela.
 *
 * As funções retiraEspecifico, contem e posicao supõe sobrecarga do operador == para o tipo T.
 *
 * Várias funções de inserção possuem duas versões: com ponteiros e com referências.
 * A versão com referência meramente extrai o endereço da referência e redireciona para a outra
 * versão.
 *
 * Não é um bom exemplo de orientação à objetos, alguns códigos são baseados
 * na implementação Elemento.h.
 *
 * Note que a cópia de uma cabeça de lista NÃO copiará a lista inteira; ao contrário,
 * apenas se terá dois objetos que acessam a mesma lista.
 */

#include "DebugUtils.h"

#ifndef CABECADELISTA_H
#define CABECADELISTA_H

#include "ElementoDuplamenteEncadeado.h"
#include "Elemento.h"
#include "Iterador.h"

template <typename T>
class CabecaDeLista: public ElementoDE<T> {
public:
    // Cria uma cabeça de lista vazia.
    CabecaDeLista();

    // Destrói a lista inteira, chamando destrutores dos objetos armazenados recursivamente. 
    ~CabecaDeLista();

    // Insere dado no fim da lista.
    void adiciona( T& dado );
    void adiciona( T* dado );

    // Insere dado no início da lista.
    void adicionaInicio( T& dado );
    void adicionaInicio( T* dado );

    /* Insere dado na posição pos. Caso a posição exista, true é retornado; 
     * Caso a posição referida não exista, false é retornado e dado não é alterado.
     * Note que a lista é indexada em zero. */
    bool adicionaPosicao( T& dado, int pos );
    bool adicionaPosicao( T* dado, int pos );

    /* Armazena em dado um ponteiro para o dado armazenado na última posição da lista, e o remove.
     * Caso a lista esteja vazia, false é retornado e dado não é alterado. */
    bool retira( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado na primeira posição, e o remove.
     * Caso a lista esteja vazia, false é retornado e dado não é alterado. */
    bool retiraInicio( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado na posição pos da lista, e o remove.
     * Caso a posição referida não exista, false é retornado e dado não é alterado.
     * Note que a lista é indexada em zero. */
    bool retiraPosicao( T*& dado, int pos );

    /* Remove a primeira ocorrência de dado da lista e retorna true, caso ele seja encontrado,
     * e false caso contrário. Esta função assume que o operador == está sobrecarregado para
     * os elementos da classe T. */
    bool retiraEspecifico( T& dado );

    /* Armazena em dado um ponteiro para o dado armazenado pela última posição da lista.
     * Retorna false caso a lista esteja vazia; neste caso, dado não é alterado. */
    bool ler( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado pela primeira posição da lista.
     * Retorna false caso a lista esteja vazia; neste caso, dado não é alterado. */
    bool lerInicio( T*& dado );

    /* Armazena em dado um ponteiro para o dado armazenado na posição pos da lista.
     * Retorna false caso a posição não exista; neste caso, dado não é alterado.
     * Note que a lista é indexada em zero. */
    bool lerPosicao( T*& dado, int pos );

    // Retorna true, caso a lista esteja vazia, e false caso contrário.
    bool vazia();

    // Retorna a posição de dado na lista, ou -1 caso não seja encontrado.
    int posicao( T& dado );

    // Retorna true caso a lista contenha o dado, e false caso contrário.
    bool contem( T& dado );

    // Retorna o tamanho da lista.
    int tamanho();

    // Retorna um iterador para o início da lista.
    Iterador<T> iterador();

    // Excluí toda a lista, chamando destrutores dos objetos armazenados.
    void limpar();

#ifdef DebugMode
    void printV() {
        cout << this << endl;
        ElementoDE<T>* a = this->_proximo;
        while( a != this ) {
            cout << a << endl;
            a = a->_proximo;
        }
        cout << endl;
    }
#endif

private:
    
    // Previnir erro de memória:
    CabecaDeLista( const CabecaDeLista& );
    CabecaDeLista& operator=( const CabecaDeLista& );

    // Métodos herdados
    virtual bool obterDado( T*& );
    using ElementoDE<T>::adicionarPosicao;
    using ElementoDE<T>::retiraPosicao;
    virtual bool retiraEspecifico( T* );
    virtual int posicao( T* );
    using ElementoDE<T>::lerPosicao;
    virtual bool ultimo();

    // Quantos elementos a lista possui.
    int tam;
};

/* Construtor - CabecaDeLista
 * A cabeça da lista funciona como sentinela; então, início e próximo são a mesma coisa,
 * assim como anterior e fim.
 * Valer-nos-emos dessa propriedade para otimizar inserção e remoção de elementos no fim da lista. */
template <typename T>
CabecaDeLista<T>::CabecaDeLista() {
    tam = 0;
    this->_proximo = this->_anterior = this;
    debug( cout << "Cabeça de lista criada.\n"; )
}

/* Destrutor da lista.
 * Os elementos armazenados na lista são destruídos também. */
template <typename T>
CabecaDeLista<T>::~CabecaDeLista() {
    debug( cout << "Destruíndo a cabeça " << this << " e encadeando " << this->_proximo << endl );
    if ( !this->vazia() ) //Talvez a lista esteja vazia.
        delete this->_proximo;
}

// Excluí toda a lista, chamando destrutores dos objetos armazenados.
template <typename T>
void CabecaDeLista<T>::limpar() {
    if( this->vazia() )
        return;

    delete this->_proximo;
    debug( cout << "Reconstruíndo lista " << this << endl );
    this->_proximo = this->_anterior = this;
    this->tam = 0;
}

// Insere dado no fim da lista.
template <typename T>
void CabecaDeLista<T>::adiciona( T& dado ) {
    adiciona( &dado );
}

template <typename T>
void CabecaDeLista<T>::adiciona( T* dado ) {
    Elemento<T>* elem = new Elemento<T>(dado);
    this->adicionarPosicao( elem, -1 );
    tam++;
    debug( cout << "Elemento " << dado << " adicionado no final, em  " << elem << endl; )
}

// Insere dado no início da lista.

template <typename T>
void CabecaDeLista<T>::adicionaInicio( T& dado ) {
    adicionaInicio( &dado );
}

template <typename T>
void CabecaDeLista<T>::adicionaInicio( T* dado ) {
    ElementoDE<T>* elem = new Elemento<T>(dado);
    this->adicionarPosicao( elem, 0 );
    tam++;
    debug( cout << "Elemento " << dado << " adicionado no inicio, em " << elem << endl; )
}


/* Insere dado na posição pos. Caso a posição exista, true é retornado; 
 * Caso a posição referida não exista, false é retornado e dado não é alterado.
 * Note que a lista é indexada em zero. */
template <typename T>
bool CabecaDeLista<T>::adicionaPosicao( T& dado, int pos ) {
    return adicionaPosicao( &dado, pos );
}

template <typename T>
bool CabecaDeLista<T>::adicionaPosicao( T* dado, int pos ) {
    if ( pos < 0 || pos > tam )
        return false;
    
    ElementoDE<T>* elem = new Elemento<T>(dado);
    this->adicionarPosicao( elem, pos ); //Função herdada de ElementoDE.
    tam++;
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado na última posição da lista, e o remove.
 * Caso a lista esteja vazia, false é retornado e dado não é alterado.
 *
 * Específicamente esta função não redireciona para o retiraPosicao, para ganhar eficiência
 * na remoção do último elemento da lista. */
template <typename T>
bool CabecaDeLista<T>::retira( T*& dado ) {
    if ( this->vazia() )
        return false;

    ElementoDE<T>* elem;
    this->retiraPosicao( elem, -2 );
    elem->obterDado( dado );
    operator delete( elem );
    tam--;
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado na primeira posição, e o remove.
 * Caso a lista esteja vazia, false é retornado e dado não é alterado. */
template <typename T>
bool CabecaDeLista<T>::retiraInicio( T*& dado ) {
    return this->retiraPosicao( dado, 0 );
}

/* Armazena em dado um ponteiro para o dado armazenado na posição pos da lista, e o remove.
 * Caso a posição referida não exista, false é retornado e dado não é alterado.
 * Note que a lista é indexada em zero. */
template <typename T>
bool CabecaDeLista<T>::retiraPosicao( T*& dado, int pos ) {
    if( pos < 0 || pos >= tam )
        return false;

    ElementoDE<T>* elem;
    this->_proximo->retiraPosicao( elem, pos );
    elem->obterDado( dado );
    operator delete( elem );
    tam--;
    return true;
}

/* Remove a primeira ocorrência de dado da lista e retorna true, caso ele seja encontrado,
 * e false caso contrário. Esta função assume que o operador == está sobrecarregado para
 * os elementos da classe T. */
template <typename T>
bool CabecaDeLista<T>::retiraEspecifico( T& dado ) {
    if( this->vazia() )
        return false;

    T* d;
    this->_proximo->obterDado( d );
    if( *d == dado ) {
        this->retiraInicio( d );
        return true;
    }

    if( !this->_proximo->retiraEspecifico( &dado ) )
        return false;

    tam--;
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado pela última posição da lista.
 * Retorna false caso a lista esteja vazia; neste caso, dado não é alterado. */
template <typename T>
bool CabecaDeLista<T>::ler( T*& dado ) {
    if( this->vazia() )
        return false;

    if( !this->_anterior->obterDado( dado ) )
        debug( cout << "Erro na leitura - CabecaDeLista<T>::ler( T*& ) at " << __LINE__ << endl );

    debug( cout << "Lido " << dado << " do fim, dentro de " << this->_anterior << endl ); 
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado pela primeira posição da lista.
 * Retorna false caso a lista esteja vazia; neste caso, dado não é alterado. */
template <typename T>
bool CabecaDeLista<T>::lerInicio( T*& dado ) {
    if( this->vazia() )
        return false;

    this->_proximo->obterDado( dado );

    debug( cout << "Lido " << dado << " do inicio, dentro de " << this->_proximo << endl );
    return true;
}

/* Armazena em dado um ponteiro para o dado armazenado na posição pos da lista.
 * Retorna false caso a posição não exista; neste caso, dado não é alterado.
 * Note que a lista é indexada em zero. */
template <typename T>
bool CabecaDeLista<T>::lerPosicao( T*& dado, int pos ) {
    if( pos < 0 || pos >= tam )
        return false;

    ElementoDE<T>* elem;
    this->_proximo->lerPosicao( elem, pos );
    debug( cout << "Tentando ler de " << elem << endl; )
    elem->obterDado( dado );
    return true;
}

// Retorna true, caso a lista esteja vazia, e false caso contrário.
template <typename T>
bool CabecaDeLista<T>::vazia() {
    return tam == 0;
}

// Retorna a posição de dado na lista, ou -1 caso não seja encontrado.
template <typename T>
int CabecaDeLista<T>::posicao( T& dado ) {
    return this->_proximo->posicao( &dado );
}

// Retorna true caso a lista contenha o dado, e false caso contrário.
template <typename T>
bool CabecaDeLista<T>::contem( T& dado ) {
    return this->posicao( dado ) != -1;
}

// Retorna um iterador para o início da lista.
template <typename T>
Iterador<T> CabecaDeLista<T>::iterador() {
    return Iterador<T>(this);
}

/* Funções herdadas de ElementoDE<T>.
 * Estas implementações são apenas para tornar consistente o uso da cabeça de lista
 * como nodo sentinela. */

template <typename T>
bool CabecaDeLista<T>::obterDado( T*& ) {
    return false;
}

template <typename T>
bool CabecaDeLista<T>::retiraEspecifico( T* ) {
    return false;
}

template <typename T>
int CabecaDeLista<T>::posicao( T* ) {
    return -1;
}

template <typename T>
bool CabecaDeLista<T>::ultimo() {
    return true;
}

template <typename T>
int CabecaDeLista<T>::tamanho() {
    return tam;
}

#endif /* CABECADELISTA_H */

/* Classe base da lista duplamente encadeada. O elemento duplamente encadeado aponta para
 * dois outros elementos: o próximo e o anterior. Não armazena dados; suas classes derivadas
 * implementarão esta funcionalidade.
 *
 * Por serem implementações internas, 
 *
 * Todos os métodos de inserção/leitura/remoção assumem que a lista "não tem fim"
 * (o fim não será atingido no processo de inserção/leitura/remoção),
 * e atuam com posicionamento relativo à posição atual.
 */

#ifndef ELEMENTODUPLAMENTEENCADEADO_H
#define ELEMENTODUPLAMENTEENCADEADO_H

#include "DebugUtils.h"

#define pure 0 //Pure virtual function

template <typename T> class CabecaDeLista;
template <typename T> class Elemento;
template <typename T> class Iterador;
 
template <typename T>
class ElementoDE {
    friend class CabecaDeLista<T>;
    friend class Elemento<T>;
    friend class Iterador<T>;
    virtual ~ElementoDE() {}
private:
    ElementoDE<T>* _anterior;
    ElementoDE<T>* _proximo;

    /* Grava o dado armazenado pelo elemento atual em dado.
     * Caso não haja dado armazenado, false é retornado e dado não é alterado. */
    virtual bool obterDado( T*& dado ) = pure;

    /* Insere o elemento, pos posições à frente do elemento atual.
     * (pos = 0 implica que o elemento será inserido logo após o elemento atual) */
    virtual void adicionarPosicao( ElementoDE<T>* elemento, int pos );

    /* Armazena em elemento um ponteiro para o elemento que está pos posições à frente, e o remove da lista.
     * Os ponteiros anterior e proximo do elemento retornado estarão anulados. */
    virtual void retiraPosicao( ElementoDE<T>*& elemento, int pos );

    /* Retira a primeira ocorrência de dado da lista, e retorna true. Caso não seja encontrado,
     * false é retornado. Este método supõe sobrecarga do operador == para o tipo T.
     *
     * Específicamente para este método, a busca é realizada no próximo elemento, e não neste;
     * então, há a necessidade de ser feito o teste externo para o elemento inicial. */
    virtual bool retiraEspecifico( T* dado ) = pure;

    // Retorna quantas posicões à frente da lista está o dado, ou -1 caso não esteja.
    virtual int posicao( T* dado ) = pure;

    /* Armazena em elemento o elemento encadeado pos posições à frente deste.
     * Retorna false caso a posição não exista; neste caso, elemento não é alterado.
     * Note que a lista é indexada em zero; zero posições à frente é esta posição aqui. */
    virtual void lerPosicao( ElementoDE<T>*& elemento, int pos );

    /* Informação de controle; apenas o sentinela deve ser o último nodo.
     * Neste caso, o destrutor do objeto anterior não encadea destrutores. */
    virtual bool ultimo() = pure;
};

template <typename T>
void ElementoDE<T>::adicionarPosicao( ElementoDE<T>* elemento, int pos ) {
    if( pos == 0 ) {
        elemento->_anterior = this;
        elemento->_proximo = _proximo;
        this->_proximo->_anterior = elemento;
        this->_proximo = elemento;
        debug( cout << "Posição adicionada - " << elemento << " - após " << this << endl );
    } else if ( pos > 0 )
        _proximo->adicionarPosicao( elemento, pos - 1 );
    else
        _anterior->adicionarPosicao( elemento, pos + 1 );
}

template <typename T>
void ElementoDE<T>::retiraPosicao( ElementoDE<T>*& elemento, int pos ) {
    debug( cout << "Elemento " << this << ", retira para " << pos << ". Anterior: " );
    debug( cout << this->_anterior << " - proximo: " << this->_proximo << endl );
    if( pos == 0 ) {
        elemento = this->_proximo;
        this->_proximo = elemento->_proximo;
        elemento->_proximo->_anterior = this;
        elemento->_proximo = elemento->_anterior = 0;
    } else if ( pos > 0 )
        this->_proximo->retiraPosicao( elemento, pos - 1 );
    else
        this->_anterior->retiraPosicao( elemento, pos + 1 );
}

template <typename T>
void ElementoDE<T>::lerPosicao( ElementoDE<T>*& elem, int pos ) {
    debug( cout << "Elemento " << this << ", lendo para " << pos << ". Anterior: " << this->_anterior << " - proximo: " << this->_proximo << endl);
    if (pos == 0)
        elem = this;
    else if (pos > 0)
        this->_proximo->lerPosicao( elem, pos - 1 );
    else
        this->_anterior->lerPosicao( elem, pos + 1 );
}

#endif /* ELEMENTODUPLAMENTEENCADEADO_H */

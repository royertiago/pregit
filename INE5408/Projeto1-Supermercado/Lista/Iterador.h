/* Iterador - classe cujos objetos podem navegar através de uma lista encadeada.
 * Específicamente, esta classe suporta avanço e retrocesso.
 *
 * Como a lista é circular, o método de pré-incremento retorna um booleano, que
 * é true quando o iterador atravessa o sentinela.
 *
 * Possui comportamento não previsível caso a lista não possua elementos. */

#ifndef ITERADOR_H
#define ITERADOR_H

#include "ElementoDuplamenteEncadeado.h"

#include <iostream>
using namespace std;

template <typename T>
class Iterador {
public:
    // Cria um iterador, que começa apontando para o elemento posterior ao elemento passado.
    Iterador( ElementoDE<T>* );

    /* Cria um iterador, que começa apontando para o elemento anterior ao elemento passado.
     * O inteiro passado não é usado. */
    Iterador( ElementoDE<T>*, int );

    /* Incrementa o iterador. Caso neste incremento o iterador passe pelo começo da lista
     * e "dê a volta", true é retornado. */
    bool incremento();

    /* Decrementa o iterador. Caso neste decremento o iterador passe pelo começo da lista
     * e "dê a volta", true é retornado. */
    bool decremento();

    // Redireciona para incremento().
    bool operator++();

    // Redireciona para decremento().
    bool operator--();

    // Grava em dado o dado armazenado na posição atual.
    void obter( T*& dado );

    // Retorna um ponteiro para o elemento armazenado.
    T* obter();

    /* Como este iterador itera sobre uma lista circular, ele pode dar voltas ao redor da lista;
     * este método retorna true se o iterador acabou de passar pelo começo de novo. */
    bool volta() const;

    // Provê acesso direto ao elemento armazenado.
    T* operator->();
    T& operator*();
 
private:
    ElementoDE<T>* _atual;
    bool _volta;
};

template <typename T>
Iterador<T>::Iterador( ElementoDE<T>* c ) :
    _atual(c),
    _volta(false) {
    incremento();
}

template <typename T>
Iterador<T>::Iterador( ElementoDE<T>* c, int ) :
    _atual(c),
    _volta(false) {
    decremento();
}

template <typename T>
bool Iterador<T>::incremento() {
    _atual = _atual->_proximo;
    if( !_atual->_ultimo() )
        return _volta = false;

    _atual = _atual->_proximo;
    return _volta = true;
}

template <typename T>
bool Iterador<T>::decremento() {
    _atual = _atual->_anterior;
    if( !_atual->_ultimo() )
        return _volta = false;

    _atual = _atual->_anterior;
    return _volta = true;
}

template <typename T>
inline bool Iterador<T>::operator++() {
    return this->incremento();
}

template <typename T>
inline bool Iterador<T>::operator--() {
    return this->decremento();
}

template <typename T>
inline void Iterador<T>::obter( T*& dado ) {
    _atual->_obterDado( dado );
}

template< typename T>
T* Iterador<T>::obter() {
    static T* alce;
    _atual->_obterDado( alce );
    return alce;
}

template <typename T>
inline T* Iterador<T>::operator->() {
    return this->obter();
}
 
template <typename T>
T& Iterador<T>::operator*() {
    T* alce;
    this->obter( alce );
    return *alce;
}

template <typename T>
inline bool Iterador<T>::volta() const {
    return _volta;
}
#endif /* ITERADOR_H */

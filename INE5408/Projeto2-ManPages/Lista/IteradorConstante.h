/* IteradorConstante - classe cujos objetos podem navegar através de 
 * uma lista encadeada.
 * Específicamente, esta classe suporta avanço e retrocesso.
 * Não lhe é permitido alterar os elementos da lista.
 *
 * Como a lista é circular, o método de pré-incremento retorna um
 * booleano, que é true quando o iterador atravessa o sentinela.
 *
 * Possui comportamento não previsível caso a lista não possua
 * elementos. */

#ifndef ITERADOR_CONSTANTE_H
#define ITERADOR_CONSTAHTE_H

#include "ElementoDuplamenteEncadeado.h"

template <typename T>
class IteradorConstante {
public:
    /* Cria um iterador, que começa apontando para o elemento posterior
     * ao elemento passado. */
    IteradorConstante( const ElementoDE<T>* );

    /* Cria um iterador, que começa apontando para o elemento anterior 
     * ao elemento passado.
     *
     * O inteiro passado não é usado. */
    IteradorConstante( const ElementoDE<T>*, int );

    /* Incrementa o iterador. Caso neste incremento o iterador passe 
     * pelo fim da lista e "dê a volta", true é retornado. */
    bool incremento();

    /* Decrementa o iterador. Caso neste decremento o iterador passe
     * pelo começo da lista e "dê a volta", true é retornado. */
    bool decremento();

    // Redireciona para incremento().
    bool operator++();

    // Redireciona para decremento().
    bool operator--();

    // Grava em dado o dado armazenado na posição atual.
    void obter( const T*& dado ) const;

    // Retorna um ponteiro para o elemento armazenado.
    const T* obter() const;

    /* Como este iterador itera sobre uma lista circular, ele pode dar 
     * voltas ao redor da lista; este método retorna true se o iterador
     * acabou de passar pelo começo de novo. */
    bool volta() const;

    // Provê acesso direto ao elemento armazenado.
    const T* operator->() const;
    const T& operator*() const;

private:
    const ElementoDE<T>* _atual;
    bool _volta;
};

template <typename T>
IteradorConstante<T>::IteradorConstante( const ElementoDE<T>* c ) :
    _atual(c),
    _volta(false) {
    incremento();
}

template <typename T>
IteradorConstante<T>::IteradorConstante( const ElementoDE<T>* c, int ):
    _atual(c),
    _volta(false) {
    decremento();
}

template <typename T>
bool IteradorConstante<T>::incremento() {
    _atual = _atual->_proximo;
    if( !_atual->_ultimo() )
        return _volta = false;

    _atual = _atual->_proximo;
    return _volta = true;
}

template <typename T>
bool IteradorConstante<T>::decremento() {
    _atual = _atual->_anterior;
    if( !_atual->_ultimo() )
        return _volta = false;

    _atual = _atual->_anterior;
    return _volta = true;
}

template <typename T>
inline bool IteradorConstante<T>::operator++() {
    return this->incremento();
}

template <typename T>
inline bool IteradorConstante<T>::operator--() {
    return this->decremento();
}

template <typename T>
inline void IteradorConstante<T>::obter( const T* & dado ) const {
    _atual->_obterDado( dado ); 
}

template< typename T>
const T* IteradorConstante<T>::obter() const {
    static const T* alce;
    _atual->_obterDado( alce );
    return alce;
}

template <typename T>
inline const T* IteradorConstante<T>::operator->() const {
    return this->obter();
}
 
template <typename T>
const T& IteradorConstante<T>::operator*() const {
    static const T* alce;
    this->obter( alce );
    return *alce;
}

template <typename T>
inline bool IteradorConstante<T>::volta() const {
    return _volta;
}
#endif /* ITERADOR_CONSTANTE_H */

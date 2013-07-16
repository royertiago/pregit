/* Classe derivada do elemento duplamente encadeado que é capaz de 
 * armazenar dados.
 */

#ifndef ELEMENTO_H
#define ELEMENTO_H
#include "ElementoDuplamenteEncadeado.h"

template <typename T>
class Elemento: public ElementoDE<T> {
public:
    //Cria um elemento que encapsulará dado.
    Elemento( T* const dado );
    virtual ~Elemento();
private:

    //Métodos herdados
    virtual bool _obterDado( T*& );
    virtual bool _obterDado( const T*& ) const;
    using ElementoDE<T>::_adicionarPosicao;
    using ElementoDE<T>::_retiraPosicao;
    using ElementoDE<T>::_retiraEspecifico;
    using ElementoDE<T>::_posicao;
    using ElementoDE<T>::_lerPosicao;
    virtual bool _ultimo() const;

    T* const _dado;
};

template <typename T>
Elemento<T>::Elemento( T* const dado ):
    _dado(dado) {
}

template <typename T>
Elemento<T>::~Elemento() {
    delete this->_dado;
    if( !this->_proximo->_ultimo() )
        delete this->_proximo;
}

template <typename T>
bool Elemento<T>::_obterDado( T*& dado ) {
    dado = this->_dado;
    return true;
}

template <typename T>
bool Elemento<T>::_obterDado( const T*& dado ) const {
    dado = this->_dado;
    return true;
}

template <typename T>
bool Elemento<T>::_ultimo() const {
    return false;
}

#endif /* ELEMENTO_H */

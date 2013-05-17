/* Classe derivada do elemento duplamente encadeado que é capaz de armazenar dados.
 */

#ifndef ELEMENTO_H
#define ELEMENTO_H
#include "ElementoDuplamenteEncadeado.h"

#include "DebugUtils.h"

template <typename T>
class Elemento: public ElementoDE<T> {
public:
    //Cria um elemento que encapsulará dado.
    Elemento( T* dado );
    virtual ~Elemento();
private:

    //Métodos herdados
    virtual bool obterDado( T*& );
    using ElementoDE<T>::adicionarPosicao;
    using ElementoDE<T>::retiraPosicao;
    virtual bool retiraEspecifico( T* );
    virtual int posicao( T* );
    using ElementoDE<T>::lerPosicao;
    virtual bool ultimo();

    T* _dado;
};

template <typename T>
Elemento<T>::Elemento( T* dado ) {
    this->_dado = dado;
}

template <typename T>
Elemento<T>::~Elemento() {
    debug( cout << "Destruindo elemento " << this->_dado << " - encadeando com " << this->_proximo << endl );
    delete this->_dado;
    if( !this->_proximo->ultimo() )
        delete this->_proximo;
    debug( else cout << "Cancelando encadeamento...\n" );
}

template <typename T>
bool Elemento<T>::obterDado( T*& dado ) {
    dado = this->_dado;
    return true;
}

template <typename T>
bool Elemento<T>::retiraEspecifico( T* dado ) {
    T* d;
    if( !this->_proximo->obterDado( d ) )
        return false;

    if( *d == *dado ) {
        delete d;
        ElementoDE<T>* del = this->_proximo; //Excluiremos este cara.
        this->_proximo = del->_proximo;
        del->_proximo->_anterior = this;
        operator delete( del );
        return true;
    }

    return this->_proximo->retiraEspecifico( dado );
}

template <typename T>
int Elemento<T>::posicao( T* dado ) {
    if( *dado == *_dado )
        return 0;
    int p = this->_proximo->posicao( dado );
    return p == -1? -1: p + 1;
}

template <typename T>
bool Elemento<T>::ultimo() {
    return false;
}

#endif /* ELEMENTO_H */

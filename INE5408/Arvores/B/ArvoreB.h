/* ÁrvoreB.h
 * Meramente interfaceia com NodoB.h.
 *
 * Cria uma árvore B com o tipo T e grau t. 
 *
 * Supor-se-á sobrecarga dos operadores relacional < e de inserção de fluxo << para o tipo T. */

#ifndef ARVOREB_H
#define ARVOREB_H

#include "NodoB.h"

#include <iostream>
using namespace std;

template <typename T, int t = 3>
class ArvoreB {
public:
    ArvoreB();
    ~ArvoreB();

    // Insere um elemento na árvore.
    void inserir( T* elemento );
    inline void inserir( T& elemento );

    inline ostream& print( ostream& os );

private:
    NodoB<T, t>* _raiz;
};

template <typename T, int t>
ArvoreB<T, t>::ArvoreB():
    _raiz(new NodoB<T, t>() )
{}

template <typename T, int t>
ArvoreB<T, t>::~ArvoreB() {
    delete _raiz;
}

template <typename T, int t>
inline void ArvoreB<T, t>::inserir( T& elemento ) {
    inserir( &elemento );
}

template <typename T, int t>
void ArvoreB<T, t>::inserir( T* elemento ) {
    if( _raiz->adiciona( elemento ) )
        return;

    static NodoB<T, t>* alce;
    alce = _raiz->meiose();
    _raiz = new NodoB<T, t>( _raiz, alce );
}

template <typename T, int t>
inline ostream& ArvoreB<T, t>::print( ostream& os ) {
    return _raiz->print( os );
}
#endif // ArvoreB.h

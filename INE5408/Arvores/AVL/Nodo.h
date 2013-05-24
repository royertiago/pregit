/* Nodo de uma árvore AVL.
 *
 * O destrutor encadeia destrutores dos nodos filhos e do dado armazenado.
 */

#ifndef NODO_H
#define NODO_H

template <typename T> class Arvore;

template <typename T>
class Nodo {
    friend class Arvore<T>;

    Nodo* esq;
    Nodo* dir;
    int altura;

    T* dado;
public:
    Nodo( T* );
    ~Nodo();

    /* Atualiza a altura do nó.
     * Nó folha, tem altura 0. */
    void atualizarAltura();
};

template <typename T>
Nodo<T>::Nodo( T* dado ):
    dado(dado),
    esq(0),
    dir(0),
    altura(0)
{}


template <typename T>
Nodo<T>::~Nodo() {
    delete esq;
    delete dado;
    delete dir;
}

template <typename T>
void Nodo<T>::atualizarAltura() {
    static int aEsq; // Altura Esquerda
    static int aDir; // Altura Direita
    aEsq = (esq == 0? -1 : esq->altura);
    aDir = (dir == 0? -1 : dir->altura);
    altura = 1 + ( aEsq > aDir? aEsq : aDir );
}

#endif // NodoAVL.h

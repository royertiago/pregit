/* Nodo.h - Representa um nodo genérico */
#ifndef NODO_H
#define NODO_H

template <typename T> class Arvore;

template <typename T>
class Nodo {
    // private:
    Nodo* esq;
    Nodo* dir;
    T* dado;

    //Não quero ninguém brincando com meus nodos. 
    Nodo& operator=( const Nodo<T>& c );// { return c; }
    Nodo( const Nodo<T>& );// {}

public:
    // Cria um nodo apontando para dado.
    Nodo( T* dado );

    // O destrutor destrói os nós filhos e o dado pendurado.
    ~Nodo();

    friend class Arvore<T>;
};

template <typename T>
Nodo<T>::Nodo( T* d ) {
    this->dado = d;
    esq = dir = 0;
}

template <typename T>
Nodo<T>::~Nodo() {
    delete dado;
    delete esq;
    delete dir;
}

#endif

/* Representa uma árvore binária implementada de maneira ingênua.
 * Assume sobrecarga dos operadores < e == para a classe utilizada.
 */
#ifndef ARVORE_H
#define ARVORE_H

#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class Arvore {
private:
    Nodo<T>* raiz;

    // Usado pelo método de impressão para reduzir gastos desnecessários de memória.
    int altura;
    // Não quero ninguém copiando minha árvore
    Arvore( const Arvore<T>& );
    Arvore<T>& operator=( const Arvore<T>& );
public:
    Arvore();

    //O destrutor encadeia destrutores de todos os elementos da árvore.
    ~Arvore();

    // Adiciona o dado na árvore.
    void adicionar( T* dado );

    // Imprime a árvore, ordenada, na ostream passada.
    void imprimir( ostream& os );
};

template <typename T>
Arvore<T>::Arvore():
    raiz(0),
    altura(0)
    {
}

/* Algoritmo de inserção iterativo.
 * Caso o dado a ser inserido já exista na árvore, inseriremos-no à direita do dado existente.
 */
template <typename T>
void Arvore<T>::adicionar( T* dado ) {
    if( raiz == 0 ) {
        raiz = new Nodo<T>( dado );
        return;
    }
    int alturaMax = 0;
    Nodo<T>* atual = raiz;
    Nodo<T>* Nodo<T>::* lado = &Nodo<T>::esq; //Ponteiro para um nodo* dentro de nodo.
    while( atual->*lado != 0 ) {
        cout << "Elemento analisado: " << *(atual->dado) << endl;
        atual = atual->*lado;
        if( *dado < *(atual->dado) )
            lado = &Nodo<T>::esq;
        else
            lado = &Nodo<T>::dir;
        alturaMax++;
    }

    atual->*lado = new Nodo<T>( dado );

    if( altura < alturaMax )
        altura = alturaMax;

    return;
}

template <typename T>
Arvore<T>::~Arvore() {
    delete raiz;
}

/* Aqui, topo apontará para o último dado empilhado.
 * lado é o lado a ser analisado; esq e dir apenas representarão lados diferentes aqui.
 */
template <typename T>
void Arvore<T>::imprimir( ostream& os ) {
    Nodo<T>* pilha[altura+1];
    pilha[0] = raiz;
    int topo = 0;

#define Esq true
#define Dir false
    bool lado = Esq;

    //while (topo >= 0) { //Assim que desemplilhar o último elemento, eu saio
    for( int i = 0; i < 10; i++ ) {
        if (lado == Esq) {
            if( pilha[topo]->esq == 0 ) {
                os << *(pilha[topo]->dado) << endl;
                lado = Dir; //Já analisamos a esquerda.
            }
            else {
                pilha[topo + 1] = pilha[topo]->esq;
                topo++; // Empilha e manda analisar a esquerda.
            }
        } else {
            if( pilha[topo]->dir == 0 ) {
                topo--;
            } else {
                pilha[topo + 1] = pilha[topo]->dir;
                topo++;
                lado = Esq;
            }
        }
    } //Fim while
}

#endif    

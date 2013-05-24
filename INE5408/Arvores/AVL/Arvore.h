/* Árvore AVL.
 *
 * O destrutor destrói todos os dados armazenados.
 */

#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "Nodo.h"

#include <iostream>
using namespace std;

template <typename T>
class Arvore {
public:
    Arvore();
    ~Arvore();

    void inserir( T* );

    /* Imprime a árvore, em ordem, no ostream passado.
     * Assumiremos sobrecarga para o operador de inserção de fluxo. */
    void imprimir( ostream& os );
private:
    Nodo<T>* raiz;

    static void imprimir( Nodo<T>* nodo, ostream& os );

    // Direções para a rotação.
    static Nodo<T>* Nodo<T>::* Esq;
    static Nodo<T>* Nodo<T>::* Dir;

    // Retorna Esq se recebe Dir, e Dir caso contrário.
    inline static Nodo<T>* Nodo<T>::* inverter( Nodo<T>* Nodo<T>::* );

    /* Rotaciona a árvore enraizada em alvo na direção desejada.
     * Uma rotação à direita rotaciona os nodos em sentido horário,
     * à esquerda, em sentido anti-horário.
     */
    static void rotacaoSimples( Nodo<T>*& alvo, Nodo<T>* Nodo<T>::* direcao );
    static void rotacaoDupla( Nodo<T>*& alvo, Nodo<T>* Nodo<T>::* direcao );

    // Obtém a altura do nodo, ou -1 se for nulo.
    inline static int altura( Nodo<T>* nodo );

    // Obtém o lado da árvore que tem a maior altura, ou Esq caso sejam iguais.
    static Nodo<T>* Nodo<T>::* maiorLado( Nodo<T>* nodo );

    // Insere dado na árvore enraizada em raiz. 
    static void inserir( T* dado, Nodo<T>*& raiz );

};

template <typename T>
Arvore<T>::Arvore():
    raiz(0)
{}

template <typename T>
Arvore<T>::~Arvore() {
    delete raiz;
}

template <typename T> Nodo<T>* Nodo<T>::* Arvore<T>::Esq = &Nodo<T>::esq;
template <typename T> Nodo<T>* Nodo<T>::* Arvore<T>::Dir = &Nodo<T>::dir;

template <typename T>
void Arvore<T>::imprimir( ostream& os ) {
    imprimir( raiz, os );
}

template <typename T>
void Arvore<T>::imprimir( Nodo<T>* nodo, ostream& os ) {
    if( nodo == 0 )
        return;

    imprimir( nodo->esq, os );
    cout << *nodo->dado << endl;
    imprimir( nodo->dir, os );
}

template <typename T>
inline Nodo<T>* Nodo<T>::* Arvore<T>::inverter( Nodo<T>* Nodo<T>::* alvo ) {
    return alvo == Esq ? Dir : Esq;
}

/* Obtém o lado da árvore que tem a maior altura, ou Esq caso sejam iguais.
 * Assumiremos alvo não-nulo. */
template <typename T>
Nodo<T>* Nodo<T>::* Arvore<T>::maiorLado( Nodo<T>* alvo ) {
    static int dir;
    static int esq;
    dir = alvo->dir == 0? -1 : alvo->dir->altura;
    esq = alvo->esq == 0? -1 : alvo->esq->altura;
    return dir > esq? Dir : Esq;
}


template <typename T>
inline int Arvore<T>::altura( Nodo<T>* nodo ) {
    return nodo == 0 ? -1 : nodo->altura;
}

/* Rotaciona a árvore no sentido indicado.
 * Aqui, caso a rotação seja para a esquerda, será no sentido anti-horário e vice-versa.
 *
 * k é a raíz da árvore, alce é o filho que assumirá seu lugar.
 * Assumimos que k e seu filho (na direção oposta) são não-nulos. */
template <typename T>
void Arvore<T>::rotacaoSimples( Nodo<T>*& k, Nodo<T>* Nodo<T>::* direcao ) {
    static Nodo<T>* Nodo<T>::* invDir; //Direção inversa
    static Nodo<T>* alce;
    invDir = inverter(direcao);

    alce = k->*invDir;
    k->*invDir = alce->*direcao;
    k->atualizarAltura(); //k está pronto.

    alce->*direcao = k;
    alce->atualizarAltura(); //alce está pronto.

    k = alce; //alce assume o lugar de k.
}

/* Rotaciona a árvore, duplamente, no sentido indicado.
 * Aqui, caso a rotação seja para a esquerda, será no sentido anti-horário e vice-versa.
 *
 * k é a raíz da arvore.
 * Supomos que k, o filho na direção oposta, e o filho do filho na direção desejada são não-nulos. */
template <typename T>
void Arvore<T>::rotacaoDupla( Nodo<T>*& k, Nodo<T>* Nodo<T>::* direcao ) {
    rotacaoSimples( k->*inverter(direcao), inverter(direcao) );
    rotacaoSimples( k, direcao );
}

/* Insere o dado na árvore enraizada em k.
 * Caso k seja nulo, colocaremos um nodo nele.
 *
 * Invariante a ser mantida: k é uma árvore AVL-balanceada. (loop-invariant) */
template <typename T>
void Arvore<T>::inserir( T* dado, Nodo<T>*& k ) {
    if( k == 0 ) {
        k = new Nodo<T>( dado );
        return;
        // A invariante foi mantida trivialmente.
    }

    Nodo<T>* Nodo<T>::* direcao;
    Nodo<T>* Nodo<T>::* invDir;

    if( *dado < *k->dado ) {
        direcao = Esq;
        invDir = Dir;
    } else {
        direcao = Dir;
        invDir = Esq;
    }

    Arvore<T>::inserir( dado, k->*direcao );
    k->atualizarAltura();
    /* Pela invariante, k->*direcao é uma árvore AVL-balanceada. Temos
     * de verificar se o balanceamento de k não foi alterado: */

    static int diff;
    diff = altura( k->*direcao ) - altura( k->*invDir );
    /* Proposição: diff >= -1.
     * Demonstração: pela invariante, antes da inserção, k era uma árvore AVL-balanceada,
     * então, nestas circunstâncias, o resultado de diff seria, claramente, maior ou igual a -1.
     * Mas houve uma inserção no termo k->*direcao; então, ou altura(k->*direcao) continua igual,
     * ou ele incrementa de 1. Em ambos os casos, diff >= -1. */

    if( diff <= 1 )
        return; // Não violamos a condição-AVL.

    /* Se a execução chegar até aqui, é porque houve violação na condição-AVL em k.
     * Temos de rebalancear, e faremos isso por rotações. Descobriremos, antes, o lado que causou a violação: */

    static Nodo<T>* Nodo<T>::* violacao;
    violacao = maiorLado( k->*direcao );
    // Necessariamente, um dos lados é maior que o outro (pois a árvore cresceu em uma das direções), então a resposta é consistente.
    
    if( violacao == direcao ) {
        /* Temos algo do tipo:      k (n+3)
         *                        /   \
         *                 (n+2) x     C (n)    Entre parênteses, as alturas de cada árvore.
         *                      / \
         *               (n+1) A   B (n)        Letras minúsculas são nós, maiúsculas são subárvores.
         * A < x < B < k < C. 
         * 
         * O lado em que ocorreu a violação é o mesmo lado para o qual foi feita a inserção de elementos na árvore.
         * Para corrigir isto, basta uma rotação simples no sentido oposto: */
        rotacaoSimples( k, invDir );
        /* Temos agora:         x (n+2)
         *                    /   \
         *             (n+1) A     k (n+1)
         *                        / \
         *                   (n) B   C (n)
         * Agora, x assumiu a posição de k, e a árvore que está enraizada em k (agora x) está AVL-balanceada.
         * A invariante foi restaurada. Podemos retornar. */
        return;
    } else {
        /* Este caso é um pouco mais complexo:      k (n+3)
         *                                        /   \
         *                                 (n+2) x     D (n)
         *                                     /   \
         *                                (n) A     y (n+1)
         *                                         / \
         *                                    (n) B   C (n[-1])
         * A < x < B < y < C < k < D.
         *
         * O lado em que ocorreu a violação foi oposto ao que ocorreu a inserção; a violação ocorreu "para dentro"
         * da árvore. Para isso, teremos de puxar o y (e sua subárvore) para cima, com uma rotação dupla no sentido oposto: */
        rotacaoDupla( k, invDir );
        /* Temos agora:               y (n+2)
         *                            /     \
         *                           /       \
         *                       (n+1) x   k (n+1)
         *                        /  \       /  \
         *                    (n) A  B(n)  (n)C  D(n)
         * y assumiu a posição de k, e recuperamos a invariante. Podemos retornar. */
        return;
    }
}

// Agora é fácil.
template <typename T>
void Arvore<T>::inserir( T* dado ) {
    inserir( dado, this->raiz );
}

#endif

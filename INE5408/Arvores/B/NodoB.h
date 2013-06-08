/* NodoB.h
 * Nodo de uma árvore B.
 *
 * Uma árvore B possui grau maior do que 2 .
 * Se um filho possui N elementos, ele possui N+1 filhos:
 *      elemento1   elemento2      ...      elementoN
 *  filho1      filho2      filho3 ...  filhoN      filhoN+1.
 * 
 * Todos os elementos de filho1 são menores que elemento1, são menores 
 * que todos os elementos de filho2, e assim por diante.
 * (Note que, se os filhos estiverem vazios, satisfazem trivialmente a definição.)
 *
 * Todos os nodos folha estarão no mesmo nível.
 *
 * Fixemos o grau da árvore em t.
 * Para não termos nodos demais, cada nodo conterá entre t-1 e 2t-1 chaves (entre
 * t e 2t filhos).
 *
 * Para manter essas propriedades, sempre que um nodo atingir 2t-1 chaves, iremos
 * dividi-lo em dois nodos (cada um contendo t-1 chaves) e uma chave, que será
 * "subida" para o nodo pai.
 * */
 
#ifndef NODOB_H
#define NODOB_H

#include <iostream>
using namespace std;

template <typename T, int t> class ArvoreB;

template <typename T, int t = 3>
class NodoB {
public:
    // Cria um nodo folha vazio.
    NodoB();

    /* Cria um nodo interno.
     * Esse nodo removerá, do primeiro nodo passado, o último elemento e o tomará para si,
     * apontando para ambos os nodos como filhos. */
    NodoB( NodoB<T, t>*, NodoB<T, t>* );

    // Deleta todos os elementos e filhos.
    ~NodoB();

    /* Quando um nodo fica cheio, é necessário dividi-lo.
     * Cada nodo contém entre t-1 e 2t-1 chaves; quando o limite superior
     * é atingido, chamar este método irá criar um novo nodo com
     * as t-1 últimas chaves deste aqui. */
    NodoB<T, t>* meiose();

    /* Insere o elemento no nodo. Retorna true se o nodo foi inserido corretamente,
     * false o nodo tenha ficado cheio.
     *
     * Supor-se-á que o nodo não está cheio. */
    bool adiciona( T* );
    
    // Imprime os elementos do nodo.
    ostream& print( ostream& );

private:

    int _n; //Quantidade de elementos armazenados.
    bool _folha; //True se for folha, false se for nodo interno.

    T* _elementos[2*t-1];
    NodoB<T, t>* _filhos[2*t];
};

template <typename T, int t>
NodoB<T, t>::NodoB():
    _n(0),
    _folha(true)
{}

template <typename T, int t>
NodoB<T, t>::NodoB( NodoB<T, t>* alceA, NodoB<T, t>* alceB):
    _n(1),
    _folha(false)
{
    _filhos[0] = alceA;
    _filhos[1] = alceB;
    _elementos[0] = alceA->_elementos[alceA->_n - 1];
    (alceA->_n)--;
}

template <typename T, int t>
NodoB<T, t>::~NodoB() {
    if( !_folha ) {
        int i = 0;
        for( ; i < _n; i++ )
           delete _filhos[i];
        
        delete _filhos[i];
    }
}

template <typename T, int t>
bool NodoB<T, t>::adiciona( T* e ) {
    if( _folha ) {
        int i = 0;

        // Encontrar o índice de inserção
        for( ; i < _n; i++ )
            if( *e < *_elementos[i] )
                break;

        // Deslocar os outros elementos
        for( int j = _n; j > i; j-- )
            _elementos[j] = _elementos[j-1];

        _elementos[i] = e;
        _n++;

        return _n < 2*t - 1;
    } else {
        int i = 0;

        // Encontrar o índice da inserção
        for( ; i < _n; i++ )
            if( *e < *_elementos[i] )
                break;

        if( _filhos[i]->adiciona( e ) )
            return true;

        /* Se chegou aqui, é porque _filhos[i] está cheio; vamos abrir espaço para
         * dividir o nodo. */
        for( int j = _n; j > i; j-- ) {
            _elementos[j] = _elementos[j-1];
            _filhos[j+1] = _filhos[j];
        }

        _filhos[i+1] = _filhos[i]->meiose();
        _elementos[i] = _filhos[i]->_elementos[_filhos[i]->_n - 1];
        (_filhos[i]->_n)--;
        _n++;
        return _n < 2*t - 1;
    }
}

template <typename T, int t>
NodoB<T, t>* NodoB<T, t>::meiose() {
    if( _folha ) {
        NodoB<T, t>* r = new NodoB<T, t>();
        for( int i = t; i < _n; i++ )
            r->_elementos[i-t] = _elementos[i];

        _n = t;
        r->_n = t - 1;
        return r;
    } else {
        NodoB<T, t>* r = new NodoB<T, t>();
        for( int i = t; i < _n; i++ ) {
            r->_elementos[i-t] = _elementos[i];
            r->_filhos[i-t] = _filhos[i];
        }
        r->_filhos[t-1] = _filhos[_n];

        _n = t;
        r->_n = t-1;
        r->_folha = false;
        return r;
    }
}

template <typename T, int t>
ostream& NodoB<T, t>::print( ostream& os ) {
    if( _folha ) {
        for( int i = 0; i < _n; i++ )
            os << *_elementos[i] << endl;
    } else {
        int i;
        for( i = 0; i < _n; i++ ) {
            _filhos[i]->print( os );
            os << *_elementos[i] << endl;
        }
        _filhos[i]->print( os );
    }
    return os;
}
#endif //NodoB.h

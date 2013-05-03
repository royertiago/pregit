/* Cabeça de uma lista encadeada.
 * A cabeça da lista é responsável por fazer a comunicação com os demais elementos da lista.
 * Como a inserção/remoção/leitura foi feita usando recursão, a cabeça da lista redireciona
 * as chamadas para os elementos encadeados quando necessário.
 * Importante notar que a cabeça da lista é indexada em 1, não em zero.
 *
 * Autores: Luis Decker
 *          Tiago Royer
 */

#ifndef CABECADELISTA_H
#define	CABECADELISTA_H

#include "ElementoEncadeado.h"

template<typename T>
class CabecaDeLista {
public:
    /* Cria uma lista vazia. */
    CabecaDeLista();
    /*De stroi a lista inteira, chamando todos os destrutores dos objetos guardados na lista. */
    ~CabecaDeLista();

    /* Retira o elemento da posição pos e coloca um ponteiro a ele em ret.
     * Caso a posição requisitada não exista, o valor de retorno é false
     * e ret não é alterado. Note que a lista é indexada em 1. */
    bool excluirPosicao(int pos, T*& ret);

    /* Retira o primeiro elemento da lista e coloca seu ponteiro em ret.
     * Caso a lista esteja vazia, o valor de retorno é false e ret
     * não é alterado. */
    bool excluirPrimeiro(T*& ret);

    /* Retira o último elemento da lista e coloca seu ponteiro em ret.
     * Caso a lista esteja vazia, o valor de retorno é false e ret
     * não é alterado. */
    bool excluirUltimo(T*& ret);

    /*Armazena em ret o dado que está na posição pos.
      Caso a posição não exista, false é retornado;
      neste caso, ret não é alterado. */
    bool retornaDadoPosicao(int pos, T*& ret);

    // Adiciona dado à lista, na primeira posição.
    void adicionarPrimeiro( T& dado );
    void adicionarPrimeiro( T* dado );

    // Adiciona dado à lista, na posição pos. Note que a lista é indexada em 1.
    void adicionarPosicao( T& dado, int pos );
    void adicionarPosicao( T* dado, int pos );

    // Adiciona dado à lista, na última posição.
    void adicionarUltimo( T& dado );
    void adicionarUltimo( T* dado );

    // Retorna o tamanho da lista atual.
    int obterTamanho();

    //Retorna se a lsita está vazia ou não.
    bool vazia();


private:
    //Adiciona dado ao começo da lista.
    bool adicionarPrimeiro(ElementoEncadeado<T>* dado);
    
    //Adiciona dado a posicao pos, caso ela exista.
    bool adicionarPosicao(ElementoEncadeado<T>* dado, int pos);
    
    //Adiciona dado no fim da lista
    bool adicionarUltimo(ElementoEncadeado<T>* dado);
  
    int _tamanho; // Tamanho atual da lista
    ElementoEncadeado<T>* _primeiro; //primeiro elemento da lista
};

template<typename T>
CabecaDeLista<T>::CabecaDeLista() {
    _primeiro = NULL;
    _tamanho = 0;
}

template<typename T>
CabecaDeLista<T>::~CabecaDeLista() {
    delete _primeiro;
}

template <typename T>
bool CabecaDeLista<T>::excluirPrimeiro(T*& ret) {
    return excluirPosicao(1, ret);
}

template<typename T>
bool CabecaDeLista<T>::retornaDadoPosicao(int pos, T*& retorno) {
    if (pos <= 0 || pos > _tamanho )
        return false;

    if (pos == 1) {
        retorno = _primeiro->cuspirDado();
        return true;
    }
    retorno = _primeiro->cuspirDadoPosicao(pos-1);
    return true;
}

template <typename T>
bool CabecaDeLista<T>::excluirPosicao(int pos, T*& ret) {
    if (pos > _tamanho || pos < 1) 
        return false;

    _tamanho--;
    if (pos == 1) {
        ElementoEncadeado<T>* alce = _primeiro->cuspirProximo();
        ret = _primeiro->cuspirDado();
        _primeiro->anularPointers();
        delete _primeiro; //Simplesmente chamar o delete iria invocar uma cadeia de destrutores.
        _primeiro = alce;
    }
    else
        _primeiro->excluirPosicao(pos-1, ret);

    return true;
}

template <typename T>
bool CabecaDeLista<T>::excluirUltimo(T*& ret) {
    return excluirPosicao(_tamanho, ret);
}

template <typename T>
bool CabecaDeLista<T>::vazia() {
    return (_tamanho == 0);
}

template <typename T>
void CabecaDeLista<T>::adicionarUltimo( T* dado ) {
    adicionarUltimo( new ElementoEncadeado<T>(dado) );
}

template <typename T>
void CabecaDeLista<T>::adicionarPrimeiro( T* dado ) {
    adicionarPrimeiro( new ElementoEncadeado<T>(dado) );
}

template <typename T>
void CabecaDeLista<T>::adicionarPosicao( T* dado, int pos ) {
    adicionarPosicao( new ElementoEncadeado<T>(dado), pos );
}

template <typename T>
void CabecaDeLista<T>::adicionarUltimo( T& dado ) {
    adicionarUltimo( new ElementoEncadeado<T>(&dado) );
}

template <typename T>
void CabecaDeLista<T>::adicionarPrimeiro( T& dado ) {
    adicionarPrimeiro( new ElementoEncadeado<T>(&dado) );
}

template <typename T>
void CabecaDeLista<T>::adicionarPosicao( T& dado, int pos ) {
    adicionarPosicao( new ElementoEncadeado<T>(&dado), pos );
}

template <typename T>
bool CabecaDeLista<T>::adicionarUltimo(ElementoEncadeado<T>* obj) {
    if (vazia()) {
        _primeiro = obj;
        _tamanho++;
        return true;
    } else {
        _primeiro->adicionarUltimo(obj);
        _tamanho++;
        return true;
    }

}

template <typename T>
bool CabecaDeLista<T>::adicionarPrimeiro(ElementoEncadeado<T>* obj) {
    if (_primeiro == NULL) {
        _primeiro = obj;
        _tamanho++;
        return true;
    }

    ElementoEncadeado<T>* alce = _primeiro;
    _primeiro = obj;
    ElementoEncadeado<T>* antigo = alce;
    _primeiro->apontarPara(antigo);
    _tamanho++;
    return true;
}

template <typename T>
bool CabecaDeLista<T>::adicionarPosicao(ElementoEncadeado<T>* obj, int pos) {
    if (pos > _tamanho) {
        return false;

    }
    pos--;
    _tamanho++;
    if (pos == 0) {
        ElementoEncadeado<T>* alce;
        alce = _primeiro;
        _primeiro = obj;
        _primeiro->apontarPara(alce);
        return true;
    }
    _primeiro->adicionarPosicao(obj, pos);
    return true;
}

template <typename T>
int CabecaDeLista<T>::obterTamanho() {
    return _tamanho;
}

#endif /* CABECADELISTA_H */


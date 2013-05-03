/* Representa um elemento de uma lista encadeada. 
 * As funções da lista encadeada são implementadas recursivamente aqui;
 * várias das funções assumem que os valores passados são corretos, ou seja, não haverá o risco
 * de tentar inserir um elemento na 5a posição de uma lista com 2 elementos.
 *
 * O destrutor da lista destrói o dado apontado e o próximo elemento da lista;
 * para evitar este comportamento, pode-se chamar a função anularPointers(), que anula
 * os ponteiros deste elemento.
 *
 * Autores: Luis Decker
 *          Tiago Royer
 */

#ifndef ELEMENTOFILA_H
#define	ELEMENTOFILA_H

template<typename T>
class ElementoEncadeado {
public:
    //Cria um elemento encadeado apontando para dado.
    ElementoEncadeado(T* dado);

    /* Destrói o dado apontado e o próximo elemento. Caso a intenção não seja encadear
     * destrutores, pode-se chamar a função anularPointers(), que anula os ponteiros deste elemento. */
    ~ElementoEncadeado();

    //Retorna true caso este seja o último elemento, false caso contrário.
    bool ultimo();

    //Adiciona o elemento encadeado passado na última posição da lista.
    void adicionarUltimo(ElementoEncadeado<T>*);

    //Altera para o ponteiro para o próximo elemento para o elemento passado.
    void apontarPara(ElementoEncadeado<T>*);

    //Adiciona o elemento encadeado pos posições à frente do elemento atual.
    void adicionarPosicao(ElementoEncadeado<T>*, int pos);

    //Exclui o elemento pos posições à frente do atual, e coloca o dado dele em ret.
    void excluirPosicao(int pos, T*& ret);

    //Anula os ponteiros deste objeto. Use-o para evitar que destruir o objeto inicie uma cadeia de destrutores.
    void anularPointers();

    //Obtém o elemento que está encadeado neste.
    ElementoEncadeado<T>* cuspirProximo();

    //Retorna o ponteiro para o dado armazenado aqui.
    T* cuspirDado();

    //Retorna o ponteiro apontado pelo elemento encadeado pos posições à frente deste aqui.
    T* cuspirDadoPosicao(int pos);

private:
    ElementoEncadeado<T>* _proximo;
    T* _dado;
};

template<typename T>
ElementoEncadeado<T>::ElementoEncadeado(T* dado) {
    _dado = dado;
    _proximo = NULL;
}

template <typename T>
ElementoEncadeado<T>::~ElementoEncadeado() {
    delete _dado;
    delete _proximo;
}

template<typename T>
T* ElementoEncadeado<T>::cuspirDado() {
    return _dado;
}

template<typename T>
T* ElementoEncadeado<T>::cuspirDadoPosicao(int pos) {
    if (pos == 0)
        return _dado;

    return _proximo->cuspirDadoPosicao(pos - 1);
}

template <typename T>
void ElementoEncadeado<T>::anularPointers() {
    _proximo = NULL;
    _dado = NULL;
}

template <typename T>
ElementoEncadeado<T>* ElementoEncadeado<T>::cuspirProximo() {
    return _proximo;
}

template<typename T>
void ElementoEncadeado<T>::excluirPosicao(int pos, T*& retorno) {
    if (pos == 1) { //Se é a próxima a ser excluída
        ElementoEncadeado<T>* alce = _proximo->_proximo;
        retorno = _proximo->_dado;
        _proximo->anularPointers();

        delete _proximo;
        _proximo = alce;
    }
    else
        _proximo->excluirPosicao(--pos, retorno);

}

template<typename T>
void ElementoEncadeado<T>::adicionarPosicao(ElementoEncadeado<T>* dado, int pos) {
    if (pos == 0) {
        ElementoEncadeado<T>* alce;
        alce = _proximo;
        _proximo = dado;
        _proximo->apontarPara(alce);
    }
    else
        _proximo->adicionarPosicao(dado, pos - 1);
}

template <typename T>
bool ElementoEncadeado<T>::ultimo() {
    return (_proximo == NULL);
}

template <typename T>
void ElementoEncadeado<T>::adicionarUltimo(ElementoEncadeado<T>* obj) {
    if (_proximo == NULL)
        _proximo = obj;
    else
        _proximo->adicionarUltimo(obj);
}

template<typename T>
void ElementoEncadeado<T>::apontarPara(ElementoEncadeado<T>* proximo) {
    _proximo = proximo;
}


#endif	/* ELEMENTOFILA_H */

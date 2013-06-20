/* Classe base da lista duplamente encadeada. O elemento duplamente encadeado aponta para
 * dois outros elementos: o próximo e o anterior. Não armazena dados; suas classes derivadas
 * implementarão esta funcionalidade.
 *
 * Por serem implementações internas, 
 *
 * Todos os métodos de inserção/leitura/remoção assumem que a lista "não tem fim"
 * (o fim não será atingido no processo de inserção/leitura/remoção),
 * e atuam com posicionamento relativo à posição atual.
 *
 * Em todos os métodos, caso não seja possível extrair o dado armazenado em algum elemento
 * duplamente encadeado, assumiremos que a lista terminou-se.
 *
 * Devido a erros no planejamento inicial, algumas funções de inserção e remoção
 * trabalham com elementos duplamente encadeados, e outras, com ponteiros para T.
 */

#ifndef ELEMENTO_DUPLAMENTE_ENCADEADO_H
#define ELEMENTO_DUPLAMENTE_ENCADEADO_H

template <typename T> class CabecaDeLista;
template <typename T> class Elemento;
template <typename T> class Iterador;
template <typename T> class IteradorConstante;

template <typename T>
class ElementoDE {
    friend class CabecaDeLista<T>;
    friend class Elemento<T>;
    friend class Iterador<T>;
    friend class IteradorConstante<T>;

    // Os ponteiros são determinados após a criação do objeto.
    ElementoDE() = default;

    // Quem extender esta classe é responsável por excluir os próximos elementos.
    virtual ~ElementoDE();
private:
    ElementoDE<T>* _anterior;
    ElementoDE<T>* _proximo;

    /* Grava o dado armazenado pelo elemento atual em dado.
     * Caso não haja dado armazenado, false é retornado e dado não é alterado. */
    virtual bool _obterDado( T*& dado ) = 0;
    virtual bool _obterDado( const T*& dado ) const = 0;

    /* Insere o elemento, pos posições à frente do elemento atual.
     * (pos = 0 implica que o elemento será inserido logo após o elemento atual) */
    void _adicionarPosicao( ElementoDE<T>* elemento, int pos );

    /* Armazena em elemento um ponteiro para o elemento encadeado que está pos posições à frente, e o remove da lista. */
    void _retiraPosicao( ElementoDE<T>*& elemento, int pos );

    /* Retira a primeira ocorrência de dado da lista, e retorna true. Um ponteiro para a primeira
     * ocorrência é posto em retorno. Caso não seja encontrado, false é retornado e retorno
     * não é alterado.
     *
     * Este método supõe sobrecarga do operador == para o tipo T.
     *
     * Específicamente para este método, a busca é realizada no próximo elemento, e não neste;
     * então, pode haver a necessidade de ser feito o teste externo para o elemento inicial. */
    bool _retiraEspecifico( const T* dado, T*& retorno );

    /* Retorna quantas posicões à frente da lista está o dado, ou -1 caso não esteja.
     *
     * Específicamente para este método, a busca é realizada no próximo elemento, e não neste;
     * então, pode haver a necessidade de ser feito o teste externo para o elemento inicial. */
    int _posicao( const T* dado ) const;

    /* Armazena em elemento o elemento encadeado pos posições à frente deste.
     * Retorna false caso a posição não exista; neste caso, elemento não é alterado.
     * Note que a lista é indexada em zero; zero posições à frente é esta posição aqui. */
    void _lerPosicao( ElementoDE<T>*& elemento, int pos );
    void _lerPosicao( const ElementoDE<T>*& elemento, int pos ) const;

    /* Informação de controle; apenas o sentinela deve ser o último nodo.
     * Neste caso, o destrutor do objeto anterior não deve encadear destrutores. */
    virtual bool _ultimo() const = 0;
};

template <typename T>
ElementoDE<T>::~ElementoDE() = default;

template <typename T>
void ElementoDE<T>::_adicionarPosicao( ElementoDE<T>* elemento, int pos ) {
    if( pos == 0 ) {
        elemento->_anterior = this;
        elemento->_proximo = _proximo;
        this->_proximo->_anterior = elemento;
        this->_proximo = elemento;
    } else if ( pos > 0 )
        _proximo->_adicionarPosicao( elemento, pos - 1 );
    else
        _anterior->_adicionarPosicao( elemento, pos + 1 );
}

template <typename T>
void ElementoDE<T>::_retiraPosicao( ElementoDE<T>*& elemento, int pos ) {
    if( pos == 0 ) {
        elemento = this->_proximo;
        this->_proximo = elemento->_proximo;
        elemento->_proximo->_anterior = this;
        elemento->_proximo = elemento->_anterior = 0;
    } else if ( pos > 0 )
        this->_proximo->_retiraPosicao( elemento, pos - 1 );
    else
        this->_anterior->_retiraPosicao( elemento, pos + 1 );
}

template <typename T>
bool ElementoDE<T>::_retiraEspecifico( const T* dado, T*& retorno ) {
    static T* d;

    if( !this->_proximo->_obterDado( d ) )
        return false;

    if( (*d) == (*dado) ) {
        retorno = d;
        ElementoDE<T>* del = this->_proximo; //Excluiremos este cara.
        // Emendar as listas:
        this->_proximo = del->_proximo;
        del->_proximo->_anterior = this;

        // Não queremos que a deleção do elemento encadeie destrutores, apenas desaloque memória.
        operator delete( del );
        return true;
    }

    return this->_proximo->_retiraEspecifico( dado, retorno );
}

template <typename T>
int ElementoDE<T>::_posicao( const T* dado ) const {
    static T* d;
    if( !this->_proximo->_obterDado( d ) )
        return -1;
    
    if( *d == *dado )
        return 0;

    int p = this->_proximo->_posicao( dado );
    return p == -1? -1 : p + 1;
}
template <typename T>
void ElementoDE<T>::_lerPosicao( ElementoDE<T>*& elem, int pos ) {
    if (pos == 0)
        elem = this;
    else if (pos > 0)
        this->_proximo->_lerPosicao( elem, pos - 1 );
    else
        this->_anterior->_lerPosicao( elem, pos + 1 );
}

template <typename T>
void ElementoDE<T>::_lerPosicao( const ElementoDE<T>*& elem, int pos ) const {
    if (pos == 0)
        elem = this;
    else if (pos > 0)
        this->_proximo->_lerPosicao( elem, pos - 1 );
    else
        this->_anterior->_lerPosicao( elem, pos + 1 );
}

#endif /* ELEMENTO_DUPLAMENTE_ENCADEADO_H */

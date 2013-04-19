/* Lista.h: Representa uma lista.
 * Contem otimizações (gambiarras) que permitem insersção e remoção de
 * itens no início e no fim com complexidade O(1).
 * Tenta reduzir a quantidade de elementos deslocados
 * quando insere-se elementos no meio da lista.
 * 
 * Embora não force a ordenação dos elementos da lista, há um método que
 * insere elementos na ordem correta; caso a lista não esteja ordenada,
 * não é previsível o local de inserção da lista.
 * A comparação é feita usando o operador <, que deve estar sobrecarregado
 * para a classe base. 
 * 
 * Para as funções RetiraEspecifico, Posicao e Contem, o operador == também deve estar sobrecarregado.
 *
 * O operador << insere um elemento no fim, enquanto que >> extrai o elemento do início.
 * Para ver um elemento em uma posição específica, use o operador []; essencialmente,
 * ele permite que a lista funcione como um vetor. Entretando, não é checado se os limites estão corretos.
 */
#ifndef LISTA_H
#define LISTA_H

#include<stdio.h>

template<typename T>
class Lista {
public:
    //Cria uma lista com tamanho 10.
    Lista();

    //tam = capacidade maxima da lista.
    Lista( int tam );

    //adiciona: insere um objeto no fim da lista, retorna true se houve espaço, e false se a lista estava cheia.
    bool adiciona( T obj );

    //retira: remove um objeto do fim da lista, e o grava em obj. Retorna true caso dê certo;
    //        se a fila estiver vazia, false é retornado, e obj não é alterado.
    bool retira( T& obj );

    //adicionaNoInicio: insere um objeto no início da lista, retorna true se a lista não estava cheia.
    bool adicionaNoInicio( T obj );

    //retiraDoInicio: remove um objeto do início da lista, e o grava em obj. Retorna true quando dá certo;
    //                se a lista estava vazia, false é retornado e obj não é alterado.
    bool retiraDoInicio( T& obj );
    
    //adicionaNaPosicao: adiciona o objeto obj na posição pos; retorna true se deu certo.
    //São duas situações possíveis de erro: posição incorreta e lista cheia. Não é feita distinção dos casos.
    bool adicionaNaPosicao( int pos, T obj );

    //Retira o objeto da posição pos, e o coloca em obj. Caso a posição não exista, false é retornado.
    bool retiraDaPosicao( int pos, T& obj );
    
    //Retira o objeto da posição pos, e o descarta, sem chamar destrutores.
    bool retiraDaPosicao( int pos );

    //Retorna a quantidade de objetos na lista.
    int obterTamanho();
    
    //Retorna a quantidade de objetos que a lista pode armazenar, no total.
    int obterTamanhoMax();
    
    //paraArray: retorna uma representacao em array dos elementos na lista.
    T* paraArray();
    
    //cheio: retorna true se a lista estiver cheia.
    bool cheio();

    //vazio: retorna true se a lista estiver vazia.
    bool vazio();

    //Retorna a posição da primeira ocorrência de obj na lista, e -1 caso obj não ocorra.
    int posicao( T obj );

    //Retorna true se o objeto existe, e false caso contrário.
    bool contem( T obj );

    //Procura obj e o remove, se for encontrado. Retorna true neste caso, e false no caso contrário.
    bool retiraEspecifico( T obj );
    
    //adicionaEmOrdem põe o elemento na ordem correta, definida pelo operador <. Retorna false caso a lista esteja cheia.
    bool adicionaEmOrdem( T obj );

    //Remove todos os objetos da lista, SEM executar destrutores.
    void limparLista();

    //Operador <<obj : redireciona para adiciona(obj).
    bool operator<<(T obj);
    
    //Operador >>obj : redireciona para retiraDoInicio(obj).
    bool operator>>(T& obj);

    //Operador [int]: trata essa lista como um vetor.
    T& operator[] (int pos);

    //Retorna o índice do primeiro elemento que não é menor do que o elemento requisitado, assumindo ordenação.
    //Se todos os elementos forem maiores, _inicio é retornado; no cenário oposto, _fim o é.
private:
    T* _dados;
    int _tam;
    int _inicio; //Aponta para o primerio da lista
    int _fim; //Aponta para o proximo lugar vazio
    bool _cheio;
    bool _vazio;
};

template <typename T>
Lista< T >::Lista() {
    Lista( 10 );
}

template <typename T>
Lista< T >::Lista(int tam) {
    _dados = new T[tam];
    _tam = tam;
    _fim = _inicio = 0;
    _cheio = false;
    _vazio = true;
}

template <typename T>
bool Lista< T >::adiciona( T obj ) {
    if ( _cheio )
        return false;

    _dados[_fim] = obj;
    _fim = (_fim + 1) % _tam;
    if( _inicio == _fim )
        _cheio = true;

    _vazio = false; //Pois acabei de adicionar um valor.

    return true;
    /* Caso seja possível adicionar algum item no fim,
       eu o faco no lugar apontado por _fim (é o próximo lugar
       vazio), entao o incremento. Dessa forma, eu preservo o fato
       de _fim semrpe apontar para o próximo lugar vazio.
       Exceto se ele coincidir com o início; neste caso, como eu acabei
       de adicionar um valor, a lista esta cheia. */
}

template <typename T>
bool Lista< T >::retira( T& obj ) {
    if( _vazio )
        return false;

    //A algebra modular do c++ não funciona do jeito matematico para valores negativos...
    _fim = (_fim -1 + _tam) %_tam;
    
    obj = _dados[_fim];
    if( _inicio == _fim )
        _vazio = true;

    _cheio = false; //Pois acabei de retirar um valor.

    return true;
    /* Como o fim aponta para a primeira posicao vazia, caso a lista
       não esteja vazia, (_fim - 1) aponta para o último espaço
       ocupado. Decrementando-o, ele passa a apontar para lá; entao,
       eu jogo esse valor em obj e passo a considerar aquele lugar 
       vazio. */
}

template <typename T>
bool Lista< T >::adicionaNoInicio( T obj ) {
    if ( _cheio )
        return false;
    
    _inicio = (_inicio -1 + _tam) % _tam;
    
    _dados[_inicio] = obj;
    if( _inicio == _fim )
        _cheio = true;

    _vazio = false;

    return true;
    /* _inicio sempre aponta para o primeiro valor da lista; tenho de manter essa propriedade. */
}

template <typename T>
bool Lista< T >::retiraDoInicio( T& obj ) {
    if( _vazio )
        return false;

    obj = _dados[_inicio];
    _inicio = (_inicio + 1) % _tam;
    if( _inicio == _fim )
        _vazio = true;

    _cheio = false;

    return true;
}

template <typename T>
bool Lista< T >::adicionaNaPosicao( int pos, T obj ) {
    if( _cheio )
        return false;

    if( pos < 0 || pos > obterTamanho() )
        return false;

    int l, i, ni; //ni == next i;
    if( 2*pos > obterTamanho() ) {
        //Se estamos mais perto do fim, empurraremos os objetos daqui para baixo:
        //Primeiro, iremos converter a posição lógica para uma posição física:
        l = (_inicio + pos) % _tam; //Local físico da inserção.
        int i, ni; //i, next i;
        for( i = _fim; i != l; i = ni ) {
            ni = (i - 1 + _tam) % _tam;
            _dados[i] = _dados[ni];
        }
        _fim = (_fim + 1) % _tam;
    } else {
        //Senão, puxamos os objetos do inicio:
        l = (_inicio + pos - 1 + _tam) % _tam;
        /* Eu estou, logicamente, jogando o vetor para índice -1: onde estava na posição (pos),
           agora, será pos + 1; e eu quero colocar o novo objeto uma posição antes.
           Então, vou abrir posições até a posição l: */
        for( i = (_inicio - 1 + _tam) % _tam, ni = _inicio; i != l; ni = (_inicio + i) % _tam ) {
            _dados[i] = _dados[ni];
            i = ni;
        }
        _inicio = (_inicio - 1 + _tam) % _tam;
    }
    _dados[l] = obj;

    _vazio = false;
    if( _fim == _inicio )
        _cheio = true;

    return true;        
}

template <typename T>
bool Lista< T >::retiraDaPosicao( int pos, T& obj ) {
    obj = operator[] (pos);
    return retiraDaPosicao( pos );
}

template <typename T>
bool Lista< T >::retiraDaPosicao( int pos ) {
    if (pos < 0 || pos >= obterTamanho() )
        return false;
    //Se houverem zero elementos, já é barrado aqui.
    
    int l = (pos + _inicio) % _tam; //Local físico da remoção.
    int i, ni;
    // Há dois casos: o objeto está mais perto do fim ou do começo da lista.
    if (2*pos > obterTamanho() ) {
        i = l; ni = (l + 1) % _tam;
        for( ; ni != _fim; ni = (ni + 1)% _tam) {
            _dados[i] = _dados[ni];
            i = ni;
        }
        _fim = (_fim - 1 + _tam) % _tam;
    }
    else
    {
        i = l; ni = (l - 1 + _tam) % _tam;
        for( ; i != _inicio; ni = (ni - 1 + _tam) % _tam ) {
            _dados[i] = _dados[ni];
            i = ni;
        }
        _inicio = (_inicio + 1) % _tam;
    }

    _cheio = false;
    if( _fim == _inicio )
        _vazio = true;

    return true;
}

template <typename T>
int Lista< T >::obterTamanho() {
    if( _cheio )
        return _tam;
    
    return ( (_fim >= _inicio) ? (_fim - _inicio) : (_fim + _tam - _inicio) );
}

template <typename T>
int Lista< T >::obterTamanhoMax() {
    return _tam;
}
    
template <typename T>
T* Lista< T >::paraArray() {
    int t = obterTamanho();
    T* ret = new T[t];
    int j = _inicio;
    for( int i = 0; i < t; i++ )
        ret[i] = _dados[j++ % _tam];

    return ret;
}

template <typename T>
bool Lista< T >::cheio() {
    return _cheio;
}

template <typename T>
bool Lista< T >::vazio() {
    return _vazio;
}

template <typename T>
int Lista< T >::posicao( T obj ) {
    if( _vazio )
        return -1;

    if( _dados[_inicio] == obj )
        return 0;
    //Eu considerei o caso especial de o objeto estar na primeira posição por causa de minha condição de parada:
    //caso a lista estiver cheia, o início e o fim coincidirão.
    for( int i = (_inicio + 1) % _tam; i != _fim; i = (i + 1) % _tam )
        if( _dados[i] == obj )
            return (i - _inicio + _tam) % _tam;

    return -1; //Nada foi achado.
}

template <typename T>
bool Lista< T >::contem( T obj ) {
    return posicao( obj ) != -1;
}

template <typename T>
bool Lista< T >::retiraEspecifico( T obj ) {
    int i = posicao( obj );
    if( i == -1 )
        return false;
    retiraDaPosicao( i );
    return true;
}

template <typename T>
bool Lista< T >::adicionaEmOrdem( T obj ) {
    if( _cheio )
        return false;

    if( _vazio ) //Preciso me livrar deste caso, pois, aqui, os ponteiros para o fim e para o início coincidem.
        return adiciona( obj ); //adiciona retorna true aqui.

    int l = _inicio;
    for( ; l != _fim; l = (l + 1) % _tam )
        if (!(_dados[l] < obj)) //Opa: achei o lugar de inserir o objeto.
            return adicionaNaPosicao( (l - _inicio + _tam) % _tam, obj );

    //Nenhum é menor do que o que quero adicionar; jogo no fim, então.
    return adiciona( obj );
}
  
template <typename T>
void Lista< T >::limparLista() {
    //Não estamos chamando destrutores, então...
    _inicio = _fim = 0;
    _cheio = false;
    _vazio = true;
}

template <typename T>
bool Lista< T >::operator<<(T obj) {
    return this->adiciona(obj);
}
    
template <typename T>
bool Lista< T >::operator>>(T& obj) {
    return this->retiraDoInicio(obj);
}

template <typename T>
T& Lista< T >::operator[] (int pos) {
    return _dados[ (pos + _inicio) % _tam ];
}

#endif

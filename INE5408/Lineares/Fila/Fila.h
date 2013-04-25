/* Fila.h: Representa uma fila.
 * Contem otimizacoes (gambiarras) que permitem remocao de objetos
 * (desenfileiramento) com compexidade O(1).
 * A principal alteracao em relacao ao que foi proposto em aula e' a existencia
 * de dois indices: um apontando o inicio da fila (donde serao desenfileirados
 * os dados) e um apontando para a proxima posicao vazia (para enfileirar dados).
 * Ao remover dados, ao inves de deslocar todos os outros para o inicio, apenas
 * o indice e' alterado. E, caso o indice que aponta para o fim chegue ao fim
 * do vetor, ele "volta para o inicio", dando uma volta no vetor; portanto, e'
 * necessario uma algebra modular nao tao trivial para evitar escritas no lugar
 * errado. 
 */

#ifndef FILA_H
#define FILA_H

template<typename T>
class Fila {
public:
    //tam = capacidade maxima da fila.
    Fila(int tam);

    //enfileirar: insere um objeto no fim da fila, retorna true se deu certo.
    bool enfileirar( T obj );

    //desenfileirar: remove um objeto do inicio da fila, e o grava em obj. Retorna true caso deu certo;
    //               se nao deu, retorna false e obj nao e alterado.
    bool desenfileirar( T& obj );
    
    //Retorna a quantidade de objetos na fila.
    int obterTamanho();
    
    //Retorna a quantidade de objetos que a fila pode armazenar, no total.
    int obterTamanhoMax();
    
    //paraArray: retorna uma representacao em array dos elementos na fila.
    T* paraArray();
    
    void limparFila();
    
    bool cheio();
    
    bool vazio();

    //Operador <<obj : redireciona para enfileirar(obj).
    bool operator<<(T obj);
    
    //Operador >>obj : redireciona para desenfileirar(obj).
    bool operator>>(T& obj);

private:
    T* _dados;
    int _tam;
    int _inicio; //Aponta para o primerio da fila
    int _fim; //Aponta para o proximo lugar vazio
    bool _cheio;
    bool _vazio;
};

//Implementacoes:

template <typename T>
Fila< T >::Fila(int tam) {
    _dados = new T[tam];
    _tam = tam;
    _fim = _inicio = 0;
    _cheio = false;
    _vazio = true;
}

template <typename T>
bool Fila< T >::enfileirar( T obj ) {
    if ( _cheio )
        return false;

    _dados[_fim] = obj;
    _fim = (_fim + 1) % _tam;
    if( _inicio == _fim )
        _cheio = true;

    _vazio = false;

    return true;
}

template <typename T>
bool Fila< T >::desenfileirar( T& obj ) {
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
int Fila< T >::obterTamanho() {
    if( _cheio )
        return _tam;
    
    return ( (_fim >= _inicio) ? (_fim - _inicio) : (_fim + _tam - _inicio) );
}

template <typename T>
int Fila< T >::obterTamanhoMax() {
    return _tam;
}
    
template <typename T>
T* Fila< T >::paraArray() {
    int t = obterTamanho();
    T* ret = new T[t];
    int j = _inicio;
    for( int i = 0; i < t; i++ )
        ret[i] = _dados[j++ % _tam];

    return ret;
}

template <typename T>
void Fila< T >::limparFila() {
    delete _dados;
    _dados = new T[_tam];
    _fim = _inicio = 0;
    _cheio = false;
    _vazio = true;
}

template <typename T>
bool Fila< T >::cheio() {
    return _cheio;
}

template <typename T>
bool Fila< T >::vazio() {
    return _vazio;
}
   
template <typename T>
bool Fila< T >::operator<<(T obj) {
    return this->enfileirar(obj);
}
    
template <typename T>
bool Fila< T >::operator>>(T& obj) {
    return this->desenfileirar(obj);
}
#endif

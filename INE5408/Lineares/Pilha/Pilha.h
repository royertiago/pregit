/* Pilha.h: Representa uma pilha.
 * A principal alteração em relacao ao que foi visto em aula é
 * o fato de a variável _topo não apontar para o topo da pilha,
 * e sim para a próxima posicão vazia da pilha. Isso simplifica
 * (um pouco) o código, embora a semântica da variavel seja perdida.
 */

#ifndef PILHA_H
#define PILHA_H

template<typename T>
class Pilha {
public:
    //tam = capacidade máxima da pilha.
    Pilha(int tam);

    //empilhar: insere um objeto no topo da pilha, retorna true se deu certo.
    bool empilhar( T obj );

    //desempilhar: remove um objeto do topo da pilha, e o grava em obj. Retorna true caso deu certo;
    //             se não deu, retorna false e obj nao é alterado.
    bool desempilhar( T& obj );
   
    //Informa o topo da pilha, sem removê-lo.
    T topo();

    //Retorna a quantidade de objetos na pilha.
    int obterTamanho();
    
    //Retorna a quantidade de objetos que a pilha pode armazenar, no máximo.
    int obterTamanhoMax();
    
    //paraArray: retorna uma representação em array dos elementos na pilha.
    T* paraArray();
    
    void limparPilha();
    
    bool cheio();

    bool vazio();

    //Operador <<obj : redireciona para empilhar(obj).
    bool operator<<(T obj);
    
    //Operador >>obj : redireciona para desempilhar(obj).
    bool operator>>(T& obj);

    Pilha< T > operator+( Pilha< T > alvo );

private:
    T* _dados;
    int _tam;
    int _topo; //Aponta para a próxima posição vazia.
};

//Implementações:

template <typename T>
Pilha< T >::Pilha(int tam) {
    _dados = new T[tam];
    _tam = tam;
    _topo = 0;
}

template <typename T>
bool Pilha< T >::empilhar( T obj ) {
    if ( cheio() )
        return false;

    _dados[_topo++] = obj;
    return true;
}

template <typename T>
bool Pilha< T >::desempilhar( T& obj ) {
    if( vazio() )
        return false;

    obj = _dados[--_topo];
    return true;
}

template <typename T>
T Pilha< T >::topo() {
    return _dados[_topo - 1];
}

template <typename T>
int Pilha< T >::obterTamanho() {
    return _topo;
}

template <typename T>
int Pilha< T >::obterTamanhoMax() {
    return _tam;
}
    
template <typename T>
T* Pilha< T >::paraArray() {
    T* ret = new T[_topo];
    for( int i = 0; i < _topo; i++ )
        ret[i] = _dados[i];

    return ret;
}

template <typename T>
void Pilha< T >::limparPilha() {
    delete _dados;
    _dados = new T[_tam];
    _topo = 0;
}

template <typename T>
bool Pilha< T >::cheio() {
    return _topo == _tam;
}

template <typename T>
bool Pilha< T >::vazio() {
    return !_topo; //Está vazio se topo == 0
}
   
template <typename T>
bool Pilha< T >::operator<<(T obj) {
    return this->empilhar(obj);
}
    
template <typename T>
bool Pilha< T >::operator>>(T& obj) {
    return this->desempilhar(obj);
}

#endif

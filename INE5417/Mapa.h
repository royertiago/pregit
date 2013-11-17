#ifndef CAMPO_H
#define CAMPO_H
#include <list>
using std::list;
class Cidade;
class Estrada;
class Time;
class Mapa {
public:
    list<*Cidade> cidades;
    list<*Estrada> estradas;
    list<*Time> times;
    *Cidade obterCidade( string s );
    Campo();
    virtual ~Campo();
protected:
private:
};

#endif // CAMPO_H

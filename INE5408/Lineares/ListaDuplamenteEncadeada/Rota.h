/* Rota.h
 * Definição de uma rota de ônibus.
 *
 * A rota contêm uma lista de cidades e um preço.
 *
 * A função de entrada assume que estarão, em linhas separadas,
 * o preço da passagem, a quantidade de cidades, e as cidades,
 * de acordo com a formatação de uma cidade, definida em Cidade.h.
 *
 * A função de saída imprime apenas a cidade de origem/destino,
 * valor da passagem, e total de cidades.
 */

#ifndef ROTA_H
#define ROTA_H

#include "Cidade.h"
#include "CabecaDeLista.h"
#include "Iterador.h"

class Rota {
public:
    Rota();
    ~Rota();

    friend ostream& operator<<( ostream& os, Rota& );
    friend istream& operator>>( istream& is, Rota& );

    // Imprime a rota por completo, não somente as informações de cabeçalho.
    void print( ostream& os );
    bool operator ==( const Rota& r ) const { return this == &r; }
    double obterPreco() const { return preco; }

    // Retorna um iterador apontando para a primeira cidade.
    Iterador<Cidade> iterador();
     
private:
    Rota( const Rota& ) {}
    Rota& operator=( const Rota& ) {}

    CabecaDeLista<Cidade>* cidades;
    double preco;
    char* empresa;
};

#endif /* ROTA_H */

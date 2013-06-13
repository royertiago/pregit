/* Produto.cpp */

#include "Produto.h"

#include <random>
#include <chrono>
#include <iostream>
using std::ostream;

Produto::Produto( double custo, double lucro, double complexidade ):
    custo(custo),
    lucro(lucro),
    complexidade(complexidade)
{}

Produto* Produto::gerarProduto() {
    // Parafernália para geração de números aleatórios
    static std::default_random_engine g ( std::chrono::system_clock::now().time_since_epoch().count() );
    static std::gamma_distribution<double> custo (1.5,8.0);
    static std::gamma_distribution<double> lucro (5.0,8.0);
    static std::gamma_distribution<double> complexidade (2.0,1.5);

    static double c;
    c = custo(g);
    return new Produto( c, c * (lucro(g) + 12)/100.0, complexidade(g) + 1.0 );
    // O lucro é uma porcentagem do custo, e a complexidade de passagem sempre será superiora a 1.
}

ostream& operator<<( ostream& os, const Produto& p ) {
    return os << p.custo << " - " << p.lucro << " - " << p.complexidade;
}

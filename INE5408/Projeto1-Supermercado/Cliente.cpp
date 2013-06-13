/* Cliente.cpp
 * Contém as implementações do construtor, do gerador de clientes, e do operator<<(ostream&, Cliente c). */
#include "Cliente.h"

#include "CabecaDeLista.h"
#include "IteradorConstante.h"

#include "Produto.h"
#include "Guiche.h"

#include <chrono>
#include <random>
#include <iostream>
using std::ostream;

Cliente::Cliente( CabecaDeLista<Produto>&& carrinho, int id, double pagamento, int (Guiche::* const criterio)(void) const, int tolerancia ):
    carrinho(carrinho),
    id(id),
    pagamento(pagamento),
    criterio(criterio),
    tolerancia(tolerancia)
{}

static int (Guiche::* const criterioInteligente)(void) const = &Guiche::obterTempoTotal;
static int (Guiche::* const criterioBurro)(void) const = &Guiche::obterTamanhoFila;

Cliente* Cliente::gerarCliente() {
    // Parafernália para geração de números aleatórios
    static std::default_random_engine g ( std::chrono::system_clock::now().time_since_epoch().count() );
    static std::gamma_distribution<double> pgto (1.5,1.25);
    static std::gamma_distribution<double> itens (1.25,5.0);

    static int id = 1;
    int qtde = (int) (1 + 5*itens( g ));
    CabecaDeLista<Produto> carrinho;

    for( int i = 0; i < qtde; i++ )
        carrinho.adiciona( Produto::gerarProduto() );

    double pagamento = (int) 5*(pgto( g ) + 1 );
    int (Guiche::* criterio) (void) const = 0;
    int tolerancia;

    if( g() % 2 == 0 ) {
        criterio = criterioInteligente;
        tolerancia = g() % 1200 + 600;
    }
    else {
        criterio = criterioBurro;
        tolerancia = g() % 10 + 10;
    }
    return new Cliente( static_cast< CabecaDeLista<Produto> && >(carrinho), id++, pagamento, criterio, tolerancia );
}

int Cliente::escolherFila( const CabecaDeLista<Guiche>& guiches ) const {
    int bestIndex = 0;
    IteradorConstante<Guiche> i = guiches.iterador();
    if( i.volta() ) {
        return -1; //Caso não hajam guiches, retornemos.
    }

    int best = (*i.*criterio)();
    ++i;
    // j é o índice atual.
    for( int j = 1; !i.volta(); ++i, ++j ) {
        if( (*i.*criterio)() < best ) {
            bestIndex = j;
            best = (*i.*criterio)();
        }
    }

    if( best <= tolerancia )
        return bestIndex;

    return -1;
}

ostream& operator<<( ostream& os, const Cliente& c ) {
    os << c.id << " - " << c.carrinho.tamanho() << " - ";
    double custo = 0.0, lucro = 0.0, complexidade = 0.0;
    for( IteradorConstante<Produto> i = c.carrinho.iterador(); !i.volta(); ++i ) {
        custo += i->custo;
        lucro += i->lucro;
        complexidade += i->complexidade;
    }

    return os << custo << " - " << lucro << " - " << complexidade
              << (c.criterio == criterioInteligente ? " - Cliente Inteligente" : " - Cliente Burro" );
}

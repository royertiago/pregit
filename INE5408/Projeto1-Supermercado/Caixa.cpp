/* Caixa.cpp
 * Contém a implementação dos construtores, do gerador de caixas,
 * do ostream& operator<< e da função que informa o tempo de atendimento de um cliente. */

#include "Caixa.h"
#include "IteradorConstante.h"
#include "Cliente.h"
#include "Produto.h"

#include<cstring>
using std::strcpy;
using std::strlen;

#include <iostream>
using std::istream;
using std::ostream;

#include <random>
#include <chrono>

Caixa::Caixa( Caixa&& c ):
    nome(c.nome),
    eficiencia(c.eficiencia),
    salario(c.salario),
    id(c.id)
{
    c.nome = 0;
}

Caixa::Caixa( char*&& nome, double eficiencia, double salario, int id ):
    nome(nome),
    eficiencia(eficiencia),
    salario(salario),
    id(id)
{
    nome = 0;
}

Caixa::Caixa( const Caixa& c ):
    eficiencia(c.eficiencia),
    salario(c.salario),
    id(c.id)
{
    static char* nomeGrande = new char[128];
    char* Nome;
    nome = new char[strlen(nomeGrande)+1];
    strcpy( Nome, nomeGrande );
    nome = Nome;
}

Caixa::~Caixa() {
    delete nome;
}

int Caixa::tempoPassagem( Cliente* c ) const {
    double tempo = 0;
    for( auto i = c->carrinho.iterador(); !i.volta(); ++i ) {
        tempo += i->complexidade * this->eficiencia;
    }

    return tempo + c->pagamento * this->eficiencia;
}

double Caixa::atender( Cliente* c ) const {
    double lucro = 0;
    for( auto i = c->carrinho.iterador(); !i.volta(); ++i ) {
        lucro += i->lucro;
    }
    return lucro;
}

static int IDs = 0;
Caixa* Caixa::gerarCaixa( istream& is ) {
    double salario, eficiencia;
    static char* nomeGrande = new char[128];
    char* nome;

    is >> salario >> eficiencia;

    while( is.peek() == ' ' )
        is.ignore();

    is.getline( nomeGrande, 128 );
    nome = new char[strlen(nomeGrande)+1];
    strcpy( nome, nomeGrande );
    return new Caixa( static_cast<char*&&>( nome ), eficiencia, salario/220.0, IDs++ );
}

Caixa* Caixa::gerarCaixa() {
    static std::default_random_engine gen ( std::chrono::system_clock::now().time_since_epoch().count() );
    static std::uniform_real_distribution<double> eficiencia(1.0, 4.0);
    static std::uniform_real_distribution<double> salario(0.0, 500.0);
    double Eficiencia = eficiencia( gen );

    char* nome = new char[17];
    strcpy( nome, "Caixa temporário" );

    return new Caixa( (char*&&) nome, Eficiencia, (5-Eficiencia)*(500.0 + salario(gen))/220.0, IDs++ ); 
}

ostream& operator<<( ostream& os, const Caixa& c ) {
    return os << c.nome << " - " << c.eficiencia << " - " << c.salario;
}

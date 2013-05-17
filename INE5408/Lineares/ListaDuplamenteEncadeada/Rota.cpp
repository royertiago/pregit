/* Definição de Rota.h */

#include "Rota.h"
#include "CabecaDeLista.h"
#include "Cidade.h"
#include "Iterador.h"

#include "DebugUtils.h"

#include <iostream>
#include <cstring>
using namespace std;

Rota::Rota():
    cidades( new CabecaDeLista<Cidade>() ),
    empresa(0)
{}

Rota::~Rota() {
    delete cidades;
    delete[] empresa;
}

ostream& operator<<( ostream& os, Rota& r ) {
    if( r.cidades->tamanho() == 0 )
        return (os << "Rota vazia\n");

    if( r.cidades->tamanho() == 1 ) {
        os << "Rota unitária - Empresa: " << r.empresa << " - ";
        Cidade* c;
        r.cidades->lerInicio( c );
        os << *c;
        os << "Valor da passagem: R$ " << r.preco;
        return os;
    }

    Cidade *c, *d;
    r.cidades->lerInicio( c );
    r.cidades->ler( d );

    os << "Rota " << c->obterNome() << " - " << d->obterNome() << " - Empresa: " << r.empresa << endl
       << "Valor da passagem: R$ " << r.preco
       << " - Cidades visitadas: " << r.cidades->tamanho() << endl;

    return os;
}

istream& operator>>( istream& is, Rota& r ) {
    r.cidades->limpar();
    delete r.empresa;
    is >> r.preco;

    static char tmp[1024];
    is.ignore();
    is.getline( tmp, 1024 );
    r.empresa = new char[strlen(tmp) + 1];
    strcpy( r.empresa, tmp );

    int i;
    is >> i;
    is.ignore();
    for( ; i > 0; i-- ) {
        Cidade *c = new Cidade();
        is >> *c;
        r.cidades->adiciona( *c );
        // Não posso deletar c, a lista armazenará um ponteiro para ele.
    }
    return is;
}

void Rota::print( ostream& os ) {
    os << *this;
    Iterador<Cidade> it = cidades->iterador();
    while( !it.volta() ) {
        os << "  " << *it;
        ++it;
    }
    debug( cout << "Fim da linha\n" );
}

Iterador<Cidade> Rota::iterador() {
    return cidades->iterador();
}

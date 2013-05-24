// Implementação de local.h.
#include "Local.h"
#include <iostream>
#include <cstring>
using namespace std;

Local::Local():
    nome(0),
    cep(0)
{}

Local::Local( char* n, int c ):
    nome( new char[strlen(n) + 1] ),
    cep( c ) {
    strcpy( nome, n );
}

Local::Local( const Local& l ):
    nome( new char[strlen(l.nome) + 1] ),
    cep( l.cep ) {
    strcpy( nome, l.nome );
}

Local::~Local() {
    delete nome;
}

Local& Local::operator=( const Local& l ) {
    delete nome;
    cep = l.cep;
    nome = new char[strlen(l.nome) + 1];
    strcpy( nome, l.nome );
}

bool Local::operator<( const Local& l ) {
    return strcmp( nome, l.nome ) < 0;
}

bool Local::operator>( const Local& l ) {
    return strcmp( nome, l.nome ) > 0;
}

bool Local::operator<=( const Local& l ) {
    return strcmp( nome, l.nome ) <= 0;
}

bool Local::operator>=( const Local& l ) {
    return strcmp( nome, l.nome ) >= 0;
}

bool Local::operator==( const Local& l ) {
    return strcmp( nome, l.nome ) == 0;
}

bool Local::operator!=( const Local& l ) {
    return strcmp( nome, l.nome ) != 0;
}

ostream& operator<<( ostream& os, Local& l ) {
    os << l.nome << " - " << l.cep;
    return os;
}

istream& operator>>( istream& is, Local& l ) {
    static char alce[1000];
    int i = 0;
    while(( alce[i] = is.get() ) != '|' )
        i++;

    alce[i] = '\0';
    delete l.nome;
    l.nome = new char[i + 1];
    strcpy( l.nome, alce );

    is >> l.cep;
    return is;
}

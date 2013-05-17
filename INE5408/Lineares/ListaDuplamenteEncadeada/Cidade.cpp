/* Implementação de Cidade.h */

#include <iostream>
#include <cstring>
#include "Cidade.h"
#include "DebugUtils.h"

Cidade::Cidade() : _nome(0), _horario(0), _descricao(0) {}

Cidade::Cidade( const Cidade& c ) {
    assign( c._nome, c._horario, c._descricao );
}

Cidade::Cidade( const char* nome, const char* horario, const char* descricao ) {
   assign( nome, horario, descricao );
}

Cidade::~Cidade() {
    delete _nome;
    delete _horario;
    delete _descricao;
}

Cidade& Cidade::operator=( const Cidade& c ) {
    this->~Cidade();
    assign( c._nome, c._horario, c._descricao );
}

void Cidade::assign( const char* nome, const char* horario, const char* descricao ) {
    int tam = strlen(nome);
    _nome = new char[tam+1];
    strcpy( _nome, nome );
    tam = strlen(horario);
    _horario = new char[tam+1];
    strcpy( _horario, horario );
    tam = strlen(descricao);
    _descricao = new char[tam+1];
    strcpy( _descricao, descricao );
}

bool Cidade::operator==( const Cidade& c ) {
    if( strcmp( _nome, c._nome ) )
        return false;

    if( strcmp( _horario, c._horario ) )
        return false;

    if( strcmp( _descricao, c._descricao ) )
        return false;

    return true;
}

ostream& operator<<( ostream& os, const Cidade& c ) {
    os << c._nome 
       << " - Chegada: " << c._horario << endl
       << c._descricao << endl;
    return os;
}

istream& operator>>( istream& is, Cidade& c ) {
    debug( cout << "Lendo cidade...\n" );
    static char nome[600], horario[600], desc[600];
    is.getline( nome, 600 );
    is.getline( horario, 600 );
    is.getline( desc, 600 );
    c.~Cidade(); //Destruir os ponteiros
    c.assign( nome, horario, desc );
    return is;
}

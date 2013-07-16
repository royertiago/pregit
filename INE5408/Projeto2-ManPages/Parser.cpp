#include "Parser.h"
#include "TrieIndex.h"
#include <iostream>
using std::ifstream;

Parser::Parser( ifstream& file ):
    _file( file ) {
    _palavra[0] = '\0';
}

const char* Parser::ler() const {
    return _palavra;
}

bool Parser::next() {
    if( ! _file.good() )
        return false;

    int i = 0; // Índice de inserção
    int c; // Último caractere lido

    /* Primeiro passo: descartar os delimitadores antes da próxima
     * palavra. */
    while( (c = _file.peek() ) != EOF ) {
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
            break;
        else
            _file.get();
    }

    // Agora, inseriremos, um a um, os caracteres lidos em _palavra
    while( (c = _file.peek() ) != EOF ) {
        if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
            _palavra[i++] = _file.get();
        else
            break;
    }

    _palavra[i] = '\0';

    if( !_file.good() )
        return false;

    return true;
}

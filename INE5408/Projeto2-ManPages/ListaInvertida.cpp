#include "ListaInvertida.h"
#include "CabecaDeLista.h"
#include "MemoryTrie.h"

void ListaInvertida::inserir( const char* chave, int valor ) {
    int* v = new int(valor);
    int* w = new int;
    CabecaDeLista<int>* l = _data.recuperar( chave );
    l->ler( w );
    if( *w != *v )
        l->adiciona( v );
}

void ListaInvertida::serializar( ofstream& out ) {
    static int (*serializaInt)( const int* , ofstream& ) =
        [] ( const int* x, ofstream& out) -> int {
            out.write(reinterpret_cast<const char*>(x), sizeof(int) );
            return sizeof(int);
        };

    static int (*serializaLista)
                ( const CabecaDeLista<int>*, ofstream& ) =
        [] ( const CabecaDeLista<int>* l, ofstream& out ) ->int {
        // Inner lambda
           int (*serializaInt)( const int* , ofstream& ) =
        [] ( const int* x, ofstream& out) -> int {
            out.write(reinterpret_cast<const char*>(x), sizeof(int) );
            return sizeof(int);
        }; // end inner lambda

             return l->serializar( out, serializaInt );
        };

    _data.serializar( out, serializaLista );
}

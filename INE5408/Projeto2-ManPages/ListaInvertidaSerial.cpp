#include "ListaInvertidaSerial.h"
#include "ListaSerializada.h"
#include <fstream>
using std::ifstream;

ListaInvertidaSerial::ListaInvertidaSerial( ifstream& in ) :
    _data( in, [] (ifstream& in, int t) -> CabecaDeLista<int>* {
        return new CabecaDeLista<int>( desserializar<int>( in, 
            [] (ifstream& in, int t) ->int* { //Inner lambda
                int* x = new int;
                in.read( reinterpret_cast<char*>( x ), sizeof(int) );
                return x;
            })); //end inner lambda
        })
{}

CabecaDeLista<int> ListaInvertidaSerial::recuperar( const char* c ) {
    CabecaDeLista<int>* t = _data.recuperar( c );
    if( t == 0 )
        return CabecaDeLista<int>();
    return *t;
}

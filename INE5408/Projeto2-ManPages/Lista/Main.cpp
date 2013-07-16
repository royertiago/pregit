/* Arquivo de teste da lista. */

#include "CabecaDeLista.h"
#include "Iterador.h"
#include "IteradorConstante.h"
#include "ListaSerializada.h"

#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

void lerLista( CabecaDeLista<double> l ) {
    for( Iterador<double> i = l.iterador(); !i.volta(); ++i )
        cout << *i << endl;
}

int main() {
    CabecaDeLista<double> lista;
    lista.adiciona( new double(4.0) );
    lista.adiciona( new double(6.0) );
    lista.adicionaInicio( new double(3.0) );
    lista.adicionaPosicao( new double(5.0), 2 );
    lista.adiciona( new double(7.0) );
    lista.adicionaInicio( new double(2.0) );
    lista.adicionaPosicao( new double(1.0), 0 );
    lista.adicionaPosicao( new double(8.0), 7 );

    ofstream out( "data.dat" );

    int (*s)( const double*, ofstream& ) =
        []( const double* n, ofstream& os ) -> int {
            os.write( reinterpret_cast<const char*>( n ),
                        sizeof( double ) );
            return sizeof( double );
        };

    double* (*d)( ifstream&, int ) =
        []( ifstream& in, int ) -> double* {
            double* d = new double;
            in.read( reinterpret_cast<char*>( d ), sizeof(double) );
            return d;
        };

    cout << "Serializando - " << lista.serializar( out, s ) << endl;
    out.close();
    ifstream in( "data.dat" );
    CabecaDeLista<double> lista2 = desserializar( in, d );

    lerLista( lista );
    cout << endl;
    lerLista( lista2 );
    return 0;
}

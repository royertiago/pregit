#include "Tecnologia.h"

Tecnologia::Tecnologia() :
    quantidade( 1.0 ),
    contador( 0 )
{}

void Tecnologia::aumentarTecnologia() {
    quantidade *= (1 + contador/100.0);
    contador = 0;
}

void Tecnologia::registrarContador( int quantidade ) {
    if( quantidade > 0 )
        contador += quantidade;
}

Tecnologia::operator double () const {
    return quantidade;
}

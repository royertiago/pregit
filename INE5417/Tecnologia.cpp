#include "Tecnologia.h"

Tecnologia::Tecnologia() :
    quantidade( 1.0 )
{}

void Tecnologia::aumentarTecnologia( int percentagem ) {
    quantidade *= (1 + percentagem/100.0);
}

Tecnologia::operator double () const {
    return quantidade;
}

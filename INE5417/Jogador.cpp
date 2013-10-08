#include "Jogador.h"
#include "Tecnologia.h"

int Jogador::idcount = 0;

Jogador::Jogador( Time* t ) :
    id( ++idcount ),
    t(),
    time( t )
{}

Tecnologia& Jogador::tecnologia() {
    return t;
}

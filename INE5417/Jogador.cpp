#include <functional>

#include "Jogador.h"
#include "Tecnologia.h"

int Jogador::idcount = 0;

Jogador::Jogador() :
    id( ++idcount ),
    t()
{}

const Tecnologia Jogador::tecnologia() const {
    return t;
}

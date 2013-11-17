#include "Exercito.h"
#include "ExercitoMovendo.h"
class Cidade;

ExercitoMovendo::ExercitoMovendo( int quantidade, Jogador* dono,
        const cidade* destino ) :
    Exercito( quantidade, dono ),
    destino( destino )
{}

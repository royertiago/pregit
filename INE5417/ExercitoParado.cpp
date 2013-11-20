#include "Exercito.h"
#include "ExercitoMovendo.h"
#include "ExercitoParado.h"

ExercitoParado::ExercitoParado( int quantidade, Jogador* dono ) :
    Exercito( quantidade, dono )
{}

ExercitoMovendo deslocarTropas( int tropas, const Cidade* destino ) {
    return ExercitoMovendo( subtrair(tropas), dono, destino );
}

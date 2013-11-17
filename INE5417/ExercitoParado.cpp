#include "Exercito.h"
#include "ExercitoMovendo.h"
#include "ExercitoParado.h"

ExercitoMovendo* deslocarTropas( int tropas, const Cidade* destino ) {
    return new ExercitoMovendo( subtrair(tropas), dono, destino );
}

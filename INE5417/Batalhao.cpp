#include "Exercito.h"
#include "Batalhao.h"
#include "Jogador.h"

#include <cmath>
using std::round;
using std::ceil;
using std::floor;

#include "Depurador.h"

Batalhao::Batalhao( Exercito* exercito, int limite ) :
    exercito( exercito ),
    limite( limite )
{}

int Batalhao::danificar( double proporcao ) {
    int quantidadeDeMortos = round( proporcao * limite );
    if( quantidadeDeMortos > limite )
        quantidadeDeMortos = limite;

    debug( "Proporcao: %i - Quantidade de mortos: %i - Jogador: %i\n",
            proporcao, quantidadeDeMortos, exercito->dono->id );

    return exercito -> subtrair( quantidadeDeMortos );
}

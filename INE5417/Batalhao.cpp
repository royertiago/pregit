#include "Exercito.h"
#include "Batalhao.h"

#include <cmath>
using std::round;

Batalhao::Batalhao( Exercito* exercito, int limite ) :
    exercito( exercito ),
    limite( limite )
{}

int Batalhao::danificar( double proporcao ) {
    int quantidadeDeMortos = round( proporcao * limite );
    if( quantidadeDeMortos > limite )
        quantidadeDeMortos = limite;

    return exercito -> subtrair( quantidadeDeMortos );
}

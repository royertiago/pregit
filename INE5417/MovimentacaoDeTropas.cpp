#include "MovimentacaoDeTropas.h"
class Exercito;
class Cidade;

MovimentacaoDeTropas::MovimentacaoDeTropas( Exercito* exercito, 
        const Cidade* destino ) :
    exercito( exercito ),
    destino( destino )
{}

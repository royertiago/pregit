#include "MovimentacaoDeTropas.h"
#include "Exercito.h"
class Exercito;
class Cidade;

MovimentacaoDeTropas::MovimentacaoDeTropas( Exercito* exercito, 
        Cidade* const destino ) :
    exercito( exercito ),
    destino( destino )
{}

MovimentacaoDeTropas MovimentacaoDeTropas::unir(
       MovimentacaoDeTropas m ) {
    return MovimentacaoDeTropas( new Exercito( 
                exercito->unir( *m.exercito ) ), destino );
}

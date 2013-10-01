#include "OrdemDeEnvio.h"
#include "MovimentacaoDeTropas.h"
#include "Exercito.h"

class Cidade;

OrdemDeEnvio::OrdemDeEnvio( Cidade* destino, int quantidade,
        Exercito* alvo ) :
    destino( destino ),
    quantidade( quantidade ),
    alvo( alvo )
{}

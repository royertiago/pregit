#include "Eventos.h"
#include "Cliente.h"

eClienteAdicionado::eClienteAdicionado( int espera, const Cliente* cliente, int idCaixa ):
    espera(espera),
    cliente(cliente),
    idCaixa(idCaixa)
{}

eClienteAtendido::eClienteAtendido( double lucro, const Cliente* cliente, int idCaixa ):
    lucro(lucro),
    cliente(cliente),
    idCaixa(idCaixa)
{}

eCarrinhoAbandonado::eCarrinhoAbandonado( double prejuizo, const Cliente* cliente ):
    prejuizo(prejuizo),
    cliente(cliente)
{}

eCaixaContratado::eCaixaContratado( Caixa* caixa ):
    caixa(caixa)
{}

#include <string>

#include "Jogador.h"
#include "Tecnologia.h"
#include "Mapa.h"

#include "Caneta.h"

int Jogador::idcount = 0;

Jogador::Jogador( Time* t ) :
    id( ++idcount ),
    t(),
    time( t )
{}

Tecnologia& Jogador::tecnologia() {
    return t;
}

void Jogador::gerarOrdemDeEnvio( string cidadeOrigem,
        string cidadeDestino, int quantidadeDeTropas )
{
    Cidade* origem = mapa->obterCidade( cidadeOrigem );
    Cidade* destino = mapa->obterCidade( cidadeDestino );
    origem->criarOrdemEnvio( this, destino, quantidadeDeTropas );
}

void Jogador::alterarBalanceamento( string cidade, int soldados ) {
    if( soldados > 10 || soldados < 0 ) {
        Caneta umaCaneta;
        umaCaneta.explodir();
    }
    
    Cidade* alvo = mapa->obterCidade( cidade );
    alvo->modificarBalanceamento( soldados );
}

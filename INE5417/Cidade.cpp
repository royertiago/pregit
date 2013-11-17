#include "Cidade.h"
#include "OrdemDeEnvio.h"
#include "Estrada.h"
#include "Jogador.h"
#include "Time.h"
#include "Exercito.h"
#include "ExercitoParado.h"

#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

Cidade::Cidade( string nome ) : nome( nome ) {}

Cidade::adicionarDestino( Estrada* e ) {
    if( e.esquerda == this )
        destinos[e.direita] = e;
    if( e.direita == this )
        destinos[e.esquerda] = e;
}

Cidade::criarOrdemDeEnvio( Jogador* j, Cidade* d, int tropas ) {
    ordens.emplace_back( j, d, tropas );
}

Cidade::adicionarExercito( Exercito* exercito ) {
    for( ExercitoParado* e : exercitos )
        if( e->dono == exercito->dono ) {
            e->unir( *exercito );
            delete exercito;
            return;
        }
    lista.push_back( exercito );

    //TODO: adicionar um atualizarEstado()?
}

Cidade::alterarBalanceamento( int soldados ) {
    producaoSoldados = soldados;
}

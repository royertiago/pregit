#include "LocalDeBatalha.h"
#include "CampoAberto.h"
#include "ExercitoMovendo.h"
#include "Cidade.h"
#include "Jogador.h"
#include "Time.h"

#include <list>
#include <unordered_map>
#include <unordered_set>
using std::list;
using std::unordered_map;
using std::unordered_set;

CampoAberto::CampoAberto( Cidade* esquerda, Cidade* direita ) :
    cidadeEsquerda( esquerda ),
    cidadeDireita( direita )
{}

void CampoAberto::AdicionarExercito( ExercitoMovendo* exercito ) {
    // Queremos garantir a não-duplicação de exércitos.
    list< ExercitoMovendo* > lista& =
        exercito->destino == cidadeEsquerda? 
            exercitosEsquerda :
            exercitosDireita;

    for( ExercitoMovendo* e : lista )
        if( e->dono == exercito->dono ) {
            e->unir( *exercito );
            delete exercito;
            return;
        }

    lista.push_back( exercito );

    atualizarEstado();
}

void CampoAberto::efetuarBatalha() {
    if( estado == TransitoLivre )
        return;

    /* Iremos criar um mapeamento entre os times e as divisões.
     * No primeiro passo, separaremos os exéricitos de ambos os lados
     * nos times correspondentes. */
    unordered_map< Time*, list< Exercito* > > lados; //da batalha

    for( ExercitoMovendo* e : exercitosEsquerda )
        lados[ e->dono->time ].push_back( e );
    for( ExercitoMovendo* e : exercitosEsquerda )
        lados[ e->dono->time ].push_back( e );

    list< Divisao* > divisoes;
    for( auto pair : lados )
        divisoes.push_back( lados->second );
    /* pair é um par chave-valor. Aqui, a lista de exércitos é o valor,
     * e este é o segundo elemento. */

    Divisao::guerrear( divisoes, h );

    for( Divisao* d : divisoes ) delete d;

    atualizarEstado();
};

void CampoAberto::movimentacaoTerminal() {
    if( estado == EmBatalha )
        return;

    if( campoEsquerda == 0 )
        while( ! exercitosEsquerda.empty() )
            cidadeEsquerda->adicionarExercito( 
                    exercitosEsquerda.pop_back() );
    if( campoDireita == 0 )
        while( ! exercitosDireita.empty() )
            cidadeDireita->adicionarExercito(
                    exercitosDireita.pop_back() );
}

void CampoAberto::movimentacaoEsquerda() {


void CampoAberto::atualizarEstado() {
    /* Limparemos os times e exércitos que não possuem mais
     * soldados. Também contaremos quantos times tem, para determinar
     * se estamos em trânsito livre ou em batalha. */
    unordered_set< Time* > timesRestantes;

    for( list< ExercitoMovendo* >* lista : 
            {&exercitosEsquerda, &ExercitosDireita} )
    /* Estou iterando sobre a lista que contém, como elementos, apenas
     * as listas de exercitos Esquerda e direita, para evitar
     * duplicação de código. */
    for( auto i = lista->begin(); i != lista->end(); ) {
        if( *i == 0 ) //quantidade nula de exércitos
            i = lista->erase( i );
        else {
            timesRestantes.insert( i->dono->time );
            ++i;
        }
    } // Este código estava dentro do foreach externo.

    if( timesRestantes.size() <= 1 )
        estado = TransitoLivre;
    else
        estado = EmBatalha;
}

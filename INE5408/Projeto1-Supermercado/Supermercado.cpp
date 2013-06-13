#include "Supermercado.h"
#include "Caixa.h"
#include "Guiche.h"
#include "Escutador.h"
#include "Eventos.h"
#include "Cliente.h"
#include "Produto.h"

#include "CabecaDeLista.h"
#include "IteradorConstante.h"
#include "Iterador.h"

#include <chrono>
#include <random>
#include <cstring>
using std::strlen;
using std::strcpy;

Supermercado::Supermercado( const char* nome, double mediaTempoClientes, int tamanhoFila ):
    _distribution(mediaTempoClientes),
    _tempoCliente(mediaTempoClientes),
    _tamanhoFila(tamanhoFila),
    _nome(new char[strlen(nome) + 1])
{
    strcpy(_nome, nome);
}

Supermercado::~Supermercado() {
    Escutador* e;
    while( !_ouvintes.vazia() )
        _ouvintes.retira( e );

    delete _nome;
}

void Supermercado::adicionarOuvinte( Escutador* e ) {
    _ouvintes.adiciona( e );
    for( auto i = _guiches.iterador(); !i.volta(); ++i )
        i->adicionarEscutador( e );
}

void Supermercado::adicionarCaixa( Caixa* c ) {
    Guiche* g = new Guiche( c );
    _guiches.adiciona( g );

    for( auto i = _ouvintes.iterador(); !i.volta(); ++i )
        g->adicionarEscutador( i.obter() );

    // Disparar evento de contratação
    eCaixaContratado e( c );
    for( auto i = _ouvintes.iterador(); !i.volta(); ++i )
        i->ouvirContratacao( e );
}

void Supermercado::adicionarCliente() {
    static std::default_random_engine gen ( std::chrono::system_clock::now().time_since_epoch().count() );
    static Cliente* c;
    static Guiche* g;
    static int opcao;
    static double prejuizo;

    c = Cliente::gerarCliente();
    opcao = c->escolherFila( _guiches );

    if( opcao == -1 ) {
        // O cliente não gostou de nenhuma fila; computaremos o prejuízo e dispararemos o evento correspondente.
        prejuizo = 0.0;
        for( auto i = c->carrinho.iterador(); !i.volta(); ++i )
            prejuizo += i->custo + 3*i->lucro;

        eCarrinhoAbandonado e( prejuizo, c );
        for( auto i = _ouvintes.iterador(); !i.volta(); ++i )
            i->ouvirAbandono( e );
    } else {
        // O cliente gostou de uma fila.
        _guiches.lerPosicao( g, opcao );
        g->adicionarCliente( c );
    }

    _tempoCliente = _distribution( gen );
}


void Supermercado::simular( double horas ) {
    int tempoRestante = horas * 3600; //Tempo de simulação restante.

    const int GRANDE = 3141592; // Sentinela

    int proximoEvento = _tempoCliente;

    while( tempoRestante > 0 ) {
        // Primeiro passo: avançar o tempo.
        int avanco = proximoEvento;

        tempoRestante -= avanco;
        _tempoCliente -= avanco;

        /* No laço seguinte, faremos três coisas:
         *  - Avançar o tempo em avanco segundos cada guiche
         *  - Descobir o menor tempo para o próximo evento
         *  - Encontrar a fila mínima */

        proximoEvento = GRANDE;
        int menorFila = _tamanhoFila + 1;

        for( auto i = _guiches.iterador(); !i.volta(); ++i ) {
            i->avancar( avanco );
            int prox = i->obterTempoProximoEvento();
            if( prox != -1 && prox < proximoEvento )
                proximoEvento = prox;
            if( i->obterTamanhoFila() < menorFila )
                menorFila = i->obterTamanhoFila();
        }

        if( menorFila > _tamanhoFila )
            // Temos de contratar um novo caixa.
            adicionarCaixa( Caixa::gerarCaixa() );

        if( _tempoCliente == 0 )
            adicionarCliente();
        
        if( _tempoCliente < proximoEvento )
            proximoEvento = _tempoCliente;
    }

    // Nenhum cliente mais entra; mas ainda existem clientes nas filas esperando sair.
    bool temClientes = true;
    while( temClientes ) {
        temClientes = false;

        int avanco = proximoEvento;  //proximoEvento ainda é válido aqui.
        proximoEvento = GRANDE;
        for( auto i = _guiches.iterador(); !i.volta(); ++i ) {
            i->avancar( avanco );
            int prox = i->obterTempoProximoEvento();
            if( prox != -1 ) {
                temClientes = true;
                if( prox < proximoEvento )
                    proximoEvento = prox;
            }
        } // Fim for
    } // Não tem mais clientes esperando.

    // Fim da simulação.
    return;
}

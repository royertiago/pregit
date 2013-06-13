/* Guiche.cpp */

#include "Guiche.h"
#include "Caixa.h"
#include "CabecaDeLista.h"
#include "Cliente.h"
#include "Escutador.h"
#include "Eventos.h"

Guiche::Guiche( Caixa* c ):
    _caixa(c),
    _fila(),
    _tempoEvento(-1),
    _tempoTotal(0)
{}

Guiche::~Guiche() {
    Escutador* e;
    while( !_escutadores.vazia() )
        _escutadores.retira( e );

    delete _caixa;
}

void Guiche::avancar( int s ) {
    if( _tempoEvento == -1 )
        // Se não tem clientes na fila,
        return;

    // Tem clientes na fila.

    if( s < _tempoEvento ) {
        // Não dá tempo de acontecer nenhum evento.
        _tempoEvento -= s;
        _tempoTotal -= s;
        return;
    }

    // Dá tempo de ocorrer um evento.
    
    // Avançar o tempo
    s -= _tempoEvento;
    _tempoTotal -= _tempoEvento;
    
    // Disparar o evento de atendimento
    Cliente* c;
    _fila.retiraInicio( c );
    double lucro = _caixa->atender( c );
    eClienteAtendido evento( lucro, c, _caixa->id );

    for( auto i = _escutadores.iterador(); !i.volta(); ++i )
        i->ouvirAtendimento( evento );

    delete c; //Este cliente já foi atendido.

    // Corrijir previsão de próximo evento
    if( _fila.lerInicio( c ) )
        _tempoEvento = _caixa->tempoPassagem( c );
    else
        _tempoEvento = -1;

    // Verificar próximos eventos
    avancar( s );
}

void Guiche::adicionarCliente( Cliente* c ) {
    eClienteAdicionado evento( _tempoTotal, c, _caixa->id );
    for( auto i = _escutadores.iterador(); !i.volta(); ++i )
        i->ouvirAdicionamento( evento );

    int tempoPassagem = _caixa->tempoPassagem( c );
    _tempoTotal += tempoPassagem;
    if ( _tempoEvento == -1 )
        _tempoEvento = tempoPassagem;

    _fila.adiciona( c );
}

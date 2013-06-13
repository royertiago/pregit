#include "Estatistico.h"
#include "CabecaDeLista.h"
#include "Escutador.h"
#include "Eventos.h"
#include "Supermercado.h"
#include "Guiche.h"

#include "CabecaDeLista.h"
#include "Iterador.h"
#include "IteradorConstante.h"

#include <iostream>
using std::ostream;
using std::endl;

// Estatísticas de cada funcionário.
struct Estatisticas {
    double dinheiroNoBolso; // Dinheiro que a empresa embolsou com este funcionário.
    int tempoEsperaTotal; // Somatório dos tempos de espera dos clientes na fila deste funcionário.
    int qtdeAtendimentos; // Quantidade de clientes atendidos por este funcionário.

    Estatisticas():
        dinheiroNoBolso( 0 ),
        tempoEsperaTotal( 0 ),
        qtdeAtendimentos( 0 )
    {}
};

Estatistico::Estatistico( int qtdeCaixas ) {
    for( int i = 0; i < qtdeCaixas; i++ )
        _estatisticas.adiciona( new Estatisticas() );
}

void Estatistico::ouvirAtendimento( eClienteAtendido e ) {
    Estatisticas* s;
    _estatisticas.lerPosicao( s, e.idCaixa );
    s->qtdeAtendimentos++;
    s->dinheiroNoBolso += e.lucro;
}

void Estatistico::ouvirAdicionamento( eClienteAdicionado e ) {
    Estatisticas* s;
    _estatisticas.lerPosicao( s, e.idCaixa );
    s->tempoEsperaTotal += e.espera;
}

void Estatistico::ouvirAbandono( eCarrinhoAbandonado e ) {
    qtdeAbandonos++;
    prejuizoAbandono += e.prejuizo;
}

void Estatistico::ouvirContratacao( eCaixaContratado ) {
    _estatisticas.adiciona( new Estatisticas() );
}

void Estatistico::gerarEstatisticas( Supermercado* comper, double horas, ostream& os ) {
    double lucroTotal = 0.0;
    double salarios = 0.0;
    os << "Relatório da simulação do supermercado " << comper->obterNome()
        << "\nRelatório individual:\n";

    auto i = comper->obterGuiches().iterador();
    auto j = _estatisticas.iterador();
    for( ; !i.volta() && !j.volta(); ++i, ++j ) {
        os << "Caixa " << i->obterCaixa()->obterNome() << endl;
        double salario = i->obterCaixa()->salario * horas;
        lucroTotal += j->dinheiroNoBolso;
        salarios += salario;
        os << "Lucro total: " << j->dinheiroNoBolso << " - Lucro descontando salário: "
            << j->dinheiroNoBolso - salario << " - Tempo médio de espera na fila: "
            << (double) j->tempoEsperaTotal/j->qtdeAtendimentos << endl;
    }

    os << endl;
    os << "Quantidade de abandonos: " << qtdeAbandonos << " - Prejuízo total com abandonos: " << prejuizoAbandono << endl;
    os << "Lucro total: " << lucroTotal << " - Descontando prejuízo com abandono e salários: "
       << lucroTotal - prejuizoAbandono - salarios << endl;
}

#include "Pichador.h"
#include "Eventos.h"
#include "Cliente.h"
#include "Caixa.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Pichador::Pichador():
    saida( &cout )
{}

Pichador::Pichador( ostream* saida ):
    saida( saida )
{}

void Pichador::ouvirAtendimento( eClienteAtendido e ) {
    *saida << "O cliente " << e.cliente->id << " foi atendido no caixa "
           << e.idCaixa << ". Lucro obtido: R$" << e.lucro << endl;
}

void Pichador::ouvirAdicionamento( eClienteAdicionado e ) {
    *saida << "O cliente " << e.cliente->id << " entrou na fila do caixa "
           << e.idCaixa << ". Previsão de espera: " << e.espera << " segundos.\n";
}

void Pichador::ouvirAbandono( eCarrinhoAbandonado e ) {
    *saida << "O cliente " << e.cliente->id << " abandonou seu carrinho, causando um prejuízo de R$" << e.prejuizo << endl;
}

void Pichador::ouvirContratacao( eCaixaContratado e ) {
    *saida << "O caixa " << e.caixa->obterNome() << " foi contratado, por R$" << e.caixa->salario << " por hora."
              " Possui eficiência " << e.caixa->eficiencia << endl;
}

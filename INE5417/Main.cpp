#include "Tecnologia.h"
#include "OrdemDeEnvio.h"
#include "MovimentacaoDeTropas.h"
#include "Jogador.h"
#include "Exercito.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
    Jogador j;

    Exercito e( 100, &j );
    OrdemDeEnvio o( 0, 30, &e );
        
    cout << *o.alvo << endl;
    cout << e << endl;
}



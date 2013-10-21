#include "Exercito.h"
#include "Batalhao.h"
#include "Jogador.h"

#include <cmath>
using std::round;
using std::ceil;
using std::floor;

#include <iostream>
using std::cout;
using std::endl;

Batalhao::Batalhao( Exercito* exercito, int limite ) :
    exercito( exercito ),
    limite( limite )
{}

int Batalhao::danificar( double proporcao ) {
    int quantidadeDeMortos = round( proporcao * limite );
    if( quantidadeDeMortos > limite )
        quantidadeDeMortos = limite;
    cout << "Proporcao: " << proporcao;
    cout << " - Quantidade de mortos: " << quantidadeDeMortos;
    cout << " - Jogador: " << exercito->dono->id << endl;

    return exercito -> subtrair( quantidadeDeMortos );
}

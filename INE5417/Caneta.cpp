#include "Caneta.h"
#include "Historiador.h"
#include "Jogador.h"

#include <iostream>
#include <iomanip>
#include <unordered_map>
using std::unordered_map;
using std::cout;
using std::endl;
using std::setw;

void Caneta::explodir() {
    cout << "Caneta umaCaneta();\numaCaneta.explodir()\n";
    int * x = 0;
    *x = 3141592;
}

void Caneta::escreverRegistroHistorico( const Historiador& h ) {
    cout << "Jogador | Mortes\n";
    auto mapa = h.obterRegistro();
    for( auto par : mapa )
        cout << setw(3) << par.first->id << setw(10) 
            << par.second << endl;
}

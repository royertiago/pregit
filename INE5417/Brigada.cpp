#include "Batalhao.h"
#include "Brigada.h"
#include "Historiador.h"

#include <list>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using std::list;
using std::unordered_map;
using std::round;
using std::sqrt;
using std::max;
using std::pow;

Brigada::Brigada( list< Batalhao* > batalhoes, double forca,
        unordered_map< Jogador*, double > percentagem ) :
    batalhoes( batalhoes ),
    forca( forca ),
    percentagem( percentagem )
{}

Brigada::~Brigada() {
    for( Batalhao* b : batalhoes )
        delete b;
}

int Brigada::propagarDanos( double percentagem ) {
    int total = 0;
    for( Batalhao* b : batalhoes )
        total += b->danificar( percentagem );

    return total;
}

static const double Phi = (1 + sqrt(5))/2;
// Função de cerco
static double cerco( double x, double y ) {
    return max( 1.0, sqrt( x*y/(10*(x + y)) ) );
}

void Brigada::brigar( Brigada& b1, Brigada& b2, Historiador& h ) {
    // Brigadas com maior e menor força.
    Brigada& maior = (b1.forca > b2.forca ? b1 : b2);
    Brigada& menor = (b1.forca <= b2.forca ? b1 : b2);

    // Dano na brigada menor.
    double danoMenor = 1/ cerco( maior.forca, menor.forca );
    double danoMaior = pow( menor.forca / maior.forca, Phi ) /
                    cerco( maior.forca, menor.forca );

    // Mortes na brigada menor.
    int mortesMenor = menor.propagarDanos( danoMenor );
    int mortesMaior = maior.propagarDanos( danoMaior );

    // Registrar as mortes
    h.registrarMortes( mortesMenor, maior.percentagem );
    h.registrarMortes( mortesMaior, menor.percentagem );
}

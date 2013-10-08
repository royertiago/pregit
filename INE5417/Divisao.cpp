#include "Batalhao.h"
#include "Brigada.h"
#include "Divisao.h"
#include "Exercito.h"
#include "Historiador.h"
#include "Jogador.h"
#include "Tecnologia.h"

#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

#include <iostream>
using std::cout;
using std::endl;

Divisao::Divisao( list< Exercito* > exercitos ) :
    exercitos( exercitos )
{
    forca = 0.0;
    for( Exercito* e : exercitos ) 
        forca += e->operator int() * e->dono->tecnologia();
}

std::unordered_map< Divisao*, Brigada* >
    Divisao::obterBrigadas( list< Divisao* > divisoes )
{
    /* As brigadas precisam desta informação para registrar no
     * historiador as informações das mortes. */
    unordered_map< Jogador*, double > aliados;

    double forcaInterna = 0.0;
    /* A força interna serve para estabelecer as percentagens corretas
     * para o mapeamento [aliados]. 
     * Nossa força total pode ser maior (p.ex. Divisao com muralha). */
    for( Exercito* e : exercitos )
        forcaInterna += e->operator int() * e->dono->tecnologia();
    for( Exercito* e : exercitos )
        aliados[ e->dono ] = e->operator int() * e->dono->tecnologia()/
            forcaInterna;

    double somaForcas = 0.0;
    for( Divisao* d : divisoes )
        somaForcas += d->forca;

    cout << "Forca interna: " << forcaInterna << "\t Somatorio forcas:"
        << somaForcas << endl;

    unordered_map< Divisao*, Brigada* > inimigos;

    for( Divisao* d : divisoes ) {
        double percentual = d->forca / somaForcas;
        cout << "Reservo " << percentual << " para este, que tem "
            << d->forca << " de forca.\n";
        list< Batalhao* > batalhoes;
        for( Exercito* e : exercitos )
            batalhoes.push_front( 
                    new Batalhao( e, percentual * e->operator int() )
                    );

        inimigos[ d ] = new Brigada( batalhoes, 
                forca * percentual, aliados );
    }

    return inimigos;
}

void Divisao::guerrear( list<Divisao*> divisoes, Historiador& h ) {
    unordered_map< Divisao*, unordered_map< Divisao*, Brigada* > > war;
    /* Mapeamento triplo entre duas divisões D1 e D2 e a brigada
     * que a divisão D1 escolheu para enfrentar a brigada da D2. */

    for( Divisao* d : divisoes ) {
        list<Divisao*> lista( divisoes );
        lista.remove( d );
        war[ d ] = d->obterBrigadas( lista );
    }

    for( auto it = divisoes.begin(); it != divisoes.end(); ++it ) {
        auto jt = it;
        for( ++jt; jt != divisoes.end(); ++jt ) {
/*
                    Divisao* d = *it;
                    cout << "Enfrentamento ";
                    Exercito* e = (*d->exercitos.begin());
                    cout << e->dono->id << 'x';
                    d = *jt;
                    e = (*d->exercitos.begin());
                    cout << e->dono->id << endl;
*/
            Brigada* b1 = war[*it][*jt];
            Brigada* b2 = war[*jt][*it];
            Brigada::brigar( *b1, *b2, h );

            delete b1;
            delete b2;
        }
    }
}

#include <iostream>
#include <functional>
#include <unordered_map>
#include <list>
using std::unordered_map;
using std::list;
using std::hash;
using std::cout;
using std::endl;

#include "Batalhao.h"
#include "Brigada.h"
#include "Caneta.h"
#include "Divisao.h"
#include "DivisaoComMuralha.h"
#include "Exercito.h"
#include "Historiador.h"
#include "Jogador.h"
#include "Tecnologia.h"
#include "Time.h"

int main() {
    hash< Time > THash;
    hash< Jogador > JHash;

    // Testar criação de times e jogadores
    Time t1 = Time::fabricarTime( 1 );
    Time t2 = Time::fabricarTime( 2 );
    Time t3 = Time::fabricarTime( 1 );
    Jogador* j = &(*t2.begin());
    cout << "Tecnologia j: " << int(j->tecnologia()) << endl;
    cout << "Hash t3: " << THash( t3 ) << endl;

    // Historiador
    Jogador* j1 = &(*t1.begin());
    auto temp_iterator = t2.begin();
    Jogador* j2 = &(*temp_iterator);
    ++temp_iterator;
    Jogador* j3 = &(*temp_iterator);
    Jogador* j4 = &(*t3.begin());

    Historiador h;
    h.registrarMortes( 6, j1 );
    h.registrarMortes( 10, j2 );
    cout << "Primeiro vencedor: " << h.obterVencedor()->id << endl;
    h.registrarMortes( 10, j3 );
    cout << "Segundo vencedor: " << h.obterVencedor()->id << endl;
    cout << "Segundo vencedor: " << h.obterVencedor()->id << endl;
    cout << "Segundo vencedor: " << h.obterVencedor()->id << endl;
    h.registrarMortes( 8, j4 );
    h.queimaDeArquivo( &t2 );
    cout << "Terceiro vencedor: " << h.obterVencedor()->id << endl;
    h.queimaDeArquivo( j4 );
    cout << "Quarto vencedor: " << h.obterVencedor()->id << endl << 
        endl;

    // Multiplos registros no historiador
    unordered_map< Jogador*, double > m;
    m[j2] = 0.75;
    m[j3] = 0.25;
    h.registrarMortes( 20, m );
    cout << "Quinto vencedor: " << h.obterVencedor()->id << endl;
    h.queimaDeArquivo( j2 );
    cout << "Sexto vencedor: " << h.obterVencedor()->id << endl <<endl;

    // Exércitos e batalhões
    Exercito e( 50, j );
    cout << "Exército inicialmente: " << e << endl;
    Batalhao b( &e, 20 );
    cout << "Batalhão danificou: " << b.danificar( 0.76 ) << endl;
    cout << "Exército após: " << e << endl << endl;

    // Brigadas
    Exercito e1( 20, j1 );
    Batalhao* b1 = new Batalhao( &e1, 20 );
    Exercito e2( 12, j2 );
    Batalhao* b2 = new Batalhao( &e2, 12 );
    Exercito e3( 4, j3 );
    Batalhao* b3 = new Batalhao( &e3, 4 );

    Brigada br1( list<Batalhao*>{b1}, 30.0, {{j1, 1.0}} );
    Brigada br2( list<Batalhao*>{b2, b3}, 40.0, 
            { {j2, 0.75}, {j3, 0.25} } );
    h.queimaDeArquivo( j1 );
    h.queimaDeArquivo( j2 );
    h.queimaDeArquivo( j3 );
    h.queimaDeArquivo( j4 );
    
    Caneta::escreverRegistroHistorico( h );
    Brigada::brigar( br1, br2, h );
    Caneta::escreverRegistroHistorico( h );
    cout << e1 << '\t' << e2 << '\t' << e3 << endl << endl;

    // Divisoes
    h.queimaDeArquivo( j1 );
    h.queimaDeArquivo( j2 );
    h.queimaDeArquivo( j3 );
    h.queimaDeArquivo( j4 );

    j3->tecnologia().registrarContador( 50 );
    j3->tecnologia().aumentarTecnologia();

    Exercito ex1( 20, j1 );
    Exercito ex2( 10, j2 );
    Exercito ex3( 10, j3 );
    Exercito ex4( 10, j4 );
    Divisao d1( list<Exercito*>{&ex1} );
    Divisao d2( list<Exercito*>{&ex2, &ex3} );
    DivisaoComMuralha d3( list<Exercito*>{&ex4}, j4 );
    Divisao::guerrear( list<Divisao*>{&d1, &d2, &d3}, h );
    Caneta::escreverRegistroHistorico( h );
    cout << ex1 << '\t' << ex2 << '\t' << ex3 << '\t' << ex4 << endl;
    cout << h.obterVencedor()->id << endl;

    Caneta umaCaneta;
    //umaCaneta.explodir();
    return 0;
}

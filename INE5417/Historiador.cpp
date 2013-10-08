#include "Historiador.h"
#include "Jogador.h"
#include "Time.h"

#include <unordered_map>
#include <unordered_set>
using std::unordered_map;
using std::unordered_set;
#include <cmath>
using std::round;

#include <random>
#include <chrono>


#include <iostream>
using std::cout;
using std::endl;

void Historiador::registrarMortes( int pontos, Jogador* j ) {
    cout << "Registrando " << pontos << " para " << j->id << endl;
    registro[j] += pontos;
}

void Historiador::registrarMortes( int pontos,
        const unordered_map< Jogador*, double >& proporcao ) {
    for( auto& pair: proporcao )
        registrarMortes( round( pontos * pair.second ), pair.first );
}

void Historiador::queimaDeArquivo( Jogador* j ) {
    registro[j] = 0;
}

void Historiador::queimaDeArquivo( Time* t ) {
    for( Jogador& j : *t )
        this->queimaDeArquivo( &j );
}

Jogador* Historiador::obterVencedor() const {
    int max = -1; // Pontuação máxima até agora.
    // No conjunto, guardaremos todos os jogadores com mais mortes.
    unordered_set< Jogador* > vencedores;

    for( auto & p : registro ) {
        if( p.second > max ) {
            vencedores.clear();
            vencedores.insert( p.first );
            max = p.second;
        }
        else if( p.second == max )
            vencedores.insert( p.first );
    }
    static unsigned int seed = std::chrono::system_clock::now().
        time_since_epoch().count();
    static std::default_random_engine generator (seed);
    
    std::uniform_int_distribution<int> distribution(1,
            vencedores.size());

    int n = distribution(generator);
    /* n é um número aleatório entre zero e a quantidade de jogadores
     * que foram selecionados no conjunto. */
    for( Jogador* j : vencedores ) {
        if( n == 1 )
            return j;
        n--;
    }
    return 0;
}

const unordered_map< Jogador*, int >& Historiador::obterRegistro()
    const {
    return registro;
}

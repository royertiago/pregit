/* O time é uma lista de jogadores.
 *
 * A função de hash retorna o id do primeiro jogador da lista.
 */

#ifndef TIME_H
#define TIME_H

#include <list>
using std::list;

#include "Jogador.h"

class Time {
    list< Jogador > time;
public:

    /* Cria um time vazio, sem jogadores. */
    Time();

    // Simplesmente retorna os iteradores da lista de times.
    list<Jogador>::iterator begin();
    list<Jogador>::const_iterator begin() const;
    list<Jogador>::iterator end();
    list<Jogador>::const_iterator end() const;

    /* Cria um time com a quantidade especificada de jogadores. */
    static Time fabricarTime( int jogadores );

    friend struct std::hash< Time >;
    friend struct std::hash< Time* >;
};

namespace std {
    template <> struct hash< Time > {
        size_t operator()( const Time& t ) const {
            return t.time.front().id; //Piuííí...
        }
    };

    template <> struct hash< Time* > {
        size_t operator()( const Time* & t ) const {
            return t->time.front().id;
        }
    };
} // TODO: Talvez não precise destas especializações.

#endif

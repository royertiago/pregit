/* O time é uma lista de jogadores.
 *
 * A função de hash retorna o id do primeiro jogador da lista.
 */

#ifndef TIME_H
#define TIME_H

#include <list>

class Time {
public:
    Time( const list< Jogadores > time );

    const list< Jogadores > time;
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
}

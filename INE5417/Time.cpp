#include "Time.h"
#include "Jogador.h"

Time::Time() :
    time()
{}

list<Jogador>::iterator Time::begin() {
    return time.begin();
}

list<Jogador>::const_iterator Time::begin() const {
    return time.begin();
}

list<Jogador>::iterator Time::end() {
    return time.end();
}

list<Jogador>::const_iterator Time::end() const {
    return time.end();
}

Time Time::fabricarTime( int jogadores ) {
   Time t;
   for( int i = 0; i < jogadores; i++ )
       t.time.push_back( Jogador( &t ) );
   return t;
}

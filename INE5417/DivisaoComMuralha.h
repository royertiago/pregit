/* A divisão com muralha computa as forças de suas brigadas incluíndo
 * o bônus da muralha. */
#ifndef DIVISAO_COM_MURALHA
#define DIVISAO_COM_MURALHA
#include "Divisao.h"
#include <list>

class Jogador;

class DivisaoComMuralha : public Divisao {
public:
    DivisaoComMuralha( std::list< Exercito* >, Jogador* dono );
    using Divisao::obterBrigadas;
};


#endif

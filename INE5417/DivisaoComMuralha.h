/* A divisão com muralha computa as forças de suas brigadas incluíndo
 * o bônus da muralha. */

#include "Divisao.h"
#include <list>

class Jogador;

class DivisaoComMuralha : public Divisao {
public:
    DivisaoComMuralha( std::list< Exercito* >, Jogador* dono );
    using Divisao::obterBrigadas;
};

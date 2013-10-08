#include "DivisaoComMuralha.h"
#include "Divisao.h"
#include "Jogador.h"
#include <list>
using std::list;

DivisaoComMuralha::DivisaoComMuralha( list< Exercito* > exercitos,
       Jogador* dono ) :
    Divisao( exercitos )
{
    this->forca += 10.0 * dono->tecnologia();
}

/* Contador de Geiger - 
 * Ferramenta para geração em massa de números aleatórios.
 *
 * Os campos abertos possuem uma prioridade que define qual exército
 * avança em caso de empate. O contador de Geiger é responsável
 * por alterar as prioridades dos campos abertos de forma aleatória,
 * a fim de simular o lance de moeda efetuado em cada colisão.
 *
 * Dados n campos abertos para gerência do contador, ele atribuirá
 * os números entre 0 e (n-1) de forma aleatória para cada campo
 * aberto, garantindo unicidade das prioridades. 
 *
 * O contador não exclui os ponteiros dos campos ao ser deletado. */

#ifndef CONTADOR_DE_GEIGER
#define CONTADOR_DE_GEIGER

class CampoAberto;
class Estrada;

#include <list>
using std::list;

class ContadorDeGeiger {
    list< CampoAberto* > campos;
public:
    // Cria um contador de Geiger associado à lista passada.
    ContadorDeGeiger( list< CampoAberto* > );

    /* Cria um contador de Geiger associado aos campos abertos
     * associados às estradas da lista passada. */
    ContadorDeGeiger( list< Estrada* > );

    // Não deletamos ponteiros.
    ~ContadorDeGeiger() = default;

    // Gera os números aleatórios.
    void aferirRadiacao();
};

#endif // ContadorDeGeiger.h

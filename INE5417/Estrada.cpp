#include "Cidade.h"
#include "Estrada.h"
#include "CampoAberto.h"
#include "ExercitoMovendo.h"

#include <cstdlib>
using std::malloc;

/* Atenção: só utilize estas constantes para invocar
 * campos[primeiro] e campos[ultimo]. */
#define primeiro 0
#define ultimo comprimento - 1

Estrada::Estrada( Cidade* esquerda, Cidade* direita, int comprimento ):
    esquerda( esquerda ),
    direita( direita ),
    comprimento( comprimento ),
    // Código potencialmente destrutivo nas próximas cinco linhas
    campos( static_cast< CampoAberto* >(
                malloc(sizeof( CampoAberto[comprimento]) ) ) )
{
    for( int i = 0; i < comprimento; i++ ) // Placement new
        new ( &campos[i] ) CampoAberto( direita, esquerda );

    for( int i = 0; i < comprimento - 1; i++ ) {
        campos[i].campoDireita = &campos[i+1];
        campos[i+1].campoEsquerda = &campos[i];
    }
    campos[primeiro].campoEsquerda = 0;
    campos[ultimo].campoDireita = 0;
}

/* Explicação do código maligno:
 *
 * Este código aloca um vetor de campos abertos de maneira não usual.
 * Se a alocação fosse feita de maneira usual, de acordo com o
 * funcionamento da alocação de vetores, em cada espaço do vetor
 * haveria um campo aberto  criado com o construtor padrão. Entretanto,
 * os campos abertos possuem dois atributos constantes: as cidades
 * de cada lado. Após a construção destes objetos, não seria possível
 * alterar as cidades da esquerda/direita destes campos (que são
 * inicializadas com zero).
 *
 * Para evitar este problema, a solução encontrada foi alocar memória
 * crua do sistema operacional (usando malloc) e construir cada objeto
 * separadamente, no local correto (usando alocação direcionada -
 * placement new).
 *
 * Entretanto, não fica registrado em lugar algum que estes objetos
 * foram criados, então é necessário executar o destrutor de cada
 * objeto explicitamente. */

Estrada::~Estrada() {
    // Neutralização do código maligno do construtor
    for( int i = 0; i < comprimento; i++ )
        campos[i].~CampoAberto();
    free( campos );
}

void Estrada::adicionarExercito( ExercitoMovendo* e ) {
    if( e->dono == esquerda )
        campos[primeiro].adicionarExercito( e );
    else
        campos[comprimento-1].adicionarExercito( e );
}

void Estrada::movimentacaoTerminal() {
    campos[primeiro].movimentacaoTerminal();
    if( comprimento > 1 )
        campos[ultimo].movimentacaoTerminal();
    /* Caso o comprimento seja 1, o primeiro e o último campo
     * serão os mesmos, então chamaríamos movimentacaoTerminal()
     * do mesmo objeto duas vezes. */
}

void Estrada::movimentacaoInterna() {
    for( int i = 0; i <= ultimo; i++ )
        campos[i].movimentacaoEsquerda();
    for( int j = ultimo; j >= 0; j-- )
        campos[j].movimentacaoDireita();
}

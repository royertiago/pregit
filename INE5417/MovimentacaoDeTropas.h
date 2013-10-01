/* É um deslocamento de tropas que ocorre entre cidades.
 * Pode ser tanto de auxílio (entre cidades amigas) quanto de ataque
 * (entre cidades inimigas). Cada movimentação está num campo aberto
 * de uma estrada, possui uma cidade de destino, e um exército
 * associado.
 *
 * O jogador de quem partiu a ordem de envio pode ser deduzido
 * a partir do exército.
 *
 * A movimentação de tropas é um contêiner para os dados associados
 * a ela. Nenhuma movimentação real é feita - isto é tarefa da estrada.
 */

#ifndef MOVIMENTACAO_DE_TROPAS_H
#define MOVIMENTACAO_DE_TROPAS_H

class Exercito;
class Cidade;

class MovimentacaoDeTropas {
public:
    MovimentacaoDeTropas( Exercito*, const Cidade* );
    // Exército a qual esta movimentação de tropas está associado.
    Exercito * const exercito;

    // Destino desta cidade.
    const Cidade * const destino;
};

#endif // MovimentacaoDeTropas.h

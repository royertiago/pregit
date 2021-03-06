/* A tecnologia é um número real que é utilizado na batalha para
 * fortalecer as tropas de cada jogador. Ele começa em 1 para todos
 * os jogadores, e aumenta conforme o jogo progride, caso o jogador
 * opte por tecnologia ao invés de soldados no balanceamento.
 *
 * Cada cidade "gera" tecnologia, de acordo com o balanceamento imposto
 * pelo jogador. No passar do turno, toda a tecnologia produzida pelas
 * cidades é somado (através do método registrarContador()), e o valor
 * da soma é incrementado, em percentagem, na tecnologia (método
 * aumentarTecnologia()).
 *
 * Por exemplo, se um jogador possui 3 cidades, uma delas em cerco, 
 * e escolheu ganhar 3 soldados de cada uma, cada uma das duas cidades
 * que não estão em cerco irá chamar registrarContador( 7 )
 * (totalizando 14 no contador). Quando o método aumentarTecnologia()
 * é chamado, a tecnologia do jogador é multiplicada por 1.14 
 * (é aumentada em 14%) e o contador é zerado.
 */

#ifndef TECNOLOGIA_H
#define TECNOLOGIA_H

class Tecnologia {
private:
    double quantidade;

    // Quanto de tecnologia deve ser aumentado desta vez.
    int contador;

public:
    // Cria uma tecnologia cujo valor inicial é 1.0
    Tecnologia();

    /* O valor da tecnologia será incrementado de acordo com o valor
     * armazenado no contador, e o contador será zerado. */
    void aumentarTecnologia();

    /* Adiciona a quantidade especificada ao contador. Quantias
     * negativas são rejeitadas. */
    void registrarContador( int quantidade );

    // Retorna o valor da tecnologia.
    operator double() const;
};

#endif // Tecnologia.h

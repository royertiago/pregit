/* O batalhão é o responsável por propagar as perdas de uma brigada
 * para o exército correspondente.
 *
 * Como cada batalhão representa um pedaço de um exército, existe
 * um limite de quantos soldados exército pode perder através
 * do batalhão. Este limite é controlado pelo próprio batalhão. */

#ifndef BATALHAO_H
#define BATALHAO_H

class Exercito;

class Batalhao {
private:
    Exercito * const exercito;

    /* Limite de soldados que o exército pode perder através
     * deste batalhão. */
    int limite;

public:
    /* Cria um batalhão associado ao exército passado, limitado
     * apenas à quantidade explicitada de soldados. */
    Batalhao( Exercito *, int );

    /* Mata a proporção especificada de soldados do exército que
     * está sendo controlado por este batalhão. Por exemplo,
     * se proporcao = 0.5, metade dos soldados do limite serão
     * subtraídos do exército correspondente.
     *
     * Caso os danos excederiam o limite, apenas o que não passa
     * o limite é contabilizado.
     *
     * O valor de retorno é a quantidade de soldados que foram,
     * efetivamente, mortos. */
    int danificar( double proporcao );
};
#endif // Batalhao.h

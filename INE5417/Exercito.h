/* O exército é um número natural que representa a quantidade de
 * soldados de um jogador num campo de batalha. São exércitos
 * que se deslocam entre cidades e combatem outros jogadores.
 *
 * Dentro de um campo de batalha deve existir apenas um exército
 * de cada jogador. O método "unir" junta dois exércitos num único.
 *
 * Embora esteja na descrição do exército, não é ele quem gerencia
 * as batalhas. Isto é tarefa das classes anexas - Divisão, Brigada
 * e Batalhão.
 */

#ifndef EXERCITO_H
#define EXERCITO_H

class Jogador;
class ExercitoMovendo;
class Batalhao;

class Exercito {
    friend class Batalhao;
private:
    /* Cria um exército com o mesmo jogador deste e com a quantidade
     * fornecida de soldados. Esta quantidade é subtraída do exército
     * atual. Caso esta quantidade seja superior à quantidade de
     * soldados no exército atual, a quantidade deste é zerada
     * e "transferida" para o exército de destino. */
    //Exercito separar( int quantidade ); TODO: não precisa disto.

    /* Subtrai a quantidade de soldados passada da quantidade atual.
     * (Morte de soldados, por exemplo.)
     *
     * O valor de retorno é a quantidade de tropas removidas. Caso
     * a quantidade a ser subtraída seja maior do que a quantidade
     * disponível, é subtraído até ficar com zero soldados.
     */
    int subtrair( int quantidade );

    // Quantidade de soldados neste batalhão.
    int quantidade = 0;
public:

    Jogador* const dono = 0;

    Exercito() = default;
    Exercito( const Exercito& ) = default;
    virtual ~Exercito() = default;

    // Cria um exércido com a quantidade especificada de soldados.
    Exercito( int quantidade, Jogador* dono );

    // Une este exército com o exército passado. 
    virtual void unir( const Exercito& alvo );

    /* Gera um batalhão que controla a quantidade especificada de
     * soldados. */
    //Batalhao dividir( int quantidade );
    //TODO: Acho que não precisamos disto.

    // Retorna a quantidade de tropas neste exército.
    operator int() const;
};

#endif // Exercito.h

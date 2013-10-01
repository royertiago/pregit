/* O exército é um número natural que representa a quantidade de
 * soldados de um jogador num campo de batalha. São exércitos
 * que se deslocam entre cidades e combatem outros jogadores.
 *
 * Dentro de um campo de batalha deve existir apenas um exército
 * de cada jogador. o método "unir" junta dois exércitos num único.
 *
 */
#ifndef EXERCITO_H
#define EXERCITO_H

class Jogador;

class Exercito {
private:
    int quantidade;
    const Jogador* const dono;

public:
    // Cria um exército de zero soldados sem dono (dono nulo).
    Exercito();

    // Copia os dados do exército passado.
    Exercito( const Exercito& );

    // Cria um exércido com quantidade soldados.
    Exercito( int quantidade, const Jogador* dono );

    /* Cria um exército que corresponde à união deste com o exército
     * alvo. O dono do exército será o mesmo deste. */
    Exercito unir( const Exercito &alvo ) const;

    /* Cria um exército com o mesmo jogador deste e com a quantidade
     * fornecida de soldados. Esta quantidade é subtraída do exército
     * atual. Caso esta quantidade seja superior à quantidade de
     * soldados no exército atual, a quantidade deste é zerada
     * e "transferida" para o exército de destino. */
    Exercito separar( int quantidade );

    /* Subtrai a quantidade de soldados passada da quantidade atual.
     * (Morte de soldados, por exemplo.)
     * 
     * O valor de retorno é a quantidade de tropas removidas. Caso
     * a quantidade a ser subtraída seja maior do que a quantidade
     * disponível, é subtraído até ficar com zero soldados.
     */
    int subtrair( int quantidade );
    
    // Retorna a quantidade de tropas neste exército.
    operator int() const;

    // Retorna a força deste exército.
    double forca() const;
};

#endif // Exercito.h

/* O exército é um número natural que representa a quantidade de
 * soldados de um jogador num campo de batalha. São exércitos
 * que se deslocam entre cidades e combatem outros jogadores.
 *
 * Dentro de um campo de batalha deve existir apenas um exército
 * de cada jogador. O método "unir" junta dois exércitos num único.
 *
 * Embora esteja na descrição do exército, não é ele quem gerencia
 * as batalhas. Isto é tarefa do campo de batalha.
 */
#ifndef EXERCITO_H
#define EXERCITO_H

class Jogador;
class Batalhao;

class Exercito {
    friend class Batalhao;
private:
    int quantidade;

    /* Cria um exército com o mesmo jogador deste e com a quantidade
     * fornecida de soldados. Esta quantidade é subtraída do exército
     * atual. Caso esta quantidade seja superior à quantidade de
     * soldados no exército atual, a quantidade deste é zerada
     * e "transferida" para o exército de destino. */
    //Exercito separar( int quantidade );

    /* Subtrai a quantidade de soldados passada da quantidade atual.
     * (Morte de soldados, por exemplo.)
     * 
     * O valor de retorno é a quantidade de tropas removidas. Caso
     * a quantidade a ser subtraída seja maior do que a quantidade
     * disponível, é subtraído até ficar com zero soldados.
     */
    int subtrair( int quantidade );
 
public:

    Jogador* const dono;
    
    // Cria um exército de zero soldados sem dono (dono nulo).
    Exercito() = default;

    // Copia os dados do exército passado.
    Exercito( const Exercito& ) = default;

    // Cria um exércido com a quantidade especificada de soldados.
    Exercito( int quantidade, Jogador* dono );

    /* Cria um exército que corresponde à união deste com o exército
     * alvo. O dono do exército será o mesmo deste. */
    Exercito unir( const Exercito &alvo ) const;

    /* Gera um batalhão que controla a quantidade especificada de
     * soldados. */
    Batalhao dividir( int quantidade );
    
    // Retorna a quantidade de tropas neste exército.
    operator int() const;
};

#endif // Exercito.h

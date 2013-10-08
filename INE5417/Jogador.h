/* Jogador é uma fachada para acesso ao sistema, que é usado
 * pelos atores para jogar o jogo.
 *
 * O Jogador não é um "jogador" no sentido usual, não é ele
 * quem ganha ou perde as partidas. Ele serve apenas para diferenciar
 * os exércitos de cada jogador.
 *
 * Cada jogador possui um ID único e constante por toda a duração
 * da execução do programa.
 * A função de hash disponível meramente retorna o ID.
 *
 * O "dono" do jogador (responsável por deletar o ponteiro ao fim da
 * execução) é o time.
 */
#ifndef JOGADOR_H
#define JOGADOR_H

#include <functional> //std::hash
#include <string>
using std::string;

#include "Tecnologia.h"

class Time;

/*namespace std {
    template <> struct hash< Jogador* > {
        size_t operator()( Jogador* j ) const;
    };
}*/
 
class Jogador {
private:
    Tecnologia t;

    // Usado para atribuir um novo ID a cada jogador.
    static int idcount;
public:

    /* Cria um jogador com tecnologia 1.0, associado ao time
     * passado. */
    Jogador( Time* );

    const int id;
    Time* const time;

    // Retorna a tecnologia do jogador.
    Tecnologia& tecnologia();

    // Gera uma ordem de envio.
    void gerarOrdemDeEnvio( string cidadeOrigem, string cidadeDestino,
                            int quantidade ) const;

    /* Altera o balanceamento da cidade alvo. A cidade alvo
     * será instruída a gerar a quantidade passada de soldados. */
    void alterarBalanceamento( string cidadeAlvo,
           int balanceamento ) const;

};


namespace std {
    template <> struct hash< Jogador > {
        size_t operator()( const Jogador& j ) const {
            return j.id;
        }
    };

/*    template <> size_t hash< Jogador* >
        ::operator() ( Jogador* j ) const {
            return j->id;
        }*/
}
#endif // Jogador.h

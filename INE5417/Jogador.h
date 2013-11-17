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
class Mapa;
class Time;

class Jogador {
private:
    Tecnologia t;
    
    // Usado para atribuir um novo ID a cada jogador.
    static int idcount;
public:

    // Cria um jogador com tecnologia 1.0, associado ao time passado.
    Jogador( Time* );

    const int id;
    Time* const time; 
    Mapa* const mapa; // Time e mapa em que este jogador está inserido

    // Retorna a tecnologia do jogador.
    Tecnologia& tecnologia();

    // Gera uma ordem de envio associada a este jogador.
    void gerarOrdemDeEnvio( string cidadeOrigem, string cidadeDestino,
                            int quantidade ) const;

    /* Altera o balanceamento da cidade alvo. A cidade alvo
     * será instruída a gerar a quantidade passada de soldados.
     *
     * Passar uma quantidade de soldados maior que 10 ou menor
     * que 0 causa comportamento indefinido. */
    void alterarBalanceamento( string cidadeAlvo,
           int quantidadeSoldados ) const;
};

/* Sobrescrita da função de hash. TODO: o namespace std já define
 * funções de hash padrão para ponteiros. Talvez esta aqui não
 * seja necessária. */
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

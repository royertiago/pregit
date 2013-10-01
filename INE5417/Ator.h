/* O ator é quem irá jogar o jogo.
 *
 * Cada ator que implemente esta classe deve sobrescrever o método
 * jogar(), que deverá conter as ações do jogador efetivo.
 */
#ifndef ATOR_H
#define ATOR_H

#include "Jogador.h"

class Ator {
protected:
    const Jogador* j;

public:
    // Instancia o ator com o jogador passado.
    Ator( Jogador* j );

    // Método que deve ser sobrescrito.
    virtual void jogar() = 0;

    // Não destrói o jogador passado.
    virtual ~Ator();
};

#endif // Ator.h

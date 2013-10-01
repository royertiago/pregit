/* A tecnologia é um número real que é utilizado na batalha para
 * fortalecer as tropas de cada jogador. Ele começa em 1 para todos
 * os jogadores, e aumenta conforme o jogo progride, caso o jogador
 * opte por tecnologia ao invés de soldados no balanceamento.
 */

#ifndef TECNOLOGIA_H
#define TECNOLOGIA_H

class Tecnologia {
private:
    double quantidade;

public:
    // Cria uma tecnologia cujo valor inicial é 1.0
    Tecnologia();

    // O valor da tecnologia será incrementado em percentagem %.
    void aumentarTecnologia( int percentagem );

    // Retorna o valor da tecnologia.
    operator double() const;
};

#endif // Tecnologia.h

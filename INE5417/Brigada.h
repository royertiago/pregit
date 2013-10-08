/* A brigada é uma unidade composta por vários batalhões, de diversos
 * times diferentes. A brigada é responsável por efetuar batalhas.
 *
 * Na batalha, o registro das mortes é proporcional à força de cada
 * jogador; portanto, é necessário uma relação entre o percentual
 * de força de cada jogador e a força total da brigada. 
 * (Por exemplo, se um jogador enviou 4 soldados e o outro 12, o
 * primeiro jogador estará associado com o número 0.25, e o segundo,
 * 0.75.)
 * */
#ifndef BRIGADA_H
#define BRIGADA_H

class Batalhao;
class Jogador;
class Historiador;

#include <list>
#include <unordered_map>

class Brigada {
private:
    // Batalhões envolvidos na guerra.
    std::list< Batalhao* > batalhoes;

    // Força total do batalhão.
    double forca;

    // O quanto da força total cada jogador ajudou.
    std::unordered_map< Jogador*, double > percentagem;

    /* Propaga os danos para todos os batalhões internos.
     * percentagem refere-se à percentagem das tropas que morreram
     * no combate.
     *
     * O retorno é a quantidade de soldados que morreram. */
    int propagarDanos( double percentagem );

public:
    /* Cria uma brigada com os batalhões, forças e percentagem
     * de forças passado. A destruição dos batalhões é responsabilidade
     * da brigada. */
    Brigada( std::list< Batalhao* >, double, 
            std::unordered_map< Jogador*, double > );

    /* Efetua o cálculo da batalha, de acordo com a seção de batalhas
     * entre dois jogadores do documento de regras. */
    static void brigar( Brigada&, Brigada&, Historiador& );

    ~Brigada();
};

#endif // Brigada.h

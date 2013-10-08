/* O historiador é o registrador de batalha.
 * Durante as batalhas, cada jogador será responsável por certa
 * quantidade de mortes dentro de um time, dependendo da quantidade de
 * soldados que enviou à batalha. O registrador de batalha registra
 * quantas mortes cada jogador teve numa batalha específica. Seu 
 * comportamento está detalhado na seção “Conquista de cidades” das
 * regas. O registrador de batalha serve para decidir quem manterá o
 * controle da cidade caso ela seja conquistada por exércitos
 * de mais de um jogador.
 */

#include <unordered_map>

class Jogador;
class Time;
class Caneta;

class Historiador {
private:
    std::unordered_map< Jogador*, int > registro;

public:
    // Cria um historiador.
    Historiador() = default;

    /* Adiciona ao jogador j certa quantidade de pontos (mortes).
     * Caso o jogador não esteja na contagem, ele será adicionado
     * iniciando com a pontuação dada. */
    void registrarMortes( int pontos, Jogador* j );

    /* Registra, a todos os jogadores, certa quantidade de mortos.
     * A quantidade é pontos*valor, sendo valor o valor associado
     * no mapeamento passado.
     *
     * Por exemplo, se houverem dois jogadores mapeados para 0.6 e 0.4,
     * respectivamente, caso ocorram 10 pontos para ambos, ao primeiro
     * será registrado 6 mortes, e ao segundo, 4. */
    void registrarMortes( int pontos, 
            const std::unordered_map< Jogador*, double >& proporcao );

    // Zera a contagem de mortes do jogador j.
    void queimaDeArquivo( Jogador* j );

    /* Zera a contagem de mortos de todos os jogadores 
     * da equipe passada. */
    void queimaDeArquivo( Time* t );

    // Informa quem é o jogador que mais matou.
    Jogador* obterVencedor() const;

    // Devolve o registro deste historiador. 
    const std::unordered_map< Jogador*, int >& obterRegistro() const;
};

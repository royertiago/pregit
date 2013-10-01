/* Registro da batalha
 * Durante as batalhas, cada jogador será responsável por certa
 * quantidade de mortes dentro de um time, dependendo da quantidade de
 * soldados que enviou à batalha. O registrador de batalha registra
 * quantas mortes cada jogador teve numa batalha específica. Seu 
 * comportamento está detalhado na seção “Conquista de cidades” das
 * regas. O registrador de batalha serve para decidir quem manterá o
 * controle da cidade caso ela seja conquistada por exércitos
 * de mais de um jogador.
 */

class Jogador;

class RegistroDeBatalha {
private:
    std::unordered_map< Jogadores*, int > reg;

public:
    // Adiciona ao jogador j certa quantidade de pontos.
    void registrarMortes( int pontos, Jogador* j );

    // Zera a contagem de mortes do jogador j.
    void limparRegistro( Jogador* j );

    // Informa quem é o jogador que 
    Jogador* obterVencedor();
};

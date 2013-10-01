/* Locais de batalha são os locais do jogo que registração
 * exércitos e batalhas no mapa.
 * 
 * Pode ser um campo aberto ou uma cidade.
 *
 */

class Time;

class LocalDeBatalha {
protected:
    // Função que deve ser implementada pelas classes que estendidas.
    virtual unordered_map< Time*, double > obterForcas() = 0;
public:
    LocalDeBatalha();

    // Efetua a batalha de acordo com o método obterForcas.
    void batalhar();

    virtual ~LocalDeBatalha();
};

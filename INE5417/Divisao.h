/* A divisão é a primeira unidade criada na sequuencia de eventos
 * que resultarão nas batalhas. Ele representa a união de diversos
 * exércitos, que mais tarde serão divididos em várias brigadas
 * para efetuar as batalhas individuais.
 *
 * O batalhão existe apenas durante a passagem de turno.
 * O objeto permanente é o exército. */
#ifndef DIVISAO_H
#define DIVISAO_H

#include <list>
#include <unordered_map>

class Brigada;
class Exercito;
class Historiador;

class Divisao {
public:
    std::list<Exercito*> exercitos;

    double forca;

public:
    Divisao( std::list<Exercito*> );

    /* O sistema de batalhas irá passar uma lista de divisões e espera
     * um mapeamento entre divisões e brigadas, uma brigada para cada
     * divisão passada. As divisões passadas são as divisões inimigas,
     * e cada brigada devolvida é a brigada que deverá enfrentar a
     * divisão correspondente.
     *
     * A rotina chamadora deve cuidar do trabalho de deletar as
     * brigadas quando elas não forem mais necessárias. */
    virtual std::unordered_map< Divisao*, Brigada* > obterBrigadas(
        std::list< Divisao* >);

    /* Efetua a guerra entre todas as divisões passadas. */
    static void guerrear( std::list< Divisao* >, Historiador& h );
};    

#endif // Divisao.h

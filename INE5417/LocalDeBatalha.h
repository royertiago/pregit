/* Locais de batalha são os locais do jogo que registração
 * exércitos e batalhas no mapa.
 * 
 * Pode ser um campo aberto ou uma cidade.
 *
 */

#ifndef LOCAL_DE_BATALHA_H
#define LOCAL_DE_BATALHA_H

#include "Historiador.h"


class LocalDeBatalha {
protected:
    Historiador h;
    std::list< Exercito* > exercitos;
public:
    LocalDeBatalha();

    // Efetua a batalha. 
    void batalhar();

    virtual ~LocalDeBatalha();
};

#endif

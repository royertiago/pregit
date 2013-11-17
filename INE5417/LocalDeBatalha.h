/* Locais de batalha são os locais do jogo que registrarão
 * exércitos e batalhas no mapa.
 *
 * Pode ser um campo aberto ou uma cidade.
 *
 * Os locais de batalha são os "donos" dos exércitos; são eles que são
 * responsáveis por deletar os ponteiros, quando estes não são mais
 * necessários.
 */

#ifndef LOCAL_DE_BATALHA_H
#define LOCAL_DE_BATALHA_H

#include "Historiador.h"

class LocalDeBatalha {
protected:
    Historiador h;

public:
    LocalDeBatalha() = default;
    virtual ~LocalDeBatalha() = default;

    // Efetua a batalha.
    virtual void batalhar() = 0;
};

#endif

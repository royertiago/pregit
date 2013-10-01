/* Subdivisão de uma estrada. */

#ifndef CAMPO_ABERTO_H
#define CAMPO_ABERTO_H

#include "LocalDeBatalha.h"

class CampoAberto : public LocalDeBatalha {
public:
    // Informa todos os times que estão controlando este campo aberto.
    list< Time* > obterTimes();
};

#endif

/* Pichador.h
 * Classe que imprime os eventos que recebe. */

#include "Escutador.h"

class eClienteAtendido;
class eClienteAdicionado;
class eCarrinhoAbandonado;
class eCaixaContratado;

#include <iostream>
using std::ostream;

class Pichador: public Escutador {
private:
    ostream* saida;
public:
    // Cria um pichador em cout.
    Pichador();

    explicit Pichador( ostream* os );

    virtual void ouvirAtendimento( eClienteAtendido );
    virtual void ouvirAdicionamento( eClienteAdicionado );
    virtual void ouvirAbandono( eCarrinhoAbandonado );
    virtual void ouvirContratacao( eCaixaContratado );
};

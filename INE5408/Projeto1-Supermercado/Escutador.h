/* Classe capaz de escutar eventos.
 */

#ifndef ESCUTADOR_H
#define ESCUTADOR_H

class eClienteAtendido;
class eClienteAdicionado;
class eCarrinhoAbandonado;
class eCaixaContratado;

class Escutador {
public:
    virtual void ouvirAtendimento( eClienteAtendido ) = 0;
    virtual void ouvirAdicionamento( eClienteAdicionado ) = 0;
    virtual void ouvirAbandono( eCarrinhoAbandonado ) = 0;
    virtual void ouvirContratacao( eCaixaContratado ) = 0;

    virtual ~Escutador() {};
};

#endif //ESCUTADOR_GUICHE_H

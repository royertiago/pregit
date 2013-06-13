/* Eventos.
 * Embora os eventos apontem para clientes e caixas, estes não serão deletados
 * pelos usuário sdesta classe, nem pelo destrutor do evento.*/

#ifndef EVENTOS_H
#define EVENTOS_H

class Cliente;
class Caixa;

/* Evento de cliente adicionado. */
class eClienteAdicionado {
public:
    eClienteAdicionado( int espera, const Cliente* cliente, int idCaixa );
    ~eClienteAdicionado() = default;

    const int idCaixa; // ID do caixa cujo guichê este cliente foi adicionado.
    const int espera; // Tempo de espera para o cliente na fila, até ele começar a ser atendido.
    const Cliente* const cliente;
};

/* Evento de cliente atendido. */
class eClienteAtendido {
public:
    eClienteAtendido( double lucro, const Cliente* cliente, int idCaixa );
    ~eClienteAtendido() = default;

    const int idCaixa; // ID do caixa que atendeu este cliente.
    const Cliente* const cliente;
    const double lucro;
};

/* Evento disparado quando um cliente abandona um carrinho. */
class eCarrinhoAbandonado {
public:
    eCarrinhoAbandonado( double prejuizo, const Cliente* cliente );

    const double prejuizo;
    const Cliente* const cliente;
};

/* Evento de caixa contratado. */
class eCaixaContratado {
public:
    eCaixaContratado( Caixa* );

    const Caixa* const caixa;
};
#endif // Eventos.h

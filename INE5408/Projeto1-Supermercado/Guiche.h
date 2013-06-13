/* Guichê;
 * Possui um ID e uma fila de clientes.
 * Responsável por gerenciar o atendimento dos clientes.
 *
 * Os clientes passados para o guighê serão considerados posse do guichê;
 * seus destrutores serão chamados ao saírem da fila. O caixa passado
 * também é do guichê.
 *
 * Dispara dois eventos: eClienteAtendido e eClienteAdicionado.
 *
 * O controle do tempo do Guichê é relativo ao tempo atual: _tempo é o tempo,
 * em segundos, que demorará para ocorrer o próximo evento eClienteAtendido.
 * Quando ocorre uma chamada ao método avancar( int s ), o guichê executa todas
 * as operações que ocorrem ao avançar o tempo em s segundos, incluindo o que
 * ocorre no instante s.
 * Ou seja, o Guichê recalcula o tempo até o próximo evento, deslocando o
 * referencial s segundos à frente.
 *
 * Note que _previsao >= _tempo >= 0.
 *
 * O guichê atualiza _previsao em dois casos: é executado avancar() ou adicionarCliente().
 * No último caso, o guichê usa o caixa para obter uma previsão de tempo que o caixa
 * demorará para atender o novo cliente.
 */

#ifndef GUICHE_H
#define GUICHE_H

#include "Caixa.h"
#include "CabecaDeLista.h"
#include "Escutador.h"

class Guiche {
private:
    Caixa* _caixa;
    CabecaDeLista<Cliente> _fila;

    // Objetos que serão notificados
    CabecaDeLista<Escutador> _escutadores;

    // Tempo até o próximo evento eClienteAtendido. Caso não hajam clientes na fila, é -1.
    int _tempoEvento;

    // Demora para atender todos os clientes da fila.
    int _tempoTotal;
public:
    Guiche( Caixa* );
    ~Guiche();

    /* Avança o tempo em s segundos e dispara os eventos correspondentes.
     * Assumiremos s > 0. */
    void avancar( int s );

    /* Os escutadores adicionados não serão propriedade do guichê, sendo necessário,
     * portanto, destruição manual destes. */
    void adicionarEscutador( Escutador* e );

    // Coloca um novo cliente na lista e dispara os eventos correspondentes.
    void adicionarCliente( Cliente* );

    // Retorna o tempo do caixa até o próximo evento, em segundos.
    int obterTempoProximoEvento() const;

    // Informa o tempo necessário para atender todos os clientes da fila, em segundos.
    int obterTempoTotal() const;

    // Informa o tamanho da fila de clientes.
    int obterTamanhoFila() const;

    const Caixa* obterCaixa() const;
};

inline int Guiche::obterTempoProximoEvento() const {
    return _tempoEvento;
}

inline int Guiche::obterTempoTotal() const {
    return _tempoTotal;
}

inline int Guiche::obterTamanhoFila() const {
    return _fila.tamanho();
}

inline void Guiche::adicionarEscutador( Escutador* e ) {
    _escutadores.adiciona( e );
}

inline const Caixa* Guiche::obterCaixa() const {
    return _caixa;
}

#endif // Guiche.h

/* Cliente abstrato.
 *
 * Cada cliente possui um número de identificação e uma lista de produtos.
 *
 * O cliente abstrato não define o método de busca de fila; todos os demais métodos
 * estão implementados.
 */

#ifndef CLIENTE_ABSTRATO_H
#define CLIENTE_ABSTRATO_H

#include <iostream>
using std::ostream;

#include "CabecaDeLista.h"
class Produto;
class Guiche;

class Cliente {
private:
    // Critério usado na seleção de filas; o guichê com o menor resultado é escolhido.
    int (Guiche::* const criterio)(void) const;

     // Cria um cliente com o carrinho passado, que utilizará criterio como critério de seleção de filas.
    Cliente( CabecaDeLista<Produto>&& carrinho, int id, double pagamento, int (Guiche::* criterio)(void) const, int tolerancia );
public:
    // Tempo de demora para efetuar o pagamento.
    const double pagamento;

    const CabecaDeLista<Produto> carrinho;

    const int id;

    // Caso o melhor guichê tiver um resultado maior do que tolerância, o cliente abandonará o carrinho.
    int tolerancia;



    /* Método que, dada uma lista de guichês, retorna o índice da
     * fila escolhida pelo cliente. Caso o índice retornado seja
     * -1, significa que o cliente não gostou de nenhuma das filas
     * e resolveu abandonar o carrinho no mercado. */
    int escolherFila( const CabecaDeLista<Guiche>& ) const;

     /* Cria um cliente com id crescente iniciado em 1.
     * Os produtos são gerados através do gerador de produtos de Produto.h.
     * A quantiade de produtos segue a distribuição gama, com alfa=1.25, beta=5.0, multiplicado por 5 acrescido de 1.
     * O tempo de pagamento segue a distribuição gama, com alfa=1.5, beta=1.25, acrescido de 1, multiplicado por 5.
     *
     * Existe 50% de chance de o cliente gerado escolher a fila por tempo de espera; neste caso, a tolerância
     * será um valor aleatório entre 600 e 1200, seguindo a distribuição uniforme.
     * Caso contrário, o cliente escolherá a fila pelo tamanho; neste caso, a tolerância será um valor aleatório
     * entre 10 e 20, seguindo a distribuição uniforme. */
    static Cliente* gerarCliente();

    /* Formato de impressão:
     * <id> - <quantidade de produtos> - <preço total dos produtos> - <lucro total dos produtos> - <tempo total de passagem>\
     *  - <inteligência do cliente>
     * Tempo total de passagem inclui o tempo de pagamento; inteligência do cliente é o modo de escolha de fila dele. */
    friend ostream& operator<<( ostream&, const Cliente& );
};
#endif // ClienteAbstrato.h

/* Produto que pode ser comprado pelo cliente.
 * Utiliza funções análogas a de uma classe do padrão factory para gerar os objetos.
 */
#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
using std::ostream;

class Produto {
public:
    // Custo, para o mercado, do produto.
    const double custo;

    // Lucro que o mercado obtêm com a venda do produto.
    const double lucro;

    // Complexidade para passar no caixa.
    const double complexidade;

    /* Gera um produto com valores aleatórios.
     * O custo segue a distribuição gama, com alfa=1.5, beta=10.0.
     * O lucro é uma porcentagem do custo; essa procentagem segue a distribuição gama, com alfa=5.0, beta=8.0, acrescido de 20.
     * A complexidade segue a distribuição gama, com alfa=2.0, beta=1.5, acrescido de 1.
     */
    static Produto* gerarProduto();

    /* Formato de impressão:
     * <custo> - <lucro> - <complexidade> */
    friend ostream& operator<<( ostream& os, const Produto& p );

private:
    Produto( double, double, double );
};

#endif // Produto.h

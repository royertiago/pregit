/* Caixa de um supermercado.
 * Cada caixa possui um nome, um salário, um parâmetro de eficiência, e um ID.
 * Ele usará este parâmetro de eficiência para determinar quanto
 * tempo levará para atender os clientes.
 *
 * Se um produto possui tempo de passagem 10, e o parâmetro de eficiência
 * é 1.3, este caixa demorará 13 segundos para passar o item.
 *
 * Uma conta similar é feita para o pagamento do cliente.
 *
 * Possui uma função capaz de construir um caixa a partir de uma sintaxe específica:
 * Salário_Mensal Taxa_de_eficiencia Nome Completo.
 */

#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>
using std::ostream;
using std::istream;

class Cliente;

class Caixa {
private:
    const char * nome;
public:
    Caixa( char * && nome, double eficiencia, double salarioPorHora, int id );
    Caixa( Caixa&& );
    Caixa( const Caixa& );
    ~Caixa();
    // Os construtores de transferência apenas transferem o nome. IDs também são copiados.

    // Modificador de eficiência.
    const double eficiencia;

    // Salário, por hora, do funcionário.
    const double salario;

    const int id;

    const char* obterNome() const;

    /* Formato de impressão:
     * <nome> - <eficiencia> - <salario> */
    friend ostream& operator<<( ostream& os, const Caixa& );

    /* Tempo, em segundos, que o caixa demorará para atender o cliente
     * (passar todos os produtos do cliente e efetuar o pagamento).
     */
    int tempoPassagem( Cliente* ) const;

    /* Obtém o lucro gerado pelo cliente. */
    double atender( Cliente* ) const;

    /* Supor-se-á que o objeto passado possui, no local de leitura atual, dois valores double;
     * o primeiro será o salário mensal do caixa, que será dividido por 220; o segundo será a eficiência.
     * Dali para o fim da linha será considerado o nome do caixa. Exemplo:
     * 678 4.0 João De Mora
     * O Caixa de nome "João De Mora" possui eficiência 4.0 e salário 678.00 por mês, ou 3.08 por hora.
     * IDs serão gerados em ordem crescente, partindo de zero. */
    static Caixa* gerarCaixa( istream& );

    /* Gera um caixa temporário.
     * A taxa de eficiência será um valor aleatório entre 1.0 e 4.0, seguindo distribuição constante.
     * O salário será (5 - eficiencia) * ( 500 + k ), sendo k um valor aleatório entre 0.0 e 500.0
     * seguindo distribuição constante. */
    static Caixa* gerarCaixa();
};

inline const char* Caixa::obterNome() const {
    return nome;
}

#endif // Caixa.h

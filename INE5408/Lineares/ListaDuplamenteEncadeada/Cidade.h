/* Representa uma cidade pertencente a um roteiro.
 *
 * O operador de entrada assume que estarão, em linhas separadas,
 * o nome, o horário de chegada, e a descrição das cidades, respectivamente.
 *
 * A função de impressão imprime o nome da cidade e o horário de chegada na linha
 * atual, a descrição da cidade na próxima linha, e imprime uma quebra de linha após.
 */

#ifndef CIDADE_H
#define CIDADE_H
#include <iostream>
#include <cstring>
using namespace std;

class Cidade {
public:
    Cidade();
    Cidade( const Cidade& c );
    Cidade( const char* nome, const char* horario, const char* descricao );
    ~Cidade();
    Cidade& operator=( const Cidade& );

    bool operator==( const Cidade& );
    const char* obterNome() const { return _nome; }

    friend ostream& operator<<( ostream&, const Cidade& );
    friend istream& operator>>( istream&, Cidade& );

private:
    void assign( const char* nome, const char* horario, const char* descricao );
    char* _nome;
    char* _horario;
    char* _descricao;
};

#endif /* CIDADE_H */

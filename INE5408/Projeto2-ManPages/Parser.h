/* Parser.h
 * Classe responsável por separar as palavras de uma manpage.
 *
 * Internamente, o parser mantém uma string que representa a última
 * palavra a ser lida. O parser avança de palavra apenas quando é
 * executado o método next().
 *
 * "Palavra", aqui, é entendida como uma sequência de letras.
 * Por exemplo, "vire-se" são duas palavras.
 */

#include <fstream>
using std::ifstream;

class Parser {
public:

    /* Avança a palavra lida. Caso não hajam mais palavras para serem
     * lidas, o parser retorna false; senão, retorna true. */
    bool next();

    // Retorna o ponteiro interno, para a última palavra lida.
    const char * ler() const;

    // Constrói o parser, pronto para ler o arquivo passado.
    Parser( ifstream& );
private:
    char _palavra[1000];
    ifstream& _file;
};

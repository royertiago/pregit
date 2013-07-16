/* Lista invertida
 * Cada chave possui uma lista encadeada de inteiros. */

#include "CabecaDeLista.h"
#include "MemoryTrie.h"

#include <fstream>
using std::ofstream;

class ListaInvertida {
public:
    /* Insere o par chave,valor na lista.
     * Caso o valor passado seja o último valor posto com a chave
     * especificada, ele não será inserido. */
    void inserir( const char* chave, int valor );

    // Serializa a lista na stream passada.
    void serializar( ofstream& );
private:
    MemoryTrie<CabecaDeLista<int>> _data;
};

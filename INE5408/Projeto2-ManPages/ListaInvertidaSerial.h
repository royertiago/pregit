/* Lista invertida serial
 * Lê serializações de ListaInvertida.h
 *
 * A ListaInvertidaSerial assume posse do ifstream passado.
 */

#include "CabecaDeLista.h"
#include "FileTrie.h"

#include <fstream>
using std::ifstream;

class ListaInvertidaSerial {
public:
    // Lê a lista a partir do arquivo passado
    ListaInvertidaSerial( ifstream& );

    // Joga para a memória a cabeça de lista armazenada com a chave c.
    CabecaDeLista<int> recuperar( const char* c );

private:
    FileTrie<CabecaDeLista<int>> _data;
};

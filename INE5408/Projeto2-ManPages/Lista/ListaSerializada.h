/* Utilitários para listas serializadas. */
#ifndef LISTA_SERIALIZADA_H
#define LISTA_SERIALIZADA_H
#include <fstream>
using std::ifstream;

#include "CabecaDeLista.h"

/* Desserializa a lista passada.
 * Se baseia na implementação de CabecaDeLista.h da serialização.
 *
 * Para cada objeto a ser desserializado, o método chamará a função d
 * com a stream in na posição correta, junto com o número de bytes a
 * serem lidos; é como uma inversa à função passada à
 * CabecaDeLista::serializar. Bytes além do limite serão lixo, do ponto
 * de vista da função. */
template <typename T>
CabecaDeLista<T> desserializar(
        ifstream& in, T* (*d)( ifstream&, int ) );

// Classe que lê, diretamente, de uma lista serializada.
template <typename T>
class ListaSerial {
public:
    ListaSerial( ifstream* pFile, T* (*d)( ifstream&, int ) );
};

// Implementações

template <typename T>
CabecaDeLista<T> desserializar(
        ifstream& in, T* (*d)( ifstream&, int ) ) {
    CabecaDeLista<T> lista;

    int tamLista; //Tamanho da Lista
    in.read( reinterpret_cast<char*>( &tamLista ), sizeof(int) );
    int posicao = in.tellg();
    
    for( int i = 0; i < tamLista; i++ ) {
        short tamanho; //Tamanho do Elemento
        in.read( reinterpret_cast<char*>( &tamanho ), sizeof(short) );
        lista.adiciona( d( in, tamanho ) );
        posicao = posicao + tamanho + sizeof(short);
        in.seekg( posicao );
    }

    return lista;
}
#endif // LISTA_SERIALIZADA_H

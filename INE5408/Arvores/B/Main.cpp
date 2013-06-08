/* Arquivo Main
 * O programa aceita dois argumentos na linha de comando, que serão,
 * respectivamente, o arquivo de entrada, e o de informações a
 * respeito da execução do algoritmo.
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

#include "Local.h"
#include "ArvoreB.h"

ArvoreB<Local> arvore;

void inserir( Local* l ) {
    arvore.inserir( l );
}

/* Lê dados do arquivo in e escreve os tempos no arquivo out.
 * execute(Local*) é a função chamada por esta para contar os tempos.
 */
bool ler( const char* in, const char* out, void execute(Local*) ) {
    fstream arq( in );
    fstream saida( out );
    if( !in || !out )
        return false;

    Local* l;
    int qtde = 0;

    while( arq.peek() != EOF ) {
        l = new Local();
        arq >> *l;
        arq.ignore(); //Pular o \n que o >> deixou

        timeval start, end;

        gettimeofday( &start, 0 );
        execute( l );
        gettimeofday( &end, 0 );
        double elapsedTime;
        elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;
        elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0; //Código copiado do exemplo.

        saida << qtde++ << "\t" << elapsedTime << endl;
    }

    return true;
}

int main( int argc, char* argv[] ) {
    Local l;

    if( argc < 2 || argc > 3 ) {
        cout << "Uso: " << argv[0] << " entrada.txt saida.txt\n";
        return 1;
    }

    if( !ler( argv[1], argv[2], inserir ) ) {
        cout << "Erro na abertura do arquivo.\n";
        return 1;
    }
    
    arvore.print( cout );

    return 0;
}

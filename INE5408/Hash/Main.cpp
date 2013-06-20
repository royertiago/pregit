/* Memory Leaks à reveria. */

#include <cstring>
#include <iostream>
using std::strlen;
using std::cout;
using std::cin;
using std::strcmp;

#include "HashTable.h"
#include "ElementoHash.h"
#include "TypeUtils.h"

int funcaoHash( char* chave ) {
    //soma os codigos dos caracteres da chave de  retorna soma%17.

    int length = strlen( chave );
    int soma = 0;

    for ( int i = 0; i < length; i++ )
        soma += ( int ) chave[i];
    
    return (soma % 17 );
}

int main( int argc , char** argv ) {
    cout << "Hashing\n";
    HashTable<char*, 17> h( &funcaoHash );
    int* i;
    double* d;
    char** c;
    char* key;
    char op;
    ElementoHash<char*>* e;

    while (true) {
        cout << "Escolha a opção: \n"
                "c) Armazenar uma cadeia de caracteres\n"
                "d) Armazenar um valor double\n"
                "i) Armazenar um inteiro\n"
                "r) Recuperar um valor específico\n"
                "p) Imprimir toda a lista\n"
                "q) Sair do programa.\n";
        cin >> op;
        cin.ignore();

        switch( op ) {
            case 'c':
            case 'C':
                c = new char*( new char[80] );
                key = new char[80];
                cout << "Digite a chave:\n";
                cin.getline( key, 80 );
                cout << "Digite a cadeia de caracteres a ser armazenada:\n";
                cin.getline( *c, 80 );
                h.put( key, c );
                cout << "Valor armazenado.\n";
            break;

            case 'd':
            case 'D':
                d = new double();
                key = new char[80];
                cout << "Digite a chave:\n";
                cin.getline( key, 80 );
                cout << "Digite o valor double a ser armazenado:\n";
                cin >> *d;
                cin.ignore();
                h.put( key, d );
                cout << "Valor armazenado.\n";
            break;
 
            case 'i':
            case 'I':
                i = new int();
                key = new char[80];
                cout << "Digite a chave:\n";
                cin.getline( key, 80 );
                cout << "Digite o valor inteiro a ser armazenado:\n";
                cin >> *i;
                cin.ignore();
                h.put( key, i );
                cout << "Valor armazenado.\n";
            break;

            case 'r':
            case 'R':
                cout << "Digite a chave do valor a ser recuperado:\n";
                cin.getline( key, 80 );
                e = h.get( key, [](char* c, char* d)->bool { return strcmp( c, d ) == 0; } );
                if( e == 0 )
                    cout << "Valor não encontrado.\n";
                else {
                    cout << "Valor encontrado: ";
                    getPrintUtility( e->tipo )( e->valor );
                }
            break;

            case 'p':
            case 'P':
                h.print();
            break;
            
            case 'q':
            case 'Q':
                return 0;
                
            default:
                cout << "Opção inválida.\n";
        }
    }
	return 0 ;
}



/* Main.cpp
 * Istruções de uso: Leiame.txt
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using std::strlen;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

#include "FileTrie.h"
#include "MemoryTrie.h"
#include "CabecaDeLista.h"
#include "ListaInvertida.h"
#include "ListaInvertidaSerial.h"
#include "TrieIndex.h"
#include "Parser.h"

// Indexa os arquivos especificados.
void index( int argc, char* argv[] );

// Busca pela manpage especificada.
void manSearch( char* manpage );

// Busca pela palavra-chave especificada.
void keySearch( char* keyword );

// Busca por ambas as palavras-chave especificadas.
void keySearch( char* key1, char* key2 );

// Cria o arquivo de chaves proibidas.
void forbidden( char* file );

int main( int argc, char* argv[]) {
    if( argc <= 2 || argv[1][0] != '-' ) {
        cout << "Ver arquivo Leiame.txt\n";
        return 1;
    }
    switch( argv[1][1] ) {
        case 'f':
            forbidden( argv[2] ); 
            break;

        case 'i':
            index( argc, argv );
            break;

        case 'm':
            manSearch( argv[2] );
            break;

        case 'k':
            if( argc == 3 )
                keySearch( argv[2] );
            else
                keySearch( argv[2], argv[3] );

            break;

        default:
            cout << "Ver arquivo Leiame.txt\n";
            break;
    }
    return 0;
}

void forbidden( char* file ) {
    cout << "Criando arquivo de palavras proibidas...";
    ifstream in( file );
    MemoryTrie<bool> m;
    char palavra[1000];
    while( in >> palavra )
        m.adiciona( palavra, new bool(0) ); //dummy bool 

    int (*serial)( const bool*, ofstream& ) =
        [] ( const bool* x, ofstream& out ) -> int {
            out.write( reinterpret_cast<const char*>( x ),
                   sizeof(bool) );
             return sizeof(bool);
        };

    ofstream out( "forbidden.dat" );
    m.serializar( out, serial );

    cout << "ok.\n";
}

void index( int argc, char* argv[] ) {
    int (*serial)( const int*, ofstream& ) =
        [] ( const int* x, ofstream& out ) -> int {
            out.write( reinterpret_cast<const char*>( x ),
                   sizeof(int) );
             return sizeof(int);
        };

    bool* (*des)( ifstream&, int ) =
        [] ( ifstream& in, int k ) {
            bool* x = new bool;
            in.read( reinterpret_cast<char*>( x ), sizeof(bool) );
            return x;
        };

    cout << "Carregando palavras proibidas...\n";
    ifstream forb( "forbidden.dat", ios::binary );
    MemoryTrie<bool> forbidden = desserializar<bool>( forb, des );

    MemoryTrie<int> primary;
    ListaInvertida secondary;
    ofstream manpages( "manpages.dat" );

    cout << "Iniciando indexação\n";

    for( int i = 2; i < argc; i++ ) {
        cout << "Indexando " << i - 1 << " de " <<
            argc - 2 <<  " - " << argv[i] << endl;
        // Gravar a posição de inserção da manpage.
        int pos = manpages.tellp();

        // Inserir a manpage.
        manpages.write( argv[i], strlen(argv[i]) + 1 );
        ifstream manP( argv[i] );

        manP.seekg( 0 , manP.end );
        int size = manP.tellg();
        manP.seekg( 0 );

        char * buffer = new char[size];
        manP.read( buffer, size );
        buffer[size-1] = '\0';
        manpages.write( buffer, size );

        manP.seekg( 0 );
        manP.clear();

        // Remover o caminho
        int j = 0, k = 0;
        char manPageName[1000];
        while( argv[i][j] != '\0' ) {
            manPageName[k] = argv[i][j];
            if( trieIndex( manPageName[k] ) == -1 )
                k = 0;
            else
                k++;
            j++;
        }
        /* Se argc[i] == "caminho/para/o/arquivo.txt", manPageName
         * é "arquivo.txt". Basta remover o ".txt". */
        manPageName[k-4] = '\0';
        primary.adiciona( manPageName, new int( pos ) );

        /* Já indexamos a chave primária, agora, indexaremos as
         * chaves secundárias. */
        Parser parser( manP );
        while( parser.next() ) {
            if( !forbidden.contem( parser.ler() ) )
                secondary.inserir( parser.ler(), pos );
        }

        //Concluído. Indexamos esta manpage.
    }

    //Já indexamos todas as manpages, falta agora gravar em arquivo.
    ofstream primaryFile( "primary.dat", ios::binary );
    ofstream secondaryFile( "secondary.dat", ios::binary );

    cout << "Gravando chaves primarias...\n";
    primary.serializar( primaryFile, serial );
    cout << "Gravando chaves secundárias...\n";
    secondary.serializar( secondaryFile );
}

void manSearch( char* manpage ) {
    int* (*des)( ifstream&, int ) =
        [] ( ifstream& in, int k ) {
            int* x = new int;
            in.read( reinterpret_cast<char*>( x ), sizeof(int) );
            return x;
        };

    ifstream manpages( "manpages.dat" );
    ifstream primary( "primary.dat" );
    FileTrie<int> trie( primary, des );

    // Reconstruir nome do arquivo, similar à construção feita em index
    char manPageName[1000];
    int i = 0, j = 0;
    while( manpage[i] != '\0' ) {
        manPageName[j] = manpage[i];
        if( trieIndex( manpage[i] ) == -1 )
            j = 0;
        else
            j++;
        i++;
    }
    manPageName[j] = '\0';

    if( ! trie.contem( manPageName ) ) {
        cout << manpage << " não encontrada.\n";
        return;
    }

    int* alcePos = trie.recuperar( manPageName );
    int pos = *alcePos;
    delete alcePos;

    manpages.seekg( pos );
    manpages.getline( manPageName, 1000, '\0' );
    cout << manPageName << " encontrado, imprimindo conteúdo...\n";

    char c;
    while( (c = manpages.get() ) != '\0' )
        cout << c;
    
    cout << endl;
}

void keySearch( char* keyword ) {
    bool* (*des)( ifstream&, int ) =
        [] ( ifstream& in, int k ) {
            bool* x = new bool;
            in.read( reinterpret_cast<char*>( x ), sizeof(bool) );
            return x;
        };
    ifstream manpages( "manpages.dat" );

    ifstream forb( "forbidden.dat" );
    FileTrie<bool> forbidden( forb, des );

    if( forbidden.contem( keyword ) ) {
        cout << keyword << " é uma palavra proibida "
            "e não foi indexada.\n";
        return;
    }

    for( int i = 0; keyword[i] != '\0'; i++ )
        if( (keyword[i] < 'a' || keyword[i] > 'z') &&
            (keyword[i] < 'A' || keyword[i] > 'Z') ) {
            cout << keyword << " não é uma palavra indexável.\n";
            return;
        }
    
    ifstream secondary( "secondary.dat" );
    ListaInvertidaSerial listaInv( secondary );
    CabecaDeLista<int> listaChaves = listaInv.recuperar( keyword );

    if( listaChaves.tamanho() == 0 ) {
        cout << "Não há nenhuma man page com a palavra " << keyword
            << endl;
        return;
    }
    if( listaChaves.tamanho() == 1 )
        cout << "Existe uma man page com a palavra " << keyword <<
            ":\n";
    else
        cout << "Existem " << listaChaves.tamanho() << " man pages com"
           " a palavra " << keyword << ":\n";

    char manPageName[1000];
    for( auto it = listaChaves.iterador(); !it.volta(); ++it ) {
        manpages.seekg( *it );
        manpages.getline( manPageName, 1000, '\0' );
        cout << manPageName << endl;
    }
}

void keySearch( char* key1, char* key2 ) {
    bool* (*des)( ifstream&, int ) =
        [] ( ifstream& in, int k ) {
            bool* x = new bool;
            in.read( reinterpret_cast<char*>( x ), sizeof(bool) );
            return x;
        };
    ifstream manpages( "manpages.dat" );

    ifstream forb( "forbidden.dat" );
    FileTrie<bool> forbidden( forb, des );

    if( forbidden.contem( key1 ) ) {
        cout << key1 << " é uma palavra proibida "
            "e não foi indexada.\n";
        return;
    }
    if( forbidden.contem( key2 ) ) {
        cout << key2 << " é uma palavra proibida "
            "e não foi indexada.\n";
        return;
    }

    for( int i = 0; key1[i] != '\0'; i++ )
        if( (key1[i] < 'a' || key1[i] > 'z') &&
            (key1[i] < 'A' || key1[i] > 'Z') ) {
            cout << key1 << " não é uma palavra indexável.\n";
            return;
        }

    for( int i = 0; key2[i] != '\0'; i++ )
        if( (key2[i] < 'a' || key2[i] > 'z') &&
            (key2[i] < 'A' || key2[i] > 'Z') ) {
            cout << key2 << " não é uma palavra indexável.\n";
            return;
        }
    
    ifstream secondary( "secondary.dat" );
    ListaInvertidaSerial listaInv( secondary );
    CabecaDeLista<int> lista1 = listaInv.recuperar( key1 );
    CabecaDeLista<int> lista2 = listaInv.recuperar( key2 );

    if( lista1.tamanho() == 0 ) {
        cout << "Não há nenhuma man page com a palavra " << key1
            << endl;
        return;
    }

    if( lista2.tamanho() == 0 ) {
        cout << "Não há nenhuma man page com a palavra " << key2
            << endl;
        return;
    }

    CabecaDeLista<int> listaChaves;
    auto i = lista1.iterador();
    auto j = lista2.iterador();
    while( !i.volta() && !j.volta() )
        if( *i < *j )
            ++i;
        else if( *j < *i )
            ++j;
        else {
            listaChaves.adiciona( new int( *i ) );
            ++i;
            ++j;
        }

    if( listaChaves.tamanho() == 0 ) {
        cout << "Não há nenhuma man page com ambas as palavras " <<
            key1 << " e " << key2 << endl;
        return;
    }
    if( listaChaves.tamanho() == 1 )
        cout << "Existe uma man page com as palavras " << key1 <<
            " e " << key2 << ":\n";
    else
        cout << "Existem " << listaChaves.tamanho() << " man pages com"
           " as palavras " << key1 << " e " << key2 << ":\n";

    char manPageName[1000];
    for( auto it = listaChaves.iterador(); !it.volta(); ++it ) {
        manpages.seekg( *it );
        manpages.getline( manPageName, 1000, '\0' );
        cout << manPageName << endl;
    }
}

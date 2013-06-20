/* Supor-se-á que o formato dos arquivos de entrada é: <inteiro de 10 dígitos> <string de 68 caracteres>
 *
 * Convenções:
 *  - ao terminar uma operação, uma função deve resetar a posição de leitura do arquivo.
 *  - Todos os vetores de char passados tem tamanho 69, incluindo o '\0'. */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

fstream out( "out.txt" );
fstream tmp( "tmp.txt" );

// Joga todos os dados da stream in para out.
void copiar( fstream& in ) {
    int i;
    char c[69];
    while( in.peek() != EOF ) {
        in >> i;
        in.ignore();
        in.getline( c, 70 );

        out << setw(10) << i << ' ' << setw(68) << c << endl;
        out.flush();
    }
    out.seekp( 0 );
    out.seekg( 0 );
    in.seekp( 0 );
    in.seekg( 0 );
}

// Insere <i> <68c> em out, usando tmp como temporário.
void inserir( int i, char * c ) {
    int j;
    char d[69];
    tmp << setw(10);
    out << setw(10);

    out >> j;
    out.ignore();
    out.getline( d, 70 );
    while( out.peek() != EOF ) {
        if( j >= i )
            break;

        tmp << setw(10) << j << ' ' << setw(68) << d << endl;
        tmp.flush();

        out >> j;
        out.ignore();
        out.getline( d, 70 );
    }
    tmp << setw(10) << i << ' ' << setw(68) << c << endl;
    tmp << setw(10) << j << ' ' << setw(68) << d << endl;
    tmp.flush();

    while( out.peek() != EOF ) {
        out >> j;
        out.ignore();
        out.getline( d, 70 );

        tmp << setw(10) << j << ' ' << setw(68) << d << endl;
        tmp.flush();
    }
    tmp.seekp( 0 );
    tmp.seekg( 0 );
    out.seekp( 0 );
    out.seekg( 0 );

    copiar( tmp );
}

// impressão trivial: lê uma linha por vez e a imprime.
void print() {
    char c[80];
    while( out.peek() != EOF ) {
        out.getline( c, 80 );
        if( c[9] != ' ' ) //Se foi marcado para exclusão, é ' '.
            cout << c << endl;
    }
    out.seekg( 0 );
    out.seekp( 0 );
}

// Exclui (preenche com zeros) o registro de chave i em out.
void excluir( int i ) {
    int j;
    auto pos = out.tellg();
    while( out.peek() != EOF ) {
        out >> j;
        if( j == i ) { // Preencher com zeros e sair
            out.seekp( pos );
            out.write( "                                                                               \n", 80 );
            // insere string com 79 espaços e um '\n' em out.
            cout << "Registro excluído com sucesso.\n";
            break;
        }

        out.ignore( 70 ); //Depois da leitura, estaremos apontando para o espaço.
        pos = out.tellg();
    }
    out.seekp( 0 );
    out.seekg( 0 );
}

int main() {
    cout << setw(10);
    fstream in( "in.txt" );
    copiar( in );
    in.close();
    cout << "Funções de arquivo - arquivo sequencial ordenado.\n";
    char c;
    char uInput[68]; //user input
    int uKey; //chave do usuário
    char write[80]; //valor a ser impresso no arquivo.
    
    while( true ) {
        cout << "Escolha a opção:\n"
                "i) inserir registro\n"
                "e) excluir registro\n"
                "p) imprimir arquivo\n"
                "q) sair\n";
        cin >> c;

        switch( c ) {
            case 'i':
            case 'I':
                cout << "Digite a chave do registro (máximo 10 dígitos):\n";
                cin >> uKey;
                uKey = uKey % 10000000000; //GAMBIARRA
                cin.ignore();
                cout << "Digite o valor do registro (máximo 69 caracteres):\n";
                cin.getline( uInput, 69 );
                
                inserir( uKey, uInput );

            break;
            case 'e':
            case 'E':
                cout << "Digite o valor a ser excluído: ";
                cin >> uKey;

                excluir( uKey );
            break;
            case 'p':
            case 'P':
                print();
            break;
            case 'q':
            case 'Q':
                return 0;
            default:
                cout << "Opção inexistente.\n";
            break;
        }
    }
    return 0;
}

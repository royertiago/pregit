//TODO: colocar construtor de cópia na rota e na lista para previnir memory leaks.

#include <iostream>
#include <fstream>
using namespace std;

#define DebugMode
#include "DebugUtils.h" 
#include "CabecaDeLista.h"
#include "Iterador.h"
#include "Cidade.h"
#include "Rota.h"

CabecaDeLista<Rota> rotas;

bool inicializar() {
    ifstream a( "rotas.txt", ios::in );
    if( !a )
        return false;
    int qtde;
    a >> qtde;
    for( ; qtde > 0; --qtde ) {
        Rota* r = new Rota();
        a >> *r;
        rotas.adiciona( r );
    }
    return true;
}

void imprimirRotas() {
    cout << "Rotas disponíveis\n";

    Iterador<Rota> it = rotas.iterador();
    int i = 0;
    while( !it.volta() ) {
        cout << "Rota " << i++ << " - " << *it;
        ++it;
    }
}

void verRota( Rota* r ) {
    Iterador<Cidade> c = r->iterador();
    char op;
    while( true ) {
        cout << "Cidade atual: " << *c;
        cout << "Escolha a opção:\n"
                " a - Avançar cidade\n"
                " r - Retroceder cidade\n"
                " b - Gerar bilhete\n"
                " i - Imprimir rota completa\n"
                " q - Voltar para o menu inicial\n";
        cin >> op;
        switch( op ) {
            case 'a':
            case 'A':
                ++c;
                break;
            case 'r':
            case 'R':
                --c;
                break;
            case 'b':
            case 'B':
                cout << "Bilhete gerado para " << *r;
                break;
            case 'i':
            case 'I':
                r->print( cout );
                cout << endl;
                break;
            case 'q':
            case 'Q':
                return;

            default:
                cout << "Opção inválida!\n";
        } // Fim switch
    } // Fim while
} //Fim verRota

int main() {
    if( !inicializar() ) {
        cerr << "Erro ao abrir arquivo rotas.txt\n";
        return 1;
    }
    char op;
    Iterador<Rota> r = rotas.iterador();
    cout << "      Bem vindo ao navegador de rotas turísticas!\n";

    while ( !false ) {
        cout << "Rota atual: " << *r;

        cout << "\nEscolha a opção: \n"
                " i - Imprimir todas as rotas\n"
                " c - Consultar rota atual\n"
                " a - Avançar rota\n"
                " r - Retroceder rota\n"
                " q - sair do programa\n";

        cin >> op;
        switch( op ) {
            case 'i':
            case 'I':
                imprimirRotas();
                cout << endl;
                break;

            case 'c':
            case 'C':
                verRota( r.obter() );
                break;

            case 'a':
            case 'A':
                ++r;
                break;

            case 'r':
            case 'R':
                --r;
                break;

            case 'q':
            case 'Q':
                return 0;

            default:
                cout << "Opção inválida!\n";
        } //Fim switch
    } //Fim while
    return 0;
} //Fim main

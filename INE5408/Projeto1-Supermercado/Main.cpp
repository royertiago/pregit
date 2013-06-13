/* Arquivo principal.
 * Todo o trabalho já ta feito, esse aqui só mostra bonitinho pro usuário. */

#include "Supermercado.h"
#include "Caixa.h"
#include "Pichador.h"
#include "Estatistico.h"

#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;

Supermercado* comper = 0;
double horasSimulacao;
int qtdeCaixas;

void lerArquivoConfiguracao() {
    char arquivo[100];
    cout << "Digite o nome do arquivo de configuração:\n";
    cin >> arquivo;

    fstream arq( arquivo );
    if( !arq ) {
        cout << "Erro na abertura do arquivo.\n";
        return;
    }

    while( arq.peek() == '#' )
        arq.ignore(10000, '\n' );
    char nome[100];
    arq.getline( nome, 100 );
    cout << "Nome do supermercado: " << nome << endl;

    while( arq.peek() == '#' )
        arq.ignore(10000, '\n' );
    arq >> horasSimulacao;
    arq.ignore();
    cout << "Tempo de simulação: " << horasSimulacao << endl;

    while( arq.peek() == '#' )
        arq.ignore(10000, '\n' );
    double tempoMedioClientes;
    arq >> tempoMedioClientes;
    arq.ignore();
    cout << "Tempo médio de chegada de clientes: " << tempoMedioClientes << endl;

    while( arq.peek() == '#' )
        arq.ignore(10000, '\n' );
    int tamanhoFilas;
    arq >> tamanhoFilas;
    arq.ignore();
    cout << "Tamanho das filas antes de contratar caixas temporários: " << tamanhoFilas << endl;

    delete comper;
    comper = new Supermercado( nome, tempoMedioClientes, tamanhoFilas );

    while( arq.peek() == '#' )
        arq.ignore(10000, '\n' );
    arq >> qtdeCaixas;
    arq.ignore();
    cout << "Quantidade de caixas no supermercado, inicialmente: " << qtdeCaixas << endl;

    for( int i = 0; i < qtdeCaixas; i++ ) {
        while( arq.peek() == '#' )
            arq.ignore(10000, '\n');
        Caixa* c = Caixa::gerarCaixa( arq );
        comper->adicionarCaixa( c );
        cout << "Caixa contratado: " << *c << endl;
    }

    cout << "Arquivo de configuração lido.\n";
}

void digitarConfiguracao() {
    cin.ignore();
    cout << "Digite o nome do supermercado:\n";
    char nome[100];
    cin.getline( nome, 100 );

    cout << "Digite a quantidade de horas de simulação:\n";
    cin >> horasSimulacao;

    cout << "Digite o tempo médio de aparecimento de clientes:\n";
    double tempoMedioClientes;
    cin >> tempoMedioClientes;

    cout << "Digite o tamanho mínimo de todas as filas antes de o supermercado contratar caixas temporários:\n";
    int tamanhoFilas;
    cin >> tamanhoFilas;

    delete comper;
    comper = new Supermercado( nome, tempoMedioClientes, tamanhoFilas );

    cout << "Digite a quantidade de caixas no supermercado:\n";
    cin >> qtdeCaixas;
    cin.ignore();

    for( int i = 0; i < qtdeCaixas; i++ ) {
        cout << "Digite o salário, taxa de eficiência, e nome completo do caixa " << i << ", em uma única linha:\n";
        Caixa* c = Caixa::gerarCaixa( cin );
        comper->adicionarCaixa( c );
    }
}

int main() {
    cout << "Bem vindo ao simulador de supermercados!\n";
    while (true) {
        char opcao;
        cout << "Escolha a opção:\n"
                " A - carregar arquivo de configuração\n"
                " D - Digitar configurações\n";
        if( comper != 0 )
            cout << " S - Iniciar a simulação\n";
        cin >> opcao;
        switch( opcao ) {
            case 'A':
            case 'a':
                lerArquivoConfiguracao();
                break;

            case 'D':
            case 'd':
                digitarConfiguracao();
                break;

            case 'S':
            case 's':
                if( comper != 0 ) {
                    Pichador* p = new Pichador();
                    comper->adicionarOuvinte( p );
                    Estatistico* Barbetta = new Estatistico( qtdeCaixas );
                    comper->adicionarOuvinte( Barbetta );
                    comper->simular( horasSimulacao );
                    cout << endl << endl;
                    Barbetta->gerarEstatisticas( comper, horasSimulacao, cout );
                    return 0;
                }
                cout << "Configure a simulação antes!\n";
                break;

            default:
                cout << "Opção inválida.\n";
        } // Fim switch
    } // Fim while
    return 0;
}

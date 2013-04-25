#include <iostream>
#include <iomanip>
using namespace std;

#include "Fila.h"

#define MAXFILA 100

int main() {
    Fila<char*> fila(MAXFILA);
    int opcao = 0;
    char* valor; // Variavel auxiliar.
    char** arr; // Array auxiliar.
    
    while (opcao != 5) {
        cout << "Filas:" << endl
             << "Digite o numero da opção desejada:" << endl
             << "1) Enfileirar Elemento" << endl
             << "2) Desenfileirar Elemento" << endl
             << "3) Limpar Fila" << endl
             << "4) Mostrar Fila" << endl
             << "5) Sair do programa" << endl;
        
        cin >> opcao;
        switch( opcao ) {
        case 1:
            cout << "Digite uma string (sem espaços) a ser enfileirada:" << endl;
            valor = new char[30];
            cin >> valor;
            if( fila << valor )
                cout << "String enfileirada corretamente." << endl;
            else
                cout << "Erro: fila cheia." << endl;
                
        break;
        case 2:
            cout << "Desenfileirando um valor:" << endl;
            if( fila >> valor )
                cout << "Valor desenfileirando: " << valor << endl;
            else
                cout << "Erro: fila vazia." << endl;
        
        break;
        case 3:
            fila.limparFila();
            cout << "Fila limpa." << endl;
        break;
        case 4:
            cout << "Posição  Valor" << endl;
            arr = fila.paraArray();
            for( int i = 0; i < fila.obterTamanho(); i++ )
                cout << setw(3) << i << "      " << arr[i] << endl;
                
        break;
        // Caso seja 5, nada é executado e o programa simplesmente sai.
        } //Fim switch
    } // Fim while
    
    return 0;
}

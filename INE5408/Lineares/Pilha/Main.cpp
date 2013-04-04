#include <iostream>
#include <iomanip>
using namespace std;

#include "Pilha.h"

#define MAXPILHA 30

int main() {
    Pilha<int> pilha(MAXPILHA);
    int opcao = 0;
    int valor; // Variavel auxiliar.
    int* arr; // Array auxiliar.
    
    while (opcao != 5) {
        cout << "Pilhas:" << endl
             << "Digite o numero da opção desejada:" << endl
             << "1) Empilhar Elemento" << endl
             << "2) Desempilhar Elemento" << endl
             << "3) Limpar Pilha" << endl
             << "4) Mostrar Pilha" << endl
             << "5) Sair do programa" << endl;
        
        cin >> opcao;
        switch( opcao ) {
        case 1:
            cout << "Digite o elemento a ser empilhado:" << endl;
            cin >> valor;
            if( pilha << valor ) //Também dá para testar antes e executar a ação apenas caso dê.
                cout << "Valor empilhado corretamente." << endl;
            else
                cout << "Erro: pilha cheia." << endl;
                
        break;
        case 2:
            cout << "Desempilhando um valor:" << endl;
            if( pilha >> valor )
                cout << "Valor desempilhado: " << valor << endl;
            else
                cout << "Erro: pilha vazia." << endl;
        
        break;
        
        case 3:
            pilha.limparPilha();
            cout << "Pilha limpa." << endl;
        break;
        case 4:
            cout << "Posição  Valor" << endl;
            arr = pilha.paraArray();
            for( int i = 0; i < pilha.obterTamanho(); i++ )
                cout << setw(3) << i << " " << setw(10) << arr[i] << endl;
                
        break;
        // Caso seja 5, nada é executado e o programa simplesmente sai.
        } //Fim switch
    } // Fim while
    
    return 0;
}

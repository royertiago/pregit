#include <stdio.h>

#include "Lista.h"
#include "Lancamento.h"
#include "listaContabil.h"

#define MAXLISTA 100
#define menu "Digite a opção desejada:\n"\
             "(c) Seleciona a lista de créditos\n"\
             "(d) Seleciona a lista de débitos\n"\
             "(l) Lançar Transações\n"\
             "(t) Listar Transações\n"\
             "(r) Remover Transações\n" \
             "(s) Mostrar Saldo\n" \
             "(q) Sair\n"

listaContabil creditos = listaContabil(MAXLISTA);
listaContabil debitos = listaContabil(MAXLISTA);

int main() {
    listaContabil* lista = &creditos; //Lista selecionada
    char* opt = new char[5]; //Opçao escolhida
    double valor = 0.0;
    char* causa; //Variáveis auxiliares, usadas na opção 'l'.
    while (!false) {

        printf(menu);
        scanf("%s", opt); //Por alguma razão, scanf estava lendo \n como um caracter.
        switch (opt[0]) {
        case 'c':
            lista = &creditos;
            printf( "Lista alterada para CRÉDITOS\n" );
            break;

        case 'd':
            lista = &debitos;
            printf( "Lista alterada para DÉBITOS\n" );
            break;

        case 'l':
            causa = new char[100];
            printf("Digite o valor do lançamento: ");
            scanf("%lf", &valor);
            printf("Digite o nome do Lançamento");
            gets( causa );
            lista->adicionar(lancamento(valor, causa));
            break;

        case 't':
            printf("%s", lista->listar());
            break;

        case 'r':
            printf( "Digite o valor da transacão a ser removida: \n" );
            scanf( "%lf", &valor );
            if( lista->removerEspecifico( valor ) )
                printf( "Lançamento removido\n" );
            else
                printf( "Erro: transação não encontrada. " );
            break;

        case 's':
            printf("Seu saldo é de R$ %.2f", (creditos.resultante() - debitos.resultante()));
            break;
        
        case 'q':
            return 0;

        default:
            printf("Opção inválida: %c\n", opt[0] );
            break;
        }//Fim switch
    }//Fim while
    return 0;
}

/* 
 * File:   main.cpp
 * Author: grad
 *
 * Created on 2 de Maio de 2013, 15:12
 */

#include <cstdlib>
#include <stdio.h>
#include "CabecaDeLista.h"
#include "ElementoEncadeado.h"
#include "ElementoAgenda.h"
#define menu "\n\tMenu de opcoes\n"\
             "1)Adicionar Contato\n"\
             "2)Tirar ultimo contato\n"\
             "3)Imprimir contatos\n"\
             "4)Sair\n"


using namespace std;

ElementoAgenda* construirContato() {
    char* tel = new char[10000];
    char* nome = new char[10000];

    printf("Digite o nome do contato a ser inserido\n");
    fgets(nome, 10000, stdin);
    nome[strlen(nome) - 1] = '\0'; //fgets inclui o \n

    printf("Digite o telefone do contato a ser inserido\n");
    fgets(tel, 10000, stdin);
    tel[strlen(tel) - 1] = '\0';

    return new ElementoAgenda(tel, nome);
};

int main() {
    CabecaDeLista<ElementoAgenda> agenda = CabecaDeLista<ElementoAgenda>();
    int op;
    char alce[100];
    ElementoAgenda* elemAlce;

    while (1) {
        printf(menu);
        fgets(alce, 100, stdin);
        sscanf(alce, "%i", &op);
        switch (op) {
            case 1:
            {
                elemAlce = construirContato();
                agenda.adicionarUltimo( elemAlce );
                printf( "Contato adicionado %s - %s\n", elemAlce->cuspirNom(), elemAlce->cuspirTel() );
            }
            break;
            case 2:
            {
                if ( agenda.vazia() )
                    printf( "A agenda está vazia.\n" );
                else {
                    agenda.excluirUltimo(elemAlce);
                    printf("Foi excluido o %s, - %s\n", elemAlce->cuspirNom(), elemAlce->cuspirTel());
                    delete elemAlce;
                }
            }
            break;
            case 3:
            {
                printf( "\nTotal de %i contatos.\n", agenda.obterTamanho() );
                for (int i = 1; i <= agenda.obterTamanho(); i++) {
                    agenda.retornaDadoPosicao(i, elemAlce);
                    printf("%s - %s\n", elemAlce->cuspirNom(), elemAlce->cuspirTel());
                }
            }
            break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida");
        }//Fim Switch
    }//Fim While
    return 0;
}


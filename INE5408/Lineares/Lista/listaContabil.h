/* Lista contábil é um contêiner, que engloba uma lista, definida em Lista.h.
   Possui alguns problemas de gerenciamento de memória, que o são por causa
   da forma como Lista.h é implementada.

 */

#include "Lista.h"
#include "Lancamento.h"
#ifndef LISTACONTABIL_H
#define	LISTACONTABIL_H

class listaContabil {
public:
    listaContabil(int);
    bool adicionar(lancamento);
    bool removerUltima();
    bool removerEspecifico( double valor );
    double resultante();
//    bool limpar();
    char* listar();
private:
    Lista<lancamento> _interna;
};

listaContabil::listaContabil(int tamanho) {
    _interna = Lista <lancamento>(tamanho);
}

bool listaContabil::adicionar(lancamento l) {
    return _interna.adiciona(l);
}

bool listaContabil::removerUltima() {
    if (_interna.vazio()) {
        return false;
    }
    lancamento l = lancamento();
    _interna.retira(l);
    return true;
}

bool listaContabil::removerEspecifico(double valor) {
    if (_interna.vazio()) {
        return false;
    }
    lancamento l = lancamento( valor );
    return _interna.retiraEspecifico( l );
}

double listaContabil::resultante() {
    double _total = 0;
    for (int i = 0; i < _interna.obterTamanho(); i++) {
        _total += _interna[i].cospeValor();
    }
    return _total;

}

char* listaContabil::listar() {
    if( _interna.vazio() ) {
       char *retorno = new char[30];
       strcpy( retorno, "Nenhum lançamento!\n" );
       return retorno;
    }

    char *retorno = new char[120* _interna.obterTamanho()];
    char *tmp = new char[120];
    for (int i = 0; i < _interna.obterTamanho(); i++) {
        sprintf(tmp, "R$ %10.2f - %s\n", _interna[i].cospeValor(),_interna[i].cospeCausa());
        strcat( retorno, tmp );
    }
    
    return retorno;

}
#endif	/* LISTACONTABIL_H */


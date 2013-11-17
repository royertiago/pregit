#include "Mapa.h"

Cidade* Mapa::obterCidade(string s){
    for(Cidade *c:cidades){
        if(c->getNome()==s)return c;
    }
    return 0;
}

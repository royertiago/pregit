
#include "Cidade.h"
#define add push_back


Cidade::Cidade(list<Cidade*> vizinhos, list<Estrada*> estrada,string nome){
    this->vizinhos=vizinhos;
    this->estradas=estrada;
    this->nome=nome;
    for(Estrada *e: estrada){//supondo que toda estrada esta conectada a esta cidade
        if(e->inicio == this){
           hashDestino[e->fim]=e;
        }else{
            hashDestino[e->inicio]=e;
        }
    }

}
string Cidade::getNome(){
return nome;
}

void Cidade::addExercito(Exercito *e){
    this->garrison.add(e);
}
void Cidade::modificarBalanceamento(int t){
    producaoSoldado=10-t;
    producaoTecnologia=t;
}
void Cidade::criarOrdemdeEnvio(Jogador *jogador, Cidade *destino, int quantidade){
    Exercito *exercito;
    for(Exercito* j: garrison){
        Jogador *dono=j->dono;
        if(dono==jogador){
            exercito=j;
            break;
        }
    }
    if(exercito==0){
        return;
    }
    Cidade *cidade;
    for(Cidade* c: vizinhos){
        if(c==destino){
            cidade=c;
        }
    }
    if(cidade==0)return;
    /* DESCOMENTAR QUANDO exercitoMovendo extender exercito
    exercito=exercito->dividirExercito(quantidade);
    exercito.destino=cidade;
    exercitosMovendo.add(exercito);
    //*/

}
double Cidade::getSoldadosProduzido(){
    return producaoSoldado/10 * CONSTANTE_SOLDADO;
}
double Cidade::getTecnologiaProduzida(){
    return producaoTecnologia/10 * CONSTANTE_TECNOLOGIA;
}
void Cidade::passagemDeTurno(){
    for(ExercitoMovendo *e:exercitosMovendo){
        MovimentacaoDeTropas novoMovimento= MovimentacaoDeTropas(e,e->destino);
        Estrada *estrada=hashDestino[novoMovimento.destino];

        estrada->adicionarMovimentacaoDeTropas(novoMovimento);
    }
    exercitosMovendo.clear();



}

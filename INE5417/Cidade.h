#ifndef CIDADE_H
#define CIDADE_H

#include <list>
#include "Tecnologia.h"
#include "Exercito.h"
#include "LocalDeBatalha.h"
#include "OrdemDeEnvio.h"
#include "Estrada.h"
#include "Jogador.h"
#include <unordered_map>
#include "ExercitoMovendo.h"
using namespace std;
//using std::list;
class ExercitoMovendo;

class Cidade : LocalDeBatalha{
public:

    Cidade(list<Cidade*> vizinhos, list<Estrada*> estradas,string nome);

    list<Exercito> getExercitos();
   // void adicionarVizinho(Cidade *vizinho);
    void criarOrdemdeEnvio(Jogador *jogador, Cidade *destino, int quantidade);
    void addExercito(Exercito*);
    void modificarBalanceamento(int tecnologia);
    double getSoldadosProduzido();
    double getTecnologiaProduzida();
    string getNome();
    void passagemDeTurno();
protected:
//    enum state;
    unordered_map<Cidade*,Estrada*> hashDestino;
    list<ExercitoMovendo*> exercitosMovendo;
    list<Estrada*> estradas;
    list<Exercito*> garrison;
    list<Cidade*> vizinhos;
    double producaoTecnologia;
    double producaoSoldado;
private:
    string nome;
    int const CONSTANTE_SOLDADO = 10;
    int const CONSTANTE_TECNOLOGIA = 1;

};

#endif // Cidade.h

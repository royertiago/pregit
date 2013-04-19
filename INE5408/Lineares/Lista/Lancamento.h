/* Classe representa um lançamento financeiro.
 */

#ifndef LANCAMENTO_H
#define	LANCAMENTO_H
#include <string.h>

class lancamento {
public:
    lancamento(double, char*);
    lancamento();
    lancamento( double );
    ~lancamento();
    //Retorna uma representação em string do objeto.
    char* toString();

    //Retorna true se este lançamento e o outro tiverem mesmo valor.
    bool operator==(lancamento);

    //Retorna o valor do lançamento.
    double cospeValor();

    //Retorna a causa (nome) do lançamento.
    char const* cospeCausa();

private:
    double _valor;
    char* _causa;
};
lancamento::lancamento() {
    lancamento( 0.0 );
}
lancamento::lancamento(double valor) {
    _valor = valor;
    _causa = new char;
    *_causa = '\0';
}

lancamento::lancamento(double razao, char* causa) {
    _causa = causa;
    _valor = razao;
}

lancamento::~lancamento() {
    delete _causa;
}

char* lancamento::toString() {
    char *retorno = new char[strlen(_causa) + 20];
    sprintf(retorno, "R$ %10.2f - %s", _valor, _causa );
    return retorno;
}

bool lancamento::operator ==(lancamento l) {
    return this->_valor == l._valor;
}

double lancamento::cospeValor() {
    return _valor;
}

const char* lancamento::cospeCausa() {
    return _causa;
}
#endif	/* LANCAMENTO_H */


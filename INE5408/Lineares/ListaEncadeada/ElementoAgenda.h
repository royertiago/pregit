/* 
 * File:   elementoAgenda.h
 * Author: grad
 *
 * Created on 2 de Maio de 2013, 15:32
 */

#ifndef ELEMENTOAGENDA_H
#define	ELEMENTOAGENDA_H
#include <string.h>
#include <stdio.h>
class ElementoAgenda {
public:
    /*Cria uma entrada de agenda*/
    ElementoAgenda(char* telefone, char* nome);
    /*Apaga a entrada de agenda*/
    ~ElementoAgenda();
    /*Construtor de cópia*/
    ElementoAgenda(const ElementoAgenda&);
    /*Fornece o telefone*/
    char* cuspirTel();
    /*Fornece o nome*/
    char* cuspirNom();
    /*Verifica se o elemento é alfabeticamente superior a outro elemento*/
    bool operator>(ElementoAgenda elem);
    /*Verifica se o elemento é alfabeticamente inferior a outro elemento*/
    bool operator<(ElementoAgenda elem);
    /*Verifica se o elemento é alfabeticamente igual a outro elemento*/
    bool operator==(ElementoAgenda elem);
private:
    char* _tel;
    char* _nome;
};

ElementoAgenda::ElementoAgenda(const ElementoAgenda& a) {
    _tel = new char[strlen(a._tel) + 1];
    strcpy( _tel, a._tel );

    _nome = new char[strlen(a._nome) + 1];
    strcpy( _nome, a._nome );
}

ElementoAgenda::ElementoAgenda(char* telefone, char* nome) {
    _tel = new char[strlen(telefone) + 1];
    strcpy( _tel, telefone );

    _nome = new char[strlen(nome) + 1];
    strcpy( _nome, nome );
}

ElementoAgenda::~ElementoAgenda() {
    delete _tel;
    delete _nome;
}

char* ElementoAgenda::cuspirNom() {
    return _nome;
}

char* ElementoAgenda::cuspirTel() {
    return _tel;
}

bool ElementoAgenda::operator<(ElementoAgenda elem) {
    return (strcmp(_nome, elem._nome) < 0);
}

bool ElementoAgenda::operator>(ElementoAgenda elem) {
    return (strcmp(_nome, elem._nome) > 0);
}

bool ElementoAgenda::operator==(ElementoAgenda elem) {
    return (strcmp(_nome, elem._nome) == 0);
}

#endif	/* ELEMENTOAGENDA_H */


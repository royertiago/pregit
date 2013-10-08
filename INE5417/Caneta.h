/* A caneta é o responsável por escrever as coisas na tela. */
#ifndef ISAIAS_H
#define ISAIAS_H

class Historiador;

class Caneta {
public:
    // Piada interna.
    void explodir();

    // Imprime o estado interno do historiador.
    static void escreverRegistroHistorico( const Historiador& );
};

#endif // Isaias.h - digo, Caneta.h

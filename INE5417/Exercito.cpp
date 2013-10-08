#include "Exercito.h"
#include "Jogador.h"
#include "Batalhao.h"

Exercito::Exercito( int quantidade, Jogador* dono ) :
    quantidade( quantidade ),
    dono( dono )
{}

Exercito Exercito::unir( const Exercito& alvo ) const {
    return Exercito( quantidade + alvo.quantidade, dono );
}

/*Exercito Exercito::separar( int quantidade ) {
    return Exercito( subtrair( quantidade ), dono );
}*/

int Exercito::subtrair( int n ){
    if( quantidade < n ) {
        int retorno = quantidade;
        quantidade = 0;
        return quantidade;
    }
    quantidade -= n;
    return n;
}

Exercito::operator int() const {
    return quantidade;
}
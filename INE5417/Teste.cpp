#include "Depurador.h"

int main() {
    for( int i = 0; i < 5; i++ )
        debug( "Teste %i\n", i );

    for( int j = 1; j < 2; j++ ) {
        debug( "%s %s %s\n", "Testando", "alces", "fofinhos" );
        if( j == 1 )
            debug( "Funciona\n" );
    }

    return 0;
}

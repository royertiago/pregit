/* Debugger pra quê? Temos printf! */

#ifndef MEU_DEPURADOR_FOFINHO
#define MEU_DEPURADOR_FOFINHO

#ifdef DEPURAR

#include <iostream>
using std::cout;
#include <cstdio>
using std::printf;

#define debug( ... )            \
    if( true ) {                \
        cout.flush();           \
        printf( __VA_ARGS__ );  \
        fflush( stdout );       \
    } else (void) 0

#else // !DEPURAR

#define debug( ... ) (void) 0

#endif // DEPURAR

#endif // MeuDepuradorFofinho

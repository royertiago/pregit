/* DebugUtils.h: utilitário para o melhor debugger de todos os tempos: printf.
 * Usaremos, entretanto, iostream, por sua versatilidade.
 *
 * Instruções de uso: Coloque debug( cout << "Teste\n"; ) em seu código.
 * Caso a macro DebugMode esteja definida, este código será substituído por
 *      cout << "Teste\n";
 * Caso contrário, não será gerado código. */

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H

/*#ifdef DebugMode
    #include <iostream>
    using namespace std;
    #define debug( something ) something
//#else
//  */  #define debug( something ) ;
//#endif

#endif /* DEBUGUTILS_H */

/* Arquivo de utilitários para inserção de múltiplas variáveis
 * na tabela de hash. */
#ifndef TYPEUTILS_H
#define TYPEUTILS_H

#include <iostream>
using std::cout;
using std::endl;

static void(**printFunctions)( const void* );

static int typeCount = 0;

template <typename T>
class TypeGetter {
public:
    static bool used;
    static int value;
    TypeGetter() {
        if( !used ) {
            used = true;
            value = typeCount++;

            void (**alce)( const void * );
            alce = new (  void (* [typeCount])(const void*)  );
            int i;
            for( i = 0; i < typeCount-1; i++ )
                alce[i] = printFunctions[i];
            alce[i] = []( void const* v ){ cout << *((T const *) v ) << endl; };
            delete [] printFunctions;
            printFunctions = alce;
        }
    }
};

template <typename T>
int TypeGetter<T>::value = 0;
template <typename T>
bool TypeGetter<T>::used = false;

template <typename T>
int getTypeValue( T& valor ) {
    static TypeGetter<T> g;
    return g.value;
}

template <typename T>
void setPrintUtility( void (*print)( void const* ) ) {
    static TypeGetter<T> g;
    printFunctions[g.value] = print;
}

void ( *getPrintUtility( int valor ) )( const void * ) {
    return printFunctions[valor];
}

#endif // TypeUtils.h

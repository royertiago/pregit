// not TODO: Está errado isto.
#include <iostream>
#include "Arvore.h"

int main() {
    int n;
    Arvore<int> a;
    cout << "Digite a quantidade de inteiros a serem ordenados: ";
    cin >> n;

    for( int i = 0; i < n; i++ ) {
        int *tmp = new int;
        cin >> *tmp;
        a.adicionar( tmp );
    }
    cout << "Imprimindo\n";
    a.imprimir( cout );
    return 0;
}
    


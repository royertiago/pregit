#include "ArvoreB.h"
#include <iostream>
using namespace std;

int main() {
    ArvoreB<double, 2> a;
    double* d = new double(2);
    cout << "inserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(4);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(6);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(8);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(0.1);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(3);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(3.5);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
    a.print( cout );
    d = new double(3.25);
    cout << "\ninserir " << *d << "\n";
    a.inserir(d);
 
    a.print( cout ) << endl << endl;

    return 0;
}

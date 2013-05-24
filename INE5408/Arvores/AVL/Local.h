/* Representa uma localidade, com logradouro (nome) e CEP.
 */

#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>

class Local {
public:
    Local();
    Local( const Local& );
    Local( char*, int );
    ~Local();

    Local& operator=( const Local& );

    bool operator<( const Local& );
    bool operator>( const Local& );
    bool operator==( const Local& );
    bool operator>=( const Local& );
    bool operator<=( const Local& );
    bool operator!=( const Local& );
    friend std::istream& operator>>( std::istream&, Local& );
    friend std::ostream& operator<<( std::ostream&, Local& );

private:
    char* nome;
    int cep;
};

#endif //LOCAL_H

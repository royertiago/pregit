/* Aresta de um grafo.
 * Suporemos que o tipo Vertex sobrecarregou o operador < (menor que).
 */

#ifndef EDGE_H
#define EDGE_H

template< typename Vertex >
class Edge {
public:
    // Cria uma aresta com origem e destino especificados.
    Edge( Vertex source, Vertex target );

    // Retorna o vértice de origem da aresta.
    Vertex source() const;

    // Retorna o vértice de destino da aresta.
    Vertex target() const;

    /* O ordenamento das arestas é baseado nos vértices de destino
     * e de origem, numa ordenação semelhante à lexicográfica.
     * Caso a origem desta aresta venha antes do vértice de
     * origem de e, esta aresta será considerada menor do que a
     * outra, e vice-versa. Havendo "empate", procede-se para checar
     * o vértice de destino. */
    bool operator< ( const Edge< Vertex > e );

private:
    Vertex const _source;
    Vertex const _target;
};

template< typename Vertex >
Edge<Vertex>::Edge( Vertex source, Vertex target ) :
    _source( source ),
    _target( target )
{}

template< typename Vertex >
Vertex Edge<Vertex>::source() const {
    return _source;
}

template< typename Vertex >
Vertex Edge<Vertex>::target() const {
    return _target;
}

template< typename Vertex >
bool Edge<Vertex>::operator<( const Edge< Vertex > e ) {
    if( _source < e._source )
        return true;
    else if( e._source < _source )
        return false;
    else return _target < e._target;
}

#endif //Edge.h

/* Aresta valorada.
 * A aresta pode ter seu peso alterado livremente.
 */

#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

template< typename Vertex >
class WeightedEdge {
public:
    WeightedEdge( Vertex source, Vertex target, double weight = 1.0 );

    // Retorna o vértice de origem da aresta.
    Vertex source() const;

    // Retorna o vértice de destino da aresta.
    Vertex target() const;

    // Retorna o peso da aresta.
    double weight() const;

    // Os pesos das arestas serão comparados.
    bool operator< ( const WeightedEdge< Vertex >& e ) const;

private:
    Vertex const _source;
    Vertex const _target;
    double _weight;
};

template< typename Vertex >
WeightedEdge< Vertex >::WeightedEdge( Vertex source, Vertex target,
        double weight ):
    _source( source ),
    _target( target ),
    _weight( weight )
{}

template< typename Vertex >
Vertex WeightedEdge< Vertex >::source() const {
    return _source;
}

template< typename Vertex >
Vertex WeightedEdge< Vertex >::target() const {
    return _target;
}

template< typename Vertex >
double WeightedEdge< Vertex >::weight() const {
    return _weight;
}

template< typename Vertex >
bool WeightedEdge<Vertex>::operator <( const WeightedEdge<Vertex>& e ) const {
    return _weight < e._weight;
}

#endif // WeightedEdge.h

/* Algoritmo de Dijkstra para caminhos de custo mínimo.
 * Supõe que todas as arestas possuem peso positivo,
 * e que std::hash<Vertex*> existe.
 *
 * Caso não seja possível atingir o alvo a partir daqui, um
 * conjunto vazio é retornado.
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <unordered_set>
#include <unordered_map>
#include <list>
#include <set>
#include <limits>

template< typename Graph, typename Vertex,
          typename Edge = WeightedEdge< Vertex > >
std::list<Vertex> dijkstra( Graph g, Vertex source, Vertex target ) {
    // Lista de vértices que já foram fechados
    std::unordered_set< Vertex > closed;

    // Mapeamento entre vértices e sua estimativa de custo atual.
    std::unordered_map< Vertex, double > cost;

    // Mapeamento entre vértice fechado e o vértice usado para fechá-lo
    std::unordered_map< Vertex, Vertex > pred;

    for( auto it : g )
        cost[ it.first ] = std::numeric_limits<double>::max();

    cost[ source ] = 0.0;
    pred[ source ] = source;

    while( true ) {
        Vertex v; // V é o vértice aberto mais próximo de source.
        // Vamos primeiro atribuir um valor válido a v:
        auto it = cost.begin();
        auto end = cost.end();
        while( it != end )
            if( closed.count( it->first ) == 0 ) {
                v = it->first;
                break;
            }
            else
                ++it;

        if( it == end ) // Se não há mais ninguém próximo o bastante:
            return std::list<Vertex>(); // O grafo não é conexo.

        // Atribuir o valor correto a v:
        while ( ++it != end ) {
            if( closed.count( it->first ) == 0 
                    && cost[ it->first ] < cost[ v ] )
                v = it->first;
        }

        if( v == target ) // Missão cumprida.
            break;

        closed.insert( v );

        //Melhorar as estimativas:
        for( const Edge & e : g.successors( v ) ) {
            Vertex w = e.target();
            if( closed.count( w ) == 0 && // w não pertence a closed
                cost[v] + e.weight() < cost[w] ) {
                //Ou dá pra melhorar a estimativa atual
                cost[w] = cost[v] + e.weight();
                pred[w] = v;
            }
        }
    }
    /* Fim da contagem dos custos. Agora, iremos construir o caminho
     * de custo mínimo: */

    std::list< Vertex > l;
    l.push_front( target );

    // Iremos navegar pelos vértices de pred, até chegarmos em source.
    Vertex v = target;
    while( v != source ) {
        v = pred[ v ];
        l.push_front( v );
    }

    return l;
}

#endif // dijkstra.h

/* Grafo orientado.
 *
 * A tabela de vértices é implementada usando uma tabela de hash.
 *
 * Embora as arestas possuem orientação implícita, basta adicionar
 * arestas a ambos os nodos, com ambas as orientações, ao adicionar
 * uma aresta, para que o grafo funcione como um grafo não orientado.
 *
 * À exceção do método contains(), todos os métodos assumem que
 * os vértices passados de fato pertencem ao grafo.
 *
 * Suporemos que tanto Vertex quanto Edge sobrecarregaram o operador <.
 * Também suporemos que std::hash<Vertex> existe.
 *
 * Os iteradores retornados pelos métodos begin() e end() são os
 * mesmos da lista de sucessores, portanto, eles apontarão para
 * pares <Vertex, set<Edge> >.
 * Um algoritmo que precise de algum vértice arbitrário pode
 * obtê-lo a partir desta operação.
 * 
 * Para definir a complexidade, usaremos n para representar a ordem
 * (quantidade de arestas) no grafo, e d(v) o grau do vértice v.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <set>
using std::set;
using std::unordered_map;

#include "Edge.h"

#include <iostream>
using std::cout;
using std::endl;

template< typename Vertex, typename Edge = Edge<Vertex> >
class Graph {
private:
    // Mapeamento entre os vértices e seus sucessores.
    unordered_map< Vertex, set< Edge > > _suc;

    // Mapeamento entre os vértices e seus antecessores.
    unordered_map< Vertex, set< Edge > > _pred;

public:
    /* Adiciona o vértice v à lista de vértices.
     * Não é criada nenhuma aresta entre os vértices existentes
     * e este.
     *
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    void addVertex( Vertex v );

    /* Remove o vértice v da lista de vértices.
     * Todas as arestas que estão ligadas a este vértice também
     * são removidas.
     * O vértice em si não é destruído.
     *
     * Complexidade: O(d(v) log n) no caso médio, 
     *               O(d(v) * n log n) no pior caso. */
    void removeVertex( Vertex v );

    /* Adiciona a aresta e no grafo.
     * Os vértices de origem e de destino são assumidos estar
     * neste grafo.
     *
     * Defina v = e.source(), u = e.target(). Complexidade:
     *  O( log d(v) + log d(u) ) no caso médio,
     *  O( n * (log d(v) + log d(u) ) no pior caso. */
    void addEdge( Edge e );

    /* Remove a aresta e do grafo.
     * Os vértices de origem e de destino são assumidos estar
     * neste grafo.
     *
     * Defina v = e.source(), u = e.target(). Complexidade:
     *  O( log d(v) + log d(u) ) no caso médio,
     *  O( n * (log d(v) + log d(u) ) no pior caso. */
    void removeEdge( Edge e );
    
    /* Conecta os vértices v e w. A aresta e1 ligará v a w, e e2,
     * w a v.
     * Complexidade:
     *  O( log d(v) + log d(u) ) no caso médio,
     *  O( n * (log d(v) + log d(u) ) no pior caso. */
    void connect( Vertex v, Vertex w, Edge e1, Edge e2 );
    
    /* Remove qualquer aresta que estiver entre os vértices v e w.
     *
     * Complexidade: O(d(v) + d(w)) no caso médio, O(n) no pior caso.
     * 
     * A função examina todas as arestas partindo e saindo de v e w,
     * portanto, se as arestas que conectam v e w são conhecidas,
     * utilizar o método removeEdge é mais eficiente.*/
    void disconnect( Vertex v, Vertex w );

    /* Retorna uma referência para o conjunto de sucessores
     * do vértice v.
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    set< Edge >& successors( Vertex v );

    /* Retorna uma referência para o conjunto de predecessores
     * do vértice v.
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    set< Edge >& predecessors( Vertex v );

    /* Retorna um forward_iterator para o início da lista de
     * sucessores.
     * 
     * Complexidade de uso do iterador: constante amortizada */
    decltype( _suc.begin() ) begin();

    /* Retorna um forward_iterator para o fim da lista de sucessores.
     * Este iterador não deve ser derreferenciado.
     *
     * Complexidade de uso do iterador: constante amortizada. */
    decltype( _suc.end() ) end();

    /* Informa se o referido vértice pertence ao grafo.
     *
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    bool contains( Vertex v ) const;

    /* Retorna a ordem (quantidade de vértices no grafo.
     * Complexidade: constante. */
    int order() const;

    /* Retorna o grau de emissão do vértice.
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    int outDegree( Vertex v ) const;

    /* Retorna o grau de recepção do vértice.
     * Complexidade: constante no caso médio, O(n) no pior caso. */
    int inDegree( Vertex v ) const;
};

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::addVertex( Vertex v ) {
    _suc[ v ] = set< Edge >();
    _pred[ v ] = set< Edge >();
}

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::removeVertex( Vertex v ) {
    
    for( const Edge & e: successors( v ) )
        predecessors( e.target() ).erase( e );

    for( const Edge & e: predecessors( v ) )
        successors( e.source() ).erase( e );
    
    _suc.erase( v );
    _pred.erase( v );
}

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::addEdge( Edge e ) {
    successors( e.source() ).insert( e );
    precedessors( e.target() ).insert( e );
}

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::removeEdge( Edge e ) {
    successors( e.source() ).erase( e );
    precedessors( e.target() ).erase( e );
}

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::connect( Vertex v, Vertex w,
            Edge e1, Edge e2 ) {
    successors( e1.source() ).insert( e1 );
    successors( e2.source() ).insert( e2 );
    predecessors( e1.target() ).insert( e1 );
    predecessors( e2.target() ).insert( e2 );
}

template< typename Vertex, typename Edge >
void Graph< Vertex, Edge >::disconnect( Vertex v, Vertex w ) {
    /* A sintaxe aqui é um pouco ilegível para que a deleção
     * pudesse ser feita usando o próprio iterador de leitura. */
    for( auto it = successors(v).begin(), end = successors(v).end();
            it != end; ++it ) {
        if( it->target() == w ) {
            auto tmp = it;
            --tmp;
            successors(v).erase( it );
            it = tmp;
        } //Gambiarra para manter a validade do ponteiro.
    }

    for( auto it = successors(w).begin(), end = successors(w).end();
            it != end; ++it )
        if( it->target() == v ) {
            auto tmp = it;
            --tmp;
            successors(w).erase( it );
            it = tmp;
        }

    for( auto it = predecessors(v).begin(),end = predecessors(v).end();
            it != end; ++it )
        if( it->source() == w ) {
            auto tmp = it;
            --tmp;
            predecessors(v).erase( it );
            it = tmp;
        }

    for( auto it = predecessors(w).begin(),end = predecessors(w).end();
            it != end; ++it )
        if( it->source() == v ) {
            auto tmp = it;
            --tmp;
            predecessors(w).erase( it );
            it = tmp;
        }
}
template< typename Vertex, typename Edge >
set< Edge >& Graph< Vertex, Edge >::successors( Vertex v ) {
    return _suc[ v ];
}

template< typename Vertex, typename Edge >
set< Edge >& Graph< Vertex, Edge >::predecessors( Vertex v ) {
    return _pred[ v ];
}

template< typename Vertex, typename Edge >
auto Graph< Vertex, Edge >::begin() -> decltype( _suc.begin() ) {
    return _suc.begin();
}

template< typename Vertex, typename Edge >
auto Graph< Vertex, Edge >::end() -> decltype( _suc.end() ) {
    return _suc.end();
}

template< typename Vertex, typename Edge >
bool Graph< Vertex, Edge >::contains( Vertex v ) const {
    return _suc.count(v) > 0;
}

template< typename Vertex, typename Edge >
int Graph< Vertex, Edge >::order() const {
    return _suc.size();
}

template< typename Vertex, typename Edge >
int Graph< Vertex, Edge >::outDegree( Vertex v ) const {
    return successors( v ).size();
}

template< typename Vertex, typename Edge >
int Graph< Vertex, Edge >::inDegree( Vertex v ) const {
    return predecessors( v ).size();
}

#endif //Graph.h

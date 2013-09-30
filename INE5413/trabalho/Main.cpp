/* Interface com o usuário. */

#include <string>
#include <iostream>
#include <list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;

#include "Graph.h"
#include "WeightedEdge.h"
#include "dijkstra.h"

Graph< string, WeightedEdge< string > > g;
int main() {
    cout << "\t\tTrabalho de Grafos\n"
        "Digite os comandos a serem executados (h para ajuda.)\n";

    while( true ) {
        // Laço que lê uma entrada e executa a ação correspondente.
        char c;
        cout << " > ";
        cin >> c;
        switch( c ) {
            case 'd' : {
                string origem, destino;
                cin >> origem >> destino;
                cin.ignore(); //Matar o '\n' que sobra
                if( !g.contains( origem ) )
                    cout << origem << " não encontrado no grafo.\n";
                else if( !g.contains( destino ) )
                    cout << destino << " não encontrado no grafo.\n";
                else {
                    cout << "Desconectando " << origem << ' ' <<
                        destino << endl;
                    g.disconnect( origem, destino );
                }
            } break;

            case 'e': {
                string origem, destino;
                double custo;
                cin >> origem >> destino >> custo;
                cin.ignore();
                if( !g.contains( origem ) )
                    cout << origem << " não encontrado no grafo.\n";
                else if( !g.contains( destino ) )
                    cout << destino << " não encontrado no grafo.\n";
                else
                g.connect( origem, destino, 
                    WeightedEdge< string >( origem, destino, custo ),
                    WeightedEdge< string >( destino, origem, custo )
                    );
            } break;

            case 'h' :
                cout << "O programa é uma implementação de um grafo"
                        " capaz de rodar o algoritmo \n"
                        "de Dijkstra para caminhos de custo mínimo. "
                        "Os vértices do grafo são cadeias\n"
                        "de caracteres sem espaços e as arestas"
                        " possuem valores em ponto flutuante.\n\n"
                        "Comandos disponíveis:\n"
                        "d ORIGEM DESTINO - Desconecta os vértices\n"
                        "e ORIGEM DESTINO CUSTO - insere uma aresta "
                        "entre os vértices passados \n"
                        "\t com o custo dado\n"
                        "h - Mostrar a ajuda\n"
                        "p - Imprimir lista de cidades\n"
                        "q - Sair do programa\n"
                        "r VERTICE - Remove o vértice do grafo\n"
                        "s ORIGEM DESTINO - Executa o algoritmo de"
                        " Dijkstra entre os vértices.\n"
                        "v VERTICE - Adiciona o vértice no grafo.\n";
                break;

            case 'p':
                for( auto it : g ) {
                    cout << "Vértice " << it.first << endl;
                    if( !it.second.empty() ) {
                        cout << "Arestas partindo deste vértice: \n";
                        for( auto e : it.second )
                            cout << e.target() << " - peso: "
                                << e.weight() << endl;
                        cout << endl;
                    }
                }
            break;
            case 'q':
                return 0;

            case 'r': {
                string vertice;
                cin >> vertice;
                cin.ignore();
                if( !g.contains( vertice ) )
                    cout << vertice << " não encontrado no grafo.\n";
                else
                    g.removeVertex( vertice );
            } break;

            case 's': {
                string origem, destino;
                cin >> origem >> destino;
                cin.ignore();
                if( !g.contains( origem ) )
                    cout << origem << " não encontrado no grafo.\n";
                else if( !g.contains( destino ) )
                    cout << destino << " não encontrado no grafo.\n";
                else {
                    list<string> l = dijkstra( g, origem, destino );
                    cout << "O caminho mais curto é: \n";
                    for( auto it = l.begin(), end = l.end();
                            it != end; ++it )
                        cout << *it << endl;
                }
            } break;
            case 'v': {
                string vertice;
                cin >> vertice;
                cin.ignore();
                g.addVertex( vertice );
            } break;

            default:
                cout << "Comando não reconhecido.\n";
        }
    } // while externo

    return 0;
}

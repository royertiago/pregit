/**
 * Contêinter que representa uma intersecção no plano. Possui o ângulo da colisão
 * e o ponto em que ocorreu a intersecção.
 */

package modelo.fisico.estruturas;

import modelo.Coordenada;

public class Intersecao {
    
    public final double angulo;
    public final Coordenada origem;
    
    public Intersecao( double angulo, Coordenada origem)
    {
        this.angulo = angulo;
        this.origem = origem;
    }

}

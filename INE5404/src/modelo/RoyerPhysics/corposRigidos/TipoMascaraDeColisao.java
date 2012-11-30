/**
 * Representa uma máscara de colisão genérica.
 */

package modelo.RoyerPhysics.corposRigidos;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.Vetor;
import modelo.estruturasDeDados.ListaLegivel;

public interface TipoMascaraDeColisao {

    /**
     * Diz se uma determinada coordenada está ou não contido na máscara de
     * colisão. Caso a coordenada estiver sobre uma aresta, é considerado dentro
     * da máscara.
     * 
     * @param c
     *            A coordenada a ser analisado.
     * @return <b>true</b> se estiver contido, <b>false</b> caso contrário.
     */
    public abstract boolean estaDentro(Coordenada c);

    /**
     * Obtêm uma lista de coordenadas, que representam as extremidades da
     * máscara de colisão.
     * 
     * @return Uma lista de Coordenadas, que estão nas extremidades da máscara.
     */
    public abstract ListaLegivel<Coordenada> obterPontosExtremidades();

    /**
     * Cria uma coordenada que representa o centro da máscara de colisão.
     * 
     * @return Um objeto Coordenada que representa o centro da máscara de
     *         colisão.
     */
    public abstract Coordenada obterCentro();

    /**
     * Retorna o ângulo de colisão com o ponto p. Por exemplo, se o ponto
     * estiver na extremidade de um círculo, o valor retornado deve ser ângulo
     * de inclinação da reta tangente, em relação ao eixo X.
     * 
     * Possui um comportamento não previsível caso o ponto testado não esteja no
     * interior do objeto.
     * 
     * @param p
     *            Ponto contra o qual será calculado o ângulo de colisão.
     * @return O ângulo de colisão, em radianos.
     */
    public abstract double anguloColisao(Coordenada p);
    
    /**
     * Desloca a máscara de colisão, de acordo com o vetor de movimento que lhe
     * for passado.
     * 
     * Por exemplo, se o vetor contém (1, 1), o corpo deve ser deslocado uma
     * unidade para a esquerda e uma abaixo.
     */
    public abstract void mover(Vetor movimento);

}
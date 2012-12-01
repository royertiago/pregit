package modelo.RoyerPhysics;

import modelo.estruturasDeDados.ListaLegivel;
//FIXME: o corpo rígido atual é um corpo rígido móvel; tenho de criar outra interface chamada "CorpoRigidoEstrutural".
/**
 * Representa um corpo rígido (que não se deforma). Todo corpo rígido tem:
 * <ul>
 * <li>Um vetor de movimento</li>
 * <li>Massa</li>
 * <li>Máscara de colisão</li>
 * </ul>
 * Essas grandezas podem ser usadas pelas implementações das leis da física para
 * haver uma física minimamente realista no jogo.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoCorpoRigido {
    
    /**
     * Diz se uma determinada coordenada está ou não contida no colidível.
     * 
     * @param c
     *            A coordenada a ser analisado.
     * @return <b>true</b> se estiver contido, <b>false</b> caso contrário.
     */
    public abstract boolean estaDentro(Coordenada c);

    /**
     * Obtêm uma lista de coordenadas, que representam as extremidades do
     * colidível.
     * 
     * @return Uma lista de Coordenadas, que estão nas extremidades do
     *         colidível.
     */
    public abstract ListaLegivel<Coordenada> obterPontosExtremidades();

    /**
     * Retorna uma coordenada que representa o centro de gravidade do colidível.
     * 
     * @return O centro do colidível.
     */
    public abstract Coordenada obterCentro();

    /**
     * Retorna o ângulo de colisão com o ponto p. Por exemplo, se o ponto
     * estiver na extremidade de um círculo, o valor retornado deve ser ângulo
     * de inclinação da reta tangente, em relação ao eixo X.
     * 
     * Possui um comportamento não previsível caso o ponto testado não esteja na
     * superfície do objeto.
     * 
     * @param p
     *            Ponto contra o qual será calculado o ângulo de colisão.
     * @return O ângulo de colisão, em radianos.
     */
    public abstract double anguloColisao(Coordenada p);

    /**
     * Desloca o corpo rígido, de acordo com o vetor de movimento que ele
     * possui.
     * 
     * Por exemplo, se o vetor contém (1, 1), o corpo deve ser deslocado uma
     * unidade para a esquerda e uma abaixo.
     */
    public abstract void mover();

    /**
     * Obtém o vetor de movimento do corpo rígido..
     * 
     * @return o vetor de movimento.
     */
    public abstract Vetor obterVetorMovimento();

    /**
     * Altera o vetor de movimento do corpo rígido.
     * 
     * @param v
     *            O novo vetor de movimento.
     */
    public abstract void fixarVetorMovimento(Vetor v);

    /**
     * Espelha o vetor de movimento do corpo rígido em torno de uma reta de
     * ângulo <b>angulo</b>.
     * 
     * @param angulo
     *            Ângulo do espelhamento.
     */
    public abstract void espelharVetorMovimento(double angulo);

    /**
     * Informa a massa do objeto. Massa negativa representa massa infinita.
     * 
     * @return A massa do objeto.
     */
    public abstract double obterMassa();
}

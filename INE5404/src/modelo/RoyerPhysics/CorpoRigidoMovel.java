package modelo.RoyerPhysics;

import modelo.estruturasDeDados.ListaLegivel;

/**
 * Representa um corpo rígido que pode ser movido. Todo corpo rígido móvel tem:
 * <ul>
 * <li>Um vetor de movimento</li>
 * <li>Massa</li>
 * <li>Extremidades</li>
 * </ul>
 * Essas grandezas podem ser usadas pelas implementações das leis da física para
 * haver uma física minimamente realista no jogo.
 * 
 * @author Tiago Royer
 * 
 */
public interface CorpoRigidoMovel extends TipoCorpoRigido {
    
    /**
     * Obtêm uma lista de coordenadas, que representam as extremidades do
     * colidível.
     * 
     * @return Uma lista de Coordenadas, que estão nas extremidades do
     *         colidível.
     */
    public abstract ListaLegivel<Coordenada> obterPontosExtremidades();

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

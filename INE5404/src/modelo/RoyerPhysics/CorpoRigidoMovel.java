package modelo.RoyerPhysics;

import modelo.estruturasDeDados.ListaLegivel;
import modelo.estruturasDeDados.TipoEditor;

/**
 * Representa um corpo rígido que pode ser movido. Todo corpo rígido móvel tem:
 * <ul>
 * <li>Um vetor de movimento</li>
 * <li>Massa</li>
 * <li>Extremidades</li>
 * <li>Forças que estão sendo aplicadas a ele</li>
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
     * Desloca o corpo rígido, de acordo com o vetor de movimento que ele contém.
     * 
     * Por exemplo, se o vetor contém (1, 1), o corpo deve ser
     * deslocado uma unidade para a esquerda e uma abaixo.
     */
    public abstract void mover();

    /**
     * Desloca o corpo rígido, de acordo com o vetor de movimento que ele contém,
     * multiplicado por um escalar.
     * 
     * Por exemplo, se o vetor contém (2, 2) e o escalar for 0.5, o corpo deve ser
     * deslocado uma unidade para a esquerda e uma abaixo.
     * 
     * @param c Escalar a ser multiplicada pelo vetor de movimento.
     */
    public abstract void mover(double c);

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

    /**
     * Obtém um editor para a força cujo nome está especificado.
     * 
     * Caso a força não exista ainda, ela será criada como vetorNulo e um editor
     * para ela será retornado.
     * 
     * @param nome
     *            Nome atribuído à força
     * @return
     */
    public abstract TipoEditor<Vetor> obterForca(String nome);

    /**
     * Obtém um vetor de força que é o somatório de todas as forças aplicadas ao
     * corpo.
     * 
     * @return um vetor que representa uma força.
     */
    public abstract Vetor obterSomatorioForcas();
}

package modelo.RoyerPhysics;


/**
 * Representa um corpo rígido que pode ser movido. Um corpo rígido é um polígono
 * com um vetor de movimento e um conjunto de forças lhe sendo aplicadas.
 * 
 * @author Tiago Royer
 * 
 */

public interface CorpoRigidoMovel extends TipoPoligonoConvexo, TipoConjuntoDeForcas {
    
    /**
     * Obtém o vetor de movimento deste corpo rígido móvel.
     * @return
     */
    public Vetor obterVetorMovimento();
    
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
     * Altera o vetor de movimento do corpo rígido.
     * 
     * @param v
     *            O novo vetor de movimento.
     */
    public abstract void fixarVetorMovimento(Vetor v);

}

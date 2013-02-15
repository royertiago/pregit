package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * Representa uma forma poligonal convexa, delimita objetos no campo e pode checar
 * colisão contra outros polígonos.
 * 
 * @author Tiago Royer
 */
public interface TipoPoligonoConvexo extends TipoPoligono {

    /**
     * Obtêm uma lista de coordenadas, que representam as extremidades do
     * colidível.
     * 
     * @return Uma lista de Coordenadas, que estão nas extremidades do
     *         colidível.
     */
    public abstract ListaLegivel<Coordenada> obterPontosExtremidades();
    
    /**
     * Obtêm uma caixa delimitador alinhada aos eixos (Axis-Aligned Bounding Box),
     * que contêm o corpo.
     * @return
     */
    public abstract AABB obterAABB();
    
    /**
     * Informa o centro do corpo rígido.
     * @return O centro do corpo rígido.
     */
    public abstract Coordenada obterCentro();
}

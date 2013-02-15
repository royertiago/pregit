package modelo.RoyerPhysics;

/**
 * Representa um polígono estrutural, como, por exemplo, uma parede.
 * 
 * @author Tiago Royer
 * 
 */
public interface PoligonoEstrutural extends TipoPoligono {

    /**
     * Determina se o polígono em questão está intersectando a caixa
     * delimitadora.
     * 
     * @param box
     *            Caixa contra a qual interseção será testada.
     * @return <b>true</b> caso a caixa esteja intersectando o polígono,
     *         <b>false</b> caso contrário.
     */
    public boolean contem(AABB box);
}

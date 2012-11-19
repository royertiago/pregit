/**
 * Interface que representa um <i>listener</i> de colisões.
 */

package modelo.fisico.colisoes;

public interface EscutadorDeColisoes {

    /**
     * Envia uma colisao para o escutador.
     * 
     * @param c
     *            Colisao a ser enviada.
     */
    public void escutar(Colisao c);
    
}

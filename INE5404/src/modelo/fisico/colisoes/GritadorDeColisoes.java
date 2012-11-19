/**
 * Interface que envia eventos de colisão para os escutadores (<i>listeners</i>).
 */
package modelo.fisico.colisoes;

public interface GritadorDeColisoes {

    /**
     * Adiciona um EscutadorDeColisoes para este gritador.
     * @param e Escutador a ser adicionado.
     */
    public void adicionarEscutador( EscutadorDeColisoes e );
    
    /**
     * Remove um escutador deste gritador.
     * 
     * @param e Escutador a ser removido.
     */
    public void removerEscutador( EscutadorDeColisoes e );
    
}

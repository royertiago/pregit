package modelo.RoyerPhysics.observacaoDeCorpos;

/**
 * Representa um corpo observável.
 * 
 * @author Tiago Royer
 * 
 */
public interface CorpoObservavel {

    /**
     * Adiciona um observador à lista dos que são notificados por este objeto ao
     * ser atualizado.
     * 
     * @param o
     *            Observador a ser adicionado.
     */
    public void adicionarObservador(ObservadorDeCorpos o);

    /**
     * Remove o observador da lista.
     * 
     * @param o
     *            Observador a ser removido.
     */
    public void removerObservador(ObservadorDeCorpos o);
}

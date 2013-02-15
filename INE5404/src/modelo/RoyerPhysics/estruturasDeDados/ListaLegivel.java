/**
 * Represena uma lista genérica que pode ser lida.
 */

package modelo.RoyerPhysics.estruturasDeDados;

public interface ListaLegivel<Tipo> extends Iterable<Tipo> {

    /**
     * Reinicia a leitura da lista.
     */
    public void reiniciarLeitura();

    /**
     * Diz se a leitura está no fim da lista.
     * 
     * @return <b>true</b> caso não haja mais ítens a serem lidos, <b>false</b>
     *         caso contrário.
     */
    public boolean fimDaLista();

    /**
     * Pega o próximo item da lista e avança a leitura.
     * 
     * @return O próximo item da lista.
     */
    public Tipo obterProximoItem();

    /**
     * Obtém o tamanho da lista.
     * 
     * @return o tamanho da lista.
     */
    public int obterTamanho();

    /**
     * Obtém o item de índice <b>indice</b>.
     * 
     * @param indice
     *            Índice do item.
     * @return O ítem da posição <b>indice</b> da lista.
     */
    public Tipo obter(int indice);
}

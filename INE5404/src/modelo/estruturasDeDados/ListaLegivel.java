/**
 * Represena uma lista genérica que pode ser lida.
 */

package modelo.estruturasDeDados;

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
     * @return O próximo ponto da lista.
     */
    public Tipo obterProximoItem();

}

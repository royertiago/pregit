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
    
    /**
     * Retorna uma lista de tuplas, contendo todas as combinações de tamanho <b>t</b>
     * dos objetos da lista.
     * 
     * Exemplo: se a lista contém os elementos A B C D E, obterTuplasUnicas(3)
     * retornaria as tuplas:
     * <ul>
     * <li> (A, B, C) </li>
     * <li> (A, B, D) </li>
     * <li> (A, B, E) </li>
     * <li> (A, C, D) </li>
     * <li> (A, C, E) </li>
     * <li> (A, D, E) </li>
     * <li> (B, C, D) </li>
     * <li> (B, C, E) </li>
     * <li> (B, D, E) </li>
     * <li> (C, D, E) </li>
     * </ul>
     * 
     * @param t Tamanho das tuplas
     * @return Uma lista de tuplas.
     */
    public ListaLegivel<Tupla<Tipo>> obterTuplasUnicas( int t );
}

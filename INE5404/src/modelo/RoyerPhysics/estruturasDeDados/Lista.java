/**
 * Representa uma lista, que pode ser lida sequencialmente e adicionar
 * novos valores no final.
 */

package modelo.RoyerPhysics.estruturasDeDados;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Lista<Tipo> implements ListaLegivel<Tipo> {

    private List<Tipo> lista;
    private Iterator<Tipo> leitor;

    /**
     * Cria uma nova lista.
     */
    public Lista() {
        lista = new ArrayList<Tipo>();
    }

    @Override
    public void reiniciarLeitura() {
        leitor = lista.iterator();
    }

    @Override
    public boolean fimDaLista() {
        return !leitor.hasNext();
    }

    @Override
    public Tipo obterProximoItem() {
        return leitor.next();
    }

    @Override
    public Iterator<Tipo> iterator() {
        return new IteradorLista<Tipo>(this);
    }

    /**
     * Adiciona um novo item na lista.
     * 
     * @param i
     *            item a ser adicionado.
     */
    public void adicionarItem(Tipo i) {
        lista.add(i);
    }

    /**
     * Remove a primeira ocorrência do item <b>i</b> da lista.
     * 
     * Caso o item não exista, nada é feito.
     * 
     * @param i
     *            Item a ser removido.
     */
    public void removerItem(Tipo i) {
        lista.remove(i);
    }

    /**
     * Método que retorna o elemento do <b>índice</b> da lista.
     * 
     * @param indice
     *            Índice do elemento.
     * @return O elemento referido.
     */
    public Tipo obter(int indice) {
        return lista.get(indice);
    }

    /**
     * Grava o ítem especificado na posição especificada. O ítem antigo é
     * perdido.
     * 
     * @param indice
     *            Local onde deve ser feita a gravação.
     * @param item
     *            Ítem a ser gravado.
     */
    public void gravar(int indice, Tipo item) {
        lista.set(indice, item);
    }

    /**
     * Método que informa o tamanho da lista.
     * 
     * @return o tamanho da lista.
     */
    public int obterTamanho() {
        return lista.size();
    }

    @Override
    public String toString() {
        String out = "";
        for (Tipo t : lista)
            out = out + t + "\n";

        return out;
    }
}

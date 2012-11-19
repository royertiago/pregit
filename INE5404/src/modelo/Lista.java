/**
 * Representa uma lista, que pode ser lida sequencialmente e adicionar
 * novos valores no final.
 */

package modelo;

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
        leitor = lista.iterator();
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

    /**
     * Adiciona um novo item na lista.
     * 
     * @param i
     *            item a ser adicionado.
     */
    public void adicionarItem(Tipo i) {
        lista.add(i);
    }
    
    public String toString()
    {
        String out = "";
        for( Tipo t: lista)
            out = out + t + "\n";
        
        return out;
    }
}

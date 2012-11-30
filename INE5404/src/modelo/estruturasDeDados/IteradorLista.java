package modelo.estruturasDeDados;

import java.util.Iterator;

/**
 * Iterador para a classe ListaLegivel. Simplesmente redireciona chamadas
 * para os métodos da lista.
 * 
 * @param <Tipo> Tipo de objeto da lista.
 */
public class IteradorLista<Tipo> implements Iterator<Tipo> {

    private ListaLegivel<Tipo> lista;
    
    public IteradorLista( ListaLegivel<Tipo> fonte )
    {
        lista = fonte;
        fonte.reiniciarLeitura();
    }
    
    @Override
    public boolean hasNext() {
        return !lista.fimDaLista();
    }

    @Override
    public Tipo next() {
        return lista.obterProximoItem();
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException("Esta lista pode apenas ser lida através do iterador. ");
    }

}

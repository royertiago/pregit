package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.Editor;
import modelo.RoyerPhysics.estruturasDeDados.ListaComEditor;
import modelo.RoyerPhysics.estruturasDeDados.Par;
import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;
import static modelo.RoyerPhysics.Vetor.vetorNulo;

/**
 * Representa um conjunto de forças atuando sobre um objeto. As forças são
 * manipuladas separadamente.
 * 
 * @author Tiago Royer
 *
 */
public class ConjuntoDeForcas implements TipoConjuntoDeForcas {

    private ListaComEditor<Vetor> _forcas;
    
    /**
     * Cria um conjunto de forças vazio.
     */
    public ConjuntoDeForcas () {
        _forcas = new ListaComEditor<Vetor>();
    }
    
    /* (non-Javadoc)
     * @see modelo.RoyerPhysics.TipoConjuntoForcas#obterForca(java.lang.String)
     */
    @Override
    public TipoEditor<Vetor> obterForca(String nome)
    {
        Editor<Vetor> e = _forcas.obterEditor(nome);
        if (e != null)
            return e;
        
        Par<String, Vetor> par = new Par<String, Vetor>(nome, vetorNulo);
        _forcas.inserirPar(par);
        return new Editor<Vetor>(par);
    }
    
    /* (non-Javadoc)
     * @see modelo.RoyerPhysics.TipoConjuntoForcas#obterSomatorioForcas()
     */
    @Override
    public Vetor obterSomatorioForcas()
    {
        Vetor soma = vetorNulo;
        for(Vetor v: _forcas)
            soma = soma.somarCom(v);
        
        return soma;
    }
}

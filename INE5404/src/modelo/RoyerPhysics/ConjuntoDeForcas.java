package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.Editor;
import modelo.RoyerPhysics.estruturasDeDados.DicionarioEditavel;
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

    private DicionarioEditavel<Vetor> _forcas;
    
    /**
     * Cria um conjunto de forças vazio.
     */
    public ConjuntoDeForcas () {
        _forcas = new DicionarioEditavel<Vetor>();
    }
    
    @Override
    public TipoEditor<Vetor> obterForca(String nome)
    {
        if( _forcas.existeChave(nome))
            return _forcas.obterEditor(nome);
        
        Par<String, Vetor> par = new Par<String, Vetor>(nome, vetorNulo);
        _forcas.inserirPar(nome, vetorNulo);
        return new Editor<Vetor>(par);
    }
    
    @Override
    public Vetor obterSomatorioForcas()
    {
        Vetor soma = vetorNulo;
        for(Vetor v: _forcas)
            soma = soma.somarCom(v);
        
        return soma;
    }
}

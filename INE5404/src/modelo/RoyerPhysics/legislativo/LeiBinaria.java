package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.estruturasDeDados.ListaLegivel;
import modelo.estruturasDeDados.Tupla;

/**
 * Representa uma classe que aplica leis aos pares de corpos móveis.
 * 
 * A classe abstrata se encarrega de usar o método <b>aplicarLeiA</b> em todos
 * os pares de objetos, restando ao programador implementar esse método.
 * 
 * @author Tiago Royer
 *
 */
public abstract class LeiBinaria implements TipoLei {

    @Override
    public final void aplicarLei(ListaLegivel<CorpoRigidoMovel> l) {
        for( Tupla<CorpoRigidoMovel> t: l.obterTuplasUnicas(2))
            aplicarLeiA(t.obter(0), t.obter(1));
    }
    
    /**
     * Aplica a lei aos dois corpos rígidos móveis passados.
     * @param c Primeiro corpo.
     * @param d Segundo corpo.
     */
    protected abstract void aplicarLeiA(CorpoRigidoMovel c, CorpoRigidoMovel d);

}

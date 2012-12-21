package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Representa uma lei que é capaz de operar tanto ente pares de objetos móveis quanto
 * entre um objeto móvel e um não móvel.
 * 
 * A classe abstrata se encarrega de usar o método <b>aplicarLeiA</b> em todos
 * os pares de objetos, restando ao programador implementar esse método.

 * @author Tiago Royer
 *
 */
public abstract class LeiBinariaEstrutural extends LeiBinaria implements
        TipoLeiEstruturas {

    @Override
    public void aplicarLei(ListaLegivel<CorpoRigidoMovel> l,
            ListaLegivel<TipoCorpoRigido> m) {
        
        for( CorpoRigidoMovel c: l)
            for( TipoCorpoRigido d: m)
                aplicarLeiA(c, d);

    }

    protected abstract void aplicarLeiA(CorpoRigidoMovel c, CorpoRigidoMovel d);
    protected abstract void aplicarLeiA(CorpoRigidoMovel c, TipoCorpoRigido d);

}

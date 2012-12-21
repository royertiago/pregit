package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Representa uma lei que se aplica a um objeto de cada vez.
 * 
 * A classe abstrata se encarrega de usar o método <b>aplicarLeiA</b> em todos
 * os objetos, um por vez, restando ao programador implementar esse método.
 * 
 * @author Tiago Royer
 * 
 */
public abstract class LeiUnaria implements TipoLei {

    @Override
    public final void aplicarLei(ListaLegivel<CorpoRigidoMovel> l) {
        for (CorpoRigidoMovel c : l)
            aplicarLeiA(c);
    }

    /**
     * Aplicação individual da lei.
     * 
     * @param c
     *            Corpo que terá a lei aplicada.
     */
    protected abstract void aplicarLeiA(CorpoRigidoMovel c);

}

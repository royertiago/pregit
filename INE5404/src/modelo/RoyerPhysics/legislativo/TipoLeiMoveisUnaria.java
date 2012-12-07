package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * Representa uma lei que pode ser aplicada a um único corpo rígido por vez.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLeiMoveisUnaria {

    /**
     * Aplica a lei ào corpo rígido passado.
     * 
     * @param c
     *            Corpo rígido sobre o qual será aplicado a lei.
     */
    public abstract void aplicarLei(CorpoRigidoMovel c);

}

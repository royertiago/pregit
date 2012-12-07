package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * Representa uma lei que pode ser aplicada a pares de corpos rígidos.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLeiMoveisBinaria {

    /**
     * Aplica a lei aos corpos rígidos passados.
     * 
     * @param c
     *            Primeiro corpo rígido móvel que terá a lei executada.
     * @param d
     *            Segundo corpo rígido móvel.
     */
    public abstract void aplicarLei(CorpoRigidoMovel c, CorpoRigidoMovel d);

}

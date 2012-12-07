package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;

/**
 * Representa uma lei que, além de ser aplicada entre dois corpos rígidos móveis,
 * pode ser aplicada entre um corpo rígido móvel e um TipoCorpoRigido (não-móvel).
 * 
 * @author Tiago Royer
 *
 */
public interface TipoLeiBinaria extends TipoLeiMoveisBinaria {

    /**
     * Aplica a lei aos corpos rígidos passados.
     * 
     * @param c
     *            Primeiro corpo rígido, móvel, que terá a lei executada.
     * @param d
     *            Segundo corpo rígido, não-móvel.
     */
    public abstract void aplicarLei(CorpoRigidoMovel c, TipoCorpoRigido d);
}

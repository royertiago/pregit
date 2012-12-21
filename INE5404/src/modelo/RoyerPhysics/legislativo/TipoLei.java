package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Representa uma lei que pode ser aplicada a corpos rígidos móveis.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLei {

    /**
     * Aplica a lei aos corpos rígidos passados.
     * 
     * @param l
     *          Conjunto de corpos rígidos, aos quais a lei deve ser aplicada.
     */
    public abstract void aplicarLei(ListaLegivel<CorpoRigidoMovel> l);

}

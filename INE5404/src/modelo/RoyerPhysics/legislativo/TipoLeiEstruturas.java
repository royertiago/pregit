package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Representa uma lei que, além de ser aplicada entre dois corpos rígidos
 * móveis, pode ser aplicada entre corpos rígidos móveis TipoCorpoRigido
 * (não-móvel).
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLeiEstruturas extends TipoLei {

    /**
     * Aplica a lei aos corpos rígidos passados.
     * 
     * @param l
     *            Lista de corpos rígidos móveis
     * @param m
     *            Lista de corpos rígidos, não-móvel.
     */
    public abstract void aplicarLei(ListaLegivel<CorpoRigidoMovel> l,
            ListaLegivel<TipoCorpoRigido> m);
}

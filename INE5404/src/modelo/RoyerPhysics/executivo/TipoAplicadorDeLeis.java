package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.TipoLei;

/**
 * Essa classe é responsável por aplicar as leis nos corpos rígidos.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoAplicadorDeLeis {

    /**
     * Adiciona um corpo rígido ao grupo de corpos rígidos que sofrem ações das
     * leis.
     * 
     * @param c
     *            Corpo a ser adicionado.
     */
    public abstract void adicionarCorpoRigido(TipoCorpoRigido c);

    /**
     * Remove um corpo rígido do grupo de corpos rígidos que sofrem ações das
     * leis.
     * 
     * @param c
     *            Corpo a ser removido.
     */
    public abstract void removerCorpoRigido(TipoCorpoRigido c);

    /**
     * Adiciona uma lei para ser aplicada ao grupo de corpos rígidos.
     * 
     * @param l
     */
    public abstract void adicionarLei(TipoLei l);

    /**
     * Remove uma lei que é aplicada aos corpos rígidos.
     * 
     * @param l
     */
    public abstract void removerLei(TipoLei l);

    /**
     * Aplica leis adicionadas aos corpos rígidos adicionados.
     */
    public abstract void aplicarLeis();

}

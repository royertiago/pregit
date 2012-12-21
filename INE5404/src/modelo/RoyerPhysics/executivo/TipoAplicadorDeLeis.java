package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
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
     * Adiciona um corpo rígido móvel ao grupo de corpos rígidos que sofrem
     * ações das leis.
     * 
     * @param c
     *            Corpo a ser adicionado.
     */
    public abstract void adicionarCorpoRigido(CorpoRigidoMovel c);

    /**
     * Adiciona um corpo rígido não-móvel ao grupo de corpos rígidos que sofrem
     * ações das leis.
     * 
     * @param c
     *            Corpo a ser adicionado.
     */
    public abstract void adicionarCorpoRigido(TipoCorpoRigido c);

    /**
     * Remove um corpo rígido móvel do grupo de corpos rígidos que sofrem ações
     * das leis.
     * 
     * Nada ocorre caso o corpo não esteja no grupo.
     * 
     * @param c
     *            Corpo a ser removido.
     */
    public abstract void removerCorpoRigido(CorpoRigidoMovel c);

    /**
     * Remove um corpo rígido não-móvel do grupo de corpos rígidos que sofrem
     * ações das leis.
     * 
     * Nada ocorre caso o corpo não esteja no grupo.
     * 
     * @param c
     *            Corpo a ser removido.
     */
    public abstract void removerCorpoRigido(TipoCorpoRigido c);

    /**
     * Adiciona uma lei, para ser aplicada a um corpo rígido móvel de cada vez,
     * à lista de leis.
     * 
     * @param l
     *            Lei a ser adicionada.
     */
    public abstract void adicionarLei(TipoLei l);

    /**
     * Remove um TipoLeiMoveisUnaria da lista de leis.
     * 
     * Nada acontece se a lei não estiver presente na lista de leis.
     * 
     * @param l
     *            Lei a ser removida.
     */
    public abstract void removerLei(TipoLei l);

    /**
     * Aplica as leis aos corpos rígidos existentes.
     */
    public abstract void aplicarLeis();

    /**
     * Informa às leis quanto tempo deve-se passar entre essa e a próxima
     * aplicação das leis.
     * 
     * @param t
     *            Novo tempo a ser considerado.
     */
    public abstract void alterarTempo(double t);
}

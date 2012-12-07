package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.TipoLeiBinaria;
import modelo.RoyerPhysics.legislativo.TipoLeiMoveisBinaria;
import modelo.RoyerPhysics.legislativo.TipoLeiMoveisUnaria;

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
    public abstract void adicionarLei(TipoLeiMoveisUnaria l);

    /**
     * Adiciona uma lei, para ser aplicada a pares de corpos rígidos móveis de
     * cada vez, à lista de leis.
     * 
     * @param l
     *            Lei a ser adicionada.
     */
    public abstract void adicionarLei(TipoLeiMoveisBinaria l);

    /**
     * Adiciona uma lei, para ser aplicada tanto entre um corpo rígido móvel e
     * um TipoCorpoRigido (não-móvel) e a pares de corpos rígidos móveis, à
     * lista de leis.
     * 
     * @param l
     *            Lei a ser adicionada.
     */
    public abstract void adicionarLei(TipoLeiBinaria l);

    /**
     * Remove um TipoLeiMoveisUnaria da lista de leis.
     * 
     * Nada acontece se a lei não estiver presente na lista de leis.
     * 
     * @param l
     *            Lei a ser removida.
     */
    public abstract void removerLei(TipoLeiMoveisUnaria l);

    /**
     * Remove um TipoLeiMoveisBinaria da lista de leis.
     * 
     * Nada acontece se a lei não estiver presente na lista de leis.
     * 
     * @param l
     *            Lei a ser removida.
     */
    public abstract void removerLei(TipoLeiMoveisBinaria l);

    /**
     * Remove um TipoLeiBinaria da lista de leis.
     * 
     * Nada acontece se a lei não estiver presente na lista de leis.
     * 
     * @param l
     *            Lei a ser removida.
     */
    public abstract void removerLei(TipoLeiBinaria l);

    /**
     * Aplica leis adicionadas aos corpos rígidos adicionados.
     */
    public abstract void aplicarLeis();

}

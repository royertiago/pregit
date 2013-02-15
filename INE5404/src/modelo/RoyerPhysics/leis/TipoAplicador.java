package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;

/**
 * Aplicadores de leis são classes que mantêm controle de todos os objetos em um campo
 * e todas as leis; é responsável por aplicar a lei a cada objeto no campo.
 * @author Tiago Royer
 *
 */
public interface TipoAplicador {

    /**
     * Adiciona uma lei ao conjunto das leis aplicadas ao sistema.
     * 
     * @param l
     *            Lei a ser adicionada.
     */
    public abstract void registrarLei(TipoLei l);

    /**
     * Remove uma lei do conjunto das leis aplicadas ao sistema, se ela existir
     * lá.
     * 
     * @param l
     *            Lei a ser removida.
     */
    public abstract void removerLei(TipoLei l);

    /**
     * Adiciona um corpo rígido ao conjunto dos corpos que sofre a aplicação das
     * leis do sistema.
     * 
     * @param c
     *            Corpo rígido a ser adicionado.
     */
    public abstract void registrarCorpo(CorpoRigidoMovel c);

    /**
     * Remove o corpo rígido do conjunto dos corpos que sofre a aplicação das
     * leis do sistema, se ele existir lá.
     * 
     * @param c
     */
    public abstract void removerCorpo(CorpoRigidoMovel c);

    /**
     * Adiciona uma estrutura ao conjunto das estruturas que sofrem a aplicação
     * das leis do sistema.
     * 
     * @param p
     *            Estrutura a ser adicionada.
     */
    public abstract void registrarEstrutura(PoligonoEstrutural p);

    /**
     * Remove a estrutura do conjunto das estruturas que sofrem a aplicação das
     * leis do sistema, se ela existir lá.
     * 
     * @param p
     *            Estrutura a ser removida.
     */
    public abstract void removerEstrutura(PoligonoEstrutural p);

    /**
     * Avança o sistema em <b>tempo</b> segundos.
     * 
     * Todas as leis são aplicadas ao sistema.
     * 
     * @param tempo
     *            Tempo, em segundos, a ser avançado o sistema.
     */
    public abstract void avancar(double tempo);

}
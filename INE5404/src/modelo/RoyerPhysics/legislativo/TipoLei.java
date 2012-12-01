package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.estruturasDeDados.Tupla;

/**
 * Representa uma lei que pode ser aplicada em vários corpos rígidos.
 * 
 * Por exemplo, a colisão entre dois corpos é uma lei da física.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLei {

    /**
     * Aplica a lei aos corpos rígidos passados.
     * 
     * @param o
     *            Tupla de corpos rígidos sobre os quais será aplicada a lei.
     */
    public abstract void aplicarLei(Tupla<TipoCorpoRigido> o);

    /**
     * O método aplicarLei é aplicado a uma certa quantidade de corpos rígidos;
     * este método informa qual é essa quantidade.
     * 
     * @return O tamanho das tuplas para o método aplicarLei.
     */
    public abstract int obterNumeroParametros();

}

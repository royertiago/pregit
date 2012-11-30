package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.TipoCorpoRigido;

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
     *            Os corpos rígidos sobre o qual serão aplicados a lei.
     */
    public abstract void aplicarLei(TipoCorpoRigido... o);

    /**
     * O método aplicarLei é aplicado a uma certa quantidade de corpos rígidos;
     * este método informa qual é essa quantidade.
     * 
     * @return A quantidade de parâmetros para o método aplicarLei.
     */
    public abstract int obterNumeroParametros();

}

package modelo.RoyerPhysics.legislativo;

/**
 * Representa uma lei que tem o seu comportamento alterado, de acordo com o
 * tempo que deve se passar entre essa aplicação da lei e da próxima.
 * 
 * Por exemplo, se for passado 0.5 a uma lei de movimento, ela deve mover o
 * corpo metade da quantidade que seria movida se fosse 1.
 * 
 * @author Tiago Royer
 * 
 */
public interface LeiSensivelAoTempo extends TipoLei {

    /**
     * Informa a quantidade de tempo que deve passar entre essa aplicação da lei
     * e da próxima.
     * 
     * @param tempo
     *            Quantidade de tempo passada, em segundos.
     */
    public abstract void informarTempo(double tempo);

}

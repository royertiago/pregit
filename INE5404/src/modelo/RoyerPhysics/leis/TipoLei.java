package modelo.RoyerPhysics.leis;

/**
 * Representa uma lei, que pode ser aplicada aos objetos do jogo.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLei {

    /**
     * Aplicar a lei àos corpos do campo <b>c</b>.
     * 
     * @param c
     *            ClockDoCampo que deve ser considerado para a aplicação da lei.
     */
    public void aplicar(TipoClockDoCampo c);
}

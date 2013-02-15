package modelo.RoyerPhysics.leis;

/**
 * Representa uma lei, que pode ser aplicada aos objetos do jogo.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoLei {

    /**
     * Aplicar a lei àos corpos do campo <b>c</b>. <b>tempo</b> é o tempo, em
     * segundos, que o sistema deve ser avançado.
     * 
     * Por exemplo, se um objeto está se movendo a 10m/s, avançar o sistema em
     * 1.5 segundo deslocaria este objeto 15m.
     * 
     * @param c
     *            Campo em que será aplicada a lei
     * @param tempo
     *            Tempo, em segundos, que o sistema deve ser avançado.
     */
    public void aplicar(Campo c, double tempo);
}

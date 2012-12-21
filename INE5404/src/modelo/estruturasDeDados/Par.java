package modelo.estruturasDeDados;

/**
 * Representa um par ordenado. Armazena dois valores de dois tipos, não
 * necessariamente os mesmos.
 * 
 * @author Tiago Royer
 * 
 * @param <Tipo1>
 *            Primeiro tipo do par ordenado.
 * @param <Tipo2>
 *            Segundo tipo do par ordenado.
 */
public class Par<Tipo1, Tipo2> {

    public Tipo1 t1;
    public Tipo2 t2;

    public Par(Tipo1 t1, Tipo2 t2) {
        this.t1 = t1;
        this.t2 = t2;
    }
}

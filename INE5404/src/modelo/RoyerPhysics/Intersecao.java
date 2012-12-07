package modelo.RoyerPhysics;

/**
 * Classe que representa uma interseção entre dois (ou mais) objetos.
 * 
 * @author Tiago Royer
 * 
 */
public class Intersecao {

    /**
     * Interseção que deve ser usada caso não haja interseção.
     */
    public static final Intersecao semIntersecao = new Intersecao(null, 0);
    
    public final Coordenada origem;
    public final double angulo;

    /**
     * Representa um evento de colisao.
     * 
     * @param origem
     *            Ponto em que ocorreu a interseção.
     * @param angulo
     *            Ângulo da interseção.
     */
    public Intersecao(Coordenada origem, double angulo) {
        this.origem = origem;
        this.angulo = angulo;
    }
    
    public String toString()
    {
        if (this == semIntersecao)
            return "Sem Intersecao";
        else
            return origem + " - Ângulo: " + angulo;
    }
}

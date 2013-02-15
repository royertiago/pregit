package modelo.RoyerPhysics;

import static modelo.RoyerPhysics.Coordenada.*;

/**
 * Representa um vetor matemático. O sistema de coordenadas considerado é
 * espelhado em relação ao eixo X, se comparado com o modelo cartesiano
 * matemático.
 * 
 * @author Tiago Royer
 */
public class Vetor {

    public static final Vetor vetorNulo = new Vetor(0, 0);

    public final double x;
    public final double y;

    /**
     * Cria um vetor.
     * 
     * @param x
     *            Abcissa da grandeza representada.
     * 
     * @param y
     *            Ordenada da grandeza representada.
     */
    public Vetor(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Converte este vetor para uma coordenada.
     * 
     * @return Uma Coordenada com os mesmos valores deste vetor.
     */
    public Coordenada paraCoordenada() {
        return new Coordenada(x, y);
    }

    /**
     * Espelha o vetor sobre o ângulo <b>angulo</b>.
     * 
     * O novo vetor calculado possui o mesmo módulo do original e ângulo
     * invertido, em relação a <b>angulo</b>. Por exemplo, o vetor (1, 1),
     * espelhado em torno de π/2 (o eixo Y), retornaria (-1, 1).
     * 
     * Note que, como o sistema de coordenadas considerdo é espelhado em relação
     * ao eixo X, comparado com o plano cartesiano matemático (a origem é o
     * canto superior esquerdo), espelhar mesmo vetor contra π/2 (reta x = y)
     * retornaria (-1, -1), enquanto espelhar contra -π/2 (reta y = -x)
     * retornaria (1, 1).
     * 
     * @param angulo
     *            Ângulo contra o qual o vetor será espelhado.
     * @return
     */
    public Vetor espelharSeSobre(double angulo) {
        // Girar para o eixo X;
        Coordenada alce = this.paraCoordenada().girarEmTornoDe(origem, -angulo);

        // Espelhar em torno do eixo X e girar de volta ao original:
        return new Coordenada(alce.x, -alce.y).girarEmTornoDe(origem, angulo)
                .paraVetor();
    }

    /**
     * Soma este vetor ao vetor <b>v</b>.
     * 
     * @param v
     *            Vetor a ser somado.
     * @return Um novo vetor, que é a soma desse com <b>v</b>.
     */
    public Vetor somarCom(Vetor v) {
        return new Vetor(this.x + v.x, this.y + v.y);
    }

    /**
     * Multiplica esse vetor pelo escalar <b>c</b>
     * 
     * @param c
     *            Constante a ser multiplicada
     * @return Um novo vetor, com seus valores alterados.
     */
    public Vetor escalar(double c) {
        return new Vetor(x * c, y * c);
    }

    @Override
    public String toString() {
        return String.format("[%.3f;%.3f]", x, y);
    }
    
    /**
     * Projeta este vetor perpendicularmente sobre <b>v</b>.
     * @param v Vetor sobre o qual este será projetato.
     * @return A projeção deste vetor.
     */
    public Vetor projetarSe (Vetor v)
    {
        return new Vetor((v.x*v.x*this.x + v.x*v.y*this.y)/(v.x*v.x + v.y*v.y),(v.x*v.y*this.x + v.y*v.y*this.y)/(v.x*v.x + v.y*v.y));
    }
}

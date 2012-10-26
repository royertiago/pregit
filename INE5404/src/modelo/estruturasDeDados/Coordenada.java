/**
 * Esta classe representa uma coordenada no plano cartesiano. Indo à direita aumenta-se a variável X,
 * descendo aumenta-se a variável Y.
 * 
 * @author Tiago Royer
 */

package modelo.estruturasDeDados;

public class Coordenada {

    public final int x, y;

    /**
     * Cria uma coordenada com os valores X e Y passados.
     * 
     * @param x
     *            O valor da abscissa (eixo X)
     * @param y
     *            O valor da ordenada (exio Y)
     */
    public Coordenada(int x, int y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Retorna uma coordenada <b>quantidade</b> abaixo, no plano cartesiano.
     * Caso a quantidade seja negativa, a coordenada estará movida para cima.
     * 
     * @param quantidade
     *            A quantidade a ser movida.
     * @return Um novo objeto Coordenada, movido.
     */
    public Coordenada moverAbaixo(int quantidade) {
        return new Coordenada(x, y + quantidade);
    }

    /**
     * Retorna uma coordenada <b>quantidade</b> acima, no plano cartesiano. Caso
     * a quantidade seja negativa, a coordenada estará movida para baixo.
     * 
     * @param quantidade
     *            A quantidade a ser movida.
     * @return Um novo objeto Coordenada, movido.
     */
    public Coordenada moverAcima(int quantidade) {
        return new Coordenada(x, y - quantidade);
    }

    /**
     * Retorna uma coordenada <b>quantidade</b> à direita, no plano cartesiano.
     * Caso a quantidade seja negativa, a coordenada estará movida à esquerda.
     * 
     * @param quantidade
     *            A quantidade a ser movida.
     * @return Um novo objeto Coordenada, movido.
     */
    public Coordenada moverDireita(int quantidade) {
        return new Coordenada(x + quantidade, y);
    }

    /**
     * Retorna uma coordenada <b>quantidade</b> à esquerda, no plano cartesiano.
     * Caso a quantidade seja negativa, a coordenada estará movida à direita.
     * 
     * @param quantidade
     *            A quantidade a ser movida.
     * @return Um novo objeto Coordenada, movido.
     */
    public Coordenada moverEsquerda(int quantidade) {
        return new Coordenada(x - quantidade, y);
    }

    /**
     * Retorna uma representação em string do objeto. Formato: (x,y).
     * 
     * @return Uma representação em string da coordenada.
     */
    @Override
    public String toString() {
        return "(" + x + "," + y + ")";
    }
}

/**
 * Esta classe representa um ponto no plano cartesiano. O canto superior esquerdo
 * é a origem (0,0). Indo à direita aumenta-se o valor da abscissa (eixo X), descendo 
 * umenta-se a ordenada (eixo Y).
 * 
 * @author Tiago Royer
 */

package modelo;

public final class Coordenada {

    public final double x, y;

    public static final Coordenada origem = new Coordenada(0, 0);

    /**
     * Cria uma coordenada com os valores X e Y passados.
     * 
     * @param x
     *            O valor da abscissa (eixo X)
     * @param y
     *            O valor da ordenada (exio Y)
     */
    public Coordenada(double x, double y) {
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
    public Coordenada moverAbaixo(double quantidade) {
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
    public Coordenada moverAcima(double quantidade) {
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
    public Coordenada moverDireita(double quantidade) {
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
    public Coordenada moverEsquerda(double quantidade) {
        return new Coordenada(x - quantidade, y);
    }

    /**
     * Gira esta coordenada em torno da coordenada <b>p</b>, <b>angulo</b>
     * radianos em sentido anti-horário.
     * 
     * @param c
     *            Coordenada em torno da qual esta coodenada será girado.
     * @param angulo
     *            Ângulo, em radianos, da rotação.
     * @return Uma nova coordenada, rotacionada.
     */
    public Coordenada girarEmTornoDe(Coordenada c, double angulo) {
        // Desloca a coordenada para a origem
        double x = this.x - c.x;
        double y = this.y - c.y;
        // Gira a coordenada em torno da origem
        double x0 = Math.cos(angulo) * x + Math.sin(angulo) * y;
        double y0 = Math.cos(angulo) * y - Math.sin(angulo) * x;
        // Devolve a coordenada, deslocada para o ponto original.
        return new Coordenada(x0 + c.x, y0 + c.y);
    }

    /**
     * Retorna uma representação em string da coordenada. Formato: (x,y), precisão: 3 casas decimais.
     * 
     * @return Uma representação em string do ponto.
     */
    @Override
    public String toString() {
        return String.format("(%.3f;%.3f)", x, y);
    }

    /**
     * Informa o ângulo da inclinação da reta que passa por esse ponto e por
     * <b>c</b>.
     * 
     * @param c
     *            Coordenada com a qual será obtido o ângulo.
     * @return O ângulo da inclinação da reta que passa por esse ponto e por
     *         <b>c</b>.
     */
    public double obterAnguloCom(Coordenada c) {
        /*if (c.x == this.x)
            return Math.PI / 2;
        else
            return Math.atan((this.y - c.y) / (this.x - c.x));
        */
        return Math.atan2(this.y - c.y, this.x - c.x);
    }
}

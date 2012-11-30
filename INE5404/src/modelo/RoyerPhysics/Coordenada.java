package modelo.RoyerPhysics;

/**
 * Esta classe representa um ponto no plano. O sistema de coordesadas é
 * espelhado em relação ao eixo X, se comparado com o modelo cartesiano
 * matemático.
 * 
 * @author Tiago Royer
 */
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
     * Desloca esta coordenada de acordo com o vetor <b>v</b>.
     * 
     * Por exemplo, se o vetor contém (2, 0) a coordenada será deslocada 2
     * unidades para a esquerda.
     * 
     * @param v
     *            Vetor que "comandará" o deslocamento.
     * @return Uma nova coordenada, deslocada.
     */
    public Coordenada deslocar(Vetor v) {
        return new Coordenada(this.x + v.x, this.y + v.y);
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
     * Retorna uma representação em string da coordenada. Formato: (x,y),
     * precisão: 3 casas decimais.
     * 
     * @return Uma representação em string do ponto.
     */
    @Override
    public String toString() {
        return String.format("(%.3f;%.3f)", x, y);
    }

    /**
     * Informa o ângulo da inclinação da reta que passa por esse ponto e por
     * <b>c</b>. O ângulo é positivo no sentido horário, e negativo no sentido
     * anti-horário.
     * 
     * Essa função tem um conjunto de retornos semelhante à função atan2, mas,
     * como o sistema de coordenadas é invertido, a saída é, geralmente,
     * invertida.
     * 
     * Casos:
     * <ul>
     * <li><b>c</b> está perfeitamente acima desta coordenada: retorna π/2.</li>
     * <li><b>c</b> está perfeitamente abaixo: retorna -π/2.</li>
     * <li><b>c</b> está perfeitamente à esquerda: retorna 0.</li>
     * <li><b>c</b> está perfeitamente à direita: retorna π.</li>
     * <li><b>c</b> está acima e à esquerda: retorna um valor entre 0 e π/2.</li>
     * <li><b>c</b> está acima e à direita: retorna um valor entre π/2 e π.</li>
     * <li><b>c</b> está abaixo e à esquerda: retorna um valor entre -π/2 e 0.</li>
     * <li><b>c</b> está abaixo e à direita: retorna um valor entre -π e -π/2.</li>
     * </ul>
     * 
     * Embora caso as duas coordenadas sejam coincidentes não haja uma reta, o
     * valor retornado é π/2. Note que a função nunca retorna -π.
     * 
     * @param c
     *            Coordenada com a qual será obtido o ângulo.
     * @return O ângulo da inclinação da reta que passa por esse ponto e por
     *         <b>c</b>.
     */
    public double obterAnguloCom(Coordenada c) {
        double vX = c.x - this.x;
        double vY = this.y - c.y;
        if (vX == 0)
            return (vY >= 0 ? Math.PI / 2 : -Math.PI / 2);
        else if (vX > 0)
            return Math.atan(vY / vX);
        else
            return Math.atan(vY / vX) + (vY > 0 ? Math.PI : -Math.PI);
    }

    /**
     * Converte esta coordenada para um Vetor.
     * 
     * @return um Vetor com os mesmos valores que esta coordenada.
     */
    public Vetor paraVetor() {
        return new Vetor(x, y);
    }
}

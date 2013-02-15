package modelo.RoyerPhysics;

public interface TipoPoligono {

    /**
     * Diz se uma determinada coordenada está ou não contida no polígono.
     * 
     * @param c
     *            A coordenada a ser analisada.
     * @return <b>true</b> se estiver contido, <b>false</b> caso contrário.
     */
    public abstract boolean contem(Coordenada c);

    /**
     * Retorna o ângulo de colisão com o ponto p. Por exemplo, se o ponto
     * estiver sobre a reta superior de um quadrado, o ângulo retornado deve ser
     * 0, e π caso esteja sobre a reta inferior.
     * 
     * O ângulo deve estar contido no intervalo (-π, π]. O sinal do ângulo deve
     * significar o lado para onde não há colisão (π/2 radianos em sentido
     * anti-horário deve ser dentro do polígono).
     * 
     * @param c
     *            Ponto contra o qual será calculado o ângulo de colisão.
     * @return O ângulo de colisão, em radianos.
     */
    public abstract double anguloColisao(Coordenada c);

    /**
     * Obtém o ponto de interseção deste objeto com o outro polígono convexo.
     * Caso não haja interseção, o valor <b>null</b> é retornado.
     * 
     * @param p
     *            Polígono contra o qual intersecção é testada.
     * @return
     */
    public abstract Coordenada obterIntersecao(TipoPoligonoConvexo p);

}
package modelo.fisico.estruturas;

public interface TipoVetorMovimento {

    /**
     * Move a máscara de colisao <b>b</b> de acordo com as grandezas
     * armazenadas.
     * 
     * @param m
     * @return
     */
    public TipoMascaraDeColisao moverMascara(TipoMascaraDeColisao m);

    /**
     * Retorna um novo vetor de movimento, que é resultado da colisão deste
     * vetor com uma parede de ângulo <b>angulo</b>.
     * 
     * @param angulo
     *            Angulo da parede contra a qual o vetor será colidido
     * @return um novo TipoVetorMovimento, com direção/sentido alterados.
     */
    public TipoVetorMovimento colidirSeCom(double angulo);

    /**
     * Retorna um novo vetor de movimento, que é resultado da colisão deste
     * vetor com uma parede do ângulo correspondente a <b>i</b>.
     * 
     * @param i
     *            Interseção contra a qual será efetuada a colisão.
     * @return um novo TipoVetorMovimento, com direção/sentido alterados.
     */
    public TipoVetorMovimento colidirSeCom(Intersecao i);
}

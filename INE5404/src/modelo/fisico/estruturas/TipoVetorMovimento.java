package modelo.fisico.estruturas;

import modelo.fisico.colisoes.Colisao;

public interface TipoVetorMovimento {

    /**
     * Move a máscara de colisao <b>b</b> de acordo com as grandezas
     * armazenadas.
     * 
     * @param m
     * @return
     */
    public TipoMascaraDeColisaoMovel moverMascara(TipoMascaraDeColisaoMovel m);

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
     * vetor com o ângulo armazenado em <b>c</b>.
     * 
     * @param c
     *            Evento de colisão a ser tratado
     * @return um novo TipoVetorMovimento, com direção/sentido alterados.
     */
    public TipoVetorMovimento colidirSeCom(Colisao c);
}

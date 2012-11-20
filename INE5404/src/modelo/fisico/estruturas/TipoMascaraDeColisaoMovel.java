/**
 * Representa uma máscara de colisão genérica, que pode ser movida.
 */

package modelo.fisico.estruturas;


public interface TipoMascaraDeColisaoMovel extends TipoMascaraDeColisao {

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para cima. Se o valor
     * for negativo, a máscara estará movida para baixo.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para cima.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisaoMovel moverAcima(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para baixo. Se o valor
     * for negativo, a máscara estará movida para cima.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para baixo.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisaoMovel moverAbaixo(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à direita. Se o valor
     * for negativo, a máscara estará movida à esquerda.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à direita.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisaoMovel moverDireita(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à esquerda. Se o valor
     * for negativo, a máscara estará movida à direita.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à esquerda.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisaoMovel moverEsquerda(double quantidade);

}

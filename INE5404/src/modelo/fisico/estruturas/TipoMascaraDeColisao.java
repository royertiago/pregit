/**
 * Representa uma máscara de colisão genérica.
 */

package modelo.fisico.estruturas;

import modelo.Coordenada;
import modelo.ListaLegivel;

public interface TipoMascaraDeColisao {

    /**
     * Diz se uma determinada coordenada está ou não contido na máscara de
     * colisão. Caso a coordenada estiver sobre uma aresta, é considerado dentro
     * da máscara.
     * 
     * @param c
     *            A coordenada a ser analisado.
     * @return <b>true</b> se estiver contido, <b>false</b> caso contrário.
     */
    public boolean estaDentro(Coordenada c);

    /**
     * Obtêm uma lista de coordenadas, que representam as extremidades da
     * máscara de colisão.
     * 
     * @return Uma lista de Coordenadas, que estão nas extremidades da máscara.
     */
    public ListaLegivel<Coordenada> obterPontosExtremidades();

    /**
     * Cria uma coordenada que representa o centro da máscara de colisão.
     * 
     * @return Um objeto Coordenada que representa o centro da máscara de
     *         colisão.
     */
    public Coordenada obterCentro();

    /**
     * Retorna o ângulo de colisão com o ponto p. Por exemplo, se o ponto
     * estiver na extremidade de um círculo, o valor retornado deve ser ângulo
     * de inclinação da reta tangente, em relação ao eixo X.
     * 
     * Possui um comportamento não previsível caso o ponto testado não esteja no
     * interior do objeto.
     * 
     * @param p
     *            Ponto contra o qual será calculado o ângulo de colisão.
     * @return O ângulo de colisão, em radianos.
     */
    public double anguloColisao(Coordenada p);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para cima. Se o valor
     * for negativo, a máscara estará movida para baixo.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para cima.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisao moverAcima(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para baixo. Se o valor
     * for negativo, a máscara estará movida para cima.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para baixo.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisao moverAbaixo(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à direita. Se o valor
     * for negativo, a máscara estará movida à esquerda.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à direita.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisao moverDireita(double quantidade);

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à esquerda. Se o valor
     * for negativo, a máscara estará movida à direita.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à esquerda.
     * @return Uma nova máscara de colisão, movida.
     */
    public TipoMascaraDeColisao moverEsquerda(double quantidade);

}

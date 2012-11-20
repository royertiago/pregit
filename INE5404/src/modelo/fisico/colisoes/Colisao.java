/**
 * Representa um evento de colisão.
 */

package modelo.fisico.colisoes;

import modelo.fisico.ObservadoFisico;

public class Colisao {

    public static final Colisao semColisao = new Colisao(0, null, null);

    public final ObservadoFisico colisor1, colisor2;
    public final double angulo;

    /**
     * Cria um novo evento de colisão, que ocorreu entre <b>colisor1</b> e
     * <b>colisor2</b>, com ângulo <b>angulo</b>. O ângulo é calculado em
     * relação ao eixo <i>x</i>.
     * 
     * @param angulo
     *            Ângulo da colisão.
     * @param colisor1
     *            Um dos Observados Fisicos que colidiram
     * @param colisor2
     *            O outro Observado Físico que colidiu.
     */
    public Colisao(double angulo, ObservadoFisico colisor1,
            ObservadoFisico colisor2) {
        this.colisor1 = colisor1;
        this.colisor2 = colisor2;
        this.angulo = angulo;
    }

    public String toString() {
        if (this == semColisao)
            return "Sem Colisao";
        else
            return "Colisao de ângulo " + angulo + " com os colisores: \n"
                    + colisor1 + "\n" + colisor2;
    }

}

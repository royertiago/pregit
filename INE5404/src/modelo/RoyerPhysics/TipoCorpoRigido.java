package modelo.RoyerPhysics;

/**
 * Representa um corpo rígido, que deve ser tratado como imóvel.
 * 
 * Todo corpo rígido deve ser capaz de:
 * <ul>
 * <li>Decidir se um ponto está contido no corpo rígido</li>
 * <li>Determinar o ângulo de colisão do ponto com o corpo rígido</li>
 * </ul>
 * 
 * @author Tiago Royer
 *
 */
public interface TipoCorpoRigido {

    /**
     * Diz se uma determinada coordenada está ou não contida no colidível.
     * 
     * @param c
     *            A coordenada a ser analisado.
     * @return <b>true</b> se estiver contido, <b>false</b> caso contrário.
     */
    public abstract boolean estaDentro(Coordenada c);

    /**
     * Retorna o ângulo de colisão com o ponto p. Por exemplo, se o ponto
     * estiver na extremidade de um círculo, o valor retornado deve ser ângulo
     * de inclinação da reta tangente, em relação ao eixo X.
     * 
     * O ângulo deve estar contido no intervalo (-π, π]. O sinal do ângulo deve
     * significar o lado para onde não há colisão (π/2 radianos em sentido
     * anti-horário deve ser dentro da máscara).
     * 
     * @param p
     *            Ponto contra o qual será calculado o ângulo de colisão.
     * @return O ângulo de colisão, em radianos.
     */
    public abstract double anguloColisao(Coordenada p);

}
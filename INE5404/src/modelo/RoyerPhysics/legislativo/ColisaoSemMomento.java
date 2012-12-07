package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.Intersecao;
import modelo.RoyerPhysics.TipoCorpoRigido;
import static modelo.RoyerPhysics.Intersecao.semIntersecao;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Esta é uma versão da lei de colisões que desconsidera momento linear.
 * 
 * @author Tiago Royer
 * 
 */
public class ColisaoSemMomento implements TipoLeiBinaria  {

    @Override
    public void aplicarLei(CorpoRigidoMovel c, TipoCorpoRigido d) {
        Intersecao i = testarColisao(c, d); //TODO: Jogar esse teste para dentro dos corpos rígidos.
        if (i != semIntersecao) {
            // Se ocorreu interseção, alterar o vetor de movimento de ambos
            // os corpos.
            c.espelharVetorMovimento(i.angulo);
        }
    }
    

    @Override
    public void aplicarLei(CorpoRigidoMovel c, CorpoRigidoMovel d) {
        Intersecao i = testarColisao(c, d);
        if (c != semIntersecao) {
            // Se ocorreu interseção, alterar o vetor de movimento de ambos
            // os corpos.
            c.espelharVetorMovimento(i.angulo);
            d.espelharVetorMovimento(i.angulo);
        }
    }

    /**
     * Método interno que testa se os dois objetos estão intersectando. Essa
     * variação testa entre dois corpos rígidos móveis.
     * 
     * Ele pede, a cada um, se eles contêm pontos um do outro. No caso afirmativo,
     * há interseção; o método pede àquele que não é "dono" do ponto qual é o
     * ângulo da interseção, e gera uma interseção com o ângulo e com o ponto em
     * que ocorreu a colisão. Caso não haja interseção, o método retorna
     * Intersecao.semIntersecao.
     * 
     * @param a
     *            Primeiro objeto a ser testado
     * @param b
     *            Segundo objeto a ser testado
     * @return Um objeto <b>Intersecao</b> caso haja colisão; e
     *         <b>Intersecao.semIntersecao</b> caso não haja.
     */
    protected static Intersecao testarColisao(CorpoRigidoMovel a,
            CorpoRigidoMovel b) {
        ListaLegivel<Coordenada> cA = a.obterPontosExtremidades(), cB = b
                .obterPontosExtremidades();

        for (Coordenada c : cA) {
            // Para cada coordenada na lista de pontos do A, testar se está
            // dentro de B; se estiver, então deu colisão; basta descobrir o
            // ângulo.
            if (b.estaDentro(c))
                return new Intersecao(c, b.anguloColisao(c));
        }

        for (Coordenada c : cB) {
            // Para cada coordenada na lista de pontos do B, testar se está
            // dentro de A; se estiver, então deu colisão; basta descobrir o
            // ângulo.
            if (a.estaDentro(c))
                return new Intersecao(c, a.anguloColisao(c));
        }

        // Se a execução chegar até aqui, significa que nenhuma colisão foi
        // detectada nos laços, então concluímos que não deve ter ocorrida
        // nenhuma colisão.

        return semIntersecao;

    }

    /**
     * Método interno que testa se os dois objetos estão intersectando. Essa
     * variação testa entre um corpo rígido móvel e um não-móvel.
     * 
     * Ele pede ao não-móvel se ele contêm pontos do móvel. No caso afirmativo,
     * há interseção; o método pede ao não-móvel qual é o
     * ângulo da interseção, e gera uma interseção com o ângulo e com o ponto em
     * que ocorreu a colisão. Caso não haja interseção, o método retorna
     * Intersecao.semIntersecao.
     * 
     * @param movel
     *            Primeiro objeto a ser testado
     * @param fixo
     *            Segundo objeto a ser testado
     * @return Um objeto <b>Intersecao</b> caso haja colisão; e
     *         <b>Intersecao.semIntersecao</b> caso não haja.
     */
    protected static Intersecao testarColisao(CorpoRigidoMovel movel,
            TipoCorpoRigido fixo) {
        
        ListaLegivel<Coordenada> cMovel = movel.obterPontosExtremidades();
        
        for( Coordenada c: cMovel )
            if( fixo.estaDentro(c) )
                return new Intersecao(c, fixo.anguloColisao(c));
        
        return semIntersecao;

    }

}

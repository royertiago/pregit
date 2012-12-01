package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.Intersecao;
import static modelo.RoyerPhysics.Intersecao.semIntersecao;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.estruturasDeDados.ListaLegivel;
import modelo.estruturasDeDados.Tupla;

/**
 * Esta é uma versão da lei de colisões que desconsidera momento linear.
 * 
 * @author Tiago Royer
 * 
 */
public class ColisaoSemMomento implements TipoLei {

    @Override
    public void aplicarLei(Tupla<TipoCorpoRigido> o) {
        if (o.tamanho() != 2)
            throw new IllegalArgumentException(
                    "Deve haver dois e somente dois corpos rígidos como argumento.");
        else {
            Intersecao c = testarColisao(o.obter(0), o.obter(1));
            if (c != semIntersecao) {
                // Se ocorreu interseção, alterar o vetor de movimento de ambos
                // os corpos.
                o.obter(0).espelharVetorMovimento(c.angulo);
                o.obter(1).espelharVetorMovimento(c.angulo);
            }
        }
    }

    @Override
    public int obterNumeroParametros() {
        return 2;
    }

    /**
     * Método interno que testa se os dois objetos estão intersectando. Ele
     * pede, a cada um, se eles contêm pontos um do outro. No caso afirmativo,
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
    protected static Intersecao testarColisao(TipoCorpoRigido a,
            TipoCorpoRigido b) {
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

}

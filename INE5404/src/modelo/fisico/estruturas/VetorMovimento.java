/**
 * Determina o vetor de movimento.
 */

package modelo.fisico.estruturas;

import modelo.Coordenada;
import modelo.fisico.colisoes.Colisao;

public class VetorMovimento implements TipoVetorMovimento {

    public final double movimentoVertical;
    public final double movimentoHorizontal;

    /**
     * Cria um vetor de movimento. Os valores armazenados são usados ao
     * atualizar a máscara de colisão.
     * 
     * @param movimentoVertical
     *            O quanto a máscara de colisão deve descer ao atualizar; Caso
     *            for negativo, será movido abaixo.
     * @param movimentoHorizontal
     *            O quanto a máscara de colisão deve ser movida à esquerda ao
     *            atualizar; Caso negativo, será movida para a direita.
     */
    public VetorMovimento(double movimentoHorizontal, double movimentoVertical) {
        this.movimentoHorizontal = movimentoHorizontal;
        this.movimentoVertical = movimentoVertical;
    }
    
    @Override
    public TipoMascaraDeColisaoMovel moverMascara(TipoMascaraDeColisaoMovel m) {
        return m.moverAbaixo(movimentoVertical).moverDireita(movimentoHorizontal);
    }

    @Override
    public VetorMovimento colidirSeCom(double angulo) {
        // Para poder usar a função de rotação da classe Coordenada
        Coordenada c = new Coordenada(this.movimentoHorizontal, this.movimentoVertical);
        // Girar para a origem:
        c = c.girarEmTornoDe(Coordenada.origem, -angulo);
        // Espelhar em torno de X:
        c = new Coordenada( c.x, -c.y);
        // Girar para o ângulo original
        c = c.girarEmTornoDe(Coordenada.origem, angulo);
        return new VetorMovimento(c.x, c.y);
    }
    
    @Override
    public String toString()
    {
        return String.format("[%.3f;%.3f]", movimentoHorizontal, movimentoVertical);
    }

    @Override
    public VetorMovimento colidirSeCom(Colisao c) {
        return this.colidirSeCom(c.angulo);
    }
}

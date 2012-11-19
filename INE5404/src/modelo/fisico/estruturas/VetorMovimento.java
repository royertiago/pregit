/**
 * Determina o vetor de movimento.
 */

package modelo.fisico.estruturas;

import modelo.Coordenada;

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
    public VetorMovimento(double movimentoVertical, double movimentoHorizontal) {
        this.movimentoHorizontal = movimentoHorizontal;
        this.movimentoVertical = movimentoVertical;
    }
    
    @Override
    public TipoMascaraDeColisao moverMascara(TipoMascaraDeColisao m) {
        return m.moverAbaixo(movimentoVertical).moverEsquerda(movimentoHorizontal);
    }

    @Override
    public TipoVetorMovimento colidirSeCom(double angulo) {
        //Obter a norma da colisão
        double a = angulo + Math.PI/2;
        // Para poder usar as funções de rotação da classe Coordenada
        Coordenada c = new Coordenada(this.movimentoHorizontal, this.movimentoVertical);
        // Girar para o eixo X
        c = c.girarEmTornoDe(Coordenada.origem, -a);
        // Espelhar em torno da origem
        c = new Coordenada(-c.x, c.y);
        //Girar de volta para o ângulo normal
        c = c.girarEmTornoDe(Coordenada.origem, a);
        //Devolver em forma de VetorMovimento
        return new VetorMovimento(c.x, c.y);
    }
    
    @Override
    public String toString()
    {
        return String.format("[%.3f;%.3f]", movimentoHorizontal, movimentoVertical);
    }

    @Override
    public TipoVetorMovimento colidirSeCom(Intersecao i) {
        return this.colidirSeCom(i.angulo);
    }
}

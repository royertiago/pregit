/**Classe que representa um retângulo, que será usado pelo controlador de colisões para
 * o teste preliminar de colisão.
 * O canto superior esquerdo é o ponto (0,0); os valores aumentam à direita e abaixo.
 * 
 * @author Tiago Royer
 */

package modelo.estruturasDeDados;

public class MascaraDeColisao {
    public final int esquerda, topo, largura, altura;

    /**
     * Cria uma máscara de colisão retangular.
     * 
     * @param esquerda
     *            Abscissa (exio X) do canto superior esquerdo da máscara de
     *            colisão.
     * @param topo
     *            Ordenada (exio Y) do canto superior esquerdo da máscara de
     *            colisão.
     * @param largura
     *            Largura da máscara de colisão.
     * @param altura
     *            Altura da máscara de colisão.
     */
    public MascaraDeColisao(int esquerda, int topo, int largura, int altura) {
        this.esquerda = esquerda;
        this.topo = topo;
        if (largura >= 0)
            this.largura = largura;
        else
            this.largura = 0;

        if (altura >= 0)
            this.altura = altura;
        else
            this.altura = 0;
    }

    /**
     * Cria uma máscara de colisão retangular.
     * 
     * @param centro
     *            Posição central da máscara de colisão.
     * @param altura
     *            Altura da máscara de colisão.
     * @param largura
     *            Largura da máscara de colisão.
     */
    public MascaraDeColisao(Coordenada centro, int altura, int largura) {
        if (altura >= 0)
            this.altura = altura;
        else
            this.altura = 0;

        if (largura >= 0)
            this.largura = largura;
        else
            this.largura = 0;

        esquerda = centro.x - altura / 2;
        topo = centro.y - largura / 2;
    }

    /**
     * Decide se esta máscara de colisão está sobreposta a <b>alvo</b>.
     * 
     * @param alvo
     *            Máscara de colisão contra qual será testada sobreposição
     * @return <b>true</b> se ambas as máscaras estiverem sobrepostas,
     *         <b>false</b> caso contrário.
     */
    public boolean estaSobreposto(MascaraDeColisao alvo) {
        return ((esquerda <= alvo.esquerda && esquerda + largura >= alvo.esquerda)
                || (alvo.esquerda <= esquerda && alvo.esquerda + alvo.largura <= esquerda))
                && ((topo <= alvo.topo && topo + altura >= alvo.topo)
                || (alvo.topo <= topo && alvo.topo + alvo.altura <= topo));
    }

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para baixo. Se o valor
     * for negativo, a máscara estará movida para cima.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para baixo.
     * @return Uma nova máscara de colisão, movida.
     */
    public MascaraDeColisao moverAbaixo(int quantidade) {
        return new MascaraDeColisao(esquerda, topo + quantidade, largura,
                altura);
    }

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> para cima. Se o valor
     * for negativo, a máscara estará movida para baixo.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover para cima.
     * @return Uma nova máscara de colisão, movida.
     */
    public MascaraDeColisao moverAcima(int quantidade) {
        return new MascaraDeColisao(esquerda, topo - quantidade, largura,
                altura);
    }

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à direita. Se o valor
     * for negativo, a máscara estará movida à esquerda.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à direita.
     * @return Uma nova máscara de colisão, movida.
     */
    public MascaraDeColisao moverDireita(int quantidade) {
        return new MascaraDeColisao(esquerda + quantidade, topo, largura,
                altura);
    }

    /**
     * Retorna uma máscara de colisão <b>quantidade</b> à esquerda. Se o valor
     * for negativo, a máscara estará movida à direita.
     * 
     * @param quantidade
     *            O quanto a máscara deve se mover à esquerda.
     * @return Uma nova máscara de colisão, movida.
     */
    public MascaraDeColisao moverEsquerda(int quantidade) {
        return new MascaraDeColisao(esquerda - quantidade, topo, largura,
                altura);
    }

    /**
     * Cria uma coordenada que representa o centro da máscara de colisão.
     * Valores fracionários são truncados.
     * 
     * @return Um objeto Coordenada que representa o centro da máscara de
     *         colisão.
     */
    public Coordenada obterCentro() {
        return new Coordenada(esquerda + largura / 2, topo + altura / 2);
    }
}

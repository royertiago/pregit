/**Classe que representa a máscara de colisão da barra que o jogador controlará.
 * 
 * @author Tiago Royer
 */

package modelo.jogo;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.corposRigidos.TipoMascaraDeColisao;
import modelo.estruturasDeDados.Lista;
import modelo.estruturasDeDados.ListaLegivel;

public class Barra implements TipoMascaraDeColisao {

    protected double esquerda, topo, largura, altura;

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
    public Barra(double esquerda, double topo, double largura, double altura) {
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
    public Barra(Coordenada centro, double altura, double largura) {
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

    @Override
    public Coordenada obterCentro() {
        return new Coordenada(esquerda + largura / 2, topo + altura / 2);
    }

    @Override
    public boolean estaDentro(Coordenada p) {
        return (esquerda <= p.x && esquerda + largura >= p.x)
                && (topo <= p.y && topo + altura >= p.y);
    }

    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        Lista<Coordenada> lista = new Lista<Coordenada>();
        // Adicionar canto superior esquerdo
        lista.adicionarItem(new Coordenada(esquerda, topo));
        // Adicionar canto superior direito
        lista.adicionarItem(new Coordenada(esquerda + largura, topo));
        // Adicionar canto inferior esquerdo
        lista.adicionarItem(new Coordenada(esquerda, topo + altura));
        // Adicionar canto inforior direito
        lista.adicionarItem(new Coordenada(esquerda + largura, topo + altura));
        return lista;
    }

    @Override
    public double anguloColisao(Coordenada p) {
        if( p.y < topo+altura / 3)
            return Math.PI / 3;
        else if( p.y < topo + altura * 2 / 3)
            return Math.PI / 2;
        else
            return Math.PI * 2 / 3;
    }

    @Override
    public void mover(Vetor movimento) {
        esquerda = esquerda + movimento.x;
        topo = topo + movimento.y;
    }
}

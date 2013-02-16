package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.Lista;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * AABB: Axis Aligned Bounding Box - Caixa limitadora alinhada aos eixos. É uma
 * máscara de colisão retangular, que é usada para teste preliminar de colisão.
 * 
 * É assumido um sistema de coordenadas cartesianas espelhado horizontalmente em
 * relação ao sistema matemático tradicional.
 * 
 * @author Tiago Royer
 * 
 */
public class AABB {

    /**
     * Abscissa (eixo X) do canto superior esquerdo da caixa.
     */
    public final double x;

    /**
     * Oordenada (eixo Y) do canto superior esquerdo da caixa.
     */
    public final double y;

    public final double largura, altura;

    /**
     * Cria uma caixa delimitadora alinhada aos eixos.
     * 
     * Caso a altura e/ou a largura fornecida sejam negativos, a correspondente
     * dimensão será deslocada e a altura/largura atribuída em módulo. Por
     * exemplo, se o valor de <b>altura</b> for -3, y será deslocado três
     * unidades para cima e a altura será convertida em 3.
     * 
     * @param x
     *            Abscissa (exio X) do canto superior esquerdo da caixa.
     * @param y
     *            Ordenada (exio Y) do canto superior esquerdo da caixa.
     * @param largura
     *            Largura da caixa.
     * @param altura
     *            Altura da caixa.
     */
    public AABB(double x, double y, double largura, double altura) {
        if (largura < 0) {
            this.x = x + largura;
            this.largura = -largura;
        } else {
            this.x = x;
            this.largura = largura;
        }

        if (altura < 0) {
            this.y = y + altura;
            this.altura = -altura;
        } else {
            this.y = y;
            this.altura = altura;
        }
    }

    /**
     * Cria uma caixa delimitadora alinhada aos eixos.
     * 
     * A altura é considerada em módulo.
     * 
     * @param centro
     *            Posição central da caixa delimitadora.
     * @param largura
     *            Largura da caixa.
     * @param altura
     *            Altura da caixa.
     */
    public AABB(Coordenada centro, double altura, double largura) {
        this.altura = Math.abs(altura);
        this.largura = Math.abs(largura);

        this.x = centro.x - altura / 2;
        this.y = centro.y - largura / 2;
    }

    /**
     * Decide se esta caixa delimitadora está sobreposta a <b>alvo</b>.
     * 
     * @param alvo
     *            Caixa delimitadora contra qual será testada sobreposição
     * @return <b>true</b> se ambas as caixas estiverem sobrepostas,
     *         <b>false</b> caso contrário.
     */
    public boolean estaSobreposto(AABB alvo) {
        return ((x <= alvo.x && x + largura >= alvo.x) || (alvo.x <= x && alvo.x
                + alvo.largura <= x))
                && ((y <= alvo.y && y + altura >= alvo.y) || (alvo.y <= y && alvo.y
                        + alvo.altura <= y));
    }

    /**
     * Retorna uma caixa delimitadora deslocada conforme o vetor passado.
     * 
     * @param v
     *            O quanto a caixa deve se mover.
     * @return Este objeto.
     */
    public AABB mover(Vetor v) {
        return new AABB(x + v.x, y + v.x, largura, altura);
    }

    /**
     * Cria uma coordenada que representa o centro da caixa delimitadora.
     * 
     * @return Um objeto Coordenada que representa o centro da caixa
     *         delimitadora.
     */
    public Coordenada obterCentro() {
        return new Coordenada(x + largura / 2, y + altura / 2);
    }

    public ListaLegivel<Coordenada> obterExtremidades() {
        Lista<Coordenada> l = new Lista<Coordenada>();
        
        l.adicionarItem(new Coordenada(x, y));
        // Canto superior esquerdo
        
        l.adicionarItem(new Coordenada(x + largura, y));
        // Canto superior direito
        
        l.adicionarItem(new Coordenada(x + largura, y + altura));
        // Canto inferior direito
        
        l.adicionarItem(new Coordenada(x, y + altura));
        // Canto inferior esquerdo
        
        return l;
    }
    
    @Override
    public String toString()
    {
        return String.format("(%.3f;%.3f) + %.3f - %.3f", x, y, largura, altura);
    }
}

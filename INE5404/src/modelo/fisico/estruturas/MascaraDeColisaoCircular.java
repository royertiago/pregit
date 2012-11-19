/**
 * Representa uma máscara de colisão circular, com centro e raio.
 */

package modelo.fisico.estruturas;

import modelo.Coordenada;
import modelo.Lista;
import modelo.ListaLegivel;

public class MascaraDeColisaoCircular implements TipoMascaraDeColisao {

    public final Coordenada centro;
    public final int raio;
    private int precisao;

    public MascaraDeColisaoCircular(Coordenada centro, int raio) {
        this.centro = centro;
        if (raio > 0)
            this.raio = raio;
        else
            this.raio = 0;

        this.precisao = 8;
    }
    
    public MascaraDeColisaoCircular(Coordenada centro, int raio, int precisao) {
        this.centro = centro;
        if (raio > 0)
            this.raio = raio;
        else
            this.raio = 0;

        if( precisao > 1 )
            this.precisao = precisao;
        else
            this.precisao = 8;
    }

    /**
     * No método <i>obterPontosExtremidades</i>, pelo fato de a máscara
     * representar um círculo, o método deveria retornar um número muito grande
     * de pontos para ter uma precisão aceitável. Este método permite escolher a
     * quantidade de pontos que serão retornados por esse método. O valor padrão
     * é 8. Os pontos são distribuídos de forma (aproximadamente) uniforme ao
     * longo da circunferência.
     * 
     * @param p
     *            A quantidade de pontos que será retornada.
     */
    public void fixarPrecisao(int p) {
        if (p >= 1)
            precisao = p;
    }

    @Override
    public boolean estaDentro(Coordenada p) {
        return (centro.x - p.x) * (centro.x - p.x) + (centro.y - p.y)
                * (centro.y - p.y) <= raio * raio;
        // A fórmula antes do "<=" é o quadrado da distância entre o centro e o
        // ponto.
        // Se o quadrado da distância for menor ou igual ao quadrado do raio, o
        // ponto estará dentro dele.
    }

    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        Lista<Coordenada> lista = new Lista<Coordenada>();

        // Darei uma volta completa no círculo (2 * PI radianos), com <precisao>
        // passos.
        double incremento = Math.PI * 2 / precisao;

        // A coordenada inical é o ponto mais acima da circunferência. Ela será
        // girada
        // em torno do centro do círculo, gerando <precisao> pontos na
        // circunferência.
        Coordenada inicial = centro.moverAcima(raio);

        for (int i = 0; i < precisao; i++)
            lista.adicionarItem(inicial.girarEmTornoDe(centro, i * incremento));

        return lista;
    }

    @Override
    public Coordenada obterCentro() {
        return centro;
    }

    @Override
    public double anguloColisao(Coordenada p) {
        return centro.obterAnguloCom(p) + Math.PI / 2;
    }

    @Override
    public TipoMascaraDeColisao moverAcima(double quantidade) {
        return new MascaraDeColisaoCircular(centro.moverAcima(quantidade), raio);
    }

    @Override
    public TipoMascaraDeColisao moverAbaixo(double quantidade) {
        return new MascaraDeColisaoCircular(centro.moverAbaixo(quantidade), raio);
    }

    @Override
    public TipoMascaraDeColisao moverDireita(double quantidade) {
        return new MascaraDeColisaoCircular(centro.moverDireita(quantidade), raio);
    }

    @Override
    public TipoMascaraDeColisao moverEsquerda(double quantidade) {
        return new MascaraDeColisaoCircular(centro.moverEsquerda(quantidade), raio);
    }
    
    public String toString()
    {
        return "Centro: " + centro + " - Raio: " + raio;
    }
}

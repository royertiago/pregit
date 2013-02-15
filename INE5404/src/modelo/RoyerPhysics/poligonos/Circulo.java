package modelo.RoyerPhysics.poligonos;

import modelo.RoyerPhysics.AABB;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.PoligonoMovelAbstrato;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.estruturasDeDados.Lista;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * Aproximação poligonal de um círculo.
 * 
 * @author Tiago Royer
 *
 */
public class Circulo extends PoligonoMovelAbstrato {

    private Coordenada _centro;
    private double _raio;
    private int _precisao;
    
    /**
     * Cria um octógono regular, aproximando um círculo.
     * @param centro Centro do octógono
     * @param raio Raio do octógono.
     */
    public Circulo(Coordenada centro, double raio) {
        this._centro = centro;
        if (raio > 0)
            this._raio = raio;
        
        this._precisao = 8;
    }
    
    /**
     * Cria um n-ágono regular, de <b>precisao</b> lados, aproximando um círculo.
     * Quanto maior a precisão, mais próximo de um círculo será.
     * 
     * @param centro Centro do n-ágono.
     * @param raio Raio do n-ágono
     * @param precisao Precisão da aproximação (número de lados).
     */
    public Circulo(Coordenada centro, double raio, int precisao) {
        this._centro = centro;
        if (raio > 0)
            this._raio = raio;

        if( precisao > 1 )
            this._precisao = precisao;
        else
            this._precisao = 8;
    }
    
    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        Lista<Coordenada> lista = new Lista<Coordenada>();

        // Darei uma volta completa no círculo (2 * PI radianos), com <precisao>
        // passos.
        double incremento = Math.PI * 2 / _precisao;

        // A coordenada inical é o ponto mais acima da circunferência. Ela será
        // girada
        // em torno do centro do círculo, gerando <precisao> pontos na
        // circunferência.
        Coordenada inicial = _centro.moverAcima(_raio);

        for (int i = 0; i < _precisao; i++)
            lista.adicionarItem(inicial.girarEmTornoDe(_centro, i * incremento));

        return lista;
    }
    
    @Override
    public boolean contem(Coordenada c) {
            return (_centro.x - c.x) * (_centro.x - c.x) + (_centro.y - c.y)
                    * (_centro.y - c.y) <= _raio * _raio;
            // A fórmula antes do "<=" é o quadrado da distância entre o centro e o
            // ponto.
            // Se o quadrado da distância for menor ou igual ao quadrado do raio, o
            // ponto estará dentro dele.
    }
    
    @Override
    public double anguloColisao(Coordenada p) {
        return _centro.obterAnguloCom(p) + Math.PI / 2;
    }

    public String toString()
    {
        return "Centro: " + _centro + " - Raio: " + _raio;
    }
    
    @Override
    public void mover(Vetor movimento) {
        _centro = _centro.deslocar(movimento);
    }

    @Override
    public AABB obterAABB() {
        return new AABB(_centro, 2*_raio, 2*_raio);
    }

    @Override
    public Coordenada obterCentro() {
        return _centro;
    }

}

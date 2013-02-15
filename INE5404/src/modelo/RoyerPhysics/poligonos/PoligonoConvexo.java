package modelo.RoyerPhysics.poligonos;

import modelo.RoyerPhysics.AABB;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.PoligonoMovelAbstrato;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.estruturasDeDados.Lista;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * Representa um polígono convexo genérico.
 * 
 * @author Tiago Royer
 *
 */
public class PoligonoConvexo extends PoligonoMovelAbstrato {

    private Lista<Coordenada> _pontos;
    private Coordenada _centro;
    private AABB _aabb;
    
    /**
     * Cria um polígono convexo genérico, com os vértices dados. Será assumido
     * que existem pelo menos três vértices, que esses vértices são, de fato,
     * de um polígono convexo, e que os pontos estão em sentido horário, em relação
     * ao centro do polígono.
     * 
     * @param vertices Os vértices do polígono.
     */
    public PoligonoConvexo( Coordenada ...vertices)
    {
        double somaX = 0, somaY = 0, minX, minY, maxX, maxY;
        minX = maxX = vertices[0].x;
        minY = maxY = vertices[0].y; //Criar a AABB
        int total = 0;
        _pontos = new Lista<Coordenada>();
        for( Coordenada c: vertices)
        {
            _pontos.adicionarItem(c);
            somaX += c.x;
            somaY += c.y;
            total++;
            minX = Math.min(minX, c.x);
            maxX = Math.max(maxX, c.x);
            minY = Math.min(minY, c.y);
            maxY = Math.max(maxY, c.y);
        }
        
        _centro = new Coordenada( somaX/total, somaY/total);
        _aabb = new AABB(minX, minY, maxX - minX, maxY - minY);
    }
    
    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        return _pontos;
    }

    @Override
    public boolean contem(Coordenada c) {
        int n = _pontos.obterTamanho();
        for( int i = 0; i < n; i++)
        {
            Parede p = new Parede(_pontos.obter((i+1)%n), _pontos.obter(i));
            //Esta é uma das arestas do polígono.
            if (!p.contem(c))
                return false; //Se o ponto em questão está fora da parede, ele também está fora
                                // do polígono, então podemos retornar.
        }
        return true;
    }

    @Override
    public double anguloColisao(Coordenada c) {
        int n = _pontos.obterTamanho();
        for( int i = 0; i < n; i++)
        {
            PoligonoConvexo p = new PoligonoConvexo(_pontos.obter(i), _pontos.obter((i+1)%n), this._centro);
            //Testo todos os triângulos internos do polígono.
            if (p.contem(c))
                return new Parede(_pontos.obter(i), _pontos.obter((i+1)%n)).anguloColisao(c); 
        }
        
        return _centro.obterAnguloCom(c); //O ponto está fora do polígono.
    }

    @Override
    public void mover(Vetor v) {
        _centro = _centro.deslocar(v);
        for( int i = 0; i < _pontos.obterTamanho(); i++) {
            Coordenada c = _pontos.obter(i);
            c = c.deslocar(v);
            _pontos.gravar(i, c);
        }
        
        _aabb = _aabb.mover( v );
        
    }

    @Override
    public AABB obterAABB() {
        return _aabb;
    }

    @Override
    public Coordenada obterCentro() {
        return _centro;
    }
}

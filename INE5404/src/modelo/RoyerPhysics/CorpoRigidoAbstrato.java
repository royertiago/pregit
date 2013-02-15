package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;
import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;

/**
 * Implementação genérica de um corpo rígido. Deixa ao usuário a opção de
 * polígono e permite usar uma biblioteca de forças externa, e deixa
 * a implementação de movimento para as subclasses.
 * 
 * @author Tiago Royer
 * 
 */
public abstract class CorpoRigidoAbstrato implements CorpoRigidoMovel {

    /**
     * Polígono que é englobado pelo corpo rígido abstrato.
     */
    protected PoligonoMovelAbstrato poligono;
    
    private TipoConjuntoDeForcas _f;

    /**
     * Cria um corpo rígido com o polígono dado e com a biblioteca de forças
     * fornecida.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     * @param f
     *            Biblioteca de forças a ser usada pelo corpo rígido.
     */
    public CorpoRigidoAbstrato(PoligonoMovelAbstrato p, TipoConjuntoDeForcas f) {
        poligono = p;
        _f = f;
    }

    /**
     * Cria um corpo rígido com o polígono dado e com uma biblioteca de forças
     * padrão.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     */
    public CorpoRigidoAbstrato(PoligonoMovelAbstrato p) {
        poligono = p;
        _f = new ConjuntoDeForcas();
    }

    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        return poligono.obterPontosExtremidades();
    }

    @Override
    public boolean contem(Coordenada c) {
        return poligono.contem(c);
    }

    @Override
    public double anguloColisao(Coordenada c) {
        return poligono.anguloColisao(c);
    }

    @Override
    public Coordenada obterIntersecao(TipoPoligonoConvexo p) {
        return poligono.obterIntersecao(p);
    }

    @Override
    public AABB obterAABB() {
        return poligono.obterAABB();
    }

    @Override
    public TipoEditor<Vetor> obterForca(String nome) {
        return _f.obterForca(nome);
    }

    @Override
    public Vetor obterSomatorioForcas() {
        return _f.obterSomatorioForcas();
    }

    @Override
    public abstract Vetor obterVetorMovimento();

    @Override
    public abstract void mover(double c);

    @Override
    public abstract void fixarVetorMovimento(Vetor v);

    @Override
    public Coordenada obterCentro() {
        return poligono.obterCentro();
    }
}

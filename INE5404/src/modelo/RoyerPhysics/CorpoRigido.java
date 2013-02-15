package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;
import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;

/**
 * Implementação genérica de um corpo rígido. Deixa ao usuário a opção de
 * polígono e permite usar uma biblioteca de forças externa.
 * 
 * @author Tiago Royer
 * 
 */
public class CorpoRigido implements CorpoRigidoMovel {

    private PoligonoMovelAbstrato _p;
    private TipoConjuntoDeForcas _f;
    private Vetor _movimento = Vetor.vetorNulo;

    /**
     * Cria um corpo rígido com o polígono dado e com a biblioteca de forças
     * fornecida.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     * @param f
     *            Biblioteca de forças a ser usada pelo corpo rígido.
     */
    public CorpoRigido(PoligonoMovelAbstrato p, TipoConjuntoDeForcas f) {
        _p = p;
        _f = f;
    }

    /**
     * Cria um corpo rígido com o polígono dado e com uma biblioteca de forças
     * padrão.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     */
    public CorpoRigido(PoligonoMovelAbstrato p) {
        _p = p;
        _f = new ConjuntoDeForcas();
    }

    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        return _p.obterPontosExtremidades();
    }

    @Override
    public boolean contem(Coordenada c) {
        return _p.contem(c);
    }

    @Override
    public double anguloColisao(Coordenada c) {
        return _p.anguloColisao(c);
    }

    @Override
    public Coordenada obterIntersecao(TipoPoligonoConvexo p) {
        return _p.obterIntersecao(p);
    }

    @Override
    public AABB obterAABB() {
        return _p.obterAABB();
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
    public Vetor obterVetorMovimento() {
        return _movimento;
    }

    @Override
    public void mover(double c) {
        _p.mover(_movimento.escalar(c));
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        _movimento = v;
    }

    @Override
    public Coordenada obterCentro() {
        return _p.obterCentro();
    }

}

package modelo.RoyerPhysics.observacaoDeCorpos;

import modelo.RoyerPhysics.AABB;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoPoligonoConvexo;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;
import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;

/**
 * Corpo rígido que pode ser observado por ObservadorDeCorpos. Redireciona
 * chamadas para outro CorpoRigidoMovel (semelhante ao padrão decorador)
 * e informa observadores em caso de movimento.
 *  
 * @author Tiago Royer
 *
 */
public class CorpoObservado implements CorpoRigidoMovel, CorpoObservavel {
    private CorpoRigidoMovel _corpo;
    private Megafone _megafone;
    
    /**
     * Cria um CorpoObservado, que irá redirecionar chamadas para o CorpoRigidoMovel
     * dado (semelhante ao padrão decorador).
     * @param corpo Corpo Rígido que controlará as ações deste corpo.
     */
    public CorpoObservado( CorpoRigidoMovel corpo )
    {
        _corpo = corpo;
        _megafone = new Megafone();
    }
    
    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        return _corpo.obterPontosExtremidades();
    }

    @Override
    public AABB obterAABB() {
        return _corpo.obterAABB();
    }

    @Override
    public boolean contem(Coordenada c) {
        return _corpo.contem(c);
    }

    @Override
    public double anguloColisao(Coordenada c) {
        return _corpo.anguloColisao(c);
    }

    @Override
    public Coordenada obterIntersecao(TipoPoligonoConvexo p) {
        return _corpo.obterIntersecao(p);
    }

    @Override
    public TipoEditor<Vetor> obterForca(String nome) {
        return _corpo.obterForca(nome);
    }

    @Override
    public Vetor obterSomatorioForcas() {
        return _corpo.obterSomatorioForcas();
    }

    @Override
    public void adicionarObservador(ObservadorDeCorpos o) {
        _megafone.adicionarOuvinte(o);
    }

    @Override
    public void removerObservador(ObservadorDeCorpos o) {
        _megafone.removerOuvinte(o);
    }

    @Override
    public Vetor obterVetorMovimento() {
        return _corpo.obterVetorMovimento();
    }

    @Override
    public void mover(double c) {
        _corpo.mover(c);
        _megafone.gritar(_corpo.obterCentro());
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        _corpo.fixarVetorMovimento(v);
    }

    @Override
    public Coordenada obterCentro() {
        return _corpo.obterCentro();
    }

    @Override
    public String toString()
    {
        return "Observando: " + _corpo;
    }
}

package modelo.RoyerPhysics.corposRigidos;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoObservavel;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.ObservadorDeCorpos;
import modelo.RoyerPhysics.Vetor;
import modelo.estruturasDeDados.Lista;
import modelo.estruturasDeDados.ListaLegivel;

/**
 * Classe que provê uma implementação padrão para os corpos rígidos.
 * 
 * @author Tiago Royer
 * 
 */
public class CorpoRigidoPadrao implements CorpoObservavel, CorpoRigidoMovel {

    private Lista<ObservadorDeCorpos> observadores = new Lista<ObservadorDeCorpos>();
    protected TipoMascaraDeColisao m;
    protected Vetor v;
    protected double massa;

    public CorpoRigidoPadrao(TipoMascaraDeColisao m, Vetor v, double massa) {
        this.m = m;
        this.v = v;
        this.massa = massa;
    }

    @Override
    public boolean estaDentro(Coordenada c) {
        return m.estaDentro(c);
    }

    @Override
    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        return m.obterPontosExtremidades();
    }

    @Override
    public double anguloColisao(Coordenada p) {
        return m.anguloColisao(p);
    }

    @Override
    public void mover() {
        m.mover(v);
        this.avisarObservadores();
    }

    @Override
    public Vetor obterVetorMovimento() {
        return v;
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        this.v = v;
    }

    @Override
    public void espelharVetorMovimento(double angulo) {
        v = v.espelharSeSobre(angulo);
    }

    @Override
    public double obterMassa() {
        return massa;
    }

    @Override
    public void adicionarObservador(ObservadorDeCorpos o) {
        observadores.adicionarItem(o);
    }

    @Override
    public void removerObservador(ObservadorDeCorpos o) {
        observadores.removerItem(o);
    }
    
    protected final void avisarObservadores()
    {
        for(ObservadorDeCorpos observador: observadores)
            observador.notificar(m.obterCentro());
    }

}

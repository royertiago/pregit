package modelo.RoyerPhysics.corposRigidos;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoObservavel;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.ObservadorDeCorpos;
import modelo.RoyerPhysics.Vetor;
import static modelo.RoyerPhysics.Vetor.vetorNulo;
import modelo.estruturasDeDados.Editor;
import modelo.estruturasDeDados.Lista;
import modelo.estruturasDeDados.ListaComEditor;
import modelo.estruturasDeDados.ListaLegivel;
import modelo.estruturasDeDados.Par;
import modelo.estruturasDeDados.TipoEditor;

/**
 * Classe que provê uma implementação padrão para os corpos rígidos.
 * 
 * @author Tiago Royer
 * 
 */
public class CorpoRigidoPadrao implements CorpoObservavel, CorpoRigidoMovel {

    private Lista<ObservadorDeCorpos> observadores = new Lista<ObservadorDeCorpos>();
    protected TipoMascaraDeColisao m;
    protected Vetor movimento;
    protected double massa;
    protected ListaComEditor<Vetor> forcas = new ListaComEditor<Vetor>();

    public CorpoRigidoPadrao(TipoMascaraDeColisao m, Vetor v, double massa) {
        this.m = m;
        this.movimento = v;
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
        m.mover(movimento);
        avisarObservadores();
    }

    @Override
    public void mover(double c) {
        m.mover(movimento.escalar(c));
        avisarObservadores();
    }

    @Override
    public Vetor obterVetorMovimento() {
        return movimento;
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        movimento = v;
    }

    @Override
    public void espelharVetorMovimento(double angulo) {
        movimento = movimento.espelharSeSobre(angulo);
    }

    @Override
    public double obterMassa() {
        return massa;
    }

    @Override
    public void adicionarObservador(ObservadorDeCorpos o) {
        observadores.adicionarItem(o);
        o.notificar(m.obterCentro());
    }

    @Override
    public void removerObservador(ObservadorDeCorpos o) {
        observadores.removerItem(o);
    }

    protected final void avisarObservadores() {
        for (ObservadorDeCorpos observador : observadores)
            observador.notificar(m.obterCentro());
    }

    @Override
    public TipoEditor<Vetor> obterForca(String nome) {
        Editor<Vetor> editor = forcas.obterEditor(nome);
        if (editor != null)
            return editor;

        // Só retorna null caso esse nome não exista. Senão, dá para

        Par<String, Vetor> par = new Par<String, Vetor>(nome, vetorNulo);
        forcas.inserirPar(par);
        return new Editor<Vetor>(par);
    }

    @Override
    public Vetor obterSomatorioForcas() {
        Vetor soma = vetorNulo;
        int teste = 0;
        for (Vetor v : forcas) {
            System.out.println(teste++);
            soma = soma.somarCom(v);
        }

        return soma;
    }

}

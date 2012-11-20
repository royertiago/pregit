package modelo.fisico;

import java.util.HashSet;
import java.util.Set;

import modelo.fisico.estruturas.TipoMascaraDeColisao;

public abstract class ObservadoFisicoAbstrato implements ObservadoFisico {

    private Set<ObservadorFisico> observadores = new HashSet<ObservadorFisico>();

    @Override
    public abstract TipoMascaraDeColisao obterMascara();

    @Override
    public final void registrarObservador(ObservadorFisico o) {
        observadores.add(o);
    }

    @Override
    public final void removerObservador(ObservadorFisico o) {
        observadores.remove(o);
    }

    /**
     * Notifica todos os observadores que estão registrados neste
     * ObservadoFisico.
     */
    protected final void notificarObservadores() {
        for (ObservadorFisico o : observadores)
            o.notificar(this);
    }

}

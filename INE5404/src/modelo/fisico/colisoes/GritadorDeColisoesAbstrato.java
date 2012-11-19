package modelo.fisico.colisoes;

import java.util.HashSet;
import java.util.Set;

public abstract class GritadorDeColisoesAbstrato implements GritadorDeColisoes {

    private Set<EscutadorDeColisoes> escutadores = new HashSet<EscutadorDeColisoes>();
    
    @Override
    public final void adicionarEscutador(EscutadorDeColisoes e) {
        escutadores.add(e);
    }

    @Override
    public final void removerEscutador(EscutadorDeColisoes e) {
        escutadores.remove(e);
    }
    
    /**
     * Envia o evento de colisão <b>c</b> para todos os escutadores.    
     * @param c Evento de colisão a ser enviado.
     */
    protected final void gritar(Colisao c) {
        for( EscutadorDeColisoes o: escutadores)
            o.escutar(c);
    }

    
}

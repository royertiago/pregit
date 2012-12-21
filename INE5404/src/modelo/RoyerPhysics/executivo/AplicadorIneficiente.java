package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.LeiSensivelAoTempo;
import modelo.RoyerPhysics.legislativo.TipoLei;
import modelo.RoyerPhysics.legislativo.TipoLeiEstruturas;
import modelo.estruturasDeDados.Lista;

/**
 * Classe ineficiente que aplica leis de um ou dois parâmetros aos corpos
 * rígidos passados.
 * 
 * @author Tiago Royer
 * 
 */
public class AplicadorIneficiente implements TipoAplicadorDeLeis {

    /**
     * Lista de corpos rígidos móveis.
     */
    protected Lista<CorpoRigidoMovel> corposMoveis = new Lista<CorpoRigidoMovel>();

    /**
     * Lista de corpos rígidos não-móveis.
     */
    protected Lista<TipoCorpoRigido> paredes = new Lista<TipoCorpoRigido>();

    /**
     * Legislação (lista de leis).
     */
    protected Lista<TipoLei> legislacao = new Lista<TipoLei>();

    /**
     * Lista das leis que são afetadas pelo tempo.
     */
    protected Lista<LeiSensivelAoTempo> cronos = new Lista<LeiSensivelAoTempo>();

    /**
     * Tempo a ser passado às leis sensíveis ao tempo.
     */
    protected double tempo;
    
    /**
     * Gera um aplicador de leis.
     * 
     * @param tempo Tempo a ser passado para as leis.
     */
    public AplicadorIneficiente( double tempo )
    {
        this.tempo = tempo;
    }
    
    @Override
    public void adicionarCorpoRigido(CorpoRigidoMovel c) {
        corposMoveis.adicionarItem(c);
    }

    @Override
    public void adicionarCorpoRigido(TipoCorpoRigido c) {
        paredes.adicionarItem(c);
    }

    @Override
    public void removerCorpoRigido(CorpoRigidoMovel c) {
        corposMoveis.removerItem(c);
    }

    @Override
    public void removerCorpoRigido(TipoCorpoRigido c) {
        paredes.removerItem(c);
    }

    @Override
    public void adicionarLei(TipoLei l) {
        legislacao.adicionarItem(l);
        if( l instanceof LeiSensivelAoTempo ) {
            cronos.adicionarItem((LeiSensivelAoTempo) l);
            ((LeiSensivelAoTempo) l).informarTempo(tempo);
        }
    }

    @Override
    public void removerLei(TipoLei l) {
        legislacao.removerItem(l);
    }

    @Override
    public void aplicarLeis() {
        for( TipoLei l: legislacao )
        {
            l.aplicarLei(corposMoveis);
            
            if( l instanceof TipoLeiEstruturas )
                ((TipoLeiEstruturas)l).aplicarLei(corposMoveis, paredes);
        }
    }

    @Override
    public void alterarTempo(double t) {
        for( LeiSensivelAoTempo l: cronos)
            l.informarTempo(t);
    }

}

package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;

/**
 * Lei que atualiza o vetor de movimento de um corpo móvel de acordo com as
 * forças aplicadas ao objeto.
 * 
 * @author Tiago Royer
 * 
 */
public class LeiDeForcas extends LeiUnaria implements LeiSensivelAoTempo {

    private double _tempo;

    /**
     * Cria uma lei de forças.
     * 
     * @param tempo
     *            Tempo que se passa ao atualizar as forças.
     */
    public LeiDeForcas(double tempo) {
        _tempo = tempo;
    }

    @Override
    protected void aplicarLeiA(CorpoRigidoMovel c) {
        Vetor forca = c.obterSomatorioForcas();
        Vetor movimento = c.obterVetorMovimento().somarCom(forca.escalar(_tempo));
        c.fixarVetorMovimento(movimento);

    }

    @Override
    public void informarTempo(double tempo) {
        _tempo = tempo;
    }

}

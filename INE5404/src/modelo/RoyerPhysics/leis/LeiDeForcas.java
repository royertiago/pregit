package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;

/**
 * Lei que atualiza o vetor de movimento de um corpo móvel de acordo com as
 * forças aplicadas ao objeto.
 * 
 * @author Tiago Royer
 * 
 */
public class LeiDeForcas extends LeiUnaria {

    @Override
    public void aplicarA(CorpoRigidoMovel cr) {
        double tempo = super.obterClockDoCampo().obterTempo();
        Vetor forca = cr.obterSomatorioForcas();
        Vetor movimento = cr.obterVetorMovimento().somarCom(forca.escalar(tempo));
        cr.fixarVetorMovimento(movimento);
    }

}

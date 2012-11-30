package modelo.RoyerPhysics.corposRigidos;

import modelo.RoyerPhysics.Vetor;

public class CorpoRigidoImovel extends CorpoRigidoPadrao {

    public CorpoRigidoImovel(TipoMascaraDeColisao m) {
        super(m, Vetor.semMovimento, -1);
    }
    
    @Override
    public void mover() {
        //Não nos moveremos.
    }
    
    @Override
    public void fixarVetorMovimento(Vetor v) {
        //Não aceitaremos outro vetor de movimento.
    }
    
    public void espelharVetorMovimento(double angulo) {
        //Não alteraremos o vetor de movimento.
    }

    
    

}

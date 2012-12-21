package modelo.jogo;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.corposRigidos.CorpoRigidoPadrao;

public class RaqueteDoPong extends CorpoRigidoPadrao {

    public RaqueteDoPong(Vetor v, double massa, Coordenada centro, double altura,
            double largura) {
        super(new Barra(centro, altura, largura), v, massa);
    }
    
    @Override
    public void espelharVetorMovimento(double angulo)
    {
        // Vamos nos mover somente sobre a reta vertical sobre a qual iniciamos.
        movimento = new Vetor(0, movimento.espelharSeSobre(angulo).y);
    }
    
    @Override
    public void fixarVetorMovimento( Vetor v )
    {
        this.movimento = new Vetor(0, v.y);
    }
    
    

}

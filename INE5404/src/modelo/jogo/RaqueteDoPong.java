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
        v = new Vetor(0, v.espelharSeSobre(angulo).y);
    }
    
    @Override
    public void fixarVetorMovimento( Vetor v )
    {
        this.v = new Vetor(0, v.y);
        System.out.println("Mudando para: " + v); //TODO: remover
    }
    
    

}

package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.Vetor;

/**
 * Testa colisão entre dois objetos; desconsidera momento linear.
 * @author Tiago Royer
 *
 */
public class ColisaoSemMomento extends LeiBinaria {

    @Override
    public void aplicar(PoligonoEstrutural p, CorpoRigidoMovel cr, double tempo) {
        if (!p.contem(cr.obterAABB())) // Se o teste preliminar deu negativo,
                                       // sair.
            return;

        Coordenada c = p.obterIntersecao(cr);
        if (c == null) // Se não há interseção
            return;

        Vetor m = cr.obterVetorMovimento();
        m = m.espelharSeSobre(cr.anguloColisao(c));
        cr.fixarVetorMovimento(m);
        
        System.out.println( "Colisão contra a parede: " + cr + " - ângulo: " + p.anguloColisao(c) ); //TODO: remover
    }

    @Override
    public void aplicar(CorpoRigidoMovel cr1, CorpoRigidoMovel cr2, double tempo) {
        if (!cr1.obterAABB().estaSobreposto(cr2.obterAABB()))
            return;

        Coordenada c = cr1.obterIntersecao(cr2);
        if (c == null)
            return;

        Vetor v = cr1.obterVetorMovimento();
        v = v.espelharSeSobre(cr1.anguloColisao(c));
        cr1.fixarVetorMovimento(v);

        v = cr2.obterVetorMovimento();
        v = v.espelharSeSobre(cr2.anguloColisao(c));
        cr2.fixarVetorMovimento(v);
    }

}

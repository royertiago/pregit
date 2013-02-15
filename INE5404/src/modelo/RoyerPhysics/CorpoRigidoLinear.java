package modelo.RoyerPhysics;

import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.PoligonoMovelAbstrato;
import modelo.RoyerPhysics.TipoConjuntoDeForcas;
import static modelo.RoyerPhysics.Vetor.vetorNulo;
/**
 * Corpo rígido que se movimenta apenas paralelamente a um vetor dado.
 * @author Tiago Royer
 *
 */
public class CorpoRigidoLinear extends CorpoRigidoAbstrato {

    private Vetor _movimento, _angulo;
    
    /**
     * Cria um corpo rígido que se moverá paralelamente a <b>angulo</b>.
     * @param p Polígono a ser usado pelo corpo.
     * @param f Biblioteca de forças a ser usada.
     * @param angulo Ângulo do movimento do corpo.
     */
    public CorpoRigidoLinear(PoligonoMovelAbstrato p, TipoConjuntoDeForcas f, Vetor angulo)
    {
        super(p, f);
        _movimento = vetorNulo;
        _angulo = angulo;
    }
    
    /**
     * Cria um corpo rígido que se moverá paralelamente a <b>angulo</b>.
     * Será usada uma biblioteca de forças padrão.
     * @param p Polígono a ser usado.
     * @param angulo Ângulo do movimento do corpo.
     */
    public CorpoRigidoLinear(PoligonoMovelAbstrato p, Vetor angulo) {
        super(p);
        _movimento = vetorNulo;
        _angulo = angulo;
    }
 
    @Override
    public Vetor obterVetorMovimento() {
        return _movimento;
    }

    @Override
    public void mover(double c) {
        poligono.mover(_movimento.projetarSe(_angulo));
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        _movimento = v;
    }
    
    @Override
    public String toString() {
        return "CorpoRigido - Poligono:\n" + poligono + "\nMovimento: "
                + _movimento + " - Orientação: " + _angulo;
    }

}

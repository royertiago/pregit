package modelo.RoyerPhysics;

import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.PoligonoMovelAbstrato;
import modelo.RoyerPhysics.TipoConjuntoDeForcas;

/**
 * Implementação genérica de um corpo rígido. Deixa ao usuário a opção de
 * polígono e permite usar uma biblioteca de forças externa.
 * 
 * @author Tiago Royer
 * 
 */
public class CorpoRigido extends CorpoRigidoAbstrato {

    private Vetor _movimento = Vetor.vetorNulo;

    /**
     * Cria um corpo rígido com o polígono dado e com a biblioteca de forças
     * fornecida.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     * @param f
     *            Biblioteca de forças a ser usada pelo corpo rígido.
     */
    public CorpoRigido(PoligonoMovelAbstrato p, TipoConjuntoDeForcas f) {
        super(p, f);
    }

    /**
     * Cria um corpo rígido com o polígono dado e com uma biblioteca de forças
     * padrão.
     * 
     * @param p
     *            Polígono a ser usado pelo corpo rígido.
     */
    public CorpoRigido(PoligonoMovelAbstrato p) {
        super(p);
    }

    @Override
    public Vetor obterVetorMovimento() {
        return _movimento;
    }

    @Override
    public void mover(double c) {
        poligono.mover(_movimento.escalar(c));
    }

    @Override
    public void fixarVetorMovimento(Vetor v) {
        _movimento = v;
    }

    @Override
    public String toString() {
        return "CorpoRigido - Poligono:\n" + poligono + "\nMovimento: "
                + _movimento;
    }

}

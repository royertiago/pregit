package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * É uma lei que vai atualizar as posições dos corpos, de acordo com o tempo
 * passado.
 * 
 * @author Tiago Royer
 * 
 */
public class Movimento extends LeiUnaria {

    @Override
    public void aplicar(CorpoRigidoMovel cr, double tempo) {
        cr.mover(tempo);
    }

}

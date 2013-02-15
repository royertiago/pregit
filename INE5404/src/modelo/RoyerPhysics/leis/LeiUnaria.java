package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * Classe abstrata que reduz o problema de aplicar a lei em uma lista de objetos
 * para a aplicação da lei em um objeto por vez.
 * 
 * Para cada CorpoRigido de Campo.corposRigidos, é chamado, uma vez, o método
 * aplicar(CorpoRigidoMovel).
 * 
 * @author Tiago Royer
 * 
 */

public abstract class LeiUnaria implements TipoLei {

    @Override
    public void aplicar(Campo c, double tempo) {
        for (CorpoRigidoMovel cr : c.corposRigidos)
            this.aplicar(cr, tempo);

    }

    public abstract void aplicar(CorpoRigidoMovel cr, double tempo);

}

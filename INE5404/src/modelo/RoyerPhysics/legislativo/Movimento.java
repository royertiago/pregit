package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;

public class Movimento implements TipoLeiMoveisUnaria {
    
    public Movimento() {}

    @Override
    public void aplicarLei(CorpoRigidoMovel c) {
        c.mover();
    }

}

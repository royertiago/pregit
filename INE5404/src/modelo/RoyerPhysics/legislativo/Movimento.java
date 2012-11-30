package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.TipoCorpoRigido;

public class Movimento implements TipoLei {
    
    public Movimento() {}
    
    @Override
    public void aplicarLei(TipoCorpoRigido... o) {
        if (o.length != 1)
            throw new IllegalArgumentException(
                    "Deve haver um e somente um corpo rígido como argumento.");
        else
            o[0].mover();
    }

    @Override
    public int obterNumeroParametros() {
        return 1;
    }

}

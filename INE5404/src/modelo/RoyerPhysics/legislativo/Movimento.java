package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.estruturasDeDados.Tupla;

public class Movimento implements TipoLei {
    
    public Movimento() {}
    
    @Override
    public void aplicarLei(Tupla<TipoCorpoRigido> o) {
        if (o.tamanho() != 1)
            throw new IllegalArgumentException(
                    "Deve haver um e somente um corpo rígido como argumento.");
        else
            o.obter(0).mover();
    }

    @Override
    public int obterNumeroParametros() {
        return 1;
    }

}

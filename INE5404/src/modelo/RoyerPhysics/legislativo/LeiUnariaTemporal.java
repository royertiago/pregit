package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * Rerpesenta uma lei que é afetada pelo tempo.
 * 
 * @author Tiago Royer
 *
 */
public abstract class LeiUnariaTemporal extends LeiUnaria implements LeiSensivelAoTempo{

    protected double _tempo = 1;
    
    //TODO: documentar
    public LeiUnariaTemporal(double tempo) {
        _tempo = tempo;
    }

    @Override
    public void informarTempo(double tempo) {
        _tempo = tempo;
    }
    
    protected abstract void aplicarLeiA(CorpoRigidoMovel c);

}
package modelo.RoyerPhysics.corposRigidos;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.TipoCorpoRigido;

public class CorpoRigidoImovel implements TipoCorpoRigido {

    protected TipoMascaraDeColisao m;

    public CorpoRigidoImovel(TipoMascaraDeColisao m) {
        this.m = m;
    }

    @Override
    public boolean estaDentro(Coordenada c) {
        return m.estaDentro(c);
    }

    @Override
    public double anguloColisao(Coordenada p) {
        return m.anguloColisao(p);
    }

}

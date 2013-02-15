package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * Provê uma implementação genérica da busca por interseções.
 * 
 * @author Tiago Royer
 * 
 */
public abstract class PoligonoMovelAbstrato implements TipoPoligonoConvexo {

    @Override
    public Coordenada obterIntersecao(TipoPoligonoConvexo p) {

        ListaLegivel<Coordenada> l = this.obterPontosExtremidades();
        for (Coordenada c : l)
            if (p.contem(c))
                return c;

        l = p.obterPontosExtremidades();
        for (Coordenada c : l)
            if (this.contem(c))
                return c;

        return null;
    }

    @Override
    public abstract ListaLegivel<Coordenada> obterPontosExtremidades();

    @Override
    public abstract boolean contem(Coordenada c);

    @Override
    public abstract double anguloColisao(Coordenada c);
    
    /**
     * Move o polígono convexo, de acordo com o vetor <b>v</b>.
     * O vetor nulo indicaria "sem movimento".
     * 
     * @param v O quanto o polígono convexo deve se mover.
     */
    public abstract void mover(Vetor v);
}

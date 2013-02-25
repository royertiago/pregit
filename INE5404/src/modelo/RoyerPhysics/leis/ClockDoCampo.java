package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * É um contêiner de dados, armazenando uma lista de estruturas e uma lista de
 * corpos rígidos.
 * 
 * @author Tiago Royer
 * 
 */
public class ClockDoCampo implements TipoClockDoCampo {

    public final ListaLegivel<CorpoRigidoMovel> corposRigidos;
    public final ListaLegivel<PoligonoEstrutural> estruturas;
    public final double tempo;

    public ClockDoCampo(ListaLegivel<CorpoRigidoMovel> corposRigidos,
            ListaLegivel<PoligonoEstrutural> estruturas, double tempo) {
        this.corposRigidos = corposRigidos;
        this.estruturas = estruturas;
        this.tempo = tempo;
    }

    @Override
    public ListaLegivel<PoligonoEstrutural> obterEstruturas() {
        return estruturas;
    }

    @Override
    public ListaLegivel<CorpoRigidoMovel> obterCorpos() {
        return corposRigidos;
    }

    @Override
    public double obterTempo() {
        return tempo;
    }
}

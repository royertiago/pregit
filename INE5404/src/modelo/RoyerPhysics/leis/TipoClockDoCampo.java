package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * É um contêiner de dados; possui em si todas as informações a respeito de um
 * avanço de tempo do sistema de leis. Por exemplo, o tempo do avanço e os
 * corpos rígidos do campo.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoClockDoCampo {

    /**
     * Obtém as estruturas do campo.
     * 
     * @return Uma lista de estruturas.
     */
    public abstract ListaLegivel<PoligonoEstrutural> obterEstruturas();

    /**
     * Obtém os corpos rígidos do campo.
     * 
     * @return Uma lista de corpos lígidos.
     */
    public abstract ListaLegivel<CorpoRigidoMovel> obterCorpos();

    /**
     * Obtém o tempo ("período de clock") em que o sistema deve ser avançado.
     * 
     * @return O avanço do sistema, em segundos.
     */
    public abstract double obterTempo();

}

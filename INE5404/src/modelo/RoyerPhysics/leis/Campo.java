package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * É um contêiner de dados, armazenando uma lista de estruturas
 * e uma lista de corpos rígidos.
 * 
 * @author Tiago Royer
 *
 */
public class Campo {

    public final ListaLegivel<CorpoRigidoMovel> corposRigidos;
    public final ListaLegivel<PoligonoEstrutural> estruturas;
    
    public Campo (ListaLegivel<CorpoRigidoMovel> corposRigidos,
    ListaLegivel<PoligonoEstrutural> estruturas)
    {
        this.corposRigidos = corposRigidos;
        this.estruturas = estruturas;
    }
}

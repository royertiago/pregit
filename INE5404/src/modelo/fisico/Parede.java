/**
 * Representa uma parede.
 */

package modelo.fisico;

import modelo.fisico.estruturas.TipoMascaraDeColisao;
import modelo.fisico.estruturas.mascarasDeColisao.ParedeAbstrata;

public class Parede extends ObservadoFisicoAbstrato {

    TipoMascaraDeColisao mascara;

    /**
     * Máscara de colisão que representa uma parede.
     * 
     * @param mascara
     *            Máscara de colisão da parede.
     */
    public Parede(ParedeAbstrata mascara) {
        this.mascara = mascara;
    }

    @Override
    public TipoMascaraDeColisao obterMascara() {
        return mascara;
    }

    @Override
    public String toString()
    {
        return mascara.toString();
    }
}

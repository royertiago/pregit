/**
 * Representa uma bola.
 * O estado da bola é a sua máscara de colisão.
 */

package modelo.fisico;

import modelo.Atualizavel;
import modelo.fisico.estruturas.TipoMascaraDeColisao;
import modelo.fisico.estruturas.TipoVetorMovimento;

public class Bola extends ObservadoFisicoAbstrato implements Atualizavel {

    private TipoMascaraDeColisao mascara;
    private TipoVetorMovimento movimento;

    public Bola( TipoMascaraDeColisao mascara, TipoVetorMovimento movimento)
    {
        this.mascara = mascara;
        this.movimento = movimento;
    }
    
    @Override
    public void atualizar() {
        mascara = movimento.moverMascara(mascara);
        
        this.notificarObservadores();
    }
    
    @Override
    public TipoMascaraDeColisao obterMascara() {
        return mascara;
    }

}

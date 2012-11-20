/**
 * Representa uma bola.
 * O estado da bola é a sua máscara de colisão.
 */

package modelo.fisico;

import modelo.Atualizavel;
import modelo.fisico.colisoes.Colisao;
import modelo.fisico.colisoes.EscutadorDeColisoes;
import modelo.fisico.estruturas.TipoMascaraDeColisao;
import modelo.fisico.estruturas.TipoMascaraDeColisaoMovel;
import modelo.fisico.estruturas.TipoVetorMovimento;
import modelo.fisico.estruturas.mascarasDeColisao.Circular;

public class Bola extends ObservadoFisicoAbstrato implements Atualizavel,
        EscutadorDeColisoes {

    private TipoMascaraDeColisaoMovel mascara;
    private TipoVetorMovimento movimento;

    public Bola(Circular mascara, TipoVetorMovimento movimento) {
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

    @Override
    public void escutar(Colisao c) {
        System.out.println("Escutei colisao ângulo " + c.angulo); //TODO: remover
        if (itsMe(c)) // Mario!!
        {
            movimento = movimento.colidirSeCom(c.angulo);
            System.out.println("Meu vetor de movimento agora é: " + movimento); //TODO: remover
        }
    }

    private boolean itsMe(Colisao c) {
        return c.colisor1 == this || c.colisor2 == this;
    }

}

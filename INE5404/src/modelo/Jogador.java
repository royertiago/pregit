package modelo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;

public class Jogador implements Atualizavel {

    private TipoEntradasJogador input;
    private CorpoRigidoMovel raquete;
    private double forca;

    /**
     * Cria um jogador.
     * 
     * Cada jogador tem uma entrada (um TipoEntradasJogador que vai lhe informar
     * quais comandos estão sendo enviados), uma raquete (que ele moverá para
     * cima e para baixo) e uma força (neste caso, a aceleração por
     * atualização).
     * 
     * @param input
     *            Entrada de dados.
     * @param raquete
     *            Barra do jogador.
     * @param forca
     *            Força imprimida por rodada.
     */
    public Jogador(TipoEntradasJogador input, CorpoRigidoMovel raquete,
            double forca) {
        this.input = input;
        this.raquete = raquete;
        this.forca = forca;
    }

    @Override
    public void atualizar() {

        if (input.comandoSubir()) {
            Vetor v = raquete.obterVetorMovimento();
            v = v.somarCom(new Vetor(0, -forca));
            raquete.fixarVetorMovimento(v);
        }

        if (input.comandoDescer()) {
            Vetor v = raquete.obterVetorMovimento();
            v = v.somarCom(new Vetor(0, +forca));
            raquete.fixarVetorMovimento(v);
        }
    }

}

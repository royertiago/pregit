package modelo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import static modelo.RoyerPhysics.Vetor.vetorNulo;
import modelo.estruturasDeDados.TipoEditor;

/**
 * Classe (gambiarrizada) que movimenta a barra do jogador.
 * 
 * @author Tiago Royer
 *
 */
public class Jogador implements Atualizavel {

    private TipoEntradasJogador _input;
    private CorpoRigidoMovel _raquete;
    private double _forca;

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
        _input = input;
        _raquete = raquete;
        _forca = forca;
    }

    @Override
    public void atualizar() { //TODO: usar eventos
        
        if (_input.comandoSubir()) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaCima");
            e.alterar(new Vetor(0, -_forca));
        } else {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaCima");
            e.alterar(vetorNulo);
        }

        if (_input.comandoDescer()) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaBaixo");
            e.alterar(new Vetor(0, _forca));
        } else {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaBaixo");
            e.alterar(vetorNulo);
        }
        
    }

}

package modelo;

import controle.Tecla;
import controle.TipoJogador;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import static modelo.RoyerPhysics.Vetor.vetorNulo;
import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;

/**
 * Classe que movimenta a barra do jogador.
 * 
 * @author Tiago Royer
 * 
 */
public class Jogador implements TipoJogador {

    private final CorpoRigidoMovel _raquete;
    private final double _forca;
    private final Tecla _teclaSubir, _teclaDescer;

    /**
     * Cria um jogador.
     * 
     * Cada jogador tem uma raquete (que ele moverá para cima e para baixo) e
     * uma força (neste caso, a aceleração por atualização).
     * 
     * @param raquete
     *            Barra do jogador.
     * @param forca
     *            Força imprimida por rodada.
     * @param teclaSubir
     *            Qual tecla fará a raquete do jogador deslocar-se para cima.
     * @param teclaDescer
     *            Qual tecla fará a raquete do jogador deslocar-se para baixo.
     */
    public Jogador(CorpoRigidoMovel raquete, double forca, Tecla teclaSubir,
            Tecla teclaDescer) {
        _raquete = raquete;
        _forca = forca;
        _teclaSubir = teclaSubir;
        _teclaDescer = teclaDescer;
    }

    @Override
    public void informarTeclaPressionada(Tecla t) {
        if (t == _teclaSubir) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaCima");
            e.alterar(new Vetor(0, -_forca));
            /*
             * Nesse sistema de coordenadas, as coordenadas verticais estão
             * invertidas em relação ao sistema cartesiano tradicional.
             */
        } else if (t == _teclaDescer) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaBaixo");
            e.alterar(new Vetor(0, _forca));
        }
    }

    @Override
    public void informarTeclaSolta(Tecla t) {
        if (t == _teclaSubir) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaCima");
            e.alterar(vetorNulo);
        } else if (t == _teclaDescer) {
            TipoEditor<Vetor> e = _raquete.obterForca("ForcaBaixo");
            e.alterar(vetorNulo);
        }
    }

}

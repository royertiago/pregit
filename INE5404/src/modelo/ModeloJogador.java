/**
 * Esta classe fará o controle de um jogador no campo.
 * 
 * @author TiagoRoyer
 */

package modelo;

import controle.TipoEntradasJogador;
import visao.TipoImagem;
import modelo.estruturasDeDados.*;

public class ModeloJogador extends ObjetoColisor {

    private TipoImagem _visao;
    private TipoEntradasJogador _controle;

    public ModeloJogador(TipoImagem visao, TipoEntradasJogador controle,
            MascaraDeColisao mascara,
            ControladorDeColisoes colisoes, RegrasDoJogo regras) {
        super(mascara, colisoes, regras);
        _visao = visao;
        _controle = controle;

        _visao.centrarSeEm(mascara.obterCentro());
    }

    @Override
    public void colidir(ObjetoColisor alvo) {
        // Como o jogador é uma barra, ele não reage às colisões.
    }

    @Override
    public void autalizarSe() {
        if (_controle.comandoSubir())
        {
            System.out.println("Subindo");
            mascara = mascara.moverAcima(regras.MOVIMENTO_JOGADOR);
        }

        if (_controle.comandoDescer())
        {
            System.out.println("Descendo");
            mascara = mascara.moverAbaixo(regras.MOVIMENTO_JOGADOR);
        }
        
        _visao.centrarSeEm(mascara.obterCentro());
    }

}

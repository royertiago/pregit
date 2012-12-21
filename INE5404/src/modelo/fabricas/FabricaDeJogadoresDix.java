package modelo.fabricas;

import modelo.Jogador;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import controle.ControladorTeclado;
import controle.ControleJogador;
import controle.Tecla;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.PaginaDix;

/**
 * Fábrica que é responsável por criar os jogadores. Precisa de um aplique Dix
 * para funcionar.
 * 
 * @author Tiago Royer
 * 
 */
public class FabricaDeJogadoresDix {

    private ControladorTeclado _input;

    public FabricaDeJogadoresDix(PaginaDix p) {
        ComponenteDix teclado = p.criarProcuradorDeComponente("teclado");
        _input = new ControladorTeclado();
        teclado.adicionarTratadorDeEventos(_input);
    };

    /**
     * Cria o jogador da direita, e adiciona a ele o corpoMóvel correspondente.
     * As teclas para subir e descer são, respectivamente, Shift e Control.
     * 
     * @param raquete
     *            Raquete usada pelo jogador da direita.
     * @param forca
     *            Força que o jogador pode aplicar à raquete.
     * @return um jogador.
     */
    public Jogador FabricarJogadorDireita(CorpoRigidoMovel raquete, double forca) {
        ControleJogador controle = new ControleJogador(_input, Tecla.SHIFT,
                Tecla.CONTROL);
        return new Jogador(controle, raquete, forca);
    }

    /**
     * Cria o jogador da esquerda, e adiciona a ele o corpoMóvel correspondente.
     * As teclas para subir e descer são as setas direcionais correspondentes.
     * 
     * @param raquete
     *            Raquete usada pelo jogador da esquerda.
     * @param forca
     *            Força que o jogador pode aplicar à raquete.
     * @return um jogador.
     */
    public Jogador FabricarJogadorEsquerda(CorpoRigidoMovel raquete,
            double forca) {
        ControleJogador controle = new ControleJogador(_input, Tecla.SETA_CIMA,
                Tecla.SETA_BAIXO);
        return new Jogador(controle, raquete, forca);
    }
}

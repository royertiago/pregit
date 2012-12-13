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

    private PaginaDix p;
    private ControladorTeclado input;

    public FabricaDeJogadoresDix(PaginaDix p) {
        this.p = p;
        ComponenteDix teclado = p.criarProcuradorDeComponente("teclado");
        ControladorTeclado input = new ControladorTeclado();
        teclado.adicionarTratadorDeEventos(input);
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
        ControleJogador controle = new ControleJogador(input, Tecla.SHIFT,
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
        ControleJogador controle = new ControleJogador(input, Tecla.SETA_CIMA,
                Tecla.SETA_BAIXO);
        return new Jogador(controle, raquete, forca);
    }
}

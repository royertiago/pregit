package modelo.fabricas;

import modelo.Jogador;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import controle.Tecla;

/**
 * Fábrica que é responsável por criar os jogadores.
 * 
 * @author Tiago Royer
 * 
 */
public class FabricaDeJogadoresDix {

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
        return new Jogador(raquete, forca, Tecla.SHIFT, Tecla.CONTROL);
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
        return new Jogador(raquete, forca, Tecla.SETA_CIMA, Tecla.SETA_BAIXO);
    }
}

/**
 * Classe imutável que representa as regras do jogo.
 * 
 * @author Tiago Royer
 */
package modelo;

public final class RegrasDoJogo {

    public final int MOVIMENTO_JOGADOR;

    public RegrasDoJogo(int movimentoMax) {
        MOVIMENTO_JOGADOR = movimentoMax;
    }
}

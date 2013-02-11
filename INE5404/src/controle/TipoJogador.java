package controle;

/**
 * Representa um jogador, que pode ser informado por controladores de teclado
 * quais teclas foram pressionadas ou soltas.
 * 
 * @author Tiago Royer
 *
 */
public interface TipoJogador {

    /**
     * Informa para o jogador que uma tecla foi pressionada.
     * 
     * @param t Tecla que foi pressionada.
     */
    public void informarTeclaPressionada( Tecla t );
    
    /**
     * Informa para o jogador que uma tecla foi solta.
     * 
     * @param t Tecla que foi solta.
     */
    public void informarTeclaSolta( Tecla t );
    
}

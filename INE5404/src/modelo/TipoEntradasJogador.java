/**
 * Informa que comandos o jogador está enviando ao jogo.
 * 
 * @author Tiago Royer
 */

package modelo;

public interface TipoEntradasJogador {

	/**
	 * Diz se a tecla que diz que o jogador quer subir está pressionada.
	 * 
	 * @return <b>true</b> se a tecla estiver pressionada, <b>false</b> caso
	 *         contrário.
	 */
	public boolean comandoSubir();

	/**
	 * Diz se a tecla que diz que o jogador quer descer está pressionada.
	 * 
	 * @return <b>true</b> se a tecla estiver pressionada, <b>false</b> caso
	 *         contrário.
	 */
	public boolean comandoDescer();
	
}

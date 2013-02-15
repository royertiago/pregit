package modelo.fabricas;

import modelo.RoyerPhysics.observacaoDeCorpos.ObservadorDeCorpos;

/**
 * Representa uma interface com a visão; as classes que implementam essa
 * interface devem prover observadores de corpos que corresponderão aos itens do
 * jogo.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoFabricaDeImagens {

    /**
     * Cria um observador de corpos que corresponderá a uma imagem de uma bola.
     * 
     * @return uma imagem para a bola.
     */
    public abstract ObservadorDeCorpos fabricarImagemBola();

    /**
     * Cria um observador de corpos que corresponderá à imagem da raquete do
     * jogador da direita.
     * 
     * @return uma imagem para o jogador da direita.
     */
    public abstract ObservadorDeCorpos fabricarImagemJogadorDireita();

    /**
     * Cria um observador de corpos que corresponderá à imagem da raquete do
     * jogador da esquerda.
     * 
     * @return uma imagem para o jogador da esquerda.
     */
    public abstract ObservadorDeCorpos fabricarImagemJogadorEsquerda();

}

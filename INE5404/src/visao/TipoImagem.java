/**
 * Representa uma imagem na tela.
 * 
 * @author Tiago Royer
 */

package visao;

import modelo.estruturasDeDados.Coordenada;

public interface TipoImagem {

    /**
     * Move a imagem para a posição desejada.
     * 
     * @param posicao
     *            A nova posição do canto superior esquerdo.
     * 
     * @return O próprio objeto.
     */
    public TipoImagem alterarPosicao(Coordenada posicao);

    /**
     * Centraliza a imagem na nova posição desejada.
     * 
     * @param posicao
     *            O centro da nova posição do objeto.
     * @return O próprio objeto
     */
    public TipoImagem centrarSeEm(Coordenada posicao);

}

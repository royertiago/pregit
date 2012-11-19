/**
 * É um adaptador entre TipoImagem e a imagem do Dix.
 * 
 * @author Tiago Royer
 */

package visao;

import modelo.Coordenada;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.PaginaDix;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import edugraf.jadix.tiposPrimitivos.Coordenadas;

public class AdaptadorImagem implements TipoImagem {

    protected ComponenteDix imagem;
    private static int _ContadorImagens = 0;

    // O Dix não permite dois componentes com o mesmo nome, então eu uso esse
    // contador para ter sempre um nome diferente.

    /**
     * Cria uma imagem na tela.
     * 
     * @param tela
     *            Aplique no qual a imagem será desenhada.
     * @param posicao
     *            Posição inicial da imagem
     * @param fonte
     *            fonte do arquivo que será mostrado na tela.
     * @param largura
     *            Largura da imagem.
     * @param altura
     *            Altura da imagem.
     */
    public AdaptadorImagem(PaginaDix tela, Coordenada posicao, String fonte,
            int largura, int altura) {
        imagem = tela.criarComponente(TiposDeComponentesDix.IMAGEM, "Imagem"
                + _ContadorImagens++);
        imagem.fixarCoordenadas(converterCoordenada(posicao));
        imagem.fixarURI(fonte).fixarLargura(largura).fixarAltura(altura);
    }

    @Override
    public AdaptadorImagem centrarSeEm(Coordenada posicao) {
        imagem.fixarCoordenadas(new Coordenadas((int) (posicao.x - imagem
                .obterLargura() / 2),
                (int) (posicao.y - imagem.obterAltura() / 2)));
        return this;
    }

    @Override
    public AdaptadorImagem alterarPosicao(Coordenada posicao) {
        imagem.fixarCoordenadas(converterCoordenada(posicao));
        return this;
    }

    /**
     * Método interno, para converter de Coordenada (do modelo do jogo) para
     * Coordenada<b>s</b> (do Dix)
     * 
     * @param c
     *            Coordenada a ser convertida
     * @return Um objeto Coordenadas equivalente a <u>c</u>
     */
    protected static final Coordenadas converterCoordenada(Coordenada c) {
        return new Coordenadas((int) c.x, (int) c.y);
    }

    /**
     * Retorna uma representação em string do objeto. Formato: [nome] - [fonte
     * da imagem] - [coordenadas do canto superior esquerdo]
     * 
     * @return Uma representação em string da imagem.
     */
    @Override
    public String toString() {
        return imagem.obterNome() + " - " + imagem.obterURI() + " - ("
                + imagem.obterEsquerda() + "," + imagem.obterTopo() + ")";
    }
}

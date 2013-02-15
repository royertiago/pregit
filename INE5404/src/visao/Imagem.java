/**
 * Redirecionador; observa um ObservadoFisico e envia o comando para um TipoImagem.
 */

package visao;

import edugraf.jadix.fachada.PaginaDix;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.observacaoDeCorpos.ObservadorDeCorpos;

public class Imagem implements ObservadorDeCorpos {

    private TipoImagem img;
    /**
     * Cria uma imagem, com um AdaptadorImagem como alvo de redirecionamento.
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
    public Imagem(PaginaDix tela, Coordenada posicao, String fonte,
            int largura, int altura)
    {
        img = new AdaptadorImagem(tela, posicao, fonte, largura, altura);
    }
    
    /**
     * Cria uma Imagem, cujo alvo de redirecionamento será <b>img</b>.
     * @param img Alvo de redirecionamento.
     */
    public Imagem(TipoImagem img)
    {
        this.img = img;
    }
    
    @Override
    public void notificar(Coordenada centro) {
        img.centrarSeEm(centro);
    }
    
    @Override
    public String toString()
    {
        return "Imagem - " + img;
    }

}

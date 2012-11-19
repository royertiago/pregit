/**
 * Redirecionador; observa um ObservadoFisico e envia o comando para um TipoImagem.
 */

package visao;

import edugraf.jadix.fachada.PaginaDix;
import modelo.Coordenada;
import modelo.fisico.ObservadoFisico;
import modelo.fisico.ObservadorFisico;

public class Imagem implements ObservadorFisico {

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
    public void notificar(ObservadoFisico o) {
        img.centrarSeEm(o.obterMascara().obterCentro());
    }

}

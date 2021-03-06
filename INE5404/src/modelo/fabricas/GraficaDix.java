package modelo.fabricas;

import static modelo.RoyerPhysics.Coordenada.origem;
import visao.Imagem;
import edugraf.jadix.fachada.PaginaDix;
import modelo.RoyerPhysics.observacaoDeCorpos.ObservadorDeCorpos;

/**
 * Fábrica de imagens que é capaz de operar com o Jadix.
 * 
 * @author Tiago Royer
 *
 */
public class GraficaDix implements TipoFabricaDeImagens {

    private PaginaDix a;
    
    /**
     * Cria uma fábrica de imagens que opera sobre o aplique <b>a</b>.
     * @param a Aplique sobre o qual serão criadas as imagens.
     */
    public GraficaDix (PaginaDix a) {
        this.a = a;
    }
    
    @Override
    public ObservadorDeCorpos fabricarImagemBola() {
        return new Imagem(a, origem, "recursos/Bola.png", 25, 25);
    }

    @Override
    public ObservadorDeCorpos fabricarImagemJogadorEsquerda() {
        return new Imagem(a, origem, "recursos/Barra1.png", 15, 100);
    }

    @Override
    public ObservadorDeCorpos fabricarImagemJogadorDireita() {
        return new Imagem(a, origem, "recursos/Barra2.png", 15, 100);
    }

}

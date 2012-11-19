/**
 * Interface que representa um objeto com uma máscara de colisão.
 */

package modelo.fisico;

import modelo.fisico.estruturas.TipoMascaraDeColisao;

public interface ObservadoFisico {

    /**
     * Informa a máscara de colisão deste observado.
     * 
     * @return uma máscara de colisão.
     */
    public TipoMascaraDeColisao obterMascara();

    /**
     * Adiciona o ObservadorFisico <b>o</b> à lista dos interessados em receber
     * notificações sobre mudanças de estado.
     * 
     * @param o
     *            ObservadorFisico a ser adicionado.
     */
    public void registrarObservador(ObservadorFisico o);

    /**
     * Remove o ObservadorFisico <b>o</b> da lista de interessados.
     * 
     * @param o
     *            ObsevadorFisico a ser removido.
     */
    public void removerObservador(ObservadorFisico o);

}

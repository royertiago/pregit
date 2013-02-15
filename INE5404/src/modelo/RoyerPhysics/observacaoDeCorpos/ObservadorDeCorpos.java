package modelo.RoyerPhysics.observacaoDeCorpos;

import modelo.RoyerPhysics.Coordenada;



/**
 * Representa alguém que é capaz de observar um CorpoObservado. O corpo
 * observado informará, a cada atualização, o centro de si para o observador
 * (uma imagem, por exemplo).
 * 
 * @author Tiago Royer
 * 
 */
public interface ObservadorDeCorpos {

    /**
     * Recebe uma notificação do observado.
     * 
     * @param centro
     *            Centro do observado.
     */
    public abstract void notificar(Coordenada centro);

}

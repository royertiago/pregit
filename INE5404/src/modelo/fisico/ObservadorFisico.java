/**
 * Representa uma classe que observa um objeto físico.
 */

package modelo.fisico;

public interface ObservadorFisico {

    /**
     * Recebe uma notificação do ObservadoFisico <b>o</b>.
     * 
     * @param o
     *            ObservadoFisico que enviou a notificação.
     */
    public void notificar(ObservadoFisico o);

}

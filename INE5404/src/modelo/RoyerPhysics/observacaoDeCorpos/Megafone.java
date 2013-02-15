package modelo.RoyerPhysics.observacaoDeCorpos;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.estruturasDeDados.Lista;

/**
 * Classe que auxilia objetos a contatarem seus observadores; o megafone mantém
 * uma lista de ouvintes e pode "gritar" para eles a posição num determinado
 * momento.
 * 
 * @author Tiago Royer
 * 
 * @param <Tipo>
 */
public class Megafone {

    private Lista<ObservadorDeCorpos> _observadores;

    /**
     * Cria um megafone.
     */
    public Megafone() {
        _observadores = new Lista<ObservadorDeCorpos>();
    }

    /**
     * Adiciona um novo observador de corpos à lista de ouvintes.
     * 
     * @param o
     *            ObservadorDeCorpos a ser adicionado.
     */
    public void adicionarOuvinte(ObservadorDeCorpos o) {
        _observadores.adicionarItem(o);
    }

    /**
     * Remove o observador de corpos da lista de ouvintes, se ele estiver nela.
     * 
     * @param o
     *            ObservatorDeCorpos a ser removido.
     */
    public void removerOuvinte(ObservadorDeCorpos o) {
        _observadores.removerItem(o);
    }

    /**
     * Anuncia a coordenada <b>mensagem</b> para todos os ouvintes deste
     * megafone.
     * 
     * @param mensagem
     *            Coordenada a ser anunciada.
     */
    public void gritar(Coordenada mensagem) {
        for (ObservadorDeCorpos o : _observadores)
            o.notificar(mensagem);
    }
}

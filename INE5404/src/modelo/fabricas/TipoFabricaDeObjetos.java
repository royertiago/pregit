package modelo.fabricas;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.executivo.TipoAplicadorDeLeis;

/**
 * Essa interface é de uma fábrica que é responsável por prover objetos ao jogo.
 * 
 * A fábrica deve ser capaz de criar a bola, as raquetes, e um colisor
 * "equipado" com as quatro paredes e um controle de colisões.
 * 
 * Para a raquete e a bola, esses objetos já devem ter registrado as imagens
 * como observadores.
 * 
 * @author Tiago Royer
 * 
 */
public interface TipoFabricaDeObjetos {

    /**
     * Cria uma bola no centro do campo com uma imagem apropriada.
     * 
     * @param v
     *            Vetor de movimento da bola.
     * @return Uma bola.
     */
    public abstract CorpoRigidoMovel fabricarBola(Vetor v);

    /**
     * Cria uma raquete para o jogador da direita, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public abstract CorpoRigidoMovel fabricarRaqueteDireita();

    /**
     * Cria uma raquete para o jogador da esquerda, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public abstract CorpoRigidoMovel fabricarRaqueteEsquerda();

    /**
     * Cria um TipoAplicadorDeLeis, com as leis de movimento e colisão
     * devidamente adicionadas, e com as quatro paredes externas já criadas.
     * 
     * @return um TipoAplicadorDeLeis equipado com colisões e paredes.
     */
    public abstract TipoAplicadorDeLeis fabricarColisorEquipado();
    //TODO: prover fachada para o colisor e tirar esse método daqui.
}

package modelo.fabricas;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.corposRigidos.CorpoRigidoImovel;
import modelo.RoyerPhysics.corposRigidos.CorpoRigidoPadrao;
import modelo.RoyerPhysics.corposRigidos.mascaras.Circular;
import modelo.RoyerPhysics.corposRigidos.mascaras.Parede;
import modelo.RoyerPhysics.executivo.AplicadorDeLeis;
import modelo.RoyerPhysics.executivo.TipoAplicadorDeLeis;
import modelo.RoyerPhysics.legislativo.ColisaoSemMomento;
import modelo.RoyerPhysics.legislativo.LeiDeForcas;
import modelo.RoyerPhysics.legislativo.LeiUnariaTemporal;
import modelo.RoyerPhysics.legislativo.Movimento;
import modelo.jogo.RaqueteDoPong;

/**
 * Essa classe é de uma fábrica que é responsável por prover objetos ao jogo.
 * 
 * A fábrica é ser capaz de criar a bola, as raquetes, e um colisor
 * "equipado" com as quatro paredes e um controle de colisões.
 * 
 * Para a raquete e a bola, esses objetos já terão registrado as imagens
 * como observadores, por isso que a fábrica precisa de uma fábrica de imagens acoplada.
 *  
 * @author Tiago Royer
 * 
 */
public class FabricaDeObjetos {

    private TipoFabricaDeImagens grafica;

    /**
     * Cria uma fábrica de objetos, que criará objetos usando a fábrica de
     * imagens passada.
     * 
     * @param grafica
     *            fábrica de imagens a ser usada.
     */
    public FabricaDeObjetos(TipoFabricaDeImagens grafica) {
        this.grafica = grafica;
    }

    /**
     * Cria uma bola no centro do campo com uma imagem apropriada.
     * 
     * @param v
     *            Vetor de movimento da bola.
     * @return Uma bola.
     */
    public CorpoRigidoMovel fabricarBola(Vetor v) {
        Circular mBola = new Circular(new Coordenada(350, 200), 13, 40);
        CorpoRigidoPadrao bola = new CorpoRigidoPadrao(mBola, v, 1);
        bola.adicionarObservador(grafica.fabricarImagemBola());
        return bola;
    }

    /**
     * Cria uma raquete para o jogador da direita, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public CorpoRigidoMovel fabricarRaqueteDireita() {
        RaqueteDoPong raquete = new RaqueteDoPong(Vetor.vetorNulo, 1,
                new Coordenada(60, 200), 100, 15);
        raquete.adicionarObservador(grafica.fabricarImagemJogadorDireita());
        return raquete;
    }

    /**
     * Cria uma raquete para o jogador da esquerda, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public CorpoRigidoMovel fabricarRaqueteEsquerda() {
        RaqueteDoPong raquete = new RaqueteDoPong(Vetor.vetorNulo, 1,
                new Coordenada(720, 200), 100, 15);
        raquete.adicionarObservador(grafica.fabricarImagemJogadorEsquerda());
        return raquete;
    }

    /**
     * Cria um TipoAplicadorDeLeis, com as leis de movimento e colisão
     * devidamente adicionadas, e com as quatro paredes externas já criadas.
     * 
     * @param tempo Tempo a ser passado ao aplicador.
     * 
     * @return um TipoAplicadorDeLeis equipado com colisões e paredes.
     */
    public TipoAplicadorDeLeis fabricarColisorEquipado(double tempo) {
      //TODO: prover uma fachada para o colisor e remover esse método daqui.
        Coordenada cA = new Coordenada(0, 0), cB = new Coordenada(700, 0), cC = new Coordenada(
                700, 400), cD = new Coordenada(0, 400);

        AplicadorDeLeis controlador = new AplicadorDeLeis(tempo);

        Parede p1 = new Parede(cA, cB);
        Parede p2 = new Parede(cB, cC);
        Parede p3 = new Parede(cC, cD);
        Parede p4 = new Parede(cD, cA);

        CorpoRigidoImovel pA = new CorpoRigidoImovel(p1);
        CorpoRigidoImovel pC = new CorpoRigidoImovel(p3);
        CorpoRigidoImovel pD = new CorpoRigidoImovel(p4);
        CorpoRigidoImovel pB = new CorpoRigidoImovel(p2);

        controlador.adicionarCorpoRigido(pA);
        controlador.adicionarCorpoRigido(pB);
        controlador.adicionarCorpoRigido(pC);
        controlador.adicionarCorpoRigido(pD);

        LeiUnariaTemporal mov = new Movimento(tempo);
        ColisaoSemMomento c = new ColisaoSemMomento();
        LeiDeForcas f = new LeiDeForcas(tempo);
        controlador.adicionarLei(c);
        controlador.adicionarLei(mov);
        controlador.adicionarLei(f);
        
        return controlador;
    }
}

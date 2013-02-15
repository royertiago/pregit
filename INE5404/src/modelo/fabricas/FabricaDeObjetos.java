package modelo.fabricas;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigido;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.leis.AplicadorDeLeis;
import modelo.RoyerPhysics.leis.ColisaoSemMomento;
import modelo.RoyerPhysics.leis.LeiDeForcas;
import modelo.RoyerPhysics.leis.Movimento;
import modelo.RoyerPhysics.leis.TipoAplicador;
import modelo.RoyerPhysics.observacaoDeCorpos.CorpoObservado;
import modelo.RoyerPhysics.poligonos.Circulo;
import modelo.RoyerPhysics.poligonos.PoligonoConvexo;
import modelo.RoyerPhysics.poligonos.Parede;

/**
 * Essa classe é de uma fábrica que é responsável por prover objetos ao jogo.
 * 
 * A fábrica é ser capaz de criar a bola, as raquetes, e um colisor "equipado"
 * com as quatro paredes e um controle de colisões.
 * 
 * Para a raquete e a bola, esses objetos já terão registrado as imagens como
 * observadores, por isso que a fábrica precisa de uma fábrica de imagens
 * acoplada.
 * 
 * @author Tiago Royer
 * 
 */
public class FabricaDeObjetos {

    private TipoFabricaDeImagens _grafica;

    /**
     * Cria uma fábrica de objetos, que criará objetos usando a fábrica de
     * imagens passada.
     * 
     * @param grafica
     *            fábrica de imagens a ser usada.
     */
    public FabricaDeObjetos(TipoFabricaDeImagens grafica) {
        this._grafica = grafica;
    }

    /**
     * Cria uma bola no centro do campo com uma imagem apropriada.
     * 
     * @param v
     *            Vetor de movimento da bola.
     * @return Uma bola.
     */
    public CorpoRigidoMovel fabricarBola(Vetor v) {
        Circulo c = new Circulo(new Coordenada(350, 200), 13, 40);
        CorpoRigido cr = new CorpoRigido(c);
        cr.fixarVetorMovimento(v);
        CorpoObservado bola = new CorpoObservado(cr);
        bola.adicionarObservador(_grafica.fabricarImagemBola());
        return bola;
    }

    /**
     * Cria uma raquete para o jogador da esquerda, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public CorpoRigidoMovel fabricarRaqueteEsquerda() {
        PoligonoConvexo p = new PoligonoConvexo(new Coordenada(10, 150),
                new Coordenada(25, 175), new Coordenada(25, 225),
                new Coordenada(10, 250));
        CorpoObservado raquete = new CorpoObservado(p);
        raquete.adicionarObservador(_grafica.fabricarImagemJogadorEsquerda());
        return raquete;
    }

    /**
     * Cria uma raquete para o jogador da direita, com uma imagem apropriada.
     * 
     * @return Uma raquete.
     */
    public CorpoRigidoMovel fabricarRaqueteDireita() {
        PoligonoConvexo p = new PoligonoConvexo(new Coordenada(690, 150),
                new Coordenada(690, 250), new Coordenada(675, 225),
                new Coordenada(675, 175));
        CorpoObservado raquete = new CorpoObservado(p);
        raquete.adicionarObservador(_grafica.fabricarImagemJogadorDireita());
        return raquete;
    }

    /**
     * Cria um TipoAplicador, com as leis de movimento e colisão devidamente
     * adicionadas, e com as quatro paredes externas já criadas.
     * 
     * @return um TipoAplicadorDeLeis equipado com colisões e paredes.
     */
    public TipoAplicador fabricarColisorEquipado() {
        Coordenada cA = new Coordenada(0, 0), cB = new Coordenada(700, 0), cC = new Coordenada(
                700, 400), cD = new Coordenada(0, 400);

        AplicadorDeLeis controlador = new AplicadorDeLeis();

        Parede p1 = new Parede(cA, cB);
        Parede p2 = new Parede(cB, cC);
        Parede p3 = new Parede(cC, cD);
        Parede p4 = new Parede(cD, cA);

        controlador.registrarEstrutura(p1);
        controlador.registrarEstrutura(p2);
        controlador.registrarEstrutura(p3);
        controlador.registrarEstrutura(p4);

        Movimento mov = new Movimento();
        ColisaoSemMomento c = new ColisaoSemMomento();
        LeiDeForcas f = new LeiDeForcas();
        controlador.registrarLei(c);
        controlador.registrarLei(mov);
        controlador.registrarLei(f);

        return controlador;
    }
}

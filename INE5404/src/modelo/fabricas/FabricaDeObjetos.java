package modelo.fabricas;

import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.corposRigidos.CorpoRigidoImovel;
import modelo.RoyerPhysics.corposRigidos.CorpoRigidoPadrao;
import modelo.RoyerPhysics.corposRigidos.mascaras.Circular;
import modelo.RoyerPhysics.corposRigidos.mascaras.Parede;
import modelo.RoyerPhysics.executivo.AplicadorIneficiente;
import modelo.RoyerPhysics.executivo.TipoAplicadorDeLeis;
import modelo.RoyerPhysics.legislativo.ColisaoSemMomento;
import modelo.RoyerPhysics.legislativo.Movimento;
import modelo.jogo.RaqueteDoPong;

/**
 * Uma fábrica que cria objetos. Precisa de uma fábrica de imagens para
 * auxiliá-la.
 * 
 * @author Tiago Royer
 * 
 */
public class FabricaDeObjetos implements TipoFabricaDeObjetos {

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

    @Override
    public CorpoRigidoMovel fabricarBola(Vetor v) {
        Circular mBola = new Circular(new Coordenada(350, 200), 13, 40);
        CorpoRigidoPadrao bola = new CorpoRigidoPadrao(mBola, v, 1);
        bola.adicionarObservador(grafica.fabricarImagemBola());
        return bola;
    }

    @Override
    public CorpoRigidoMovel fabricarRaqueteDireita() {
        RaqueteDoPong raquete = new RaqueteDoPong(Vetor.semMovimento, 1,
                new Coordenada(60, 200), 100, 15);
        raquete.adicionarObservador(grafica.fabricarImagemJogadorDireita());
        return raquete;
    }

    @Override
    public CorpoRigidoMovel fabricarRaqueteEsquerda() {
        RaqueteDoPong raquete = new RaqueteDoPong(Vetor.semMovimento, 1,
                new Coordenada(720, 200), 100, 15);
        raquete.adicionarObservador(grafica.fabricarImagemJogadorEsquerda());
        return raquete;
    }

    @Override
    public TipoAplicadorDeLeis fabricarColisorEquipado() {
        Coordenada cA = new Coordenada(0, 0), cB = new Coordenada(700, 0), cC = new Coordenada(
                700, 400), cD = new Coordenada(0, 400);

        AplicadorIneficiente controlador = new AplicadorIneficiente();

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

        Movimento mov = new Movimento();
        ColisaoSemMomento c = new ColisaoSemMomento();
        controlador.adicionarLei(c);
        controlador.adicionarLei(mov);

        return controlador;

    }

}

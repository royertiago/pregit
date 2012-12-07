package modelo;

import br.ufsc.edugraf.telis.util.PosicaoEmTexto;
import controle.*;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.Pichador;
import visao.*;
import modelo.RoyerPhysics.*;
import modelo.estruturasDeDados.*;
import modelo.fabricas.*;
import modelo.jogo.RaqueteDoPong;
import static modelo.RoyerPhysics.Coordenada.*;
import static modelo.RoyerPhysics.Intersecao.*;
import modelo.RoyerPhysics.corposRigidos.mascaras.*;
import modelo.RoyerPhysics.corposRigidos.*;
import modelo.RoyerPhysics.executivo.*;
import modelo.RoyerPhysics.legislativo.*;
import modelo.RoyerPhysics.*;

@SuppressWarnings("unused")
public class Jogo {

    public static void Jogar(Aplique a) {
        // FIXME: as fábricas não funcionam.
        /*
         * GraficaDix grafica = new GraficaDix(a); FabricaDeObjetos fabrica =
         * new FabricaDeObjetos(grafica);
         * 
         * TipoAplicadorDeLeis lhc = fabrica.fabricarColisorEquipado();
         * 
         * TipoCorpoRigido bola = fabrica.fabricarBola(new Vetor(0,
         * 3).espelharSeSobre(Math.random()*Math.PI*2 - Math.PI));
         * lhc.adicionarCorpoRigido(bola);
         * 
         * CorpoRigidoMovel raquete1 = fabrica.fabricarRaqueteDireita();
         * lhc.adicionarCorpoRigido(raquete1); CorpoRigidoMovel raquete2 =
         * fabrica.fabricarRaqueteEsquerda();
         * lhc.adicionarCorpoRigido(raquete2);
         * 
         * ComponenteDix teclado =
         * a.obterPaginaDix().criarProcuradorDeComponente("teclado");
         * ControladorTeclado input = new ControladorTeclado();
         * teclado.adicionarTratadorDeEventos(input);
         * 
         * ControleJogador inP1 = new ControleJogador(input, Tecla.SHIFT,
         * Tecla.CONTROL); //TODO: jogar isso para uma fábrica ControleJogador
         * inP2 = new ControleJogador(input, Tecla.SETA_CIMA, Tecla.SETA_BAIXO);
         * Jogador player1 = new Jogador(inP1, raquete1, 0.05); Jogador player2
         * = new Jogador(inP2, raquete2, 0.05);
         * lhc.adicionarCorpoRigido(raquete1);
         * lhc.adicionarCorpoRigido(raquete2);
         * 
         * System.out.println("Jogo criado");
         * 
         * Pichador alce = new Pichador(); while (!false) { player1.atualizar();
         * player2.atualizar(); lhc.aplicarLeis(); alce.descansar(0.01); }
         */

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

        Imagem imBola = new Imagem(a.obterPaginaDix(), origem,
                "recursos/Bola.png", 25, 25);
        Circular mBola = new Circular(new Coordenada(350, 200), 13, 40);
        CorpoRigidoPadrao bola = new CorpoRigidoPadrao(mBola, new Vetor(2, 2),
                1);
        bola.adicionarObservador(imBola);
        controlador.adicionarCorpoRigido(bola);

        ComponenteDix teclado = a.obterPaginaDix().criarProcuradorDeComponente(
                "teclado");
        ControladorTeclado input = new ControladorTeclado();
        teclado.adicionarTratadorDeEventos(input);

        ControleJogador inP1 = new ControleJogador(input, Tecla.SHIFT,
                Tecla.CONTROL);
        ControleJogador inP2 = new ControleJogador(input, Tecla.SETA_CIMA,
                Tecla.SETA_BAIXO);
        RaqueteDoPong rP1 = new RaqueteDoPong(Vetor.semMovimento, 1,
                new Coordenada(60, 200), 100, 15);
        RaqueteDoPong rP2 = new RaqueteDoPong(Vetor.semMovimento, 1,
                new Coordenada(720, 200), 100, 15);
        Imagem imP1 = new Imagem(a.obterPaginaDix(), origem,
                "recursos/Barra1.png", 15, 100);
        Imagem imP2 = new Imagem(a.obterPaginaDix(), origem,
                "recursos/Barra2.png", 15, 100);
        Jogador player1 = new Jogador(inP1, rP1, 0.2);
        Jogador player2 = new Jogador(inP2, rP2, 0.2);
        rP1.adicionarObservador(imP1);
        rP2.adicionarObservador(imP2);
        controlador.adicionarCorpoRigido(rP1);
        controlador.adicionarCorpoRigido(rP2);

        Movimento mov = new Movimento();
        ColisaoSemMomento c = new ColisaoSemMomento();
        controlador.adicionarLei(c);
        controlador.adicionarLei(mov); // TODO: criar uma fachada para o
                                       // colisor.

        System.out.println("Jogo criado.");

        Pichador alce = new Pichador();
        while (!false) {
            player1.atualizar();
            player2.atualizar();
            controlador.aplicarLeis();
            alce.descansar(0.02);
        }
    }
}

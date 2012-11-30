package modelo;

import br.ufsc.edugraf.telis.util.PosicaoEmTexto;
import controle.*;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.Pichador;
import visao.*;
import modelo.RoyerPhysics.*;
import modelo.estruturasDeDados.*;
import static modelo.RoyerPhysics.Coordenada.*;
import modelo.RoyerPhysics.corposRigidos.mascaras.*;
import modelo.RoyerPhysics.corposRigidos.*;
import modelo.RoyerPhysics.executivo.*;
import modelo.RoyerPhysics.legislativo.*;
import modelo.RoyerPhysics.*;

@SuppressWarnings("unused")
public class Jogo {
    
    public static void Jogar(Aplique a)
    {
        Coordenada cA = new Coordenada(0, 0),
                   cB = new Coordenada(700, 0),
                   cC = new Coordenada(700, 400),
                   cD = new Coordenada(0, 400);

        AplicadorIneficiente controlador = new AplicadorIneficiente();
        
        ParedeAvancada p1 = new ParedeAvancada(cA, cB);
        ParedeAvancada p2 = new ParedeAvancada(cB, cC);
        ParedeAvancada p3 = new ParedeAvancada(cC, cD);
        ParedeAvancada p4 = new ParedeAvancada(cD, cA);

        CorpoRigidoImovel pA = new CorpoRigidoImovel(p1);
        CorpoRigidoImovel pC = new CorpoRigidoImovel(p3);
        CorpoRigidoImovel pD = new CorpoRigidoImovel(p4);
        CorpoRigidoImovel pB = new CorpoRigidoImovel(p2);
        
        controlador.adicionarCorpoRigido(pA);
        controlador.adicionarCorpoRigido(pB);
        controlador.adicionarCorpoRigido(pC);
        controlador.adicionarCorpoRigido(pD);
        
        Imagem imBola = new Imagem(a.obterPaginaDix(),origem, "recursos/Bola.png",25, 25);
        Circular mBola = new Circular(new Coordenada(350, 200), 13, 40);
        CorpoRigidoPadrao bola = new CorpoRigidoPadrao(mBola, new Vetor(2, 2), 1);
        bola.adicionarObservador(imBola);
        controlador.adicionarCorpoRigido(bola);
        
        
        ComponenteDix teclado = a.obterPaginaDix().criarProcuradorDeComponente("teclado");
        ControladorTeclado input = new ControladorTeclado();
        teclado.adicionarTratadorDeEventos(input);
        
        ControleJogador inP1 = new ControleJogador(input, Tecla.SHIFT, Tecla.CONTROL);
        ControleJogador inP2 = new ControleJogador(input, Tecla.SETA_CIMA, Tecla.SETA_BAIXO);
        RaqueteDoPong rP1 = new RaqueteDoPong(Vetor.semMovimento, 1, new Coordenada(60, 200), 100, 15);
        RaqueteDoPong rP2 = new RaqueteDoPong(Vetor.semMovimento, 1, new Coordenada(720, 200), 100, 15);
        Imagem imP1 = new Imagem(a.obterPaginaDix(), origem, "recursos/Barra1.png", 15, 100);
        Imagem imP2 = new Imagem(a.obterPaginaDix(), origem, "recursos/Barra2.png", 15, 100);
        Jogador player1 = new Jogador(inP1, rP1, 0.2);
        Jogador player2 = new Jogador(inP2, rP2, 0.2);
        rP1.adicionarObservador(imP1);
        rP2.adicionarObservador(imP2);
        controlador.adicionarCorpoRigido(rP1);
        controlador.adicionarCorpoRigido(rP2);
        
        Movimento mov = new Movimento();
        ColisaoSemMomento c = new ColisaoSemMomento();
        controlador.adicionarLei(c);
        controlador.adicionarLei(mov); //TODO: criar uma fachada para o colisor.
        
        System.out.println("Jogo criado");
        
        Pichador alce = new Pichador();
        while (!false)
        {
            player1.atualizar();
            player2.atualizar();
            controlador.aplicarLeis();
            alce.descansar(0.02);
        }
    }
}

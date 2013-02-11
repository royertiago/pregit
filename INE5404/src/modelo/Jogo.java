package modelo;

import controle.*;
import edugraf.jadix.*;
import edugraf.jadix.fachada.*;
import visao.*;
import modelo.RoyerPhysics.*;
import modelo.estruturasDeDados.*;
import modelo.fabricas.*;
import modelo.jogo.RaqueteDoPong;
import static modelo.RoyerPhysics.Coordenada.*;
import static modelo.RoyerPhysics.Intersecao.*;
import static modelo.RoyerPhysics.Vetor.*;
import modelo.RoyerPhysics.corposRigidos.mascaras.*;
import modelo.RoyerPhysics.corposRigidos.*;
import modelo.RoyerPhysics.executivo.*;
import modelo.RoyerPhysics.legislativo.*;
import modelo.RoyerPhysics.*;

@SuppressWarnings("unused")
public class Jogo {

    public static void Jogar(Aplique a) {

        GraficaDix grafica = new GraficaDix(a.obterPaginaDix());
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        FabricaDeJogadoresDix academia = new FabricaDeJogadoresDix();
        
        TipoAplicadorDeLeis controlador = fabrica.fabricarColisorEquipado(0.05);

        CorpoRigidoMovel bola = fabrica.fabricarBola(new Vetor(50, 50));
        controlador.adicionarCorpoRigido(bola);

        CorpoRigidoMovel rP1 = fabrica.fabricarRaqueteDireita();
        CorpoRigidoMovel rP2 = fabrica.fabricarRaqueteEsquerda();

        ControladorTeclado keyboard = new ControladorTeclado(a.obterPaginaDix());
        Jogador player1 = academia.FabricarJogadorDireita(rP1, 100);
        Jogador player2 = academia.FabricarJogadorEsquerda(rP2, 100);
        keyboard.registrarJogador(player1);
        keyboard.registrarJogador(player2);
        
        controlador.adicionarCorpoRigido(rP1);
        controlador.adicionarCorpoRigido(rP2);

        System.out.println("Jogo criado. Este jogo usa RoyerPhysics - A Leading Computational Engine");

        Pichador alce = new Pichador();
        while (!false) {
            controlador.aplicarLeis();
            alce.descansar(0.05);
        }
    }
}
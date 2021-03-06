package modelo;

import controle.ControladorTeclado;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.leis.TipoAplicador;
import modelo.fabricas.AcademiaDix;
import modelo.fabricas.FabricaDeObjetos;
import modelo.fabricas.GraficaDix;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;

public class Jogo {

    public static void jogar(Aplique a) {

        GraficaDix grafica = new GraficaDix(a.obterPaginaDix());
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        AcademiaDix academia = new AcademiaDix();
        
        TipoAplicador controlador = fabrica.fabricarColisorEquipado();

        CorpoRigidoMovel bola = fabrica.fabricarBola(new Coordenada(350, 200), new Vetor(100, 100));
        controlador.registrarCorpo(bola);
        
        CorpoRigidoMovel rP1 = fabrica.fabricarRaqueteDireita();
        CorpoRigidoMovel rP2 = fabrica.fabricarRaqueteEsquerda();

        ControladorTeclado keyboard = new ControladorTeclado(a.obterPaginaDix());
        Jogador player1 = academia.FabricarJogadorDireita(rP1, 50);
        Jogador player2 = academia.FabricarJogadorEsquerda(rP2, 50);
        keyboard.registrarJogador(player1);
        keyboard.registrarJogador(player2);
        
        controlador.registrarCorpo(rP1);
        controlador.registrarCorpo(rP2);
        
        System.out.println("Jogo criado. Este jogo usa RoyerPhysics - A Leading Computational Engine");

        Pichador alce = new Pichador();
        while (!false) {
            controlador.avancar(0.02);
            alce.descansar(0.02);
        }
    }
}
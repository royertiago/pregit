package modelo;

import controle.*;
import modelo.RoyerPhysics.*;
import modelo.RoyerPhysics.leis.*;
import modelo.RoyerPhysics.poligonos.*;
import modelo.fabricas.*;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;

public class Jogo {

    public static void jogar(Aplique a) {

        GraficaDix grafica = new GraficaDix(a.obterPaginaDix());
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        AcademiaDix academia = new AcademiaDix();
        
        TipoAplicador controlador = fabrica.fabricarColisorEquipado();

        CorpoRigidoMovel bola = fabrica.fabricarBola(new Vetor(100, 100));
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
    
    static public void main( String[] args )
    {
        PoligonoConvexo p = new PoligonoConvexo(new Coordenada(690, 150),
                new Coordenada(690, 250), new Coordenada(675, 225),
                new Coordenada(675, 175));
        PoligonoConvexo p1 = new PoligonoConvexo(new Coordenada(690, 150),
                new Coordenada(690, 250), new Coordenada(675, 225),
                new Coordenada(675, 175));
        
        p.mover(new Vetor(10, 10));
        
        System.out.println();
        System.out.println(p.obterAABB());
        System.out.println();
        System.out.println(p1.obterAABB());
        System.out.println();
        System.out.println(p.obterAABB().estaSobreposto(p1.obterAABB()));
        
    }//*/
}
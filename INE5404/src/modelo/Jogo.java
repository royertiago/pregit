package modelo;

import controle.ControladorTeclado;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.Vetor;
import modelo.RoyerPhysics.leis.TipoAplicador;
import modelo.RoyerPhysics.poligonos.PoligonoConvexo;
import modelo.fabricas.AcademiaDix;
import modelo.fabricas.FabricaDeObjetos;
import modelo.fabricas.GraficaDix;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;

import edugraf.jadix.ajudantes.DecoradorDeComponenteDixAbstrato;
@SuppressWarnings("unused")
public class Jogo {

    public static void jogar(Aplique a) {

        GraficaDix grafica = new GraficaDix(a.obterPaginaDix());
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        AcademiaDix academia = new AcademiaDix();
        
        TipoAplicador controlador = fabrica.fabricarColisorEquipado();

        CorpoRigidoMovel bola = fabrica.fabricarBola(new Vetor(50, 50));
        controlador.registrarCorpo(bola);
        
        CorpoRigidoMovel rP1 = fabrica.fabricarRaqueteDireita();
        CorpoRigidoMovel rP2 = fabrica.fabricarRaqueteEsquerda();

        ControladorTeclado keyboard = new ControladorTeclado(a.obterPaginaDix());
        Jogador player1 = academia.FabricarJogadorDireita(rP1, 100);
        Jogador player2 = academia.FabricarJogadorEsquerda(rP2, 100);
        keyboard.registrarJogador(player1);
        keyboard.registrarJogador(player2);
        
        controlador.registrarCorpo(rP1);
        controlador.registrarCorpo(rP2);
        
        System.out.println("Jogo criado. Este jogo usa RoyerPhysics - A Leading Computational Engine");

        Pichador alce = new Pichador();
        while (!false) {
            controlador.avancar(0.05);
            alce.descansar(0.05);
        }
    }
    
    static public void main( String[] args )
    {
        PoligonoConvexo p = new PoligonoConvexo(new Coordenada(690, 150),
                new Coordenada(690, 250), new Coordenada(675, 225),
                new Coordenada(675, 175));
        System.out.println(p);
        p.mover(new Vetor(Math.PI, Math.E));
        System.out.println(p);
        p.mover(new Vetor(Math.PI, Math.E));
        System.out.println(p);
    }//*/
}
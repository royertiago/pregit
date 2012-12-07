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
    
    public static void Jogar(Aplique a)
    {
        GraficaDix grafica = new GraficaDix(a); 
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        
        TipoAplicadorDeLeis lhc = fabrica.fabricarColisorEquipado();
        
        TipoCorpoRigido bola = fabrica.fabricarBola(new Vetor(0, 3).espelharSeSobre(Math.random()*Math.PI*2 - Math.PI));
        lhc.adicionarCorpoRigido(bola);
        
        CorpoRigidoMovel raquete1 = fabrica.fabricarRaqueteDireita();
        lhc.adicionarCorpoRigido(raquete1);
        CorpoRigidoMovel raquete2 = fabrica.fabricarRaqueteEsquerda();
        lhc.adicionarCorpoRigido(raquete2);
        
        ComponenteDix teclado = a.obterPaginaDix().criarProcuradorDeComponente("teclado");
        ControladorTeclado input = new ControladorTeclado();
        teclado.adicionarTratadorDeEventos(input);
        
        ControleJogador inP1 = new ControleJogador(input, Tecla.SHIFT, Tecla.CONTROL); //TODO: jogar isso para uma fábrica
        ControleJogador inP2 = new ControleJogador(input, Tecla.SETA_CIMA, Tecla.SETA_BAIXO);
        Jogador player1 = new Jogador(inP1, raquete1, 0.05);
        Jogador player2 = new Jogador(inP2, raquete2, 0.05);
        lhc.adicionarCorpoRigido(raquete1);
        lhc.adicionarCorpoRigido(raquete2);
        
        System.out.println("Jogo criado");
        
        Pichador alce = new Pichador();
        while (!false) //FIXME: nao funciona + fazer diagrama
        {
            player1.atualizar();
            player2.atualizar();
            lhc.aplicarLeis();
            alce.descansar(0.01);
        }
    }
}

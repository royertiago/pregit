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

        GraficaDix grafica = new GraficaDix(a.obterPaginaDix());
        FabricaDeObjetos fabrica = new FabricaDeObjetos(grafica);
        FabricaDeJogadoresDix academia = new FabricaDeJogadoresDix(a.obterPaginaDix());
        
        TipoAplicadorDeLeis controlador = fabrica.fabricarColisorEquipado();

        CorpoRigidoMovel bola = fabrica.fabricarBola(new Vetor(1, 1));
        controlador.adicionarCorpoRigido(bola);

        CorpoRigidoMovel rP1 = fabrica.fabricarRaqueteDireita();
        CorpoRigidoMovel rP2 = fabrica.fabricarRaqueteEsquerda();

        Jogador player1 = academia.FabricarJogadorDireita(rP1, 0.2);
        Jogador player2 = academia.FabricarJogadorDireita(rP2, 0.2);
        
        controlador.adicionarCorpoRigido(rP1);
        controlador.adicionarCorpoRigido(rP2);

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
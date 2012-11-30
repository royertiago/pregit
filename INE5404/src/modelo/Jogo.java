package modelo;

import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;
import visao.Imagem;
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

    public static void main(String[] args) {
        Jogar (null); //Para debugging
    }
    
    public static void Jogar(Aplique a)
    {
        Coordenada cA = new Coordenada(350, 0),
                   cB = new Coordenada(700, 200),
                   cC = new Coordenada(350, 400),
                   cD = new Coordenada(0, 200);

        AplicadorIneficiente controlador = new AplicadorIneficiente();
        
        ParedeAvancada p1 = new ParedeAvancada(cA, cB);
        ParedeAvancada p2 = new ParedeAvancada(cB, cC);
        ParedeAvancada p3 = new ParedeAvancada(cC, cD);
        ParedeAvancada p4 = new ParedeAvancada(cD, cA);
        /*ParedeDeCima p1 = new ParedeDeCima(cA);
        ParedeDaEsquerda p2 = new ParedeDaEsquerda(cB);
        ParedeDeBaixo p3 = new ParedeDeBaixo(cC);
        ParedeDaDireita p4 = new ParedeDaDireita(cD);*/
        
        CorpoRigidoImovel pA = new CorpoRigidoImovel(p1);
        CorpoRigidoImovel pC = new CorpoRigidoImovel(p3);
        CorpoRigidoImovel pD = new CorpoRigidoImovel(p4);
        CorpoRigidoImovel pB = new CorpoRigidoImovel(p2);
        
        controlador.adicionarCorpoRigido(pA);
        controlador.adicionarCorpoRigido(pB);
        controlador.adicionarCorpoRigido(pC);
        controlador.adicionarCorpoRigido(pD);
        
        Imagem imBola = a != null? new Imagem(a.obterPaginaDix(),origem, "recursos/Bola.png",25, 25) : null;
        Circular mBola = new Circular(new Coordenada(350, 200), 13, 40);
        CorpoRigidoPadrao bola = new CorpoRigidoPadrao(mBola, new Vetor(1, 1), 1);
        if( a != null) bola.adicionarObservador(imBola);
        controlador.adicionarCorpoRigido(bola);
        
        Movimento mov = new Movimento();
        ColisaoSemMomento c = new ColisaoSemMomento();
        controlador.adicionarLei(c);
        controlador.adicionarLei(mov); //TODO: criar uma fachada para o colisor.
        
        System.out.println("Jogo criado");
        
        Pichador alce = a!= null? new Pichador() : null;
        while (!false)
        {
            controlador.aplicarLeis();
            if( a!=null) alce.descansar(0.02);
        }
    }
}

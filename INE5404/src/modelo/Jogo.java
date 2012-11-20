/**
 * Classe "vazia"; simplesmente constrói e executa o jogo.
 */

package modelo;

import visao.Imagem;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;
import static modelo.Coordenada.*;
import modelo.fisico.*;
import modelo.fisico.colisoes.controladorDeColisoes.*;
import modelo.fisico.estruturas.*;
import modelo.fisico.estruturas.mascarasDeColisao.*;

public final class Jogo {
    
    public static void Jogar(Aplique a)
    {
        Imagem imBola = new Imagem(a.obterPaginaDix(),origem,"recursos/bola.png",25, 25);
        
        Circular mBola = new Circular(new Coordenada(350, 200), 13);
        Bola bola = new Bola(mBola, new VetorMovimento(1, 1));

        bola.registrarObservador(imBola);
        
        Parede pA = new Parede(new ParedeDaDireita(new Coordenada(0,200))),
               pB = new Parede(new ParedeDaEsquerda(new Coordenada(700, 200))),
               pC = new Parede(new ParedeDeCima(new Coordenada(350,0))),
               pD = new Parede(new ParedeDeBaixo(new Coordenada(350,400)));
        
        FachadaColisor LHC = new FachadaColisor();
        
        LHC.adicionarObservado(bola);
        LHC.adicionarObservado(pA);
        LHC.adicionarObservado(pB);
        LHC.adicionarObservado(pC);
        LHC.adicionarObservado(pD);
        
        LHC.adicionarEscutador(bola);

        System.out.println("Jogo criado");
        
        Pichador alce = new Pichador();
        while (!false)
        {
            bola.atualizar();
            alce.descansar(0.01);
        }
    }

}

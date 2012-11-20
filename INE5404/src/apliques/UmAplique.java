package apliques;

import java.util.ArrayList;
import java.util.EventObject;

import visao.AdaptadorImagem;
import modelo.Coordenada;
import modelo.Jogo;
import modelo.Lista;
import modelo.ListaLegivel;
import modelo.fisico.*;
import modelo.fisico.colisoes.controladorDeColisoes.ControladorDeColisoes;
import modelo.fisico.estruturas.*;
import static modelo.Coordenada.origem;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.Pichador;

@SuppressWarnings("unused")
public class UmAplique extends Aplique {

	@Override
	public void iniciar() {
	    Jogo.Jogar(this);
	}
	
	static public void main (String args[]) {
	    
	    VetorMovimento v = new VetorMovimento(1, 1);
	    
	    System.out.println(v);
	    v = v.colidirSeCom(0);
	    System.out.println(v);
        v = v.colidirSeCom(0);
        System.out.println(v);
        v = v.colidirSeCom(0);
        System.out.println(v);
    }
	
}
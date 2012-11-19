package apliques;

import java.util.ArrayList;
import java.util.EventObject;

import visao.AdaptadorImagem;
import modelo.Coordenada;
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
	    
	}
	
	static public void main (String args[]) {
	    /*Coordenada a = new Coordenada( 10, 10);
	    Coordenada b = new Coordenada( 20, 10);
	    Coordenada c = new Coordenada( 15, 15);
	    Coordenada d = new Coordenada( 15, 05);
	    MascaraDeColisaoDaParede m = new MascaraDeColisaoDaParede(b, a);
	    System.out.println( m);
	    System.out.println(m.estaDentro(c) );
	    System.out.println(m.estaDentro(d) );*/
	    Coordenada a = new Coordenada(10, 10);
	    System.out.println( Coordenada.origem.obterAnguloCom(a) / Math.PI);
    }
	
}
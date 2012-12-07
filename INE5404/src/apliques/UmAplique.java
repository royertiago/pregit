package apliques;

import modelo.*;
import modelo.RoyerPhysics.*;
import modelo.estruturasDeDados.*;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class UmAplique extends Aplique {

	@Override
	public void iniciar() {
	    ComponenteDix bg = this.obterPaginaDix().criarComponente(TiposDeComponentesDix.IMAGEM, "bg");
	    bg.fixarURI("recursos/bg.png");
	    Jogo.Jogar(this);
	}
	
	static public void main( String[] args)
	{
	    Coordenada[] c = {new Coordenada(10, 4), new Coordenada(10, 4)};
	    Coordenada[] d = {new Coordenada(10, 4), new Coordenada(10, 4)};
	    Tupla<Coordenada[]> t = new Tupla<Coordenada[]>(c, d);
	    System.out.println(t);
	}
}
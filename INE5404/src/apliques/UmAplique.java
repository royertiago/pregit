package apliques;

import modelo.*;
import modelo.RoyerPhysics.*;
import modelo.estruturasDeDados.*;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.TiposDeComponentesDix;

@SuppressWarnings("unused")
public class UmAplique extends Aplique {

	@Override
	public void iniciar() {
	    ComponenteDix bg = this.obterPaginaDix().criarComponente(TiposDeComponentesDix.IMAGEM, "bg");
	    bg.fixarURI("recursos/bg.png");
	    Jogo.Jogar(this);
	}
	
}
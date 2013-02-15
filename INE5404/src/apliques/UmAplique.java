package apliques;

import modelo.Jogo;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class UmAplique extends Aplique {

	@Override
	public void iniciar() {
	    ComponenteDix bg = this.obterPaginaDix().criarComponente(TiposDeComponentesDix.IMAGEM, "bg");
	    bg.fixarURI("recursos/bg.png");
	    Jogo.jogar(this);
	}
	
}
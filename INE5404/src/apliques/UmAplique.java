package apliques;

import controle.ControladorTeclado;
import controle.ControleJogador;
import controle.Tecla;
import modelo.ModeloJogador;
import modelo.RegrasDoJogo;
import modelo.estruturasDeDados.Coordenada;
import modelo.estruturasDeDados.MascaraDeColisao;
import visao.AdaptadorImagem;
import edugraf.jadix.Aplique;
import edugraf.jadix.fachada.*;

public class UmAplique extends Aplique {

	@Override
	public void iniciar() {
	    PaginaDix p = this.obterPaginaDix();
	    Pichador preguica = new Pichador();
	    ComponenteDix teclado = p.criarProcuradorDeComponente("teclado");
	    
	    ControladorTeclado keyboard = new ControladorTeclado();
	    teclado.adicionarTratadorDeEventos(keyboard);
	    
	    ControleJogador kp1 = new ControleJogador(keyboard, Tecla.SHIFT, Tecla.CONTROL);
	    ControleJogador kp2 = new ControleJogador(keyboard, Tecla.SETA_CIMA, Tecla.SETA_BAIXO);
	   
	    RegrasDoJogo regras = new RegrasDoJogo( 10 );
	    
	    Coordenada topo = new Coordenada( 25, 25 );
	    AdaptadorImagem vp1 = new AdaptadorImagem(p, topo, "recursos/Barra1.png", 15, 100);
	    AdaptadorImagem vp2 = new AdaptadorImagem(p, topo, "recursos/Barra2.png", 15, 100);
	    
	    MascaraDeColisao mp1 = new MascaraDeColisao(150, 250, 15,100);
	    MascaraDeColisao mp2 = new MascaraDeColisao(850, 250, 15,100);
	    
	    ModeloJogador p1 = new ModeloJogador(vp1, kp1, mp1, null, regras);
	    ModeloJogador p2 = new ModeloJogador(vp2, kp2, mp2, null, regras);
	    
	    while (true)
	    {
	        p1.autalizarSe();
	        p2.autalizarSe();
	        preguica.descansar(0.02);
	    }    
	        
	}
}
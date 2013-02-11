/**
 * Classe responsável por informar jogadores registrados quais teclas foram pressionadas/soltas.
 * Somente sete teclas são detectadas: Ctrl, Shift, Alt e as setas direcionais. 
 * 
 * @author Tiago Royer
 */

package controle;

import edugraf.jadix.eventos.EventoDeTeclado;
import edugraf.jadix.eventos.nomes.NomeDeEventosDeTeclado;
import edugraf.jadix.fachada.PaginaDix;
import edugraf.jadix.fachada.TratadorDixAbstrato;
import modelo.estruturasDeDados.Lista;

/**
 * Classe responsável por redirecionar eventos de teclado para dentro do jogo.
 * 
 * Atualmente, apenas sete teclas são reconhecidas:
 * <ul>
 * <li>Shift</li>
 * <li>Control</li>
 * <li>Alt</li>
 * <li>Seta Esquerda</li>
 * <li>Seta Cima</li>
 * <li>Seta Direina</li>
 * <li>Seta Baixo</li>
 * </ul>
 * 
 * @author Tiago Royer
 *
 */
public class ControladorTeclado extends TratadorDixAbstrato {

    private Lista<TipoJogador> jogadores = new Lista<TipoJogador>();
    
    /**
     * Cria um controlador de teclado e o registra na página dix.
     * @param p
     */
    public ControladorTeclado( PaginaDix p )
    {
        p.criarProcuradorDeComponente("teclado").adicionarTratadorDeEventos(this);
    }
    
    /**
     * Método que é chamado quando ocorre algum evento do teclado.
     */
    public void seDito(EventoDeTeclado evento) {
        Tecla t = obterTecla(evento.obterTecla());
        if (t== null) return;
        
        if (evento.obterNomeDoEvento() == NomeDeEventosDeTeclado.TECLA_PRESSIONADA)
            anunciarPressionamento(t);
        else if (evento.obterNomeDoEvento() == NomeDeEventosDeTeclado.TECLA_SOLTA)
            anunciarSoltura(t);
    }

    static private Tecla obterTecla( int valor )
    {
        switch (valor)
        {
        case 16:
            return Tecla.SHIFT;
        case 17:
            return Tecla.CONTROL;
        case 18:
            return Tecla.ALT;
        case 37:
            return Tecla.SETA_ESQUERDA;
        case 38:
            return Tecla.SETA_CIMA;
        case 39:
            return Tecla.SETA_DIREITA;
        case 40:
            return Tecla.SETA_BAIXO;
        default:
            return null;
        }
    }
    
    /**
     * Adiciona um TipoJogador, que será avisado do pressionamento e soltura de teclas.
     * @param j
     */
    public void registrarJogador( TipoJogador j ) {
        jogadores.adicionarItem(j);
    }
    
    private void anunciarPressionamento(Tecla t) {
        for( TipoJogador j: jogadores )
            j.informarTeclaPressionada(t);
    }
    
    private void anunciarSoltura(Tecla t) {
        for( TipoJogador j: jogadores )
            j.informarTeclaSolta(t);
    }
    
}

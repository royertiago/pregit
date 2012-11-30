/**
 * Esta classe é responsável por controlar que teclas estão pressionadas num dado momento.
 * 
 * @author Tiago Royer
 */

package controle;

import edugraf.jadix.eventos.EventoDeTeclado;
import edugraf.jadix.eventos.nomes.NomeDeEventosDeTeclado;
import edugraf.jadix.fachada.TratadorDixAbstrato;

public class ControladorTeclado extends TratadorDixAbstrato {

    private boolean[] teclas = new boolean[256];

    // o TratadorDix retorna o código ASCII da tecla pressionada, que varia de 0
    // a 255.

    /**
     * Método que é chamado quando ocorre algum evento do teclado.
     */
    public void seDito(EventoDeTeclado evento) {

        if (evento.obterNomeDoEvento() == NomeDeEventosDeTeclado.TECLA_PRESSIONADA)
            teclas[evento.obterTecla()] = true;
        else if (evento.obterNomeDoEvento() == NomeDeEventosDeTeclado.TECLA_SOLTA)
            teclas[evento.obterTecla()] = false;
    }

    /**
     * Diz se uma tecla está pressionada ou não.
     * 
     * @param codigo
     *            Código ASCII da tecla verificada
     * @return <b>true</b> se a tecla está pressionada, <b>false</b> caso
     *         contrário.
     */
    public boolean estaPressionada(int codigo) {
        return teclas[codigo];
    }

    /**
     * Diz se uma tecla está pressionada ou não.
     * 
     * @param tecla
     *            Tecla que será verificada
     * @return <b>true</b> se a tecla está pressionada, <b>false</b> caso
     *         contrário.
     */
    public boolean estaPressionada(Tecla tecla) {
        return teclas[tecla.obterCodigo()];
    }
}

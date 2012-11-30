/**
 * Classe que fará a conexão entre o ControladorTeclado e EntradasJogador.
 * 
 * @author Tiago Royer
 */

package controle;

import modelo.TipoEntradasJogador;

public class ControleJogador implements TipoEntradasJogador {

    private ControladorTeclado _input;
    private Tecla _teclaSubir, _teclaDescer;
    
    public ControleJogador ( ControladorTeclado input, Tecla teclaSubir, Tecla teclaDescer )
    {
        _input = input;
        _teclaSubir = teclaSubir;
        _teclaDescer = teclaDescer;
    }
    
    @Override
    public boolean comandoSubir() {
        return _input.estaPressionada( _teclaSubir );
    }

    @Override
    public boolean comandoDescer() {
        return _input.estaPressionada( _teclaDescer );
    }

}

package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * Classe abstrata que reduz o problema de aplicar a lei em uma lista de objetos
 * para a aplicação da lei em um objeto por vez.
 * 
 * Para cada CorpoRigido de Campo.corposRigidos, é chamado, uma vez, o método
 * aplicar(CorpoRigidoMovel).
 * 
 * @author Tiago Royer
 * 
 */

public abstract class LeiUnaria implements TipoLei {

    private TipoClockDoCampo _clock;
    @Override
    public void aplicar(TipoClockDoCampo c) {
        _clock = c;
        
        for (CorpoRigidoMovel cr : c.obterCorpos())
            this.aplicarA(cr);
        }

    /**
     * Método interno que será chamado pela superclasse, uma vez para cada
     * objeto. Deve ser implementado na subclasse.
     * 
     * Caso algum dado adicional seja necessário, <code>obtecClockDoCampo()</code>
     * pode ser chamado para obter as informações faltantes.
     * 
     * @param cr Corpo Rígido ao qual a lei será aplicada.
     */
    protected abstract void aplicarA(CorpoRigidoMovel cr);
    
    /**
     * Obtém o clock atual do campo.
     * @return O clock do campo.
     */
    protected final TipoClockDoCampo obterClockDoCampo()
    {
        return _clock;
    }
}

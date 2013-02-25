package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;

/**
 * Classe abstrata que reduz o problema de aplicar a lei em uma lista de objetos
 * para a aplicação da lei em pares de objetos.
 * 
 * Para cada par (E, CR), sendo Estrutura vindo de Campo.estruturas
 * e CorpoRígido vindo de Campo.corposRigidos, o método aplicar(PoligonoEstrutural, CorpoRigidoMovel)
 * é chamado uma vez; para cada par (CR1, CR2), CR1 e CR2 vindos de Campo.corposRigidos, CR1 != CR2,
 * o método aplicar(CorpoRigidoMovel, CorpoRigidoMovel) é chamado, se já não o foi com (CR2, CR1).
 * 
 * @author Tiago Royer
 * 
 */
public abstract class LeiBinaria implements TipoLei  {

    private TipoClockDoCampo _clock;
    
    @Override
    public void aplicar(TipoClockDoCampo c) {
        _clock = c;
        
        for( PoligonoEstrutural p: c.obterEstruturas() )
            for( CorpoRigidoMovel cr: c.obterCorpos() )
                this.aplicarA(p, cr);
        
        for( int i = 0; i < c.obterCorpos().obterTamanho(); i++)
            for( int j = i + 1; j < c.obterCorpos().obterTamanho(); j++)
                this.aplicarA(c.obterCorpos().obter(i),c.obterCorpos().obter(j));
    }

    /**
     * Obtém o clock atual do campo.
     * @return O clock do campo.
     */
    protected final TipoClockDoCampo obterClockDoCampo()
    {
        return _clock;
    }
    
    /**
     * Método interno que será chamado pela superclasse, uma vez para cada
     * par [PolígonoEstrutural - CorpoRigidoMovel]. Deve ser implementado na subclasse.
     * 
     * Caso algum dado adicional seja necessário, <code>obtecClockDoCampo()</code>
     * pode ser chamado para obter as informações faltantes.
     * 
     * @param p Polígono estrutural ao qual a lei será aplicada.
     * @param cr Corpo Rígido ao qual a lei será aplicada.
     */
    public abstract void aplicarA(PoligonoEstrutural p, CorpoRigidoMovel cr);
    
    /**
     * Método interno que será chamado pela superclasse, uma vez para cada
     * par de corpos rígidos distintos. Deve ser implementado na subclasse.
     * 
     * Caso algum dado adicional seja necessário, <code>obtecClockDoCampo()</code>
     * pode ser chamado para obter as informações faltantes.
     * 
     * @param cr1 Primeiro corpo rígido ao qual a lei será aplicada.
     * @param cr2 Segundo corpo rígido ao qual a lei será aplicada.
     */
    public abstract void aplicarA(CorpoRigidoMovel cr1, CorpoRigidoMovel cr2);

}

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

    @Override
    public void aplicar(Campo c, double tempo) {
        
        for( PoligonoEstrutural p: c.estruturas )
            for( CorpoRigidoMovel cr: c.corposRigidos )
                this.aplicar(p, cr, tempo);
        
        for( int i = 0; i < c.corposRigidos.obterTamanho(); i++)
            for( int j = i + 1; j < c.corposRigidos.obterTamanho(); j++)
                this.aplicar(c.corposRigidos.obter(i),c.corposRigidos.obter(j), tempo);
    }
    
    public abstract void aplicar(PoligonoEstrutural p, CorpoRigidoMovel cr, double tempo);
    
    public abstract void aplicar(CorpoRigidoMovel cr1, CorpoRigidoMovel cr2, double tempo);

}

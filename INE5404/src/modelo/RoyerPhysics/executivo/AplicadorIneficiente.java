package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.TipoLei;
import modelo.estruturasDeDados.Lista;
import modelo.estruturasDeDados.Tupla;

/**
 * Classe ineficiente que aplica leis de um ou dois parâmetros aos
 * corpos rígidos passados.
 * 
 * @author Tiago Royer
 * 
 */
public class AplicadorIneficiente implements TipoAplicadorDeLeis {

    Lista<TipoCorpoRigido> cemiterio = new Lista<TipoCorpoRigido>();
    Lista<TipoLei> legislacao = new Lista<TipoLei>();

    @Override
    public void adicionarCorpoRigido(TipoCorpoRigido c) {
        cemiterio.adicionarItem(c);
    }

    @Override
    public void removerCorpoRigido(TipoCorpoRigido c) {
        cemiterio.removerItem(c);
    }

    @Override
    public void adicionarLei(TipoLei l) {
        legislacao.adicionarItem(l);
    }

    @Override
    public void removerLei(TipoLei l) {
        legislacao.removerItem(l);
    }

    @Override
    public void aplicarLeis() {
        for (TipoLei l : legislacao) {
            Lista<Tupla<TipoCorpoRigido>> tuplas = cemiterio.obterTuplasUnicas(l.obterNumeroParametros());
            for( Tupla<TipoCorpoRigido> t: tuplas)
                l.aplicarLei(t);
        }
    }

}

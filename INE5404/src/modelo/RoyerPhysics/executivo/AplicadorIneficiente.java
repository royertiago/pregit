package modelo.RoyerPhysics.executivo;

import java.util.ArrayList;
import java.util.List;

import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.TipoLei;

/**
 * Classe mal-cheirosa que aplica leis de um ou dois parâmetros aos
 * corpos rígidos passados.
 * 
 * @author Tiago Royer
 * 
 */
public class AplicadorIneficiente implements TipoAplicadorDeLeis {

    List<TipoCorpoRigido> cemiterio = new ArrayList<TipoCorpoRigido>();
    List<TipoLei> legislacao = new ArrayList<TipoLei>();

    @Override
    public void adicionarCorpoRigido(TipoCorpoRigido c) {
        cemiterio.add(c);
    }

    @Override
    public void removerCorpoRigido(TipoCorpoRigido c) {
        cemiterio.remove(c);
    }

    @Override
    public void adicionarLei(TipoLei l) {
        legislacao.add(l);
    }

    @Override
    public void removerLei(TipoLei l) {
        legislacao.remove(l);
    }

    @Override
    public void aplicarLeis() {
        for (TipoLei l : legislacao) {
            if (l.obterNumeroParametros() == 1)
            {
                for (TipoCorpoRigido c : cemiterio)
                    l.aplicarLei(c);
            }
            else if (l.obterNumeroParametros() == 2)
            {
                for(int i = 0; i < cemiterio.size(); i++)
                    for( int j = i + 1; j < cemiterio.size(); j++)
                        l.aplicarLei(cemiterio.get(i), cemiterio.get(j));
            }
        }
    }

}

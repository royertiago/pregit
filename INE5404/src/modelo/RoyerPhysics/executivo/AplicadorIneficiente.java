package modelo.RoyerPhysics.executivo;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.TipoCorpoRigido;
import modelo.RoyerPhysics.legislativo.TipoLeiBinaria;
import modelo.RoyerPhysics.legislativo.TipoLeiMoveisBinaria;
import modelo.RoyerPhysics.legislativo.TipoLeiMoveisUnaria;
import modelo.estruturasDeDados.Lista;
import modelo.estruturasDeDados.Tupla;

/**
 * Classe ineficiente que aplica leis de um ou dois parâmetros aos corpos
 * rígidos passados.
 * 
 * @author Tiago Royer
 * 
 */
public class AplicadorIneficiente implements TipoAplicadorDeLeis {

    /**
     * Lista de corpos rígidos móveis.
     */
    protected Lista<CorpoRigidoMovel> corposMoveis = new Lista<CorpoRigidoMovel>();

    /**
     * Lista de corpos rígidos não-móveis.
     */
    protected Lista<TipoCorpoRigido> paredes = new Lista<TipoCorpoRigido>();

    /**
     * Legislação (lista de leis) das leis [U]nárias.
     */
    protected Lista<TipoLeiMoveisUnaria> legislacaoU = new Lista<TipoLeiMoveisUnaria>();

    /**
     * Legislação (lista de leis) das leis [M]óveis binárias.
     */
    protected Lista<TipoLeiMoveisBinaria> legislacaoM = new Lista<TipoLeiMoveisBinaria>();

    /**
     * Legislação (lista de leis) das leis [B]inárias.
     */
    protected Lista<TipoLeiBinaria> legislacaoB = new Lista<TipoLeiBinaria>();

    @Override
    public void adicionarCorpoRigido(CorpoRigidoMovel c) {
        corposMoveis.adicionarItem(c);
    }

    @Override
    public void adicionarCorpoRigido(TipoCorpoRigido c) {
        paredes.adicionarItem(c);
    }

    @Override
    public void removerCorpoRigido(CorpoRigidoMovel c) {
        corposMoveis.removerItem(c);
    }

    @Override
    public void removerCorpoRigido(TipoCorpoRigido c) {
        paredes.removerItem(c);
    }

    @Override
    public void adicionarLei(TipoLeiMoveisUnaria l) {
        legislacaoU.adicionarItem(l);
    }

    @Override
    public void adicionarLei(TipoLeiMoveisBinaria l) {
        legislacaoM.adicionarItem(l);
    }

    @Override
    public void adicionarLei(TipoLeiBinaria l) {
        legislacaoB.adicionarItem(l);
    }

    @Override
    public void removerLei(TipoLeiMoveisUnaria l) {
        legislacaoU.removerItem(l);
    }

    @Override
    public void removerLei(TipoLeiMoveisBinaria l) {
        legislacaoM.removerItem(l);
    }

    @Override
    public void removerLei(TipoLeiBinaria l) {
        legislacaoB.removerItem(l);
    }

    @Override
    public void aplicarLeis() {
        aplicarLeisMoveis(); //As interações primeiro.
        aplicarLeisBinarias();
        aplicarLeisUnarias();
    }

    /**
     * Metodo interne que aplica todas as leis unárias àos objetos.
     */
    protected void aplicarLeisUnarias() {
        for (TipoLeiMoveisUnaria l : legislacaoU)
            for (CorpoRigidoMovel c : corposMoveis)
                l.aplicarLei(c);
    }

    /**
     * Método interno que aplica as leis binárias de corpos móveis aos corpos
     * rígidos.
     */
    protected void aplicarLeisMoveis() {
        Lista<Tupla<CorpoRigidoMovel>> lista = corposMoveis
                .obterTuplasUnicas(2);
        for (TipoLeiMoveisBinaria l : legislacaoM)
            for (Tupla<CorpoRigidoMovel> t : lista)
                l.aplicarLei(t.obter(0), t.obter(1));
    }

    protected void aplicarLeisBinarias() {
        Lista<Tupla<CorpoRigidoMovel>> lista = corposMoveis
                .obterTuplasUnicas(2);
        for (TipoLeiBinaria l : legislacaoB) {
            // Primeiro, vamos aplicar a lei aos pares de corpos rígidos móveis:
            for (Tupla<CorpoRigidoMovel> t : lista)
                l.aplicarLei(t.obter(0), t.obter(1));

            // Agora, entre um corpo móvel e um não móvel:
            for (TipoCorpoRigido d : paredes)
                for (CorpoRigidoMovel c : corposMoveis)
                    l.aplicarLei(c, d);
        }
    }

}

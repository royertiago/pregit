package modelo.RoyerPhysics.leis;

import modelo.RoyerPhysics.CorpoRigidoMovel;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.estruturasDeDados.Lista;

/**
 * O aplicador de leis é responsável por aplicar as leis aos objetos nele
 * registrados.
 * 
 * @author Tiago Royer
 */
public class AplicadorDeLeis implements TipoAplicador {

    private Lista<PoligonoEstrutural> _paredes;
    private Lista<CorpoRigidoMovel> _corpos;
    private Lista<TipoLei> _legislacao;

    public AplicadorDeLeis() {
        _paredes = new Lista<PoligonoEstrutural>();
        _corpos = new Lista<CorpoRigidoMovel>();
        _legislacao = new Lista<TipoLei>();
    }

    @Override
    public void registrarLei(TipoLei l) {
        _legislacao.adicionarItem(l);
    }

    @Override
    public void removerLei(TipoLei l) {
        _legislacao.removerItem(l);
    }

    @Override
    public void registrarCorpo(CorpoRigidoMovel c) {
        _corpos.adicionarItem(c);
    }

    @Override
    public void removerCorpo(CorpoRigidoMovel c) {
        _corpos.removerItem(c);
    }

    @Override
    public void registrarEstrutura(PoligonoEstrutural p) {
        _paredes.adicionarItem(p);
    }

    @Override
    public void removerEstrutura(PoligonoEstrutural p) {
        _paredes.removerItem(p);
    }

    @Override
    public void avancar(double tempo) {
        ClockDoCampo c = new ClockDoCampo(this._corpos, this._paredes, tempo);
        for (TipoLei l : _legislacao)
            l.aplicar(c);
    }

}

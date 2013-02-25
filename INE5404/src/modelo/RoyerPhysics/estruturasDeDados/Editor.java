package modelo.RoyerPhysics.estruturasDeDados;

/**
 * Representa um editor.
 * 
 * Um editor é um objeto que tem acesso direto a um par de um dicionário.
 * 
 * @author Tiago Royer
 * 
 * @param <Tipo>
 *            Tipo do dado a ser manipulado.
 */
public class Editor<Tipo> implements TipoEditor<Tipo> {

    /**
     * Enjambração: a ListaComEditor guarda pares, e, para prover acesso direto
     * ao valor, eu pego o par inteiro.
     */
    private Par<?, Tipo> _par;

    /**
     * Cria um editor com o par escolhido.
     * 
     * @param valor
     */
    public Editor(Par<?, Tipo> valor) {
        _par = valor;
    }

    @Override
    public void alterar(Tipo t) {
        _par.t2 = t;
    }

    @Override
    public Tipo obter() {
        return _par.t2;
    }

    @Override
    public String toString() {
        return "[Editor] " + _par.t2.toString();
    }
}

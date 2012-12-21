package modelo.estruturasDeDados;

/**
 * Representa um Editor. Editor é um objeto que é ligado diretamente à uma lista, mas que
 * só pode alterar um item em específico dela.
 * 
 * O Editor provê acesso total ao item da lista; mas, como é somente um objeto que o editor
 * é capaz de manipular, o restante da lista não pode ser tocado pelo "dono" do editor.
 * 
 * @author Tiago Royer
 *
 * @param <Tipo> Tipo do objeto que pode ser editado.
 */
public interface TipoEditor<Tipo> {

    /**
     * Altera o valor armazenado.
     * 
     * @param t
     *            Novo valor.
     */
    public abstract void alterar(Tipo t);

    /**
     * Extrai (obtém) o valor armazenado.
     * 
     * @return
     */
    public abstract Tipo extrair();

}
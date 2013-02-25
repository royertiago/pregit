package modelo.RoyerPhysics.estruturasDeDados;

/**
 * Representa um Editor. Editor é um objeto que é ligado diretamente a um item
 * de um dicionário, podendo alterar somente aquele item.
 * 
 * @author Tiago Royer
 * 
 * @param <Tipo>
 *            Tipo do objeto que pode ser editado.
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
     * @return O valor armazenado.
     */
    public abstract Tipo obter();

}
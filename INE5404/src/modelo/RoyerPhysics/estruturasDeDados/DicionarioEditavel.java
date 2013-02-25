package modelo.RoyerPhysics.estruturasDeDados;

import java.util.Iterator;

/**
 * Dicionário de dados, que faz uma associação entre uma string e o tipo
 * de dado selecionado.
 * 
 * @author Tiago Royer
 *
 * @param <Valor> Tipo de dado a ser associado com a string.
 */
public class DicionarioEditavel<Valor> implements ListaLegivel<Valor> {

    private Lista<Par<String, Valor>> _mapa;

    /**
     * Enjambração para que esse dicionário possa ser lida com um foreach.
     */
    private Iterator<Par<String, Valor>> _leitorInterno;

    public DicionarioEditavel() {
        _mapa = new Lista<Par<String, Valor>>();
        reiniciarLeitura();
    }

    /**
     * Método interno, que procura a chave especificada no dicionário e retorna o par
     * ordenado correspondente. Caso nada seja encontrado, o valor <b>null</b> é
     * retornado.
     * 
     * @param chave
     *            Chave a ser procurada
     * @return Um par com a chave desejada, se encontrado; ou <b>null</b> caso
     *         contrário.
     */
    protected Par<String, Valor> obterChave(String chave) {
        for (Par<String, Valor> par : _mapa)
            if (par.t1.equals(chave))
                return par;

        return null;
    }

    /**
     * Insere um novo par Chave-Valor no dicionário. Caso a chave já exista,
     * o valor será modificado.
     * 
     * @param chave
     *            Chave do par a ser adicionado.
     * @param v
     *            Valor a ser adicionado.
     */
    public void inserirPar(String chave, Valor v) {
        Par<String, Valor> alce = obterChave(chave);
        if( alce == null )
            _mapa.adicionarItem(new Par<String, Valor>(chave, v));
        else
            alce.t2 = v;
    }

    /**
     * Descobre se um par com a chave <b>chave</b> existe no dicionário.
     * 
     * @param chave
     *            Chave a ser testada.
     * @return <b>true</b> se a chave foi encontrada, <b>false</b> caso
     *         contrário.
     */
    public boolean existeChave(String chave) {
        return obterChave(chave) != null;
    }

    /**
     * Retorna um Editor apontando para o par cuja chave seja igual a
     * <b>chave</b>.
     * 
     * Caso a chave não seja encontrada, será retornado <b>null</b>.
     * 
     * @param chave
     *            Chave a ser buscada.
     * @return Um Editor apontando para o par desejado.
     */
    public TipoEditor<Valor> obterEditor(String chave) {
        Par<String, Valor> p = obterChave(chave);
        if (p == null)
            return null;
        else
            return new Editor<Valor>(p);
    }
    
    /**
     * Converte o dicionário atual para uma Lista, descartando as chaves.
     * @return Lista<Valor> com apenas os valores dessa lista.
     */
    public Lista<Valor> paraLista()
    {
        Lista<Valor> alce = new Lista<Valor>();
        for( Valor v: this)
            alce.adicionarItem(v);
        
        return alce;
    }

    @Override
    public Iterator<Valor> iterator() {
        return new IteradorLista<Valor>(this);
    }

    @Override
    public void reiniciarLeitura() {
        _leitorInterno = _mapa.iterator();
    }

    @Override
    public boolean fimDaLista() {
        return !_leitorInterno.hasNext();
    }

    @Override
    public Valor obterProximoItem() {
        Par<String, Valor> alce = _leitorInterno.next();
        return alce.t2;
    }

    @Override
    public int obterTamanho() {
        return _mapa.obterTamanho();
    }

    @Override
    public Valor obter(int indice) {
        return _mapa.obter(indice).t2;
    }
}

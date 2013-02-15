package modelo.RoyerPhysics;

import modelo.RoyerPhysics.estruturasDeDados.TipoEditor;

/**
 * Representa um conjunto de forças atuando sobre um objeto. As forças são
 * manipuladas separadamente.
 * 
 * @author Tiago Royer
 */
public interface TipoConjuntoDeForcas {

    /**
     * Cria um editor para a força de nome <b>nome</b>. Caso nenhuma força com
     * esse nome exista, será criado uma força nula, com esse nome, e um editor
     * para essa força será retornado.
     * 
     * @param nome Nome da força a ser manipulada.
     * @return um editor para a força.
     */
    public abstract TipoEditor<Vetor> obterForca(String nome);

    /**
     * Retorna um vetor que representa a soma de todas as forças aplicadas.
     * 
     * @return o somatório das forças.
     */
    public abstract Vetor obterSomatorioForcas();

}
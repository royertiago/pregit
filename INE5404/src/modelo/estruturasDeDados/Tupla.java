package modelo.estruturasDeDados;

/**
 * Classe que representa uma tupla ordanada.
 * 
 * @author Tiago Royer
 * 
 * @param <Tipo>
 *            Classe dos objetos que formarão a tupla.
 */
public class Tupla<Tipo> {

    private Tipo[] objetos;

    /**
     * Cria uma tupla ordenada com os elementos passados.
     * 
     * @param o
     *            Elementos a serem postos na tupla.
     */
    public Tupla(Tipo... o) {
        objetos = o.clone();
    }

    /**
     * Obtém o objeto do tipo <b>Tipo</b> que está no índice <b>indice</b>.
     * 
     * @param indice
     *            Índice do objeto.
     * 
     * @return O referido objeto.
     */
    public Tipo obter(int indice) {
        return objetos[indice];
    }

    /**
     * Obtém o tamanho da tupla.
     * 
     * @return
     */
    public int tamanho() {
        return objetos.length;
    }
    
    public String toString()
    {
        String out = " - ";
        for( int i = 0; i < tamanho(); i++)
            out = out + objetos[i] + " - ";
        
        return out;
    }

}

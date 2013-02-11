/**
 * Representa uma tecla.
 *  
 * @author Tiago Royer
 */

package controle;

public enum Tecla {

    SHIFT(16), CONTROL(17), ALT(18),

    SETA_ESQUERDA(37), SETA_CIMA(38), SETA_DIREITA(39), SETA_BAIXO(40);

    private int _codigo;

    Tecla(int codigo) {
        _codigo = codigo;
    }

    /**
     * Retorna o código ASCII da tecla selecionada.
     * 
     * @return O código ASCII da tecla selecionada.
     */
    protected int obterCodigo() {
        return _codigo;
    }
}

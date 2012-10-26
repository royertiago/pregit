/**
 * Classe genérica que representa um obeto capaz de colidir.
 * 
 * @author Tiago Royer 
 */
package modelo;

import modelo.estruturasDeDados.MascaraDeColisao;

public abstract class ObjetoColisor extends ObjetoDoJogo {

    protected MascaraDeColisao mascara;
    private ControladorDeColisoes _colisoes;

    public ObjetoColisor(MascaraDeColisao mascara,
            ControladorDeColisoes colsoes, RegrasDoJogo regras) {
        super(regras);
        this.mascara = mascara;
        _colisoes = colsoes;
    }

    /**
     * Quando a máscara de colisão de dois objetos se sobrepõem, o controlador
     * de colisões chamará, de cada objeto envolvido, o método <b>colidir</b>, e
     * cada objeto decide como reagirá à sobreposição. Por exemplo, pode haver
     * um teste se, de fato, os objetos estão colidindo.
     * 
     * @param alvo
     *            Objeto que colidirá contra este.
     */
    public abstract void colidir(ObjetoColisor alvo);

    /**
     * Método que determina se dois objetos colisores estão sobrepostos.
     * 
     * @param alvo
     *            Objeto contra o qual será testada sobreposição.
     * @return <b>true</b> se estão sobrepostos, <b>false</b> caso contrário.
     */
    public final boolean estaSobreposto(ObjetoColisor alvo) {
        return mascara.estaSobreposto(alvo.mascara);
    }
}

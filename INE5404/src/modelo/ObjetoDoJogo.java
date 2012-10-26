/**
 * Classe abstrata que representa um objeto no campo de jogo.
 * 
 * @author Tiago Royer
 */

package modelo;

public abstract class ObjetoDoJogo {

    protected RegrasDoJogo regras;

    public ObjetoDoJogo (RegrasDoJogo regras)
    {
        this.regras = regras;
    }
    
    public abstract void autalizarSe();

}

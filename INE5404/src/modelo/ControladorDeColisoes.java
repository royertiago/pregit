/**
 * Classe responsável por gerenciar as colisões do jogo.
 * Toda vez que dois objetos estão sobrepostos, o controlador chama o método <b>colidir</b>
 * de cada um deles.
 * 
 * @author Tiago Royer
 */
package modelo;

import java.util.List;

import modelo.estruturasDeDados.MascaraDeColisao;

public class ControladorDeColisoes {

    private List<ObjetoColisor> _listaObjetosColisores; //TODO: pensar num nome melhor
    private RegrasDoJogo _regras;

    public ControladorDeColisoes ( RegrasDoJogo regras )
    {
        _regras = regras;
    }
    
    /**
     * Decide se o objeto pode se mover para a posição desejada.
     * 
     * @param objeto O objeto a ser movido
     * @param pasicao A nova posição da máscara de colisão do objeto
     * @return
     */
    public boolean posicaoValida (MascaraDeColisao posicao)
    {
        return true;  //TODO: implementar teste
    }
    
}
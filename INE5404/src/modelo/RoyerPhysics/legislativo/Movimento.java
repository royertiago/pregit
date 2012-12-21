package modelo.RoyerPhysics.legislativo;

import modelo.RoyerPhysics.CorpoRigidoMovel;

/**
 * É uma lei que vai atualizar as posições dos corpos, de acordo com o tempo
 * passado.
 * 
 * @author Tiago Royer
 * 
 */
public class Movimento extends LeiUnariaTemporal {

    /**
     * Cria uma lei de movimento.
     * 
     * @param tempo
     *            Tempo que deve passar entre as atualizações.
     */
    public Movimento(double tempo) {
        super(tempo);
    }

    @Override
    public void aplicarLeiA(CorpoRigidoMovel c) {
        c.mover(_tempo);
    }

}

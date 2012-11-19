package modelo.fisico.colisoes;

import modelo.fisico.ObservadoFisico;

public class Colisao {

    public static final Colisao semColisao = new Colisao(0, null, null);
    
    public final ObservadoFisico colisor1, colisor2;
    public final double angulo;
    
    public Colisao(double angulo, ObservadoFisico colisor1, ObservadoFisico colisor2) {
        this.colisor1 = colisor1;
        this.colisor2 = colisor2;
        this.angulo = angulo;
    }

    public String toString()
    {
        if( this == semColisao )
            return "Sem Colisao";
        else
            return "Colisao de ângulo " + angulo + " com os colisores: \n" + colisor1 + "\n" + colisor2;
    }
    
}

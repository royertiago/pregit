package modelo.RoyerPhysics.poligonos;

import modelo.RoyerPhysics.AABB;
import modelo.RoyerPhysics.Coordenada;
import modelo.RoyerPhysics.TipoPoligonoConvexo;
import modelo.RoyerPhysics.PoligonoEstrutural;
import modelo.RoyerPhysics.estruturasDeDados.Lista;
import modelo.RoyerPhysics.estruturasDeDados.ListaLegivel;

/**
 * Representa uma parede, que divide o plano em dois; é como se fosse um
 * polígono infinito.
 * 
 * @author Tiago Royer
 * 
 */
public class Parede implements PoligonoEstrutural {

    public Coordenada pA, pB;

    /**
     * Cria uma máscara de colisão de uma parede.
     * 
     * A parede possui dois pontos, pelos quais passa uma reta, que divide o
     * plano em dois. Na direção de pA a pB, girando Pi/2 em sentido
     * anti-horário, têm-se o lado no qual será considerado dentro da máscara.
     * 
     * Por exemplo, se pA = (0, 0) e pB = (1, 0), será considerado dentro da
     * máscara os pontos acima do eixo X. Mas, se pA = (1, 0) e pB = (0, 0)
     * (invertendo pA e pB), são os pontos abaixo do eixo X que serão
     * considerados dentro da máscara.
     * 
     * @param pA
     *            primeiro ponto pelo qual passa a parede
     * @param pB
     *            segundo ponto.
     */
    public Parede(Coordenada pA, Coordenada pB) {
        this.pA = pA;
        this.pB = pB;
    }

    @Override
    public boolean contem(Coordenada c) {
        return c.girarEmTornoDe(pA, -pA.obterAnguloCom(pB)).y < pA.y;
        // Eu giro o ponto em torno de A, em sentido horário, no ângulo
        // da reta. Se após esse giro o ponto estiver acima do pA, significa
        // que ele estava do lado correto antes de girar, então retorno true.
    }

    public ListaLegivel<Coordenada> obterPontosExtremidades() {
        Lista<Coordenada> l = new Lista<Coordenada>();
        return l;
    }

    @Override
    public double anguloColisao(Coordenada p) {
        return pA.obterAnguloCom(pB);
    }

    @Override
    public String toString() {
        return "Parede: " + pA + " -> " + pB;
    }

    @Override
    public Coordenada obterIntersecao(TipoPoligonoConvexo p) {
        ListaLegivel<Coordenada> l = p.obterPontosExtremidades();
        for (Coordenada c : l)
            if (this.contem(c))
                return c;

        return null;
    }

    @Override
    public boolean contem(AABB box) {
        ListaLegivel<Coordenada> l = box.obterExtremidades();
        for(Coordenada c: l)
            if( this.contem(c))
                return true;
        
        return false;
    }

}

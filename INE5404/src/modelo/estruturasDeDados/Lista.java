/**
 * Representa uma lista, que pode ser lida sequencialmente e adicionar
 * novos valores no final.
 */

package modelo.estruturasDeDados;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Lista<Tipo> implements ListaLegivel<Tipo> {
    
    private List<Tipo> lista;
    private Iterator<Tipo> leitor;

    /**
     * Cria uma nova lista.
     */
    public Lista() {
        lista = new ArrayList<Tipo>();
    }

    @Override
    public void reiniciarLeitura() {
        leitor = lista.iterator();
    }

    @Override
    public boolean fimDaLista() {
        return !leitor.hasNext();
    }

    @Override
    public Tipo obterProximoItem() {
        return leitor.next();
    }

    @Override
    public Iterator<Tipo> iterator() {
        return new IteradorLista<Tipo>(this);
    }

    /**
     * Adiciona um novo item na lista.
     * 
     * @param i
     *            item a ser adicionado.
     */
    public void adicionarItem(Tipo i) {
        lista.add(i);
    }

    /**
     * Remove a primeira ocorrência do item <b>i</b> da lista.
     * 
     * Caso o item não exista, nada é feito.
     * 
     * @param i
     *            Item a ser removido.
     */
    public void removerItem(Tipo i) {
        lista.remove(i);
    }

    @Override
    public Lista<Tupla<Tipo>> obterTuplasUnicas (int t)
    {
        int n = this.obterTamanho();
        
        if( t > n )
            throw new IllegalArgumentException("O tamanho das tuplas deve ser menor que o tamanho da lista. ");
        
        int[] i = new int[t]; //Lista de iteradores.
        
        int alce; //Auxiliar.
        
        for( int j = 0; j < t; j++ )
            i[j] = j;
        //Começamos com os índices dos iteradores apontados para o primeiro objeto a ser adicionado.
        
        @SuppressWarnings("unchecked")
        Tipo[] o = (Tipo[]) new Object[t]; //Gambiarra para poder criar um array de <Tipo>.

        Lista<Tupla<Tipo>> lista = new Lista<Tupla<Tipo>>();
        
        while(!false) //quebraremos depois
        {
            for( int j = 0; j < t; j++ )
                o[j] = this.obter(i[j]);
            //Agora, "o" contém os elementos cujos índices dos iteradores apontavam; então,
            // vamos adicionar uma nova tupla â lista.
            lista.adicionarItem(new Tupla<Tipo>(o));
            
            //Agora, vamos avançar uma posição.
            
            /*Supondo que chegamos aqui com "i" = (2 4 7 8 9):
             *Se o tamanho da lista for 15, o próximo passo é adicionar o ítem (2 4 7 8 10).
             *Mas, se o tamanho for 10, o próximo é (2 5 6 7 8). Vamos procurar o elemento
             *que deve ser avançado (no caso anterior, era o 4). */
            
            alce = -1;
            
            for( int j = 0; j < t; j++ )
                if( i[t - j - 1] != n - j - 1)
                {
                    alce = t - j - 1;
                    break;
                }
            /* Suponha n = 11, t = 4 e i = (2 4 9 10). Note que:
             * j:       3   2   1   0  (estamos acessando de trás para frente)
             * t-j-1:   0   1   2   3
             * i[t-j-1]:2   4   9   10
             * Repare que 10 == 11 - 0 - 1 == n - j - 1;
             *             9 == 11 - 1 - 1 == n - j - 1;
             * mas que:    4 != 11 - 2 - 1 == n - j - 1.
             * Portanto, o número que deve ser alterado é o primeiro tal que
             * i[t - j - 1] != n - j - 1.
             * Mas, caso não haja tal valor, significa que todos os valores
             * estão em seu estado final (7 8 9 10 no caso), então não há mais
             * tuplas a adicionar. Quando isso ocorre, o alce não é alterado: */
            
            if( alce == -1 )
                break; //Então saímos do laço.
            else {
              //Caso contrário, devemos avançar a posição:
                i[alce]++;
                for( int j = 1; j + alce < t; j++)
                    i[j+alce] = i[alce] + j;
            }
            /* No exemplo (2 4 9 10), alce = 1. i[alce] = 4, então i[alce]++ o coloca para 5.
             * Agora, quero pôr os demais para (2 5 6 7). Note que:
             * j:           0   1   2
             * i[j+alce]:   5   9   10
             * i[alce] + j: 5   6   7 (que são os valores corretos).
             */

            //Prontos para mais uma etapa!
        }
        return lista;
    }
    
    /**
     * Método que retorna o elemento do <b>índice</b> da lista.
     * @param indice Índice do elemento.
     * @return O elemento referido.
     */
    public Tipo obter( int indice )
    {
        return lista.get(indice);
    }
    
    /**
     * Método que informa o tamanho da lista.
     * 
     * @return o tamanho da lista.
     */
    public int obterTamanho() {
        return lista.size();
    }
    
    @Override
    public String toString() {
        String out = "";
        for (Tipo t : lista)
            out = out + t + "\n";

        return out;
    }
}

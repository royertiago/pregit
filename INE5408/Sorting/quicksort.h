// Ordenaremos os primeiros <tamanho> elementos.
template <typename T>
void quicksort( T* vetor, int tamanho ) {
    int stack[tamanho];
    int topo = 0;
    // Conven��o: stack[topo] � o �ltimo lugar ocupado.

    int ultimo = tamanho;
    // Invariante 1: o intervalo [ultimo, tamanho) j� est� ordenado

    stack[topo] = -1; //Sentinela.

    /* Ao ordenar o intervalo [a, b], o quicksort separa o intervalo
     * em dois subintervalos [a, c-1] e [c+1, b], que precisam ser
     * ordenados. Iremos armazenar na pilha o valor c.
     *
     * Sabemos qual � o segundo subintervalo pela variavel ultimo.
     *
     * Invariante 2: 
     *  a) se c est� na pilha, vetor[c] j� est� na posi��o correta. 
     *  b) se c est�, garantidamente, na posi��o correta, e c < ultimo,
     *     c est� na pilha. */

    while( ultimo > 0 ) { //Assim que ultimo == 0, j� teremos ordenado.
        int a = stack[topo] + 1;
        int b = ultimo - 1;
        // A cada itera��o, "ordenaremos" o subvetor [a, b].
        
        if( b - a < 1 ) {
            /* Neste caso, [a, b] tem um ou nenhum elemento; j� est�
             * ordenado, portanto. Como b == ultimo, o intervalo
             * {a-1} U [a, b] U [b, tamanho) = [a - 1, tamanho)
             * passa a estar ordenado ({a-1} pela invariante 2a,
             * [b, tamanho) pela 1), e, para manter a invariante 1,
             * atualizamos ultimo. */
            ultimo = a - 1; //a - 1 == stack[topo]
            topo--; //N�o precisaremos mais do topo.
            continue;
        }

        T pivo = vetor[a]; //Heuristica complexa de escolha do piv�.

        int i = a + 1;
        int j = b;

        /* Agora, queremos fazer com que [a+1, i] <= pivo < [j, b],
         * com i + 1 == j, ou seja, pivo deve assumir a posi��o i.
         * (isto �, os valores dos intervalos)
         *
         * Invariante 3:
         * [a+1, i-1] <= pivo < [j+1, b], i < j
         * vetor[i] > pivo >= vetor[j]
         * i <= j
         *
         * Primeiro, garantiremos-na verdadeira antes do la�o. */
        while( vetor[i] <= pivo && i < j ) {
            i++;
        }

        while( pivo < vetor[j] && i < j ) {
            j--;
        }

        while( i <= j ) {
            T alce = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = alce;

            while( vetor[i] <= pivo && i <= j )
                i++;

            while( pivo < vetor[j] && i <= j )
                j--;

        }
        /* Note que, aqui, i == j + 1. A �ltima cl�usula da invariante
         * foi perdida; as demais n�o. A primeira cl�usula garante que
         * todos os elementos menores ou iguais ao piv� est�o no inter-
         * valo [a+1, j] (pois j == i-1), ent�o podemos trocar pivo
         * com vetor[j], de forma que [a, j-1] < [j] < [j+1, b], alcan-
         * �ando a biparti��o desejada. */
        vetor[a] = vetor[j];
        vetor[j] = pivo;
        stack[++topo] = j;
    }
}

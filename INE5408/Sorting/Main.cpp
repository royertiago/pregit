#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#include "quicksort.h"

int main()
{
    // Trecho copiado descaradamente do exemplo do Aldo.
    double *a, *ptr;
    struct timeb tempoInicial, tempoFinal;
    int i, tamanho;
    FILE   *arquivo;
    arquivo = fopen("arquivo.dat.txt", "r");
    fscanf(arquivo, "%d", &tamanho);
    a = (double*) malloc(tamanho * sizeof(double));
    printf("%d\t\t", tamanho);
    for (i=1; i <= tamanho; i++)
    {
        fscanf(arquivo, "%lf", &a[i-1]);
    }
    /*-------------------*/
    ftime( &tempoInicial );
    quicksort( a, tamanho );
    ftime( &tempoFinal );
    /*-------------------*/

    free(a);
    printf(" %ld \n", tempoFinal.time - tempoInicial.time );
    fclose(arquivo);
}

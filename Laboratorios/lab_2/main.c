#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "insertion_sort.h" // Inclua o metodo que deseja usar para ordenar;

extern void sort(Item *a, int lo, int hi);

int main(){
    
    clock_t start = clock();

    int numItens=0;

    printf("Digite o numero de itens a ser ordenado:\n");
    scanf("%d", &numItens);

    Item *itens = (Item*) malloc(sizeof(Item)*numItens);

    printf("Digite os numeros do array:\n");
    for(int i=0; i < numItens; i++) scanf("%d", &itens[i]);

    sort(itens,0, numItens-1);

    for(int i=0; i < numItens; i++) printf("%d ", itens[i]);

    printf("\n");
     
    free(itens);

    clock_t end = clock();

    double tempoExec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempoExec); 
    
    return 0;
}
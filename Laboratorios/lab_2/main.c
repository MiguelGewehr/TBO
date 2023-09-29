#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "insertion_sort.h" // Inclua o metodo que deseja usar para ordenar;

extern void sort(Item *a, int lo, int hi);

void arr_read(char *path, Item *itens);

int main(int argc, char *argv[]){
    
    clock_t start = clock();
    
    int numItens=0;

    printf("Digite a quantidade de itens no arquivo escolhido:\n");
    scanf("%d", &numItens);

    Item *itens = (Item*) malloc(sizeof(Item)*numItens);

    arr_read(argv[1], itens);

    sort(itens,0, numItens-1);

    for(int i=0; i < numItens; i++) printf("%d ", itens[i]);

    printf("\n");
     
    free(itens);

    clock_t end = clock();

    double tempoExec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempoExec); 
    
    return 0;
}

void arr_read(char *path, Item *itens){

    FILE *arq = fopen(path, "r");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int i=0;

    while(fscanf(arq,"%d", &itens[i]) == 1){
        i++;
    }
    
    fclose(arq);
}
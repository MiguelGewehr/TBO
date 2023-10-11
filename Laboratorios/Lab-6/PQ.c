#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

struct pq{
    Event **arr;
    int size;
    int capacity;
};


/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    
    PQ *pq = (PQ*) malloc(sizeof(PQ));

    pq->capacity = max_N;
    pq->size = 0;
    
    pq->arr = (Event**) malloc(sizeof(Event*)*pq->capacity);

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    
    for(int i=0; i < pq->size; i++)
        destroy_event(pq->arr[i]);

    free(pq->arr);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void _swap(PQ*pq, int idx1, int idx2){

    Event *aux = pq->arr[idx1];

    pq->arr[idx1] = pq->arr[idx2];

    pq->arr[idx2] = aux;  
}

void _heapfy_up(PQ *pq, int idx){
    
    int pai = idx/2;

    while(idx > 0 && get_time(pq->arr[idx]) < get_time(pq->arr[pai])){
        
        _swap(pq, idx, pai);

        idx = pai;
        pai = idx/2;
    }
    
    
    
}

void PQ_insert(PQ *pq, Event *e) {

    if(pq->size == pq->capacity){
        pq->capacity *= 2;
        pq->arr = realloc(pq->arr, pq->capacity);
    }

    pq->arr[pq->size++] = e;

    _heapfy_up(pq, pq->size-1);
}

void heapfy_down(PQ *pq, int idx){

    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;
    int smallest = idx;

    if(left_child < pq->size && get_time(pq->arr[left_child]) < get_time(pq->arr[smallest]))
        smallest = left_child;
    if(right_child < pq->size && get_time(pq->arr[right_child]) < get_time(pq->arr[smallest]))
        smallest = right_child;
    
    if(smallest != idx){
        _swap(pq, idx, smallest);
        heapfy_down(pq, smallest);
    }
    

}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    
    Event *data = pq->arr[0];

    _swap(pq, 0, pq->size-1);
    pq->size--;

    heapfy_down(pq, 0);

    return data;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    return pq->size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->size;
}

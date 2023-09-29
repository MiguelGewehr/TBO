#include "shaker_sort.h"

/*void sort(Item *a, int lo, int hi){

    int swapped;

    for(int i=lo; i <= hi-1; i++){
        swapped = 0;
        for(int j=lo; j <= hi-i -1; j++){
            compexch(a[j], a[j+1]);
            swapped = 1;
        }
        for(int j=hi; j >= lo + i + 1; j--){
            compexch(a[j-1], a[j]);
            swapped = 1;
        }
        if(!swapped)
            break;
    }
}*/
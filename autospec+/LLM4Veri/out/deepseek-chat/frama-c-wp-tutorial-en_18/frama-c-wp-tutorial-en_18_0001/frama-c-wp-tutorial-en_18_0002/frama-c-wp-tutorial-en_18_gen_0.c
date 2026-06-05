#include <stddef.h>
#include <limits.h>
/*@
requires \valid(array + (0..length-1));
ensures \result == NULL ==> \forall integer i; 0 <= i < length ==> array[i] != element;
ensures \result != NULL ==> (\exists integer i; 0 <= i < length && array[i] == element && \result == &array[i]);
assigns \nothing;
*/
int* search(int* array, size_t length, int element){
    /*@
    loop invariant i <= length;
    loop invariant \forall integer k; 0 <= k < i ==> array[k] != element;
    loop invariant 0 <= i;
    loop assigns i;
    */
    for(size_t i = 0; i < length; i++){
        if(array[i] == element) return &array[i];
    }
    return NULL;
}
int main(){
    int array[] = {1,2,3,4,5};
    int *p = search(array,5,6);
    // @ assert p == NULL;
}
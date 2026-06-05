#include <assert.h>
#define SIZE 5
int array[SIZE];
int n=SIZE;
/*@
requires n == SIZE;
requires \valid(array+(0..n-1));
assigns array[0..n-1];
*/
void SelectionSort()
{
   int lh, rh, i, temp;
   /*@
   loop invariant \forall integer p, q; 0 <= p < lh <= q < n ==> array[p] <= array[q];
   loop invariant 0 <= lh;
   loop assigns temp;
   loop assigns rh;
   loop assigns lh;
   loop assigns i;
   loop assigns array[0..n-1];
   */
   for (lh = 0; lh < n; lh++) {
      rh = lh;
      /*@
      loop invariant rh < n;
      loop invariant lh <= rh;
      loop invariant lh < i;
      loop invariant i <= n;
      loop invariant \forall integer p, q; 0 <= p < lh <= q < n ==> array[p] <= array[q];
      loop invariant \forall integer k; lh <= k < i ==> array[k] >= array[rh];
      loop invariant \forall integer k; 0 <= k < lh ==> array[k] <= array[lh];
      loop assigns rh;
      loop assigns i;
      */
      for (i = lh + 1; i < n; i++) 
         if (array[i] < array[rh]) rh = i;
      temp = array[lh];
      array[lh] = array[rh];
      array[rh] = temp;
   }
}
int main(void){
	int array[SIZE],i;
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; i <= k < SIZE ==> array[k] == k;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns array[0..SIZE-1];
	*/
	for(i=SIZE-1; i>=0; i--)
		array[i]=i;
	SelectionSort();
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> array[k] == k;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i=0; i<SIZE; i++){
		//@ assert(array[i]==i);
   }
}

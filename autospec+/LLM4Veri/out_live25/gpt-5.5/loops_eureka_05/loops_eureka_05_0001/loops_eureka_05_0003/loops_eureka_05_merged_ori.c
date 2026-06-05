#include <assert.h>
#define SIZE 5
int array[SIZE];
int n=SIZE;
/*@
requires n == SIZE;
ensures \forall integer i, j; 0 <= i <= j < n ==> array[i] <= array[j];
assigns array[0..n-1];
*/
void SelectionSort()
{
   int lh, rh, i, temp;
   /*@
   loop invariant \forall integer p, q; 0 <= p < q < lh ==> array[p] <= array[q];
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
      loop invariant rh < i;
      loop invariant lh <= rh;
      loop invariant lh + 1 <= i;
      loop invariant i <= n;
      loop invariant \forall integer k; lh <= k < i ==> array[rh] <= array[k];
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
	for(i=SIZE-1; i>=0; i--)
		array[i]=i;
	SelectionSort();
	for(i=0; i<SIZE; i++){
		// @ assert(array[i]==i);
   }
}

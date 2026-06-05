/*@ 
   requires \valid(&a[i]);
    requires \valid(&a[j]);
    assigns a[i], a[j];
    ensures a[i] == \old(a[j]);
    ensures a[j] == \old(a[i]);
 */
void swap(int a[], int i, int j);
void reverse_in_place(int a[], int size)
{
   int i;
   /*@
   loop invariant \forall integer k; 0 <= k < i ==> a[k] == \old(a[size - 1 - k]);
   loop invariant \forall integer k; size - i - 1 < k < size ==> a[k] == \old(a[size - 1 - k]);
   loop invariant \forall integer k; i <= k < size - i ==> a[k] == \old(a[k]);
   loop invariant 0 <= i <= size/2;
   loop invariant i <= size/2;
   loop invariant \forall integer k; size - i - 1 < k < size ==> a[k] == \old(a[size - 1 - k]);
   loop invariant \forall integer k; i <= k < size - i ==> a[k] == \old(a[k]);
   loop invariant \forall integer k; 0 <= k < i ==> a[k] == \old(a[size - 1 - k]);
   loop invariant \forall integer j; size - i <= j < size ==> a[j] == \old(a[size - 1 - j]);
   loop invariant \forall integer j; i <= j < size - i ==> a[j] == \old(a[j]);
   loop invariant \forall integer j; 0 <= j < i ==> a[j] == \old(a[size - 1 - j]);
   loop invariant 0 <= i;
   loop assigns i;
   loop assigns a[0..size-1];
   */
   for(i = 0; i < (size / 2); ++i) {
      swap(a, i, size - i - 1);
   }
}
#ifdef OUT_OF_TASK
#include <stdio.h>
int main(void)
{
   int a[] = {1,2,3,4,5,6,7,8,9,10};
   int size = sizeof(a) / sizeof(a[0]);
   // @ assert a[0] == 1;
   reverse_in_place(a, size);
   // @ assert a[0] == 10;
}
#endif
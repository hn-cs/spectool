#include<stddef.h>
/*@
requires \valid(array+(0..length-1));
ensures \forall integer i; 0 <= i < length ==> array[i] == 0;
assigns array[0..length-1];
*/
void reset(int* array,size_t length)
{
    /*@
    loop invariant i <= length;
    loop invariant \forall integer j; 0 <= j < i ==> array[j] == 0;
    loop invariant 0 <= i;
    loop assigns i;
    loop assigns array[0..length-1];
    */
    for(size_t i =0;i<length;i++)   
  {
    array[i] = 0;
  }
} 
void main()
{
  int a[6] = {4,6,3,6,7,89};
  reset(a,6);
  //@ assert \forall integer i; 0<= i < 6 ==> a[i] == 0;
}
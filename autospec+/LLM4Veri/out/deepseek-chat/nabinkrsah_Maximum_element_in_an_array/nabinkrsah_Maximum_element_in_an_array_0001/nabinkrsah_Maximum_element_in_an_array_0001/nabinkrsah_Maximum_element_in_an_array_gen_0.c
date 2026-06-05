#include<limits.h>
int Max_in_Array(int arr[],int n)
{
 int max=arr[0];
 /*@
 loop invariant 0 <= j <= n;
 loop invariant \forall integer k; 0 <= k < j ==> max >= arr[k];
 loop invariant \exists integer k; 0 <= k < j && max == arr[k];
 loop invariant max == arr[0] || (\exists integer k; 0 <= k < j && max == arr[k]);
 loop assigns max;
 loop assigns j;
 */
 for(int j=0;j<n;j++)
 {
 if(arr[j]>max)
 {
 max=arr[j];
 }
 }
 return max;
}
int main()
{
int n=5;
int arr[]={50,44,33,2,88};
int k=Max_in_Array(arr,n);
// @ assert \forall integer i; 0<=i<n ==> k>=arr[i];
}
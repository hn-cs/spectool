#include <limits.h>
/*@
requires n >= 0;
requires \valid_read(a + (0..n-1));
requires \valid_read(b + (0..n-1));
assigns \nothing;
ensures \result == 1 <==> \forall integer k; 0 <= k < n ==> a[k] == b[k];
ensures \result == 0 <==> \exists integer k; 0 <= k < n && a[k] != b[k];
*/
int equ(int a[], int b[], int n)
{
    /*@
    loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
    loop invariant 0 <= i;
    loop assigns i;
    */
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10]={1,2,3,4,5,6,7,8,9,10};
    int c[10]={1,2,3,4,5,6,7,8,9,11};

    int res=equ(a,b,10);
    int res1=equ(a,c,10);
    // @ assert res==1;
    // @ assert res1==0;
}
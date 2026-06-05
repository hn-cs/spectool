#include <limits.h>
int equ(int a[], int b[], int n)
{
    /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
    loop assigns i;
    loop variant n - i;
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
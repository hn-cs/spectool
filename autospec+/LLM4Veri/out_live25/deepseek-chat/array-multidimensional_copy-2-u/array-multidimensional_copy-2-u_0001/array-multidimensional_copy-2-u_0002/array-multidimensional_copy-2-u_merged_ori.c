#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j;
	int n=1000;
	int A [1000][1000];
        int B [1000][1000];
	i=0;
	j=0;
	/*@
	loop invariant j <= n;
	loop invariant i <= n;
	loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre);
	loop invariant \forall integer k; 0 <= k < i ==> (\forall integer l; 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre));
	loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre);
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns B[0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		/*@
		loop invariant n - j;
		loop invariant j <= n;
		loop invariant \forall integer k; 0 <= k < j ==> B[i][k] == \at(B[i][k], Here);
		loop invariant 0 <= j;
		loop assigns j;
		loop assigns B[i][0..n-1];
		*/
		while(j < n){
					B[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		while(j < n){
					A[i][j]=B[i][j];
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		while(j < n){
                            // @ assert(A[i][j]==B[i][j]);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

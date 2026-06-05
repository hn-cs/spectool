#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j;
	int m=1000,n=1500;
	int A [1000][1500];
	int min;
	i=0;
	j=0;
	/*@
	loop invariant 0 <= i <= m;
	loop invariant \forall integer k; 0 <= k < i && 0 <= l < n ==> 0 <= A[k][l] <= INT_MAX;
	loop invariant 0 <= j <= 0;
	loop assigns i, j, A[0..m-1][0..n-1];
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant n - j;
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer l; 0 <= l < j ==> A[i][l] == \at(A[i][l], Pre);
		loop invariant \forall integer k,l; 0 <= k < i && 0 <= l < n ==> A[k][l] == \at(A[k][l], Pre);
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns j;
		loop assigns A[i][0..n-1];
		*/
		while(j < n){
					A[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
        min=A [0][0];
	while(i < n){
		j=0;
		while(j < n){
			if(A[i][j]<min){
                            min=A[i][j];
                        }
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < n){
		j=0;
		while(j < n){
			// @ assert(A[i][j]>=min);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

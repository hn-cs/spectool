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
	int q=500,s=700;
	int A [1000][1500];
        int B [500][700];
	// @ assert(q<m);
	// @ assert(s<n);
	i=0;
	j=0;
	while(i < m){
		j=0;
		/*@
		loop invariant 0 <= j <= n;
		loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre);
		loop invariant \forall integer l; 0 <= l < j ==> B[i][l] == \at(B[i][l], Pre);
		loop assigns j, B[i][0..n-1];
		loop variant n - j;
		*/
		while(j < n){
					B[i][j]=unknown();
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < q){
		j=0;
		while(j < s){
					A[i][j]=B[i][j];
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < q){
		j=0;
		while(j < s){
                                // @ assert(A[i][j]==B[i][j]);
                                j=j+1;
		}
		i=i+1;
    }
return 0;
}

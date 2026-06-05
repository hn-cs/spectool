#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j,k;
	int n=1000;
	int A [1000][1000][1000];
	int C=unknown();
	i=0;
	j=0;
	k=0;
	while(i < n){
		j=0;
		k=0;
		while(j < n){
			k=0;
			/*@
			loop invariant n - k;
			loop invariant k <= n;
			loop invariant j < n;
			loop invariant i < n;
			loop invariant \forall integer l; 0 <= l < k ==> A[i][j][l] == C;
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns A[i][j][0..n-1];
			*/
			while(k < n){
					A[i][j][k]=C;
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < n){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < n){
					// @ assert(A[i][j][k]==C);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

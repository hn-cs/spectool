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
	/*@
	loop invariant i <= m;
	loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns B[0..m-1][0..n-1];
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant n - j;
		loop invariant j <= n;
		loop invariant \forall integer l; 0 <= l < j ==> B[i][l] == \at(B[i][l], Pre);
		loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < n ==> B[k][l] == \at(B[k][l], Pre);
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
	/*@
	loop invariant i <= q;
	loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < s ==> B[k][l] == B[k][l];
	loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < s ==> A[k][l] == B[k][l];
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns A[0..q-1][0..s-1];
	*/
	while(i < q){
		j=0;
		/*@
		loop invariant j <= s;
		loop invariant \forall integer l; 0 <= l < j ==> A[i][l] == B[i][l];
		loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < s ==> A[k][l] == B[k][l];
		loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < s ==> A[k][l] == B[k][l];
		loop invariant 0 <= j;
		loop assigns j;
		loop assigns A[i][0..s-1];
		*/
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
		/*@
		loop assigns i;
		loop assigns j;
		*/
		while(j < s){
                                // @ assert(A[i][j]==B[i][j]);
                                j=j+1;
		}
		i=i+1;
    }
return 0;
}

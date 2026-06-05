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
	int C=unknown();
	i=0;
	j=0;
	/*@
	loop invariant i <= m;
	loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == C;
	loop invariant 0 <= i;
	*/
	while(i < m){
		j=0;
		/*@
		loop invariant \forall integer q; 0 <= q < j ==> A[i][q] == C;
		loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == C;
		loop invariant 0 <= j;
		loop assigns j;
		loop assigns A[i][0..n-1];
		*/
		while(j < n){
                        A[i][j]=C;
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	while(i < m){
		j=0;
		/*@
		loop invariant j <= n;
		loop invariant \forall integer q; 0 <= q < j ==> A[i][q] == C;
		loop invariant \forall integer p, q; 0 <= p < i && 0 <= q < n ==> A[p][q] == C;
		loop invariant 0 <= j;
		loop assigns j;
		*/
		while(j < n){
                        // @ assert(A[i][j]==C);
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main()
{
	int i,j,k;
	int m=1000,n=1500,p=1800;
	int A [1000][1500][1800];
	int min;
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant p == 1800;
	loop invariant n == 1500;
	loop invariant m == 1000;
	loop invariant k <= p;
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer ii, jj, kk; 0 <= ii < i && 0 <= jj < n && 0 <= kk < p ==> INT_MIN <= A[ii][jj][kk] < INT_MAX;
	loop invariant 0 <= k;
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns A[0..m-1][0..n-1][0..p-1];
	*/
	while(i < m){
		j=0;
		k=0;
		/*@
		loop invariant p == 1800;
		loop invariant n == 1500;
		loop invariant k <= p;
		loop invariant j <= n;
		loop invariant i < m;
		loop invariant \forall integer jj, kk; 0 <= jj < j && 0 <= kk < p ==> INT_MIN <= A[i][jj][kk] < INT_MAX;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns k;
		loop assigns j;
		loop assigns A[i][0..n-1][0..p-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant p == 1800;
			loop invariant k <= p;
			loop invariant j < n;
			loop invariant i < m;
			loop invariant \forall integer t; 0 <= t < k ==> INT_MIN <= A[i][j][t] < INT_MAX;
			loop invariant 0 <= k;
			loop invariant 0 <= j;
			loop invariant 0 <= i;
			loop assigns k;
			loop assigns A[i][j][0..p-1];
			*/
			while(k < p){
					A[i][j][k]= unknown();
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
        min=A [0][0][0];
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			/*@
			loop assigns min;
			loop assigns k;
			*/
			while(k < p){
                                    if(A[i][j][k]<min){
					min=A[i][j][k];}
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < p){
					// @ assert(A[i][j][k]>=min);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

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
	int B [1000][1500][1800];
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant i <= m;
	loop invariant \forall integer x, y, z; 0 <= x < i && 0 <= y < n && 0 <= z < p ==> B[x][y][z] == \at(B[x][y][z], Pre);
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns B[0..m-1][0..n-1][0..p-1];
	*/
	while(i < m){
		j=0;
		k=0;
		/*@
		loop invariant k <= p;
		loop invariant j <= n;
		loop invariant \forall integer x, y, z; 0 <= x < i || (x == i && 0 <= y < j) || (x == i && y == j && 0 <= z < k) ==> B[x][y][z] == \at(B[x][y][z], Pre);
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop assigns k;
		loop assigns j;
		loop assigns B[i][0..n-1][0..p-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant k <= p;
			loop invariant \forall integer x, y, z; 0 <= x < i || (x == i && 0 <= y < j) || (x == i && y == j && 0 <= z < k) ==> B[x][y][z] == \at(B[x][y][z], Pre);
			loop invariant 0 <= k;
			loop assigns B[i][j][0..p-1];
			*/
			while(k < p){
					B[i][j][k]=unknown();
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
					A[i][j][k]=B[i][j][k];
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
					// @ assert(A[i][j][k]==B[i][j][k]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

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
	int p=500;
	int A [1000][1000][1000];
        int B [1000][1000][1000];
	// @ assert(p<n);
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant i <= n;
	loop invariant \forall integer x, y, z; (0 <= x < i && 0 <= y < n && 0 <= z < n) ==> B[x][y][z] == \old(B[x][y][z]) || B[x][y][z] == unknown();
	loop invariant \forall integer x, y, z; (0 <= x < i && 0 <= y < n && 0 <= z < n) ==> B[x][y][z] == \at(B[x][y][z], Pre);
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns j;
	loop assigns i;
	loop assigns B[0..n-1][0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		k=0;
		/*@
		loop invariant j <= n;
		loop invariant \forall integer x, y; 0 <= x < i && 0 <= y < n || x == i && 0 <= y < j ==> \forall integer z; 0 <= z < n ==> B[x][y][z] == \at(B[x][y][z], Pre);
		loop invariant \forall integer x, y, z; 0 <= x < i && 0 <= y < n && 0 <= z < n || x == i && 0 <= y < j && 0 <= z < n ==> B[x][y][z] == \old(B[x][y][z]) || B[x][y][z] == unknown();
		loop invariant 0 <= j;
		loop assigns k;
		loop assigns j;
		loop assigns i;
		loop assigns B[i][0..n-1][0..n-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant k <= n;
			loop invariant \forall integer x, y, z; 0 <= x < i && 0 <= y < n && 0 <= z < n || x == i && 0 <= y < j && 0 <= z < n || x == i && y == j && 0 <= z < k ==> B[x][y][z] == \old(B[x][y][z]);
			loop invariant 0 <= k;
			loop assigns B[i][j][0..n-1];
			*/
			while(k < n){
					B[i][j][k] = unknown();
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
	i=0;
	j=0;
	k=0;
	while(i < p){
		j=0;
		k=0;
		while(j < p){
			k=0;
			/*@
			loop assigns A[i][j][0..p-1];
			loop assigns k;
			*/
			while(k < p){
					A[i][j][k]=B[i][j][k];
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
		i=p;
		while(i < n){
		j=p;
		while(j < n){
			k=p;
			while(k < n){
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
	while(i < n){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < n){
					// @ assert(A[i][j][k]==B[i][j][k]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

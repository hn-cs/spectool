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
        int B [1000][1000][1000];
	i=0;
	j=0;
	k=0;
	/*@
	loop invariant 0 <= i <= n;
	loop invariant 0 <= j <= n;
	loop invariant 0 <= k <= n;
	loop invariant \forall integer x, y, z; (0 <= x < i && 0 <= y < n && 0 <= z < n) ==> B[x][y][z] == 0;
	loop invariant \forall integer y, z; (0 <= y < j && 0 <= z < n) ==> B[i][y][z] == 0;
	loop invariant \forall integer z; (0 <= z < k) ==> B[i][j][z] == 0;
	loop assigns i, j, k, B[0..n-1][0..n-1][0..n-1];
	*/
	while(i < n){
		j=0;
		k=0;
		/*@
		loop invariant k <= n;
		loop invariant j <= n;
		loop invariant \forall integer z; 0 <= z < k ==> B[i][j][z] == 0;
		loop invariant \forall integer y; 0 <= y < j ==> \forall integer z; 0 <= z < n ==> B[i][y][z] == 0;
		loop invariant \forall integer x, y; 0 <= x < i && 0 <= y < n ==> \forall integer z; 0 <= z < n ==> B[x][y][z] == 0;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop assigns k;
		loop assigns j;
		loop assigns i;
		loop assigns B[i][j][0..k-1];
		loop assigns B[i][0..j-1][0..n-1];
		loop assigns B[0..i-1][0..n-1][0..n-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant k <= n;
			loop invariant \forall integer x, y; 0 <= x <= i && 0 <= y < n ==> B[x][y][k] == 0;
			loop invariant 0 <= k;
			loop assigns k;
			loop assigns B[i][j][0..n-1];
			*/
			while(k < n){
                                        B[i][j][k]= unknown();
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
					A[i][j][k]=B[n-i-1][n-j-1][n-k-1];
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
					// @ assert(A[i][j][k]==B[n-i-1][n-j-1][n-k-1]);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

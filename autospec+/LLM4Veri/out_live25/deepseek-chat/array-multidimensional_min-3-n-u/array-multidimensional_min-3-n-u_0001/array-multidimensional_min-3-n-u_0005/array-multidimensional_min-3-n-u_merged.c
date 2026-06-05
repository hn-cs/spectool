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
	loop invariant k <= p;
	loop invariant j <= n;
	loop invariant i <= m;
	loop invariant \forall integer z; 0 <= z < k ==> A[i][j][z] >= INT_MIN && A[i][j][z] < INT_MAX;
	loop invariant \forall integer y; 0 <= y < j ==> \forall integer z; 0 <= z < p ==> A[i][y][z] >= INT_MIN && A[i][y][z] < INT_MAX;
	loop invariant \forall integer x; 0 <= x < i ==> \forall integer y; 0 <= y < n ==> \forall integer z; 0 <= z < p ==> A[x][y][z] >= INT_MIN && A[x][y][z] < INT_MAX;
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
		loop invariant k <= p;
		loop invariant j <= n;
		loop invariant i <= m;
		loop invariant \forall integer z; 0 <= z < k ==> A[i][j][z] >= INT_MIN && A[i][j][z] < INT_MAX;
		loop invariant \forall integer y; 0 <= y < j ==> \forall integer z; 0 <= z < p ==> A[i][y][z] >= INT_MIN && A[i][y][z] < INT_MAX;
		loop invariant \forall integer x; 0 <= x < i ==> \forall integer y; 0 <= y < n ==> \forall integer z; 0 <= z < p ==> A[x][y][z] >= INT_MIN && A[x][y][z] < INT_MAX;
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns k;
		loop assigns j;
		loop assigns i;
		loop assigns A[0..m-1][0..n-1][0..p-1];
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant k <= p;
			loop invariant \forall integer z; 0 <= z < k ==> A[i][j][z] >= INT_MIN && A[i][j][z] < INT_MAX;
			loop invariant \forall integer y; 0 <= y < j && 0 <= z < p ==> A[i][y][z] >= INT_MIN && A[i][y][z] < INT_MAX;
			loop invariant \forall integer x, y, z; 0 <= x < i && 0 <= y < n && 0 <= z < p ==> A[x][y][z] >= INT_MIN && A[x][y][z] < INT_MAX;
			loop invariant 0 <= k;
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
		/*@
		loop invariant k <= p;
		loop invariant j <= n;
		loop invariant i <= m;
		loop invariant \forall integer z; 0 <= z < k ==> min <= A[i][j][z];
		loop invariant \forall integer y, z; 0 <= y < j && 0 <= z < p ==> min <= A[i][y][z];
		loop invariant \forall integer x, y, z; 0 <= x < i && 0 <= y < n && 0 <= z < p ==> min <= A[x][y][z];
		loop invariant 0 <= k;
		loop invariant 0 <= j;
		loop invariant 0 <= i;
		loop assigns min;
		loop assigns k;
		loop assigns j;
		loop assigns i;
		*/
		while(j < n){
			k=0;
			/*@
			loop invariant min == \min(0 <= x < i, 0 <= y < n, 0 <= z < p, A[x][y][z]) || min == \min(0 <= y < j, 0 <= z < p, A[i][y][z]) || min == \min(0 <= z < k, A[i][j][z]);
			loop invariant k <= p;
			loop invariant \forall integer z; 0 <= z < k ==> min <= A[i][j][z];
			loop invariant \forall integer y; 0 <= y < j ==> \forall integer z; 0 <= z < p ==> min <= A[i][y][z];
			loop invariant \forall integer x; 0 <= x < i ==> \forall integer y; 0 <= y < n ==> \forall integer z; 0 <= z < p ==> min <= A[x][y][z];
			loop invariant 0 <= k;
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

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
	int max;
	i=0;
	j=0;
	k=0;
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			/*@
			loop invariant 0 <= k <= p;
			loop invariant 0 <= i < m;
			loop invariant 0 <= j < n;
			loop invariant \forall integer t; 0 <= t < k ==> INT_MIN <= A[i][j][t] < INT_MAX;
			loop assigns k, A[i][j][0..p-1];
			loop variant p - k;
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
        max=A [0][0][0];
	while(i < m){
		j=0;
		k=0;
		while(j < n){
			k=0;
			while(k < p){
                                    if(A[i][j][k]>max){
					max=A[i][j][k];}
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
					// @ assert(A[i][j][k]<=max);
					k=k+1;
			}
			j=j+1;
		}
		i=i+1;
    }
return 0;
}

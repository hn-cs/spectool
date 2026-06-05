#include<stdio.h>
/*@predicate sorted(int* a, int length)=\forall integer i,j;0<=i<=j<length==>a[i]<=a[j];
*/
/*@
requires sorted(a, n);
requires n >= 0;
requires \valid(a+(0..n-1));
ensures \result >= 0 ==> a[\result] == v;
ensures -1 <= \result < n;
assigns \nothing;
*/
int binary_search(int* a, int n, int v) {
	int l=0,u=n-1;
	/*@
	loop invariant 0 <= l && u < n;
	loop assigns u;
	loop assigns l;
	*/
	while(l<=u) {
		int m=l+(u-l)/2;
		if(a[m]==v) return m;
		else if(a[m]<v) l=m+1;
		else u=m-1;
	}
	return -1;
}
void main() {
	int a[] = {3,4,5,13,21};
	//@ assert sorted(a, 5);
	int res = binary_search(a, 5, 5);
	//@ assert res == 2;
}
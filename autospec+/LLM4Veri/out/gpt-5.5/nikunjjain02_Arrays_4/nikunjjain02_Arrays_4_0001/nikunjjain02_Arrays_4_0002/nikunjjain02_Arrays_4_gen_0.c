#include<stdio.h>
/*@predicate sorted(int* a, int length)=\forall integer i,j;0<=i<=j<length==>a[i]<=a[j];
*/
/*@
requires n >= 0;
requires \valid_read(a + (0..n-1));
requires sorted(a, n);
assigns \nothing;
ensures \result == -1 || 0 <= \result < n;
ensures \result >= 0 ==> a[\result] == v;
ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> a[i] != v;
ensures (\exists integer i; 0 <= i < n && a[i] == v) ==> \result >= 0;
*/
int binary_search(int* a, int n, int v) {
	int l=0,u=n-1;
	/*@
	loop invariant u + 1 <= n;
	loop invariant 0 <= l;
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
	// @ assert sorted(a, 5);
	int res = binary_search(a, 5, 5);
	// @ assert res == 2;
}
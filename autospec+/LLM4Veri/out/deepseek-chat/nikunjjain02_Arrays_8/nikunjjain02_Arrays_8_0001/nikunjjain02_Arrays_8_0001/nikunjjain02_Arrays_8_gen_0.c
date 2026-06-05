#include<stdio.h>
int* reverse(int a[], int n, int b[]) {
	int i = 0;
	/*@
	loop invariant 0 <= i <= n;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == a[n-k-1];
	loop assigns i, b[0..n-1];
	*/
	while(i<n) {
		b[i]=a[n-i-1];
		i++;
	}
	return b;
}
void main() {
	int a[] = {21, 24, 23, 24, 25};
	int b[10];
	int* c = reverse(a, 5, b);
	// @ assert \forall integer k; 0 <= k < 5 ==> c[k] == a[5-k-1];
}
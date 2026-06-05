#include<stddef.h>
/*@
requires \valid(array + (0..length-1));
ensures \forall integer i; 0 <= i < length ==> (array[i] == new <==> \old(array[i]) == old);
ensures \forall integer i; 0 <= i < length ==> (array[i] != new <==> \old(array[i]) != old);
*/
void search_and_replace(int* array, size_t length, int old, int new) {
	/*@
	loop invariant i <= length;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns array[0..length-1];
	*/
	for(size_t i = 0;i < length; ++i) {
		if(array[i]==old) array[i]=new;
	}
}
void main() {
	int a[] = {1, 2, 4, 5};
	search_and_replace(a, 4, 2, 3);
	// @ assert a[0] == 1 && a[1] == 3 && a[2] == 4 && a[3] == 5;
}	
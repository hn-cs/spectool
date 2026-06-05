#include<stddef.h>
void search_and_replace(int* array, size_t length, int old, int new) {
	/*@
	loop invariant \forall integer k; 0 <= k < i ==> array[k] == new ==> \at(array[k], Pre) == old;
	loop invariant \forall integer k; 0 <= k < i ==> old == new ==> array[k] == new;
	loop invariant i <= length;
	loop invariant \forall integer k; i <= k < length ==> array[k] == \at(array[k], Pre);
	loop invariant \forall integer k; 0 <= k < i ==> array[k] == old ==> array[k] == new;
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
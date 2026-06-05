unsigned lower_bound(const int *a, unsigned n, int val)
{
	unsigned left = 0;
	unsigned right = n;
	unsigned middle = 0;
	/*@
	loop invariant right <= n;
	loop invariant right - left;
	loop invariant middle <= n;
	loop invariant left <= right;
	loop invariant \forall integer i; right <= i < n ==> a[i] >= val;
	loop invariant \forall integer i; 0 <= i < left ==> a[i] < val;
	loop invariant 0 <= middle;
	loop invariant 0 <= left;
	loop assigns right;
	loop assigns middle;
	loop assigns left;
	*/
	while (left < right) {
		middle = left + (right - left) / 2;
		if (a[middle] < val) {
			// @ assert \forall integer i; 0 <= i < middle+1 ==> a[i] < val;
			left = middle + 1;
		} else right = middle;
	}
	return left;
}
int main(){
	unsigned n = 5;
	int a[5] = {1, 2, 3, 4, 5};
	unsigned result = lower_bound(a, n, 3);
	// @ assert result == 2;
	return 0;
}
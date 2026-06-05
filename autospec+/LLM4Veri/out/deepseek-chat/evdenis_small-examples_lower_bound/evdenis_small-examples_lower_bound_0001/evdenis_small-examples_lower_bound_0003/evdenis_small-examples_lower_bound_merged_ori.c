unsigned lower_bound(const int *a, unsigned n, int val)
{
	unsigned left = 0;
	unsigned right = n;
	unsigned middle = 0;
	/*@
	loop invariant \forall integer k; right <= k < n ==> a[k] >= val;
	loop invariant \forall integer k; 0 <= k < left ==> a[k] < val;
	loop invariant right <= n;
	loop invariant left <= right;
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
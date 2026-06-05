/*@
requires size > 0;
requires addr < size;
requires \valid(arr + (0 .. size-1));
requires 0 <= arr[addr] < size;
requires 0 <= arr[arr[addr]] < size;
assigns arr[arr[addr]];
ensures arr[\old(arr[addr])] == 0;
*/
void indaddr(unsigned size, int arr[size], unsigned addr)
{
	arr[arr[addr]] = 0;
}
int main(){
	unsigned size = 5;
	int arr[5] = {1, 2, 3, 4, 5};
	indaddr(size, arr, 2);
	// @ assert arr[3] == 0;
}
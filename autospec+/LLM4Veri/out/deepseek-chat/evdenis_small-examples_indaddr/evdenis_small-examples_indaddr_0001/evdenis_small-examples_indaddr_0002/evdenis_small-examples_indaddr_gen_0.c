/*@
requires \valid(arr + (0..size-1));
requires addr < size;
requires arr[addr] < size;
assigns arr[arr[addr]];
ensures \let idx = arr[addr]; arr[idx] == \old(arr[idx]);
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
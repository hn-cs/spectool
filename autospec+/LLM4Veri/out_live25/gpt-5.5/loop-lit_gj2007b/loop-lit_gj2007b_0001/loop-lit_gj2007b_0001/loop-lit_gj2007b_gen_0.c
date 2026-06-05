#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int x = 0;
    int m = 0;
    int n = unknown();
    /*@
    loop invariant x >= 0;
    loop invariant n > 0 ==> x <= n;
    loop invariant n <= 0 ==> x == 0;
    loop invariant m >= 0;
    loop invariant n > 0 ==> (m == 0 || m < x);
    loop assigns x, m;
    loop variant n - x;
    */
    while(x < n) {
	if(unknown()) {
	    m = x;
	}
	x = x + 1;
    }
    //@assert((m >= 0 || n <= 0));
    //@assert((m < n || n <= 0));
    return 0;
}

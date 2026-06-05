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
    loop invariant x <= n;
    loop invariant n - x;
    loop invariant m <= x;
    loop invariant m < n;
    loop invariant 0 <= x;
    loop invariant 0 <= m;
    loop assigns x;
    loop assigns m;
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

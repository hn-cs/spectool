#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main( ) {
  int password[ SIZE ];
  int guess[ SIZE ];
  int i;
  int result = 1;
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= password[k] < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= guess[k] < INT_MAX;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns password[0..SIZE-1];
	loop assigns i;
	loop assigns guess[0..SIZE-1];
	*/
	for (i = 0; i < SIZE; i++)
	{
	    password[i] = unknown();
			guess[i] = unknown();
	}
  /*@
  loop invariant result == 1 ==> \forall integer k; 0 <= k < i ==> password[k] == guess[k];
  loop invariant result == 0 || result == 1;
  loop invariant result == 0 ==> \exists integer k; 0 <= k < i && password[k] != guess[k];
  loop invariant i <= SIZE;
  loop invariant SIZE - i;
  loop invariant 0 <= i;
  loop assigns result;
  loop assigns i;
  */
  for ( i = 0 ; i < SIZE ; i++ ) {
    if ( password[ i ] != guess[ i ] ) {
      result = 0;
    }
  }
  if ( result ) {
    int x;
    /*@
    loop invariant x <= SIZE;
    loop invariant \forall integer k; 0 <= k < SIZE ==> password[k] == guess[k];
    loop invariant SIZE - x;
    loop invariant 0 <= x;
    loop assigns x;
    */
    for ( x = 0 ; x < SIZE ; x++ ) {
      //@ assert(password[ x ] == guess[ x ]  );
    }
  }
  return 0;
}

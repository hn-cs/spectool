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
	loop invariant result == 1 || result == 0;
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> password[j] != guess[j] || result == 1;
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
  loop invariant result == 1 ==> (\forall integer j; 0 <= j < i ==> password[j] == guess[j]);
  loop invariant result == 0 ==> (\exists integer j; 0 <= j < i && password[j] != guess[j]);
  loop invariant i <= SIZE;
  loop invariant 0 <= i;
  loop invariant (result == 1) || (result == 0);
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
    loop invariant \forall integer j; 0 <= j < x ==> password[j] == guess[j];
    loop invariant 0 <= x;
    loop assigns x;
    */
    for ( x = 0 ; x < SIZE ; x++ ) {
      //@ assert(password[ x ] == guess[ x ]  );
    }
  }
  return 0;
}

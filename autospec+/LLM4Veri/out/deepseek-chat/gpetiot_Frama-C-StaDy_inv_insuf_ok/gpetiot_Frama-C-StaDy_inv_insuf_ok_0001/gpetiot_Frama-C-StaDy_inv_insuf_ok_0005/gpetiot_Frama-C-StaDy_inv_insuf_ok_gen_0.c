int found;
/*@ 
requires \valid(t+(0..4));
*/
void f(int*t, int x) {
  int i = 0;
  found = 0;
 first_loop:
  /*@
  loop invariant i <= 5;
  loop invariant i >= 0;
  loop invariant found == 0 || found == 1;
  loop invariant \forall integer j; 0 <= j < i && t[j] != x;
  loop invariant found == 1 ==> t[i-1] == x;
  loop invariant found == 1 ==> i > 0;
  loop invariant i <= 5;
  loop invariant found == 1 ==> (\exists integer j; 0 <= j < i && t[j] == x);
  loop invariant found == 0 ==> (\forall integer j; 0 <= j < i ==> t[j] != x);
  loop invariant \exists integer j; 0 <= j < i ==> t[j] != x ==> found == 0;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns found;
  */
  for(; i <= 4; i++) {
    if(t[i] == x)
      found = 1;
  }
  // @ assert found <==> \exists integer i; 0 <= i <= 4 && t[i] == x;
}
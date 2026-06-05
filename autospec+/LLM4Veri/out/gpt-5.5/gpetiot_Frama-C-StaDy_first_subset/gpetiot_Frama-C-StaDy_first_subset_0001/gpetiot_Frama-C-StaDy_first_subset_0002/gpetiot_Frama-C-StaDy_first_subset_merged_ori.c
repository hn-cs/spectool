/*@
requires n >= 0;
requires \valid(s+(0..n-1));
ensures \forall integer i; 0 <= i < n ==> s[i] == 0;
assigns s[0..n-1];
*/
void firstSubset(int s[], int n) {
 int k;
 /*@
 loop invariant \forall integer i; 0 <= i < k ==> s[i] == 0;
 loop invariant 0 <= k;
 loop assigns s[0..n-1];
 loop assigns k;
 */
 for ( k = 0; k < n; k++) {
  s[k] = 0;
 }
}
int main(){
  int s[3];
  firstSubset(s, 3);
  // @ assert s[0] == 0 && s[1] == 0 && s[2] == 0;
}
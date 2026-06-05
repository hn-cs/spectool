void firstSubset(int s[], int n) {
 int k;
 /*@
 loop invariant 0 <= k <= n;
 loop invariant \forall integer i; 0 <= i < k ==> s[i] == 0;
 loop assigns k, s[0..n-1];
 loop variant n - k;
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
unsigned lower_bound_raw(const int *a, unsigned n, int val)
{
   unsigned i = 0;
   /*@
   loop invariant i <= n;
   loop invariant \forall integer k; 0 <= k < i ==> a[k] < val;
   loop invariant 0 <= i;
   loop assigns i;
   */
   for(; i < n; ++i) {
      if (a[i] >= val) {
         break;
      }
   }
   //@ assert \forall integer k; 0 <= k < i ==> a[k] < val;
   return i;
}
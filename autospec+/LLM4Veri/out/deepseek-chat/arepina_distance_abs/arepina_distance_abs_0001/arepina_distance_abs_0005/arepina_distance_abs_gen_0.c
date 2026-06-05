#define SPEC_INT_MIN -2147483648
#define SPEC_INT_MAX 2147483647
/*@
requires -a >= INT_MIN ==> a >= 0 || (-a) <= UINT_MAX;
requires -b >= INT_MIN ==> b >= 0 || (-b) <= UINT_MAX;
ensures \result == (a < 0 ? (unsigned)(-(long long)a) : (unsigned)a) - (b < 0 ? (unsigned)(-(long long)b) : (unsigned)b) >= 0 ? 
         ((a < 0 ? (unsigned)(-(long long)a) : (unsigned)a) - (b < 0 ? (unsigned)(-(long long)b) : (unsigned)b)) : 
         ((b < 0 ? (unsigned)(-(long long)b) : (unsigned)b) - (a < 0 ? (unsigned)(-(long long)a) : (unsigned)a));
ensures \result == ( (a < 0 ? -((unsigned)(-a)) : (unsigned)a) > (b < 0 ? -((unsigned)(-b)) : (unsigned)b) ? 
         (a < 0 ? -((unsigned)(-a)) : (unsigned)a) - (b < 0 ? -((unsigned)(-b)) : (unsigned)b) : 
         (b < 0 ? -((unsigned)(-b)) : (unsigned)b) - (a < 0 ? -((unsigned)(-a)) : (unsigned)a) );
assigns \nothing;
*/
unsigned distance_abs(int a, int b)
{
   unsigned ua = a < 0 ? -a : a;
   unsigned ub = b < 0 ? -b : b;
   return ua > ub ? ua - ub : ub - ua;
}
#ifdef OUT_OF_TASK
#include <stdio.h>
int main(void)
{
   int a = distance_abs(3, 30);
   int b = distance_abs(-5, -20);
   int c = distance_abs(7, -10);
   int d = distance_abs(-2, 15);
   // @ assert a == 27;
   // @ assert b == 15;
   // @ assert c == 17;
   // @ assert d == 17;
   return 0;
}
#endif
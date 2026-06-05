#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
/*@
requires \valid(x);
assigns *x;
behavior recursive:
    assumes unknown() != 0;
    ensures *x == \old(*x) + 2 + (*x - \old(*x) - 2);
behavior base:
    assumes unknown() == 0;
    ensures *x == \old(*x);
complete behaviors;
disjoint behaviors;
*/
void func_to_recursive_line_13_to_14_0(unsigned int *x)
{
  if (unknown())
  {
    {
      *x += 2;
    }
    func_to_recursive_line_13_to_14_0(x);
  }
  else
  {
  }
}
int main(void)
{
  unsigned int x = 1;
  func_to_recursive_line_13_to_14_0(&x);
  // @ assert(x % 2);
  return 0;
}

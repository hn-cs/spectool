#include "assert.h"

#define SZ 2048

int main(void) {
  int A[SZ];
  int B[SZ];
  int i;
  int tmp;

  //@ admit \separated(A+(0 .. SZ-1), B+(0 .. SZ-1));
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }

  //@ assert(A[SZ/2] == B[SZ/2]);
}
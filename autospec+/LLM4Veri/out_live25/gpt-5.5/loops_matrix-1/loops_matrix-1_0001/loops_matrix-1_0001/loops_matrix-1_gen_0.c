#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int unknown();
int main()
{
  unsigned int N_LIN=1;
  unsigned int N_COL=1;      
  unsigned int j,k;
  int matriz[1][1], maior;
  maior = unknown();
  for(j=0;j<N_COL;j++)
    /*@
    loop invariant N_LIN == 1;
    loop invariant N_COL == 1;
    loop invariant j == 0;
    loop invariant 0 <= k <= N_LIN;
    loop invariant \forall integer l; 0 <= l < k ==> matriz[j][l] <= maior;
    loop assigns k;
    loop assigns maior;
    loop assigns matriz[j][0..N_LIN-1];
    loop variant N_LIN - k;
    */
    for(k=0;k<N_LIN;k++)
    {       
       matriz[j][k] = unknown();
       if(matriz[j][k]>=maior)
          maior = matriz[j][k];                          
    }                       
  // @ assert(matriz[0][0]<=maior);    
  return 0;
}

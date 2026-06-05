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
  /*@
  loop invariant j <= N_COL;
  loop invariant \forall unsigned int p; 0 <= p < j ==> (\forall unsigned int q; 0 <= q < N_LIN ==> maior >= matriz[p][q]);
  loop invariant \exists unsigned int p, q; 0 <= p < j && 0 <= q < N_LIN && maior == matriz[p][q];
  loop assigns j;
  loop assigns k;
  loop assigns matriz[0..N_COL-1][0..N_LIN-1];
  loop assigns maior;
  */
  for(j=0;j<N_COL;j++)
    /*@
    loop invariant k <= N_LIN;
    loop invariant \forall unsigned int p; 0 <= p < k ==> maior >= matriz[j][p];
    loop invariant \exists unsigned int p; 0 <= p < k && maior == matriz[j][p];
    loop invariant 0 <= k;
    loop assigns matriz[j][0..N_LIN-1];
    loop assigns maior;
    loop assigns k;
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

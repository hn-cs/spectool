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
    loop invariant 0 <= k <= N_LIN;
    loop invariant \forall unsigned int p; 0 <= p < k ==> maior >= matriz[j][p];
    loop invariant \exists unsigned int p; 0 <= p < k && maior == matriz[j][p];
    loop assigns k, matriz[j][0..N_LIN-1], maior;
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

int INFINITY = 899;
int main(){
  int nodecount = 5;
  int edgecount = 20;
  int source = 0;
  int Source[20] = {0,4,1,1,0,0,1,3,4,4,2,2,3,0,0,3,1,2,2,3};
  int Dest[20] = {1,3,4,1,1,4,3,4,3,0,0,0,0,2,3,0,2,1,0,4};
  int Weight[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
  int distance[5];
  int x,y;
  int i,j;
  /*@
  loop invariant i <= nodecount;
  loop invariant \forall integer k; 0 <= k < i && k == source ==> distance[k] == 0;
  loop invariant \forall integer k; 0 <= k < i && k != source ==> distance[k] == INFINITY;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns distance[0..nodecount-1];
  */
  for(i = 0; i < nodecount; i++){
    if(i == source){
      distance[i] = 0;
    }
    else {
      distance[i] = INFINITY;
    }
  }
  /*@
  loop invariant source == 0;
  loop invariant nodecount == 5;
  loop invariant i <= nodecount;
  loop invariant edgecount == 20;
  loop invariant \forall integer k; 0 <= k < nodecount ==> distance[k] >= 0;
  loop invariant \forall integer k; 0 <= k < edgecount ==> Weight[k] >= 0;
  loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Source[k] < nodecount;
  loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Dest[k] < nodecount;
  loop invariant INFINITY == 899;
  loop invariant 0 <= i;
  loop assigns y;
  loop assigns x;
  loop assigns j;
  loop assigns i;
  loop assigns distance[0..nodecount-1];
  */
  for(i = 0; i < nodecount; i++)
    {
      /*@
      loop invariant j <= edgecount;
      loop invariant i < nodecount;
      loop invariant \forall integer k; 0 <= k < nodecount ==> distance[k] >= 0;
      loop invariant \forall integer k; 0 <= k < edgecount ==> Weight[k] >= 0;
      loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Source[k] < nodecount;
      loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Dest[k] < nodecount;
      loop invariant 0 <= j;
      loop invariant 0 <= i;
      loop assigns y;
      loop assigns x;
      loop assigns j;
      loop assigns distance[0..nodecount-1];
      */
      for(j = 0; j < edgecount; j++)
	{
	  x = Dest[j];
	  y = Source[j];
	  if(distance[x] > distance[y] + Weight[j])
	    {
	      distance[x] = distance[y] + Weight[j];
	    }
	}
    }
  /*@
  loop invariant source == 0;
  loop invariant nodecount == 5;
  loop invariant i <= edgecount;
  loop invariant edgecount == 20;
  loop invariant \forall integer k; 0 <= k < nodecount ==> distance[k] >= 0;
  loop invariant \forall integer k; 0 <= k < i ==> distance[Dest[k]] <= distance[Source[k]] + Weight[k];
  loop invariant \forall integer k; 0 <= k < edgecount ==> Weight[k] >= 0;
  loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Source[k] < nodecount;
  loop invariant \forall integer k; 0 <= k < edgecount ==> 0 <= Dest[k] < nodecount;
  loop invariant INFINITY == 899;
  loop invariant 0 <= i;
  loop assigns y;
  loop assigns x;
  loop assigns i;
  */
  for(i = 0; i < edgecount; i++)
    {
      x = Dest[i];
      y = Source[i];
      if(distance[x] > distance[y] + Weight[i])
	{
	  return 0;
	}
    }
  /*@
  loop invariant source == 0;
  loop invariant nodecount == 5;
  loop invariant i <= nodecount;
  loop invariant edgecount == 20;
  loop invariant \forall integer k; 0 <= k < nodecount ==> distance[k] >= 0;
  loop invariant INFINITY == 899;
  loop invariant 0 <= i;
  loop assigns i;
  */
  for(i = 0; i < nodecount; i++)
    {
      //@ assert(distance[i]>=0);
    }
  return 0;
}

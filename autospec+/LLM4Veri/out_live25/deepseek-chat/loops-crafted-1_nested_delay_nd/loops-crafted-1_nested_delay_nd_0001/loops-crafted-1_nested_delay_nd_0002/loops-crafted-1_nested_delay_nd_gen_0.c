#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int last ;
int SIZE = 200000; 
int main()
{
	last = unknown();
	// @ assert(last > 0);
	int a=0,b=0,c=0,st=0,d=0;
	/*@
	loop invariant 0 <= c <= SIZE;
	loop invariant st == 0 || st == 1;
	loop invariant st == 1 ==> \forall integer k; 0 <= k < c ==> k < last;
	loop invariant st == 0 ==> \exists integer k; 0 <= k < c && k >= last;
	loop invariant c == SIZE ==> st == 0;
	loop invariant 0 <= d <= SIZE + 1;
	loop invariant a == b;
	loop invariant a >= 0;
	loop invariant b >= 0;
	loop invariant c == SIZE;
	loop invariant d <= SIZE + 1;
	loop invariant \at(a,Pre) == 0 ==> \at(b,Pre) == 0;
	loop assigns a, b, c, st, d;
	loop variant 1;
	*/
	while(1) {
		st=1;  
		/*@
		loop invariant st == 1 || st == 0;
		loop invariant st == 0 <==> (\exists integer k; 0 <= k < c && k >= last);
		loop invariant c <= SIZE;
		loop invariant \forall integer k; 0 <= k < c ==> (k >= last ==> st == 0);
		loop invariant SIZE - c;
		loop invariant 0 <= c;
		loop assigns st;
		loop assigns c;
		*/
		for(c=0;c<SIZE;c++) {
			if (c>=last)  { st = 0; }
		}
		if(st==0 && c==last+1){
			a+=3; b+=3;}
		else { a+=2; b+=2; } 
		if(c==last && st==0) { 
			a = a+1;
		}
		else if(st==1 && last<SIZE) { 
			d++;
		}
		if(d == SIZE) {
			a = 0; 
			b = 1;
		}
		// @ assert(a==b && c==SIZE);
	}
	return 0;
}

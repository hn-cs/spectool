#include<limits.h>
/*@
logic integer ax_b(integer a,integer x,integer b) = a*x+b;
*/
/*@
assigns \nothing;
ensures \result==ax_b(a,x,4);
*/
/*@
return a*x+4;
int func(int a,int x){;
*/
int func(int a,int x){
return a*x+4;
}
/*@
requires a >= 0 && x <= y;
requires INT_MIN <= a*x+4 <= INT_MAX && INT_MIN <= a*y+4 <= INT_MAX;
ensures \result == \min(func(a,x), func(a,y));
assigns \nothing;
int min_func(int a, int x, int y); // not needed, just keep void

void check(int a,int x,int y){
int fmin,fmax;
if(x>y){
fmin=func(a,x);
fmax=func(a,y);
}
else{
fmin=func(a,y);
fmax=func(a,x);
}
//@assert fmin<=fmax;
}
*/
void check(int a,int x,int y){
int fmin,fmax;
if(x>y){
fmin=func(a,x);
fmax=func(a,y);
}
else{
fmin=func(a,y);
fmax=func(a,x);
}
//@assert fmin<=fmax;
}
int main(){
int w=3;
int r=4;
int s=7;
int t=func(w,r);
check(w,r,s);
}
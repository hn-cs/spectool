#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {


  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  /*@
  loop invariant x == y;
  loop invariant 0 <= x <= 1;
  loop invariant 0 <= y <= 1;
  loop invariant w == 1 - x;
  loop invariant z == x;
  loop assigns w, z, x, y;
  */
  while(unknown2()){
  	if(w) {
  	  x++;
  	  w = !w;
	  }
	
    if(!z) {
      y++; 
      z=!z;
    }
  }

  // @ assert(x==y);
  
}

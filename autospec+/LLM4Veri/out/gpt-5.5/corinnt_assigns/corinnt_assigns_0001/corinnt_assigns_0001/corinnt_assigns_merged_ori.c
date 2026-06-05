void foo(){
  int h = 42 ;
  int x = 0 ;
  int e = 0 ;
  PreLoop:
  /*@
  loop invariant x == e * (e + 1);
  loop invariant h == 42;
  loop invariant e <= 10;
  loop invariant 10 - e;
  loop invariant 0 <= e;
  loop assigns x;
  loop assigns e;
  */
  while(e < 10){
    ++ e ;
    x += e * 2 ;
  }
  // @ assert h == 42 ;
}
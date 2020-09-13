#include <stdlib.h>
#include <stdio.h>

typedef struct {
  double reel;
  double img;
} Complexe;

void ecrireComplexe(Complexe c){
  printf("(%f,%f)\n",c.reel,c.img);
}

Complexe initComplexe(double r, double i){
  Complexe c;
  c.reel = r;
  c.img = i;
  return c;
}

int main(){
  Complexe c;
  double r = 1;
  double i = 2;
  c = initComplexe(r,i);
  ecrireComplexe(c);
  return 1;
}

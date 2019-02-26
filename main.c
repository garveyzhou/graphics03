#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"


int main() {

  screen * s = calloc(250000,sizeof(color));
  color c;
  c.green = 255;
  c.red = 0;
  c.blue = 0;
  struct matrix *edges;

  edges = new_matrix(4, 4);
  int i = 0;
  int j = 0;
  while(i < 50){
    add_edge(edges,j,0,0,j,500,0);
    add_edge(edges,250,250,0,j,500,0);
    i++;
    j+= 10;
  }
  
  draw_lines(edges,s, c);
  //display(s);
  save_ppm(s,"main.png");
  free_matrix( edges );
  free(s);


  printf("Matrix Test \n");
  struct matrix * b = new_matrix(4,2);
  add_point(b,1,2,3);
  add_point(b,4,5,6);
  print_matrix(b);
  struct matrix * a = new_matrix(4,4);
  ident(a);
  printf("Identity matrix a\n");
  print_matrix(a);
  printf("Matrix mult a * b b should stay the same\n");
  matrix_mult(a,b);
  print_matrix(b);
  add_point(a,1,2,3);
  add_point(a,4,5,6);
  add_point(a,7,8,9);
  add_point(a,10,11,12);
  printf("New matrix a\n");
  print_matrix(a);
  printf("a*b\n");
  matrix_mult(a,b);
  print_matrix(b);
  free_matrix(a);
  free_matrix(b);
}  

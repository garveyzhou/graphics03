#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"


int main() {

    screen s;
    color c;
    c.green = 255;
    c.red = 0;
    c.blue = 0;
    struct matrix *edges;

    edges = new_matrix(4, 4);
    int i = 0;
    int j = 0;
    while(i < 50){
      add_edge(edges,j,250,0,j,500,0);
      add_edge(edges,250,250,0,j,500,0);
      i++;
      j+= 10;
    }
    
    draw_lines(edges,s, c);
    display(s);
    save_ppm(s,"main.png");
    free_matrix( edges );
}  

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
    struct matrix *edges;

    edges = new_matrix(4, 4);
    add_edge(edges, 0, 250, 0, 250, 0, 0);
    draw_line(0, 100,100,0,s, c);
    print_matrix(edges);
    display(s);
    free_matrix( edges );
}  

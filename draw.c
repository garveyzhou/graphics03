#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
    if(points->lastcol == points->cols){
        grow_matrix(points,points->lastcol *2);
        }
    points->m[0][points->lastcol] = x;
    points->m[1][points->lastcol] = y;
    points->m[2][points->lastcol] = z;
    points->m[3][points->lastcol] = 1;
    points->lastcol++;
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, double x0, double y0, double z0, double x1, double y1, double z1) {
    add_point(points,x0,y0,z0);
    add_point(points,x1,y1,z1);
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
    for(int i = 0; i< points->lastcol;i += 2){
        draw_line(points->m[0][i],points->m[1][i],points->m[0][i+1],points->m[1][i+1],s,c);
    }   
}

//using brians line algo
void draw_line(int x0, int y0, int x1, int y1, screen s, color c)
{
    int x, y;
    int dx, dy;
    /* D = Ax + By + C, where A = dy, B = -dx, and C is irrelevant */
    int A, B, D;
    if (x1 < x0)
    {
        int temp = x0;
        x0 = x1;
        x1 = temp;

        temp = y0;
        y0 = y1;
        y1 = temp;
    }
    x = x0;
    y = y0;
    dx = x1 - x0;
    dy = y1 - y0;

    /* Note everything is scaled by 2 to avoid the pesky floating point number 1/2 */
    A = dy * 2;
    B = -dx * 2;
    if (abs(dx) >= abs(dy)) // -1 <= m <= 1
    {
        int cy = 1;
        if (dy < 0)
        {
            cy = -1;
            A *= -1;
        }
        D = 2 * A + B;
        while (x <= x1)
        {
            plot(s, c, x, y);
            if (D > 0) // next midpoint is below the line
            {
                y += cy;
                D += B;
            }
            x++;
            D += A;
        }
    }
    else
    {
        if (dy >= 0)
        {
            D = A + 2 * B;
            while (y <= y1)
            {
                plot(s, c, x, y);
                if (D < 0) // next midpoint is above the line
                {
                    x++;
                    D += A;
                }
                y++;
                D += B;
            }
        }
        else
        {
            D = A - 2 * B;
            while (y >= y1)
            {
                plot(s, c, x, y);
                if (D > 0) // next midpoint is below the line
                {
                    x++;
                    D += A;
                }
                y--;
                D -= B;
            }
        }
    }
}

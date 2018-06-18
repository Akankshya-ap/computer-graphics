#include <GL\glew.h>
#include <GL\freeglut.h>
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int h,k;
float a,b;

void drawDot (GLint x, GLint y, GLfloat r, GLfloat g, GLfloat b)
{	glColor3f(r,g,b);
	glPointSize(1.0);
	glBegin (GL_POINTS);
    glVertex2i (x,y);
	glEnd();
}

void symmetricPixels (int x, int y, int xc, int yc, float r, float g, float b)
{ drawDot (xc + x, yc + y, r,g,b);
  drawDot (xc - x, yc + y,r,g,b);
  drawDot (xc + x, yc - y,r,g,b);
  drawDot (xc - x, yc - y,r,g,b);
}

void Ellipse (int a, int b, int xc, int yc, float r, float g, float bl)
{
	int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
	aSq = a*a;
	bSq = b*b;
	twoASq = 2*aSq;
	twoBSq = 2*bSq;
	d = bSq - b*aSq + aSq/4;
	dx = 0;
	dy = twoASq*b;
	x = 0;
	y = b;
	symmetricPixels(x,y,xc,yc,r,g,bl);
	while (dx < dy)
	{ x++;
		dx += twoBSq;
		if (d >= 0)
		{ y--;
			dy -= twoASq;
		}
		if (d < 0)
			d += bSq + dx;
		else
			d += bSq + dx - dy;
		symmetricPixels (x,y,xc,yc,r,g,bl);
	}
	d = (int)(bSq*(x+0.5)*(x+0.5) + aSq*(y-1)*(y-1) -
					aSq*bSq);
	while (y > 0)
	{
		y--;
		dy -= twoASq;
		if (d <= 0)
		{ x++;
			dx += twoBSq;
		}
		if (d > 0)
				d += aSq - dy;
		else
				d += aSq -dy +dx;
		symmetricPixels(x,y,xc,yc,r,g,bl);
	}
	glFlush();
}


 void display(void)
 {
        

         double I,J;
         int i,j;
         glClear (GL_COLOR_BUFFER_BIT);

		  glColor3f (1.0, 0.0, 0.0);
         glBegin(GL_POINTS);
         for(int i=-100 ; i<=100 ; i++)
         {
                 drawDot(i,0,1,0,1);
                 drawDot(0,i,1,0,1);
         }


         glColor3f (1.0, 0.0, 0.0);
         glBegin(GL_POINTS);
		 int p=0;
		 while(p<100)
		 {
			 Ellipse (a,b,h,k,1,1,1);
			 Sleep(100);
			 Ellipse (a,b,h,k,0,0,0);
			 a=a-10;
			 Ellipse(a,b,h,k,1,1,1);
			 Sleep(100);
			 Ellipse (a,b,h,k,0,0,0);
			 a-=10;
			 Ellipse(a,b,h,k,1,1,1);
			 Sleep(100);
			 Ellipse(a,b,h,k,0,0,0);
			 a+=20;
			 p+=1;
		 }

         //glVertex2s(h,k);
         /*for( i=0 ; i<=a ; i+=1)
         {
                 J=sqrt(1 - (i*i)/(a*a))*b;
                 j=(int)(J);
                 glVertex2s(h+i,k+j);
                 glVertex2s(h-i,k+j);
                 glVertex2s(h-i,k-j);
                 glVertex2s(h+i,k-j);
         }*/
         //glColor3f (1.0, 1.0, 1.0);
		
         /*for(int i=-2; i<=2 ; i++)
         {
                 glVertex2s(95+i,4+i);
                 glVertex2s(95-i,4+i);
         }
         for(int i=0; i<=2 ; i++)
         {
                 glVertex2s(4+i,95+i);
                 glVertex2s(4-i,95+i);
                 glVertex2s(4,95-i);
         }*/
         glEnd();
         glFlush();
 }
void init(void)
{
        glClearColor (0.0, 0.0, 0.0, 0.0);
        glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{		printf("Centre at (0,0)\n");
         printf("Enter the center of ellipse:\n");
         scanf("%d %d",&h,&k);
         printf("Enter the parameters a & b:\n");
         scanf("%f %f",&a,&b);
         glutInit(&argc, argv);
         glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize (500, 500);
         glutInitWindowPosition (100, 100);
         glutCreateWindow ("Ellipse :Midpoint method ");
         init ();
         glutDisplayFunc(display);
         glutMainLoop();
         return 0;
}
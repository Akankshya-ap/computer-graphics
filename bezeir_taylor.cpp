#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <GL/glut.h>


#define maxWD 500
#define maxHT 500

void myInit(void);
void mydisplay(void);
void draw_pixel(int x, int y);
void drawPoint(int x, int y);

void drawSq(int x[4], int y[4]);
void drawaxis();
int x[4], y[4];

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x, y);
	glEnd();
}
// this function just draws a point
void drawPoint(int x, int y)
{
	glPointSize(4.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glEnd();
}

void drawSq(int x[4], int y[4])
{
	double dt=0.01;
	double fx0,fy0,dfx0,dfy0,ddfx0,ddfy0,dddfx0,dddfy0;
	int j;
	
		fx0=x[0];
		dfx0=3*(x[1]-x[0])*dt+3*(x[0]-2*x[1]+x[2])*dt*dt+(-x[0]+3*x[1]-3*x[2]+x[3])*dt*dt*dt;
		ddfx0=6*(x[0]-2*x[1]+x[2])*dt*dt+6*(-x[0]+3*x[1]-3*x[2]+x[3])*dt*dt*dt;
		dddfx0=6*(-x[0]+3*x[1]-3*x[2]+x[3])*dt*dt*dt;

		fy0=y[0];
		dfy0=3*(y[1]-y[0])*dt+3*(y[0]-2*y[1]+y[2])*dt*dt+(-y[0]+3*y[1]-3*y[2]+y[3])*dt*dt*dt;
		ddfy0=6*(y[0]-2*y[1]+y[2])*dt*dt+6*(-y[0]+3*y[1]-3*y[2]+y[3])*dt*dt*dt;
		dddfy0=6*(-y[0]+3*y[1]-3*y[2]+y[3])*dt*dt*dt;

	for (j = 0; j<100; j+=1)
	{
		dt=j/100.0;
		draw_pixel(fx0,fy0);

		fx0=fx0+dfx0;
		dfx0=dfx0+ddfx0;
		ddfx0=ddfx0+dddfx0;

		fy0=fy0+dfy0;
		dfy0=dfy0+ddfy0;
		ddfy0=ddfy0+dddfy0;
	}
}

void drawaxis()
{
	for (int i = -100; i <= 100; i++)	//X and Y axis
	{
		draw_pixel(i, 0);
		draw_pixel(0, i);

	}
	for (int i = -2; i <= 2; i++)
	{
		draw_pixel(95 + i, 4 + i);
		draw_pixel(95 - i, 4 + i);

	}
	for (int i = 0; i <= 2; i++)
	{
		draw_pixel(4 + i, 95 + i);
		draw_pixel(4 - i, 95 + i);
		draw_pixel(4, 95 - i);

	}
}

void myDisplay(void)
{
	int opt, i;

	printf("\nBezeir function with four control points a,b,c,d\n Enter four coordinates \n");
	for (i = 0; i<4; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	
	}
	glClear(GL_COLOR_BUFFER_BIT);
	//drawP(x, y, 0, 0, 1);
	drawaxis();
	drawSq(x,y);
	glFlush();

}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(maxWD, maxHT);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Transforming point");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	glFlush();
}
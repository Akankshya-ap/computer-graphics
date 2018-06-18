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

void drawSq(int x[3], int y[3]);
void drawaxis();
int x[3], y[3];

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

/*void drawP(int x[3], int y[3], int r, int g, int b)
{
	glPointSize(1.0);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2i(x[0], y[0]);
	glVertex2i(x[1], y[1]);
	glVertex2i(x[2], y[2]);
	
	glEnd();
}*/

void drawSq(int x[3], int y[3])
{
	double ui;
	double xf,yf;
	int j;
	for (j = 0; j<100; j+=1)
	{
		ui=j/100.0;
		xf=(double)(1-ui*ui)*(double)x[0]+2*(double)(1-ui)*ui*(double)x[1]+ui*ui*(double)x[2];
		yf=(double)(1-ui*ui)*(double)y[0]+2*(1-ui)*ui*(double)y[1]+ui*ui*(double)y[2];
		printf("%f %f ",xf,yf);
		draw_pixel(xf,yf);
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

	printf("\nBezeir function with three given points\n Enter the three coordinates (-100,-100) to (100,100) : \n");
	for (i = 0; i<3; i++)
	{
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
		draw_pixel(x[i], y[i]);
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
}
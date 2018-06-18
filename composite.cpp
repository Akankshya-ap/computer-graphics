// C code to implement basic
// transformations in OPENGL
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

// window size
#define maxWD 640
#define maxHT 480

// rotation speed
#define thetaSpeed 0.05

int matX[4], matY[4];
int new_matX[4], new_matY[4];
// this creates delay between two actions
/*void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock();
while (goal > clock())
;
}*/

// this is a basic init for the glut window
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
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
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glEnd();
}


void drawP(int matX[4], int matY[4],int r,int g, int b)
{
	glPointSize(1.0);
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex2i(matX[0], matY[0]);
	glVertex2i(matX[1], matY[1]);
	glVertex2i(matX[2], matY[2]);
	glVertex2i(matX[3], matY[3]);
	glEnd();
}
void drawSq(int matX[4], int matY[4])
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		drawPoint(matX[i], matY[i]);
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
void CT(int matX[4], int matY[4])
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawP(matX, matY,0,0,1);
	int xf[4], yf[4];
	float T[3][3];
	T[0][0]=0.25;
	T[0][1]=0.75;
	T[0][2]=5;
	T[1][0]=-0.25;
	T[1][1]=-0.75;
	T[1][2]=-2;
	T[2][0]=0;
	T[2][1]=0;
	T[2][2]=1;

	double sum=0.0;

	for(int i=0;i<4;i++)
	{
		xf[i]=T[0][0]*matX[i]+T[0][1]*matY[i]+T[0][2];
		yf[i]=T[1][0]*matX[i]+T[1][1]*matY[i]+T[1][2];
	}
	drawP(xf,yf,1,0,0);
	drawaxis();
	glFlush();
}



void myDisplay(void)
{
	int opt, i;
	int tx, ty;
	int rotX, rotY, angle;
	int sx, sy;
	printf("\nEnter the four coordinates of the square : \n");
	for (i = 0; i<4; i++)
	{
		scanf("%d", &matX[i]);
		scanf("%d", &matY[i]);
	}
	printf("\nThe four coordinates of the square are : \n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	drawP(matX, matY,0,0,1);
	drawaxis();
	
	glFlush();
	CT(matX,matY);

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
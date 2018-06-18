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
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glEnd();
}


void drawP(int matX[4], int matY[4], int r, int g, int b)
{
	glPointSize(1.0);
	glColor3f(r, g, b);
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
void rotateAroundPt(int matX[4], int matY[4], int angle, int cx, int cy)
{
	float theta = 0.0;
	// while (1) 
	{
		//delay(10);
		glClear(GL_COLOR_BUFFER_BIT);

		drawP(matX, matY, 0, 0, 1);
		// update theta anticlockwise rotation
		int xf[4], yf[4];
		theta = ((float)angle * 3.14159) / 180.0;
		// check overflow

		/* if (theta >= (2.0 * 3.14159))
		theta = theta - (2.0 * 3.14159);
		*/
		// actual calculations..
		for (int i = 0; i<4; i++)
		{
			xf[i] = (matX[i] * cos(theta)) - (matY[i] * sin(theta));
			yf[i] = (matX[i] * sin(theta)) + (matY[i] * cos(theta));
		}

		// drawing the centre point
		drawP(xf, yf, 0, 0, 1);

		// drawing the rotating point
		drawP(xf, yf, 1, 0, 0);
		drawaxis();

		glFlush();
		// creating a delay
		// so that the point can be noticed

	}
}

// this function will translate the point
void translatePoint(int matX[4], int matY[4], int tx, int ty)
{
	int fx[4], fy[4];
	for (int i = 0; i<4; i++)
	{
		fx[i] = matX[i];
		fy[i] = matY[i];
	}

	//while (1)
	{
		//delay(10);
		glClear(GL_COLOR_BUFFER_BIT);
		drawP(matX, matY, 0, 0, 1); // drawing the point
		// update
		for (int i = 0; i<4; i++)
		{
			fx[i] = fx[i] + tx;
			fy[i] = fy[i] + ty;
		}

		// check overflow to keep point in screen
		/*if (px > maxWD || px < 0 || py > maxHT || py < 0) {
		px = fx;
		py = fy;
		}*/

		drawP(fx, fy, 1, 0, 0); // drawing the point
		drawaxis();
		glFlush();
		// creating a delay
		// so that the point can be noticed

	}
}

// this function draws
void scalePoint(int matX[4], int matY[4], int sx, int sy)
{
	int fx[4], fy[4];
	//while (1) 
	{
		//delay(500);
		glClear(GL_COLOR_BUFFER_BIT);
		drawP(matX, matY, 0, 0, 1);
		// update
		for (int i = 0; i<4; i++)
		{

			fx[i] = matX[i] * sx;
			fy[i] = matY[i] * sy;
		}

		drawP(fx, fy, 1, 0, 0); // drawing the point
		drawaxis();
		glFlush();
		// creating a delay
		// so that the point can be noticed

	}
}

void reflection(int matX[4], int matY[4], int flag)
{
	int fx[4], fy[4];
	//while (1) 
	{
		//delay(500);
		glClear(GL_COLOR_BUFFER_BIT);
		drawP(matX, matY, 0, 0, 1);
		// update
		if (flag == 1)
		{
			printf("\nAbout X axis");
			for (int i = 0; i<4; i++)
			{
				fx[i] = matX[i];
				fy[i] = -matY[i];
				printf("\n%d  %d %d",i,matY[i], fy[i]);
			}
		}
		else if (flag == 2)
		{
			printf("\nAbout Y axis");
			for (int i = 0; i<4; i++)
			{

				fx[i] = -matX[i];
				fy[i] = matY[i];
				printf("\n%d  %d %d", i, matX[i], fx[i]);
				
			}
		}
	

		drawP(fx, fy, 1, 0, 0); // drawing the point
		drawaxis();
		glFlush();
		// creating a delay
		// so that the point can be noticed

	}
}

// Actual display function
void myDisplay(void)
{
	int opt, i;
	int tx, ty;
	int rotX, rotY, angle;
	int sx, sy;
	printf("\nEnter the four coordinates of the square(-100,-100) to (100,100) : \n");
	for (i = 0; i<4; i++)
	{
		scanf("%d", &matX[i]);
		scanf("%d", &matY[i]);
	}
	

	glClear(GL_COLOR_BUFFER_BIT);
	drawP(matX, matY, 0, 0, 1);
	drawaxis();
	glFlush();

	while (1){
		printf("\n\n1.Translation"
			"\n2.Rotation"
			"\n3.Scaling"
			"\n4. Reflection about X axis"
			"\n5. Reflection about Y axis");
		printf("\nEnter your choice : ");
		scanf("%d", &opt);

		switch (opt) {
		case 1:

			printf("\nEnter the X displacement : ");
			scanf("%d", &tx);
			printf("\nEnter the Y displacement : ");
			scanf("%d", &ty);
			translatePoint(matX, matY, tx, ty);
			break;
		case 2:
			printf("Enter the angle of rotation : ");
			scanf("%d", &angle);
			/*printf("\nEnter the point of rotation : \n");
			scanf("%d",&rotX);
			scanf("%d",&rotY);*/
			rotateAroundPt(matX, matY, angle, maxWD / 2, maxHT / 2);
			// point will circle around
			// the centre of the window
			break;
		case 3:
			printf("\nEnter the X scaling : ");
			scanf("%d", &sx);
			printf("\nEnter the Y scaling: ");
			scanf("%d", &sy);
			scalePoint(matX, matY, sx, sy);
			break;
		case 4:
			reflection(matX, matY, 1);
			break;
		case 5:
			reflection(matX, matY, 2);
			break;

		}
	}
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
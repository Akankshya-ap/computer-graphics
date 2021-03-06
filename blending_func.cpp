#include <gl/glut.h>
#include <stdio.h>


int x1, y1, x2, y2,x_1,y_1,x_2,y_2;



void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void draw_pixel(int x, int y,int r, int g, int b) {
	glBegin(GL_POINTS);
	glColor3f(r,g,b);
	glVertex2i(x, y);
	glEnd();
}

void drawP()
{
	glPointSize(1.0);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);	
	glEnd();

	/*glBegin(GL_LINES);
	glVertex2i(x2,y2);	
	glVertex2i(x3,y3);
	glEnd();
	*/

	
}
void draw_curve() {	
	//drawP();
	double u,x,y;
	//draw_pixel(x1, y1);
	//draw_pixel(x2, y2);
	double f1,f2,f3,f4;
	for(u=0;u<=1;u+=0.01)
	{
		f1 = ( 2 * u * u - 3 * u + 1 ) ;
		f2 = ( -4 * u * u + 4 * u ) ;
		f3 = ( 2 * u * u - u) ;
		draw_pixel(u*100, f1*100,1,0,0);
		draw_pixel(u*100, f2*100,0,1,0);
		draw_pixel(u*100, f3*100,0,0,1);
		printf("\n%f\t%f\t%f\t%f",u,f1,f2,f3);

	}

	for (int i = -100; i <= 100; i++)	//X and Y axis
	{
		draw_pixel(i, 0,1,1,1);
		draw_pixel(0, i,1,1,1);

	}
	for (int i = -2; i <= 2; i++)	
	{
		draw_pixel(95 + i, 4 + i,1,1,1);
		draw_pixel(95 - i, 4 + i,1,1,1);

	}
	for (int i = 0; i <= 2; i++)
	{
		draw_pixel(4 + i, 95 + i,1,1,1);
		draw_pixel(4 - i, 95 + i,1,1,1);
		draw_pixel(4, 95 - i,1,1,1);

	}
	

}

void myDisplay() {
	draw_curve();
	glFlush();
}

void main(int argc, char **argv) {

	/*printf("Enter (x1, y1, x2, y2,x1',y1',x2',y2')\n");
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x_1,&y_1, &x_2, &y_2);
	*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Blending Functions");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
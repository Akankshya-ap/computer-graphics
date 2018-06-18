#include <stdio.h>

#include <GL/glut.h>
#include <iostream>
using namespace std;

int pntX1, pntY1, r[3],t;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}

void plot_off(int x, int y)
{
	glBegin(GL_POINTS);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}

void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}


void midPointCircleAlgo(int i)
{
	int x = 0;
	int y = r[i];
	float decision = 5/4 - r[i];
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void midPointCircleAlgo_old(int r_old)
{

	int x = 0;
	int y = r_old;
	float decision = 5/4 - r_old;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot_off(x, y);
		plot_off(x, -y);
		plot_off(-x, y);
		plot_off(-x, -y);
		plot_off(y, x);
		plot_off(-y, x);
		plot_off(y, -x);
		plot_off(-y, -x);
	}

}

void myDisplay(void)
{
	int i=0,p=1;
	for(i=0;i<3;i++)
	{	
		midPointCircleAlgo(i);
		Sleep(300);
		glFlush ();

	}
	
	while(p<10)
	{	
		int r_old=r[0];
		r[0]+=10;
		r[1]+=10;
		r[2]+=10;
	
		midPointCircleAlgo_old(r_old);
		Sleep(300);
		//for(i=0;i<3;i++)
		//{	
		midPointCircleAlgo(2);
		glFlush ();

		//}
		p++;
		//cout<<"\nEnter more 1/0 :";cin>>p;
		glFlush ();
	}
	glFlush ();
}

void emain(int argc, char** argv)
{	

	
	cout<<"\nCentre at (250,250)\n";
	cout << "Enter the coordinates of the center:\n\n" << endl;
	
	cout << "X-coordinate   : "; cin >> pntX1;
	cout << "\nY-coordinate : "; cin >> pntY1;
	int i=0;
	cout<<"\nEnter radius ";cin>>t;
	r[0]=t;
	r[1]=t+10;
	r[2]=t+20;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Circle Drawing Alogrithms");
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	glutDisplayFunc(myDisplay);
	
//
	myInit ();
	glutMainLoop();

}
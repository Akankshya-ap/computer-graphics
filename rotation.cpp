#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <GL/glut.h>
#define DEG_TO_RAD 0.017453

#include <GL/glut.h>
 
static GLfloat rotat=0.0;
static GLint rotatq=0;
 
void init(void);
void display(void);
void reshape(int w, int h);
void spindisplay(void);
void mouse(int button, int state, int x, int y);
void drawaxis();

int main(int argc, char **argv)
{   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Rotating shape");
    init();
	drawaxis();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutIdleFunc(spindisplay);
    glutMainLoop();
}
void drawaxis()
{
	glColor3f(1.0,1.0,1.0);
	//gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glBegin(GL_LINES);
                glVertex2f(0,500);
                glVertex2f(0,-500);
                glVertex2f(500,0);
                glVertex2f(-500,0);
    glEnd();
}
void init(void)
{   glClearColor(0.0,0.0,0.0,0.0);
	
    glShadeModel(GL_FLAT);
	
}
 
void display(void)
{   glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotat,0.0,0.0,1.0);
    glColor3f(1.0,1.0,1.0);
    glRectf(-200.0,-200.0,-150.0,-150.0);
    glPopMatrix();
    glutSwapBuffers();
}
 
void reshape(int w, int h)
{   glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250.0,250.0,-250.0,250.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
 
void spindisplay(void)
{   if(rotatq==1)
    {   rotat+=0.1;
        if(rotat>360.0)
            rotat-=360.0;
		Sleep(20);
    }
    glutPostRedisplay();
}
 
void mouse(int button, int state, int x, int y)
{   switch(button)
    {   case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                rotatq=1;
            break;
        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                rotatq=0;
            break;
        default:
            break;
    }
}
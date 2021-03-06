// Circle Drawing Algorithm
// Editor: kirito_ys

/* Tips for viewing the output:
 * Use Win +'+' to open magnifier.
 * Use Ctrl + Alt + 'F' for full screen
 * Use Ctrl + Alt + 'L' for lens mode
 * Use Win + Esc to exit magnifier
 */

#include <stdio.h>
//#include <math.h>
#include <GL/glut.h>
#include <windows.h>
#include <time.h>

int WINDOW_WIDTH = 900;
int WINDOW_HEIGHT = 600;

float COLOR_GRAY = 0.5;

double X1, Y1, X2, Y2;
int x0=0;
//int y0=0;

//orthographic projection input variables
//int x1=0,y1=0,z1=0,	x2=0,y2=0,z2=100,	x3=200,y3=0,z3=100,	x4=200,y4=0,z4=0,	h=50,	x5,y5,z5;	
int p[][3]={{0,0,0},{0,0,100},{200,0,100},{200,0,0},{-1,-1,-1}};
int h=150;


void draw_circle(float radius,int x_center,int y_center);
void make_points(int x0,int y0,int x,int y);
int give_rand(int MAX=WINDOW_HEIGHT);
void project_plan();
void project_elevation();
void project_side();

void Init()
{
  // Set clear color to white
  glClearColor(1.0,1.0,1.0,0);
  // Set fill color to black
  glColor3f(1.0,1.0,1.0);
  //glViewport(0 , 0 , 500 , 500);
  // glMatrixMode(GL_PROJECTION); 
  // glLoadIdentity(); 
  // gluOrtho2d(left,right,bottom,top)
  gluOrtho2D(-WINDOW_WIDTH/4 , 3*WINDOW_WIDTH/4 , -WINDOW_HEIGHT/4 , 3*WINDOW_HEIGHT/4);
}

void make_axis(){

	glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINES);
		glVertex2f(0,WINDOW_HEIGHT/2);
		glVertex2f(0,-WINDOW_HEIGHT/2);
		glVertex2f(WINDOW_WIDTH/2,0);
		glVertex2f(-WINDOW_WIDTH/2,0);
	glEnd();
}


int give_rand(int MAX){
	return (MAX*rand())/RAND_MAX;
}

void project_plan(){
	

	glColor3f(0,0,0);

	
	glBegin(GL_TRIANGLE_STRIP);	
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			glVertex2i(p[i][0],p[i][2]);
			glVertex2i(p[j][0],p[j][2]);
		}
	}	
	glEnd();

	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			glVertex2i(p[i][0],p[i][2]);
			glVertex2i(p[j][0],p[j][2]);
		}
	}
	glEnd();

	glColor3f(1,0,0);
	//glPointSize(5);
	glBegin(GL_POINTS);
	for(int i=0;i<5;i++)
		glVertex2i(p[i][0],p[i][2]);
	glEnd();
}

void project_elevation(){
	int t_x = 0;
	int t_y = 200;

	/*glBegin(GL_POLYGON);
	for(int i=0;i<5;i++)
		glVertex2i(p[i][0],p[i][1]);
	glEnd();*/

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_STRIP);	
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			glVertex2i(p[i][0] +t_x,p[i][1] +t_y);
			glVertex2i(p[j][0] +t_x,p[j][1] +t_y);
		}
	}	
	glEnd();
	
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_LINES);
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			glVertex2i(p[i][0] +t_x,p[i][1] +t_y);
			glVertex2i(p[j][0] +t_x,p[j][1] +t_y);
		}
	}
	glEnd();
	
	
}

void project_side(){
	int t_x = 400;
	int t_y = 200;

	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_STRIP);	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			glVertex2i(-p[i][2] +t_x,p[i][1] +t_y);
			glVertex2i(-p[j][2] +t_x,p[j][1] +t_y);
		}
	}	
	glEnd();

	glColor3f(0.8,0.8,0.8);
	glBegin(GL_LINES);
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			glVertex2i(-p[i][2] +t_x,p[i][1] +t_y);
			glVertex2i(-p[j][2] +t_x,p[j][1] +t_y);
		}
	}
	glEnd();

	
}

void graphics_draw(void){
	glClear(GL_COLOR_BUFFER_BIT);
	make_axis();
	glColor3f(1,1,1);

	//finding Coordinates of tip of pyramid
	p[4][0]=p[2][0]/2;
	p[4][1]=h;
	p[4][2]=p[2][2]/2;

	project_plan();
	project_elevation();
	project_side();



	glFlush();
}


void make_points(int x0,int y0,int x,int y){
	glBegin(GL_POINTS);
			glVertex2d(x0+x,y0+y);
			glVertex2d(x0+x,y0-y);
			glVertex2d(x0-x,y0+y);
			glVertex2d(x0-x,y0-y);
			glVertex2d(x0+y,y0+x);
			glVertex2d(x0+y,y0-x);
			glVertex2d(x0-y,y0+x);
			glVertex2d(x0-y,y0-x);
		glEnd();
}


void main(int argc, char **argv)
{
  printf("ORTHO\n");
 
  //make random really random
  srand(time(0));

 
  glFlush();
  // Initialise GLUT library 
  glutInit(&argc,argv);
  // Set the initial display mode 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Set the initial window position and size
  //position means the position of the output screen with r2espect to the monitor screen 
  glutInitWindowPosition(0,0);
  glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
  // Create the window with title "DDA_Line" 
  glutCreateWindow("Orthographic Projection");
  // Initialize drawing colors 
  Init();
  // Call the displaying function 
  glutDisplayFunc(graphics_draw);
  // Keep displaying untill the program is closed 
  glutMainLoop();
  glFlush();
}
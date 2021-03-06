
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
using namespace std;
double X1, Y1, X2, Y2;

float round_value(float v)
{
  return floor(v + 0.5);
}
void LineDDA(void)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  
  glClear(GL_COLOR_BUFFER_BIT);


  glBegin(GL_POINTS);
  glColor3f(1.0,1.0,1.0);
  glVertex2d(x,y);
  int k;
	 /*for(int i=0;i<=625;i++){
	  for(int j=0;j<=625;j++){
	  float error1=0.0;
	  float error2=0.0;
	  float error3=0.0;  
	  for(int m=i;m<=i+2;m++){
		  for(int n=j;n<=j+2;n++){
		  //unsigned char color[3]; 
		  /*glReadPixels(k,l,1,1, GL_RGB , GL_UNSIGNED_BYTE , color); 
		  error1+=color[0]/255.0;
		  error2+=color[1]/255.0;
		  error3+=color[2]/255.0;*/
			/*  x=X1;
			  y=Y1;
			  for(k=0;k<steps;k++)
				{
					x+=xInc;
					y+=yInc;
					if(round_value(x)==m && round_value(y)==n)
						break;
					//glVertex2d(round_value(x), round_value(y));
				}
			  if(k<steps){
				  error1+=1;
				  error2+=1;
				  error3+=1;}
	}
	  }
	  error1/=9.0;
	  error2/=9.0;
	  error3/=9.0;
	  //printf("%f %f %f \n",error1,error2,error3);
	  glColor3f(error1,error2,error3);
	  glVertex2i(i+1,j+1);
  }
  }*/
  unsigned char pixel[9][3];
  int j,i,x1,y1,p=0,q=0;

  for(i=1;i<500-1;i++){
        for(j=1;j<500-1;j++){
        x1=i+1;
        y1=j+1;
        int c=0;
  float r=0,b=0,g=0;

  for(p=x1-1;p<=x1+1;p++)
  {
          for(q=y1-1;q<=y1+1;q++){
                          x=X1,y=Y1;
                  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    if(round_value(x)==p && round_value(y)==q)
                break;
  }
                                  if(k<steps){
                                          r=r+1;
                                  g=g+1;
                                  b=b+1;}
                                  
                  c++;
          }
  }
  
   glColor3f(r/9.0,g/9.0,b/9.0);
   //if(x1==50 && y1==50)
        //printf("%f %f %f\n",r/9.0,g/9.0,b/9.0);
   glVertex2i(x1,y1);

}
}

  glEnd();
   glFlush();
  //glFlush();
}

void Init()
{
 
  glClearColor(0,0,0,0);
  
  glColor3f(0.0,0.0,0.0);
  
  gluOrtho2D(0 , 630 , 0 , 630);
}
void main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn(0,0) to (630,630):\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
  
  
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  glutInitWindowPosition(0,0);
  glutInitWindowSize(630,630);
  
  glutCreateWindow("DDA_Line");
  
  Init();
  
  glutDisplayFunc(LineDDA);
  
  glutMainLoop();
}

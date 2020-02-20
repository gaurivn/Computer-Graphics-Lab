#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb,tx,ty,dx,dy,steps,k;
float xIncrement,yIncrement,x,y,theta;
void display (void)
 {
 dx=xb-xa;
 dy=yb-ya;
	x=xa;y=ya;
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 1.0, 1.0);
 steps=abs(dx);
 xIncrement=dx/(float)steps;
 yIncrement=dy/(float)steps;
 glBegin(GL_POINTS);
float e=2*dy;
float f=e-dx;
glVertex2i(x,y);
for(k=0;k<steps;k++)
 {
	if(f>0)
	{
	f=f+2*dy;
	glVertex2i(x+1,y);
	}
	else{
	f=f+2*dy-2*dx;
	glVertex2i(x+1,y+1);
	}

 x+=xIncrement;
 y+=yIncrement;
 }
 glColor3f (1.0, 1.0, 1.0);
 

 glEnd();
 draw_rotated_fig();
 glFlush();
 }

void draw_rotated_fig(void){
	//xa= (int)(((float)(xa)*cos(0.5))-((float)(ya)*sin(0.5))); 
	xa=xa*cos(0.5)-ya*sin(0.5);
	ya= (int)(((float)(ya)*cos(0.5))+((float)(ya)*sin(0.5))); 
	xb= (int)(((float)(xb)*cos(0.5))-((float)(yb)*sin(0.5))); 
	yb= (int)(((float)(yb)*cos(0.5))+((float)(yb)*sin(0.5))); 


	dx=xb-xa;
 dy=yb-ya;
	x=xa;y=ya;
 glColor3f (1.0, 0.0, 0.0);
 steps=abs(dx);
 xIncrement=dx/(float)steps;
 yIncrement=dy/(float)steps;
 glBegin(GL_POINTS);
float e=2*dy;
float f=e-dx;
glVertex2i(x,y);
for(k=0;k<steps;k++)
 {
	if(f>0)
	{
	f=f+2*dy;
	glVertex2i(x+1,y);
	}
	else{
	f=f+2*dy-2*dx;
	glVertex2i(x+1,y+1);
	}

 x+=xIncrement;
 y+=yIncrement;
 }
 glColor3f (1.0, 0.0, 0.0);
 

 glEnd();


}
 
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
 }

int main(int argc, char** argv)
{
 printf("Enter the points\n");
 scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
 printf("Enter the rotating angle\n");
 scanf("%f",&theta);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (1366, 768);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("Simple DDA ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

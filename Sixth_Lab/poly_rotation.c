#include <GL/glut.h>
#include <GL/gl.h>
//#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int x1,x2,x3,x4,y1,y2,y3,y4,tx,ty;
float rad;
void display (void)
 {

 	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 1.0, 1.0);
 	glBegin(GL_POLYGON);
 	glVertex2i(x1, y1);
  	glVertex2i(x2, y2);
 	 glVertex2i(x3, y3);
 	 glVertex2i(x4, y4);
 	 glEnd();
 	 display_poly_rotated();
  	glFlush();
  }


void display_poly_rotated(void){
	glColor3f (1.0, 0.0, 0.0);
 	glBegin(GL_POLYGON);
 	glVertex2i(x1*cos(rad)-y1*sin(rad), y1*cos(rad)+x1*sin(rad));
  	glVertex2i(x2*cos(rad)-y2*sin(rad), y2*cos(rad)+x2*sin(rad));
 	 glVertex2i(x3*cos(rad)-y3*sin(rad), y3*cos(rad)+x3*sin(rad));
 	 glVertex2i(x4*cos(rad)-y4*sin(rad), y4*cos(rad)+x4*sin(rad));
 	 glEnd();

}

void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
 }

int main(int argc, char** argv)
{
printf("enter first point of polygon: ");
scanf("%d %d",&x1,&y1);
printf("enter 2nd point of polygon: ");
scanf("%d %d",&x2,&y2);
printf("enter 3rd point of polygon: ");
scanf("%d %d",&x3,&y3);
printf("enter 4th point of polygon: ");
scanf("%d %d",&x4,&y4);
printf("enter degree of rotation (in radians upto 2 decimal places): ");
scanf("%f",&rad);

 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (600,600);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("2D Transformation - Polygon Rotation");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

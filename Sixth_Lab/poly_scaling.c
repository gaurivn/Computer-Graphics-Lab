#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
int x1,x2,x3,x4,y1,y2,y3,y4,tx,ty;
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
 	 display_poly_translated();
  	glFlush();
  }


void display_poly_translated(void){
	glColor3f (1.0, 0.0, 0.0);
 	glBegin(GL_POLYGON);
 	glVertex2i(x1*tx, y1*ty);
  	glVertex2i(x2*tx, y2*ty);
 	 glVertex2i(x3*tx, y3*ty);
 	 glVertex2i(x4*tx, y4*ty);
 	 glEnd();

}




  void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
 }

int main(int argc, char** argv)
{
printf("enter first point of polygon\n");
scanf("%d %d",&x1,&y1);
printf("enter 2nd point of polygon\n");
scanf("%d %d",&x2,&y2);
printf("enter 3rd point of polygon\n");
scanf("%d %d",&x3,&y3);
printf("enter 4th point of polygon\n");
scanf("%d %d",&x4,&y4);
printf("enter scaling factor:\n");
scanf("%d %d",&tx,&ty);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (1366, 768);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("2D Transformation - Polygon Scaling");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

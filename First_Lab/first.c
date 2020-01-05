//#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void init(){
 glClearColor(0.0, 0.0, 0.0, 1.0);
 glColor3f(0.5, 0.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-800, 800, -800, 800);
 }
 
 void circle(){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  float x, y, i;
  for(i=0;i<(2*3.14);i+=0.001){
   x = 200 * cos(i); 
   y = 200 * sin(i);
   glVertex2i(x,y);
   }
   glEnd();
 
   glBegin(GL_POLYGON);
   glVertex2i(400,400);
   glVertex2i(400, 800);
   glVertex2i(800, 800);
   glVertex2i(800, 400);
   glEnd();
   glFlush();
  }
  
  int main(int argc, char ** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 650);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Part of Circle");
  init();
  glutDisplayFunc(circle);
  glutMainLoop();
  }
 

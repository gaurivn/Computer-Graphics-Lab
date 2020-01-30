#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <unistd.h>

int X, Y, r;

void Init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,0);
  glMatrixMode(GL_PROJECTION);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}


void drawcirc(){
  glBegin(GL_POINTS);
  int x=0, y=r;
  int p = 3-2*r;
  while(x<y) {
    x++;
    if(p<0)
      p = p + 4*x + 6;
    else {
      p = p + 4*(x-y) + 10;
      y--;
    }
    
    glVertex2d(x + X, y + Y);
    glVertex2d(y + X, x + Y);
    glVertex2d(x + X, -y + Y);
    glVertex2d(y + X, -x + Y);
    glVertex2d(-x + X, -y + Y);
    glVertex2d(-y + X, -x + Y);
    glVertex2d(-x + X, y + Y);
    glVertex2d(-y + X, x + Y);
  }
  

}

void circle(){
 printf("Enter centre (x,y) and radius of the circle\n");
 scanf("%d%d%d",&X,&Y,&r);
 //glClear(GL_COLOR_BUFFER_BIT);
 drawcirc();
 glEnd();
 glFlush();
}

int main(int argc, char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("Bresenham_circle");
  Init();
  glutDisplayFunc(circle);
  glutMainLoop();
}


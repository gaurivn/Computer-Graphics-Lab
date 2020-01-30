#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,200.0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}

void Circle(){
 /*printf("Enter centre (x,y) and radius of the circle\n");
 scanf("%d%d%d",&X,&Y,&r);*/
  int X=100, Y=100, r=50;
  int x=0,y=r;
  int d = 3/2 - r;    // = 1 - r
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f( 1 ,0, 0);
  while(x<=y){
    setPixel(X+x,Y+y);
    setPixel(X+y,Y+x);  //find other points by symmetry
    setPixel(X-x,Y+y);
    setPixel(X+y,Y-x);
    setPixel(X-x,Y-y);
    setPixel(X-y,Y-x);
    setPixel(X+x,Y-y);
    setPixel(X-y,Y+x);

    if (d<0)
  d += (2*x)+3;
    else {
 d += (2*(x-y))+5;
 y -= 1;
    }
    x++;
  }

  glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham Circle");
    init();
    glutDisplayFunc(Circle);
    glutMainLoop();
    return 0;
}


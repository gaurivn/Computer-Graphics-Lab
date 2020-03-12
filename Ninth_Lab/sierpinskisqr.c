

#include <GL/glut.h>
#include<stdio.h>
int n;
float ax=-400,ay=-400,bx=400,by=-400,cx=400,cy=400,dx=-400,dy=400;
void displayCB(void)		
{
  glClear(GL_COLOR_BUFFER_BIT);		
  glColor3f(0.0, 0.0, 0.0);		
  glBegin(GL_POLYGON);			
  glVertex2f(-400,-400);			
  glVertex2f(400,-400);
  glVertex2f(400,400);
  glVertex2f(-400,400);
  glEnd();			
  glFlush();			
}
void gasket(float ax,float ay,float bx,float by,float cx,float cy,float dx,float dy,float n){
  //printf("hello1\n");
  if(n==0){
    return;
  }
  else{
    float midax,miday,midbx,midby,midcx,midcy,middx,middy;
    midax=(bx+2*ax)/3;
    midbx=(2*bx+ax)/3;
    miday=(2*ay+dy)/3;
    midby=(2*by+cy)/3;
    midcx=(2*cx+dx)/3;
    midcy=(2*cy+by)/3;
    middx=(2*dx+cx)/3;
    middy=(2*dy+ay)/3;
    glBegin(GL_POLYGON); 
    glColor3f(1.0, 1.0, 1.0);     
    glVertex2f(midax,miday);      
    glVertex2f(midbx,midby);
    glVertex2f(midcx,midcy);
    glVertex2f(middx,middy);
    glEnd();  
    gasket(ax,ay,midax,ay,midax,miday,ax,miday,n-1);
    gasket(midbx,by,bx,by,bx,midby,midbx,midby,n-1);
    gasket(midcx,midcy,cx,midcy,cx,cy,midcx,cy,n-1);
    gasket(dx,middy,middx,middy,middx,dy,dx,dy,n-1);
    glFlush();
  }
}
void mydisplay(){
  displayCB();
  gasket(ax,ay,bx,by,cx,cy,dx,dy,n);
}

int main(int argc, char *argv[])
{
  int win;
  printf("enter the value of n\n");
  scanf("%d",&n);

  glutInit(&argc, argv);		

  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(400,500);		
  win = glutCreateWindow("square");	

  glClearColor(0.0,0.0,0.0,0.0);
  gluOrtho2D(-500,500,-500,500);		
  glutDisplayFunc(mydisplay);		

  glutMainLoop();			

  return 0;
}

#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void init(){
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0, 900, 0, 900);
}


void display(){
 glClear(GL_COLOR_BUFFER_BIT);
 
 //First mountain
 glColor3f(0.8, 0.1, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(100, 800);
 glVertex2i(0, 650);
 glVertex2i(200, 650);
 glEnd();
 
 //Second mountain
 glBegin(GL_POLYGON);
 glVertex2i(800, 800);
 glVertex2i(700, 650);
 glVertex2i(900, 650);
 glEnd();
 
 //Roof
 glColor3f(0.5, 0.0, 1.0);
 glBegin(GL_POLYGON);
 glVertex2i(450, 800);
 glVertex2i(200, 650);
 glVertex2i(700, 650);
 glEnd();
 
 //Square showing front house wall just under roof
 glColor3f(1.0, 0.6, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(200, 650);
 glVertex2i(700, 650);
 glVertex2i(700, 300);
 glVertex2i(200, 300);
 glEnd();
 
 //Left Window
 glColor3f(0.0, 0.5, 1.0);
 glBegin(GL_POLYGON);
 glVertex2i(250, 600);
 glVertex2i(350, 600);
 glVertex2i(350, 500);
 glVertex2i(250, 500);
 glEnd();
 
 //Right Window
 glColor3f(0.0, 0.5, 1.0);
 glBegin(GL_POLYGON);
 glVertex2i(550, 600);
 glVertex2i(650, 600);
 glVertex2i(650, 500);
 glVertex2i(550, 500);
 glEnd();
 
 //Door
 glColor3f(1.0, 0.4, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(400, 500);
 glVertex2i(500, 500);
 glVertex2i(500, 300);
 glVertex2i(400, 300);
 glEnd();
 
 //1st stair under door
 glColor3f(1.0, 0.2, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(350, 300);
 glVertex2i(550, 300);
 glVertex2i(550, 250);
 glVertex2i(350, 250);
 glEnd();
 
 //2nd stair under door
 glColor3f(1.0, 0.2, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(400, 250);
 glVertex2i(500, 250);
 glVertex2i(500, 200);
 glVertex2i(400, 200);
 glEnd();

 //Sun between first mountain and house roof
 glColor3f(1.0, 0.3, 0.0);
 glBegin(GL_POLYGON);
 float theta;
 for(int i=0;i<360;i++){
  theta = i*3.142/180;
  glVertex2f(300 +50*cos(theta), 800 + 50*sin(theta));
  }
 glEnd();
 
 //3rd stair under door
 /*glColor3f(1.0, 0.2, 0.0);
 glBegin(GL_POLYGON);
 glVertex2i(450, 200);
 glVertex2i(550, 200);
 glVertex2i(550, 150);
 glVertex2i(450, 150);
 glEnd();*/
 glFlush();
 }
 
 
 int main(int argc, char ** argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(1000, 1000);
 glutInitWindowPosition(0, 0);
 glutCreateWindow("A house");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 }
 

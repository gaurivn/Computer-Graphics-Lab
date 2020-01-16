#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <GL/glut.h>

float x01, x02, y01, y02;

void init(){
 glClearColor(0.9, 0.0, 0.0, 0.5);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-100, 100, -100, 200);
}

void display(){
 glClear(GL_COLOR_BUFFER_BIT);
 float dy, dx, s, x, y, k, Xincrement, Yincrement;

 dx = x02-x01;
 dy = y02-y01;
 if(abs(dx)>abs(dy))
 s = dx;
 else
 s = dy;
 Xincrement = dx/s;
 Yincrement = dy/s;
 x = x01;
 y = y01;

 /*glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();*/
 for(k=1;k<s;k++){
 x = x + Xincrement;
 y = y + Yincrement;
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}

 glFlush();
}

int main(int argc, char** argv) {
printf("Enter x1: ");
scanf("%f",&x01);
printf("Enter y1: ");
scanf("%f",&y01);
printf("Enter x2: ");
scanf("%f",&x02);
printf("Enter y2: ");
scanf("%f",&y02);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}






 

#include<stdio.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

const int inside = 0;
const int above = 8; //abrl = 1000
const int below = 4; //abrl = 0100
const int rt = 2; //abrl = 0010  rt right
const int lt = 1;  //abrl = 0001 lt left


const int x_max = 10;
const int y_max = 8; 
const int x_min = 4; 
const int y_min = 4; 

void drawLine(double x1, double y1, double x2, double y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

int region(double x, double y){
  int rc = inside;
  if(x<x_min)
    rc |= lt;
  else if(x>x_max)
    rc |= rt;
  if(y<y_min)
    rc |= below;
  else if(y>y_max)
    rc |= above;
  return rc;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void cslineclip (double x1, double y1, double x2, double y2){
 int rc1 = region(x1, y1);
 int rc2 = region(x2, y2);
 bool acc = false;
 while(true){
 if((rc1==0)&&(rc2==0)){
 acc = true;
 break;
 }
 else if(rc1 & rc2){
 break;
 }
 else{
 int rc_out;
 double x, y;
 if(rc1!=0)
  rc_out = rc1;
 else
  rc_out = rc2;
  if(rc_out & above){
  x = x1 + (x2 - x1) * (y_max - y1)/(y2 - y1);
  y = y_max;
  }
  else if(rc_out & below){
  x = x1 + (x2 - x1) * (y_min - y1)/(y2 - y1);
  y = y_min;
  }
  else if(rc_out & rt){
  y = y1 + (y2 - y1) * (x_max - x1)/(x2 - x1);
  x = x_max;
  }
  else if(rc_out & lt){
  y = y1 + (y2 - y1) * (x_min - x1)/(x2 - x1);
  x = x_min;
  }
 
  if(rc_out==rc1){
  x1 = x;
  y1 = y;
  rc1 = region(x1, y1);
  }
  else{
  x2 = x;
  y2 = y;
  rc2 = region(x2, y2);
  }
 }
}

if(acc)
 cout<<"Accept from "<<"("<<x1<<","<<y1<<") to "<<"("<<x2<<","<<y2<<")\n";
else
 cout<<"Reject\n";
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	//draw clipping area
	glBegin(GL_LINE_LOOP);
	glVertex2i(x_min, y_min);
	glVertex2i(x_max, y_min);
	glVertex2i(x_max, y_max);
	glVertex2i(x_min, y_max);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	cslineclip();

	glFlush();
}



int main(int argc, char** argv){
 double xa1, xa2, ya1, ya2;
 /*cout<<"Enter window coordinates (x_max y_max x_min y_min): ";
 cin>>x_max>>y_max>>x_min>>y_min;*/
 cout<<"Enter line coordinates (x1 y1 x2 y2): ";
 cin>>xa1>>ya1>>xa2>>ya2;
// cslineclip(xa1, ya1, xa2, ya2);
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 150);
 glutCreateWindow(" Cohen Sutherland Line Clipping");
 glutDisplayFunc(display);
 init();
 glutMainLoop();
 return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float angle = 0;

float centre_x = 0, centre_y = 0;
int radius; //= 100;

void initGL(){
    //glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    glFlush();
}

void idle(){
    centre_x -= 0.00001; 
    glutPostRedisplay();
}

void bresenham__line(int x1, int y1, int x2, int y2){
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
}

void bresenham(){
    int dec_param = 3 - 2*radius;
   // glTranslatef(-centre_x, -centre_y, 0);
    int x = 0, y = radius;
    glBegin(GL_POINTS);
    while(x<=y){
        // processing in octant 2 from (x,y)=(0,r) to (x,y)=(r/sqrt(2),r/sqrt(2))
        glVertex2i(x,y);
        glVertex2i(y,x);
        glVertex2i(-x,y);
        glVertex2i(y,-x);
        glVertex2i(-x,-y);
        glVertex2i(-y,-x);
        glVertex2i(x,-y);
        glVertex2i(-y,x);

        // increment x in octant 2
        x++;
        if(dec_param<0){
            dec_param += 4*x + 6;
        }
        else{
            dec_param += 4*(x-y) + 10;
            // decrement y
            y--;
        }
    }
    glEnd();
    glTranslatef(centre_x, centre_y, 0);
    // glFlush();
}

void draw_wheel(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = 100;
    bresenham();
    glPushMatrix();
    glTranslatef(-centre_x, -centre_y, 0);

    glRotatef(angle, 0, 0, 1);

    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y+30);
    glVertex2i(centre_x+0, centre_y+100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y-30);
    glVertex2i(centre_x+0, centre_y-100);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-30, centre_y+0);
    glVertex2i(centre_x-100, centre_y+0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+30, centre_y+0);
    glVertex2i(centre_x+100, centre_y+0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x+21, centre_y+21);
    glVertex2i(centre_x+71, centre_y+71);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x-21, centre_y-21);
    glVertex2i(centre_x-71, centre_y-71);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-21, centre_y+21);
    glVertex2i(centre_x-71, centre_y+71);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+21, centre_y-21);
    glVertex2i(centre_x+71, centre_y-71);
    glEnd();

    radius = 30;
    bresenham();

	    glTranslatef(centre_x, centre_y, 0);
    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(150, centre_y-100);
    glVertex2i(150, centre_y-100);
    glEnd();
    
    glFlush();
    angle+=0.005;

}

void draw_wheel1(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = 160;
    bresenham();
    glPushMatrix();
    glTranslatef(-centre_x, -centre_y, 0);

    glRotatef(angle, 0, 0, 1);

    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y+50);
    glVertex2i(centre_x+0, centre_y+160);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y-50);
    glVertex2i(centre_x+0, centre_y-160);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-50, centre_y+0);
    glVertex2i(centre_x-160, centre_y+0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+50, centre_y+0);
    glVertex2i(centre_x+160, centre_y+0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x+21, centre_y+21);
    glVertex2i(centre_x+71, centre_y+71);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x-21, centre_y-21);
    glVertex2i(centre_x-71, centre_y-71);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-21, centre_y+21);
    glVertex2i(centre_x-71, centre_y+71);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+21, centre_y-21);
    glVertex2i(centre_x+71, centre_y-71);
    glEnd();

    radius = 50;
    bresenham();

	    glTranslatef(centre_x, centre_y, 0);
    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(150, centre_y-100);
    glVertex2i(150, centre_y-100);
    glEnd();
    
    glFlush();
    angle+=0.005;

}

void draw_wheel2(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = 60;
    bresenham();
    glPushMatrix();
    glTranslatef(-centre_x, -centre_y, 0);

    glRotatef(angle, 0, 0, 1);

    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y+15);
    glVertex2i(centre_x+0, centre_y+60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+0, centre_y-15);
    glVertex2i(centre_x+0, centre_y-60);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-15, centre_y+0);
    glVertex2i(centre_x-60, centre_y+0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+15, centre_y+0);
    glVertex2i(centre_x+60, centre_y+0);
    glEnd();

    glBegin(GL_LINES);
    /*glVertex2i(centre_x+21, centre_y+21);
    glVertex2i(centre_x+71, centre_y+71);*/
    glVertex2i(centre_x+11, centre_y+11);
    glVertex2i(centre_x+41, centre_y+41);
    glEnd();
    glBegin(GL_LINES);
    /*glVertex2i(centre_x-21, centre_y-21);
    glVertex2i(centre_x-71, centre_y-71);*/
    glVertex2i(centre_x-11, centre_y-11);
    glVertex2i(centre_x-41, centre_y-41);
    glEnd();

    glBegin(GL_LINES);
    /*glVertex2i(centre_x-21, centre_y+21);
    glVertex2i(centre_x-71, centre_y+71);*/
    glVertex2i(centre_x-11, centre_y+11);
    glVertex2i(centre_x-41, centre_y+41);
    glEnd();
    glBegin(GL_LINES);
    /*glVertex2i(centre_x+21, centre_y-21);
    glVertex2i(centre_x+71, centre_y-71);*/
    glVertex2i(centre_x+11, centre_y-11);
    glVertex2i(centre_x+41, centre_y-41);
    glEnd();

    radius = 15;
    bresenham();

	    glTranslatef(centre_x, centre_y, 0);
    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(150, centre_y-100);
    glVertex2i(150, centre_y-100);
    glEnd();
    
    glFlush();
    angle+=0.005;

}


void keyboard(unsigned char key, int x, int y){
 switch(key){
  case 'i': draw_wheel();
            break;
  case 'd': draw_wheel2();
            break;
  case 'c': exit(0);
            break;
 }
}

void mouse(int button, int state, int x, int y){
 if(button==GLUT_LEFT_BUTTON){ // && state==GLUT_DOWN){
  glutDisplayFunc(draw_wheel);
  }
}


void display(){
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glFlush();
}

int main(int argc, char** argv){
    glClear(GL_COLOR_BUFFER_BIT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0, 0);
    // scanf("%d%d%d", &centre_x, &centre_y, &radius);
    glutCreateWindow("Wheel keyboard mouse event");
    initGL();
   // glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
   // glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

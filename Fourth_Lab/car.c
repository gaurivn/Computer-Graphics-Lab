#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float angle = 0;
int sign = 1;

float centre_x = -100, centre_y = -50;
float centre2_x = 50, centre2_y = -50;
int radius = 100/2;

void initGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}

void idle(){
    centre_x = centre_x +  0.06*sign; 
    centre2_x = centre2_x + 0.06*sign;
    if(sign == 1 && centre2_x > 300){
        sign = -1;
    }
    if(sign == -1 && centre2_x < -300){
        sign = 1;
    }

    glutPostRedisplay();
}


void bresenham(){
    int dec_param = 3 - 2*radius;
    int x = 0, y = radius;
    glTranslatef(centre_x, centre_y, 0);
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
    glTranslatef(-centre_x, -centre_y, 0);
    // glFlush();
}

void bresenham2(){
    int dec_param = 3 - 2*radius;
    int x = 0, y = radius;
    glTranslatef(centre2_x, centre2_y, 0);
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
    glTranslatef(-centre2_x, -centre2_y, 0);
    // glFlush();
}

void draw_wheel1(){
    // glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = 50;
    bresenham();
    glPushMatrix();
    glTranslatef(centre_x, centre_y, 0);

    glRotatef(angle, 0, 0, 1);
    glTranslatef(-centre_x, -centre_y, 0);

    glBegin(GL_LINES);
    glVertex2i(centre_x, centre_y+30/2);
    glVertex2i(centre_x, centre_y+100/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x, centre_y-30/2);
    glVertex2i(centre_x, centre_y-100/2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-30/2, centre_y);
    glVertex2i(centre_x-100/2, centre_y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+30/2, centre_y);
    glVertex2i(centre_x+100/2, centre_y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x+21/2, centre_y+21/2);
    glVertex2i(centre_x+71/2, centre_y+71/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x-21/2, centre_y-21/2);
    glVertex2i(centre_x-71/2, centre_y-71/2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-21/2, centre_y+21/2);
    glVertex2i(centre_x-71/2, centre_y+71/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+21/2, centre_y-21/2);
    glVertex2i(centre_x+71/2, centre_y-71/2);
    glEnd();
    // glTranslatef(-centre_x, -centre_y, 0);

    radius = 15;
    bresenham();

    // glTranslatef(centre_x, centre_y, 0);

    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(-700, -100);
    glVertex2i(700, -100);
    glEnd();
    
    // glFlush();
    angle+=0.05;

}

void draw_wheel2(){
    // glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = 50;
    bresenham2();
    glPushMatrix();
    glTranslatef(centre2_x, centre2_y, 0);

    glRotatef(angle, 0, 0, 1);
    glTranslatef(-centre2_x, -centre2_y, 0);

    glBegin(GL_LINES);
    glVertex2i(centre2_x, centre2_y+30/2);
    glVertex2i(centre2_x, centre2_y+100/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre2_x, centre2_y-30/2);
    glVertex2i(centre2_x, centre2_y-100/2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre2_x-30/2, centre2_y);
    glVertex2i(centre2_x-100/2, centre2_y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre2_x+30/2, centre2_y);
    glVertex2i(centre2_x+100/2, centre2_y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre2_x+21/2, centre2_y+21/2);
    glVertex2i(centre2_x+71/2, centre2_y+71/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre2_x-21/2, centre2_y-21/2);
    glVertex2i(centre2_x-71/2, centre2_y-71/2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre2_x-21/2, centre2_y+21/2);
    glVertex2i(centre2_x-71/2, centre2_y+71/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre2_x+21/2, centre2_y-21/2);
    glVertex2i(centre2_x+71/2, centre2_y-71/2);
    glEnd();
    // glTranslatef(-centre2_x, -centre2_y, 0);

    radius = 15;
    bresenham2();

    // glTranslatef(centre2_x, centre2_y, 0);

    glPopMatrix();

    glBegin(GL_LINES);
    glVertex2i(-150, -100);
    glVertex2i(150, -100);
    glEnd();
    
    // glFlush();
    angle+=0.05;

}

void draw_2_wheel(){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_wheel1();
    draw_wheel2();
    glTranslatef(centre_x, centre_y, 0);

    // bottom horizontal

    glBegin(GL_LINES);
    glVertex2i(50, 0);
    glVertex2i(100, 0);
    glEnd();

    // up left

    glBegin(GL_LINES);
    glVertex2i(0, 100);
    glVertex2i(0, 150);
    glEnd();

    // up right

    glBegin(GL_LINES);
    glVertex2i(150, 100);
    glVertex2i(150, 150);
    glEnd();

    // top horizontal

    glBegin(GL_LINES);
    glVertex2i(0, 150);
    glVertex2i(150, 150);
    glEnd();

    // left horizontal

    glBegin(GL_LINES);
    glVertex2i(-100, 100);
    glVertex2i(0, 100);
    glEnd();

    // left left vertical

    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(-100, 100);
    glEnd();

    // left left bottom

    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(-50, 0);
    glEnd();

    // right horizontal

    glBegin(GL_LINES);
    glVertex2i(150+100, 100);
    glVertex2i(150, 100);
    glEnd();

    // right right vertical

    glBegin(GL_LINES);
    glVertex2i(150+100, 0);
    glVertex2i(150+100, 100);
    glEnd();

    // right right bottom

    glBegin(GL_LINES);
    glVertex2i(150+100, 0);
    glVertex2i(150+50, 0);
    glEnd();

    glTranslatef(-centre_x, -centre_y, 0);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0, 0);
    // scanf("%d%d%d", &centre_x, &centre_y, &radius);
    glutCreateWindow("Bresenham Circle");
    glutDisplayFunc(draw_2_wheel);
    initGL();
    glutIdleFunc(idle);
    glutMainLoop();
}

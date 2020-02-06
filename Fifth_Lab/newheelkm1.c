#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float centre_x = -1000, centre_y = -1000;
int radius1 = 50;
int radius = 50;
int radius2 = 15;
float angle = 0;
int flag = 1;

void initGL(){
    // glClearColor(0, 0, 0, 1);
    gluOrtho2D(-300, 300, -300, 300);
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

void draw_wheel(){
    if(flag){
        glClear(GL_COLOR_BUFFER_BIT);
        flag = 0;
    }
    // glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    radius = radius1;
    bresenham();
    glPushMatrix();
    glTranslatef(centre_x, centre_y, 0);

    glRotatef(angle, 0, 0, 1);
    glTranslatef(-centre_x, -centre_y, 0);

    glBegin(GL_LINES);
    glVertex2i(centre_x, centre_y+radius2);
    glVertex2i(centre_x, centre_y+radius1);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x, centre_y-radius2);
    glVertex2i(centre_x, centre_y-radius1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-radius2, centre_y);
    glVertex2i(centre_x-radius1, centre_y);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+radius2, centre_y);
    glVertex2i(centre_x+radius1, centre_y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x+radius2/1.41, centre_y+radius2/1.41);
    glVertex2i(centre_x+radius1/1.41, centre_y+radius1/1.41);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x-radius2/1.41, centre_y-radius2/1.41);
    glVertex2i(centre_x-radius1/1.41, centre_y-radius1/1.41);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(centre_x-radius2/1.41, centre_y+radius2/1.41);
    glVertex2i(centre_x-radius1/1.41, centre_y+radius1/1.41);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(centre_x+radius2/1.41, centre_y-radius2/1.41);
    glVertex2i(centre_x+radius1/1.41, centre_y-radius1/1.41);
    glEnd();
    // glTranslatef(-centre_x, -centre_y, 0);

    radius = radius2;
    bresenham();

    // glTranslatef(centre_x, centre_y, 0);

    glPopMatrix();

    // glBegin(GL_LINES);
    // glVertex2i(-700, -100);
    // glVertex2i(700, -100);
    // glEnd();
    
    glFlush();
    // angle+=0.05;

}

void mouse(int button, int state, int x, int y){
    int mouse_x = x - 300, mouse_y = -y + 300;
    // printf("%d %d %d %d\n", x, y, mouse_x, mouse_y);
    switch(button){
        case GLUT_LEFT_BUTTON:
            centre_x = mouse_x, centre_y = mouse_y;
            draw_wheel();
            glutPostRedisplay();
            break;
        case GLUT_RIGHT_BUTTON:
            exit(1);
        default: return;
    }

}

void keyboard(unsigned char key, int x, int y){
    if (key=='i'){
        radius1 += 10;
        radius2 += 5;
    }
    if (key=='d'){
        radius1 -= 10;
        radius2 -= 5;
    }
    if (key == 'c'){
        centre_x = -1000, centre_y = -1000;
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Keyboard and Mouse");
    glutDisplayFunc(draw_wheel);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
}

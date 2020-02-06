#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

float cx = 0, cy = 0;
float sqw = 30;
float handh = 30, handw = 5;
float gap = 4;
float legh = 10, legw = 7;
float angle = 0;
int rotate = 0;
float scalex = 1, scaley = 1;
int clear = 0;
float headrad = 30;
float eyerad = 3, hornlen = 10;

void initGL(){
    // glClearColor(0, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.7);
    gluOrtho2D(-300, 300, -300, 300);
}

void bresenham(int centre_x, int centre_y, int radius){
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

void bresenham_semi(int centre_x, int centre_y, int radius){
    int dec_param = 3 - 2*radius;
    int x = 0, y = radius;
    glTranslatef(centre_x, centre_y, 0);
    glBegin(GL_POINTS);
    while(x<=y){
        // processing in octant 2 from (x,y)=(0,r) to (x,y)=(r/sqrt(2),r/sqrt(2))
        glVertex2i(x,y);
        glVertex2i(y,x);
        glVertex2i(-x,y);
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

void idle(){
    if(rotate){
        angle += 0.05;
    }
    else{
        angle = 0;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    int mouse_x = x - 300, mouse_y = -y + 300;
    switch(button){
        case GLUT_RIGHT_BUTTON:
            exit(1);
        default: return;
    }

}

void keyboard(unsigned char key, int x, int y){
    if (key=='i'){
        scalex += 0.1;
        scaley += 0.1;
    }
    if (key=='d'){
        scalex -= 0.1;
        scaley -= 0.1;
        if(scalex <= 0 | scaley <= 0){
            scalex = 0, scaley = 0;
        }
    }
    if (key=='t'){
        cx += 4;
    }
    if (key=='h'){
        cx -= 4;
    }
    if (key=='c'){
        clear = 1;
    }
    else{
        clear = 0;
    }
    if (key == 'r'){
        rotate = 1;
    }
    if (key == 's'){
        rotate = 0;
        // cx = 0, cy = 0;
    }
    if (key == 'e'){
        exit(1);
    }
    glutPostRedisplay();
    
}

void draw_figure(){
    if (clear){
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        return;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glScalef(scalex, scaley, 0);

    // glRotatef(angle, 0, 0, 1); 

    // ------------------------------------- central body
    // body top hori
    glBegin(GL_LINES);
    glVertex2i(-sqw, +sqw);
    glVertex2i(+sqw, +sqw);
    glEnd();
    // body bottom hori
    glBegin(GL_LINES);
    glVertex2i(-sqw, -sqw);
    glVertex2i(+sqw, -sqw);
    glEnd();
    // body left vert
    glBegin(GL_LINES);
    glVertex2i(-sqw, -sqw);
    glVertex2i(-sqw, +sqw);
    glEnd();
    // body right vert
    glBegin(GL_LINES);
    glVertex2i(+sqw, +sqw);
    glVertex2i(+sqw, -sqw);
    glEnd();

    // ------------------------------------- left hand
    glPushMatrix();
    if(rotate){
        glTranslatef(0, sqw, 0);
        glRotatef(angle, 1, 0, 0);
        glTranslatef(0, -sqw, 0);
    }
    glTranslatef(- sqw - handw - gap, 0, 0);
    // body top hori
    glBegin(GL_LINES);
    glVertex2i(-handw, handh);
    glVertex2i(+handw, +handh);
    glEnd();
    // body bottom hori
    glBegin(GL_LINES);
    glVertex2i(-handw, -handh);
    glVertex2i(+handw, -handh);
    glEnd();
    // body left vert
    glBegin(GL_LINES);
    glVertex2i(-handw, -handh);
    glVertex2i(-handw, +handh);
    glEnd();
    // body right vert
    glBegin(GL_LINES);
    glVertex2i(+handw, +handh);
    glVertex2i(+handw, -handh);
    glEnd();
    glTranslatef(+ sqw + handw + gap, 0, 0);

    // ------------------------------------- right hand
    glTranslatef(+ sqw + handw + gap, 0, 0);
    // body top hori
    glBegin(GL_LINES);
    glVertex2i(-handw, handh);
    glVertex2i(+handw, +handh);
    glEnd();
    // body bottom hori
    glBegin(GL_LINES);
    glVertex2i(-handw, -handh);
    glVertex2i(+handw, -handh);
    glEnd();
    // body left vert
    glBegin(GL_LINES);
    glVertex2i(-handw, -handh);
    glVertex2i(-handw, +handh);
    glEnd();
    // body right vert
    glBegin(GL_LINES);
    glVertex2i(+handw, +handh);
    glVertex2i(+handw, -handh);
    glEnd();
    glTranslatef(- sqw - handw - gap, 0, 0);

    // if(rotate){
    //     glTranslatef(0, sqw, 0);
    //     glRotatef(angle, 1, 0, 0);
    //     glTranslatef(0, -sqw, 0);
    // }

    glPopMatrix();

    // ------------------------------------- right leg
    glTranslatef(+ sqw/2, -sqw - legh, 0);
    // body top hori
    glBegin(GL_LINES);
    glVertex2i(-legw, legh);
    glVertex2i(+legw, +legh);
    glEnd();
    // body bottom hori
    glBegin(GL_LINES);
    glVertex2i(-legw, -legh);
    glVertex2i(+legw, -legh);
    glEnd();
    // body left vert
    glBegin(GL_LINES);
    glVertex2i(-legw, -legh);
    glVertex2i(-legw, +legh);
    glEnd();
    // body right vert
    glBegin(GL_LINES);
    glVertex2i(+legw, +legh);
    glVertex2i(+legw, -legh);
    glEnd();
    glTranslatef(- sqw/2, +sqw + legh, 0);

    // ------------------------------------- left leg
    glTranslatef(- sqw/2, -sqw - legh, 0);
    // body top hori
    glBegin(GL_LINES);
    glVertex2i(-legw, legh);
    glVertex2i(+legw, +legh);
    glEnd();
    // body bottom hori
    glBegin(GL_LINES);
    glVertex2i(-legw, -legh);
    glVertex2i(+legw, -legh);
    glEnd();
    // body left vert
    glBegin(GL_LINES);
    glVertex2i(-legw, -legh);
    glVertex2i(-legw, +legh);
    glEnd();
    // body right vert
    glBegin(GL_LINES);
    glVertex2i(+legw, +legh);
    glVertex2i(+legw, -legh);
    glEnd();
    glTranslatef(+ sqw/2, +sqw + legh, 0);

    // ------------------------------------- head
    glTranslatef(0, sqw + gap, 0);
    // head
    bresenham_semi(0, 0, headrad);
    // right horn
    glBegin(GL_LINES);
    glVertex2i(headrad/1.41, headrad/1.41);
    glVertex2i(headrad/1.41 + hornlen, headrad/1.41 + hornlen);
    glEnd();
    // left horn
    glBegin(GL_LINES);
    glVertex2i(-headrad/1.41, headrad/1.41);
    glVertex2i(-headrad/1.41 - hornlen, headrad/1.41 + hornlen);
    glEnd();
    //right eye
    bresenham(sqw/2, sqw/2, eyerad);
    //left eye
    bresenham(-sqw/2, sqw/2, eyerad);
     // bottom line
    glBegin(GL_LINES);
    glVertex2i(-headrad, 0);
    glVertex2i(headrad, 0);
    glEnd();
    glTranslatef(0, -sqw - gap, 0);

    glPopMatrix();
    
    glFlush();
    // angle+=0.05;

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Figure");
    glutDisplayFunc(draw_figure);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    initGL();
    glutIdleFunc(idle);
    glutMainLoop();
}

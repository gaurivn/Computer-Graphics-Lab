
#include <GL/gl.h>
#include <GL/glut.h>
static int window;
int flag = 0, temp = 0;
static int menu_id;
static int submenu_id;
static int submenu_color;

void display () {


    glClear(GL_COLOR_BUFFER_BIT);
    if(flag == 4){
        glColor3f(1.0, 0.0, 0.0);
        if(temp == 1)
            glutSolidTeapot(0.5);
        else if(temp == 2)
            glutWireTeapot(0.5);

    }
    else if(flag == 5){
        glColor3f(0.0, 0.0, 1.0);
        if(temp == 1)
            glutSolidTeapot(0.5);
        else if(temp == 2)
            glutWireTeapot(0.5);
    }
    if(flag == 1)
        glutSolidTeapot(0.5);
    else if(flag == 2)
        glutWireTeapot(0.5);
    else if(flag == 3)
        return;

    glFlush();

}


void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    if(flag == 1 || flag ==2)
        temp = flag;
    flag = num;
  }
  glutPostRedisplay();
} 


void createMenu(){


    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Solid",1);
    glutAddMenuEntry("Wired",2);

    submenu_color = glutCreateMenu(menu);
    glutAddMenuEntry("Red",4);
    glutAddMenuEntry("Blue",5);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 3);
    glutAddSubMenu("Type", submenu_id);
    glutAddSubMenu("Color", submenu_color);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main ( int argc, char * argv[] ) {

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    window =glutCreateWindow("2d teapot");
    glutDisplayFunc(display);

    

    createMenu();
    glutMainLoop();
}

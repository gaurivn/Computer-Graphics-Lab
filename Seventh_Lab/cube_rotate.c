#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>
#define pi 3.142857 

int cx[]={-100,0,200,200,0,-100,100,100,0},cy[]={-100,0,0,200,200,100,100,-100,0},cz[]={0,100,100,100,100,0,0,0,250};
int rx[]={-100,0,200,200,0,-100,100,100,0},ry[]={-100,0,0,200,200,100,100,-100,0},rz[]={0,100,100,100,100,0,0,0,0};
float tx=0,ty=0,tz=0;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glOrtho(-780, 780, -420, 420,-400,400); 
}

void drawQuad(int a,int b,int c, int d)
{
	glVertex3i(cx[a],cy[a],cz[a]);
	glVertex3i(cx[b],cy[b],cz[b]);
	glVertex3i(cx[c],cy[c],cz[c]);
	glVertex3i(cx[d],cy[d],cz[d]);
}

void drawTriangle(int a,int b,int c)
{
	glVertex3i(cx[a],cy[a],cz[a]);
	glVertex3i(cx[b],cy[b],cz[b]);
	glVertex3i(cx[c],cy[c],cz[c]);
}



void display11() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	int i;
	for(i=0;i<9;i++)
	{
		cx[i]-=250;
	}	

       glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		drawQuad(5,6,7,0);
		glColor3f(0.3f, 0.5f, 1.0f);
		drawQuad(5,4,3,6);
		glColor3f(0.5f, 0.5f, 1.0f);
		drawQuad(6,3,2,7);
		glColor3f(0.7f, 0.5f, 1.0f);
		drawQuad(0,5,4,1);
		glColor3f(0.6f, 0.5f, 1.0f);
		drawQuad(1,4,3,2);
		glColor3f(0.8f, 0.5f, 1.0f);
		drawQuad(1,2,7,0);
	glEnd();
	

	float u1,u2,u3;
	float si=sin(tx),co=cos(tx);
	

	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}	
	for(i=0;i<9;i++)
	{
		u1=cx[i];
		u2=co*cy[i]-si*cz[i];
		u3=si*cy[i]+co*cz[i];
		cx[i]=u1;
		cy[i]=u2;
		cz[i]=u3;
	}	
	
	si=sin(ty),co=cos(ty);
	
	for(i=0;i<9;i++)
	{
		u1=co*cx[i]+si*cz[i];
		u2=cy[i];
		u3=-si*cx[i]+co*cz[i];
		cx[i]=u1;
		cy[i]=u2;
		cz[i]=u3;
	}	

	si=sin(tz),co=cos(tz);
	
	for(i=0;i<9;i++)
	{
		u1=co*cx[i]-si*cy[i];
		u2=si*cx[i]+co*cy[i];
		u3=cz[i];
		cx[i]=u1;
		cy[i]=u2;
		cz[i]=u3;
	}	
	
	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}	
	

     glBegin(GL_QUADS);
		drawQuad(5,6,7,0);
		glColor3f(0.3f, 0.5f, 1.0f);
		drawQuad(5,4,3,6);
		glColor3f(0.5f, 0.5f, 1.0f);
		drawQuad(6,3,2,7);
		glColor3f(0.7f, 0.5f, 1.0f);
		drawQuad(0,5,4,1);
		glColor3f(0.6f, 0.5f, 1.0f);
		drawQuad(1,4,3,2);
		glColor3f(0.8f, 0.5f, 1.0f);
		drawQuad(1,2,7,0);
	glEnd();
   glutSwapBuffers();  	
}

int main(int argc, char** argv) {
	printf("Enter rotation angle wrt x,y,z\n");
	scanf("%f %f %f",&tx,&ty,&tz);
	tx=pi*tx/180;
	ty=pi*ty/180;
	tz=pi*tz/180;

   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);  // Position the window's initial top-left corner
   glutCreateWindow("3D Translation");          // Create window with the given title
  
   glutDisplayFunc(display11);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}

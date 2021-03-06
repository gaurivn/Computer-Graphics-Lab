#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>

int cx[]={-100,0,200,200,0,-100,100,100,200},cy[]={-100,0,0,200,200,100,100,-100,200},cz[]={0,100,100,100,100,0,0,0,100};
int rx[]={-100,0,200,200,0,-100,100,100,200},ry[]={-100,0,0,200,200,100,100,-100,200},rz[]={0,100,100,100,100,0,0,0,100};
int tx=0,ty=0,tz=0,flag=0;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
   glOrtho(-780, 780, -420, 420,-400,400); 
}

void factor(int i)
{
	rx[i]=cx[i]*(1.0+(cz[i]+400)/800);
	ry[i]=cy[i]*(1.0+(cz[i]+400)/800);
}

void drawQuad1(int a,int b,int c, int d)
{
	glVertex3i(cx[a],cy[a],cz[a]);
	glVertex3i(cx[b],cy[b],cz[b]);
	glVertex3i(cx[c],cy[c],cz[c]);
	glVertex3i(cx[d],cy[d],cz[d]);
}

void drawQuad(int a,int b,int c, int d)
{
	glVertex3i(rx[a],ry[a],rz[a]);
	glVertex3i(rx[b],ry[b],rz[b]);
	glVertex3i(rx[c],ry[c],rz[c]);
	glVertex3i(rx[d],ry[d],rz[d]);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	   glMatrixMode(GL_MODELVIEW);    
int i;
	for(i=0;i<9;i++)
		factor(i);


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
	
	
	for(i=0;i<8;i++)
	{
		cx[i]+=tx;
		cy[i]+=ty;
		cz[i]+=tz;
	}	
	for(i=0;i<9;i++)
		factor(i);
	
	   glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		drawQuad(5,6,7,0);
		glColor3f(0.3f, 0.5f, 1.0f);
		drawQuad(5,4,3,6);
		glColor3f(0.5f, 0.5f, 1.0f);
		drawQuad(6,3,2,7);
		glColor3f(0.7f, 0.5f, 1.0f);
		drawQuad(0,5,4,1);
		glColor3f(1.6f, 0.5f, 1.0f);
		drawQuad(1,4,3,2);
		glColor3f(0.8f, 0.5f, 1.0f);
		drawQuad(1,2,7,0);
	glEnd();
   glutSwapBuffers();  
}



int main(int argc, char** argv) {
	printf("Enter tx,ty,tz\n");
	scanf("%d %d %d",&tx,&ty,&tz);

   glutInit(&argc, argv);           
   glutInitDisplayMode(GLUT_DOUBLE); 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);  
   glutCreateWindow("Cube Translation");          
   glutDisplayFunc(display);       
   initGL();                      
   glutMainLoop();                 
   return 0;
}

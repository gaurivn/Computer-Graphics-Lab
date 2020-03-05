#include <stdio.h>
#include <GL/glut.h>

int xmin, ymin, xmax, ymax;
int x1, y11, x2, y2;
int rej = 0;
int code1[4] = { 0, 0, 0, 0 };
int code2[4] = { 0, 0, 0, 0 };



int getcode1(int x, int y) {
	if (y > ymax) // above
		code1[0] = 1;
	if (y < ymin) // below
		code1[1] = 1;
	if (x > xmax) // right
		code1[2] = 1;
	if (x < xmin) // left
		code1[3] = 1;

	int codeRes1 = code1[0] * 1000 + code1[1] * 100 + code1[2] * 10 + code1[3];

	return codeRes1;
}

int getcode2(int x, int y) {
	if (y > ymax)  //abrl = 1000
		code2[0] = 1;
	if (y < ymin)  //abrl = 0100
		code2[1] = 1;
	if (x > xmax)  //abrl = 0010
		code2[2] = 1;
	if (x < xmin)  //abrl = 0001
		code2[3] = 1;

	int codeRes2 = code2[0] * 1000 + code2[1] * 100 + code2[2] * 10 + code2[3];

	return codeRes2;
}



void drawLine(int x0, int y0, int x1, int y11)
{
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y11);
	glEnd();
}

void cohenSuth()
{
	if (getcode1(x1, y11) == 0 && getcode2(x2, y2) == 0 && rej == 0)
	{
		drawLine(x1, y11, x2, y2);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (code1[i] == code2[i] && code1[i] == 1)
			{
				rej = 1;
				break;
			}


		}

		if(rej)
		{

			printf("both points lie outside");
		}
		else
		{

			for (int i = 0; i < 4; i++)
			{
				if (code1[i] == 1)
				{
					switch (i)
					{

					case 0:y11 = ymax;
							break;
					case 1:y11 = ymin;
							break;
					case 2:x1 = xmax;
							break;
					case 3:x1 = xmin;
						break;
					}
				}

				if (code2[i] == 1)
				{
					switch (i)
					{
					case 0:y2 = ymax;
						break;
					case 1:y2 = ymin;
						break;
					case 2:x2 = xmax;
						break;
					case 3:x2 = xmin;
						break;
					}
				}



			}

			drawLine(x1, y11, x2, y2);
                     printf("Accept from (%d, %d) to (%d, %d)\n", x1, y11, x2, y2);
		}
                 
	}
}
void code() 
{
	getcode1(x1, y11);
	getcode2(x2, y2);
}


void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	//draw clipping area
	glBegin(GL_LINE_LOOP);
		glVertex2i(xmin, ymin);
		glVertex2i(xmax, ymin);
		glVertex2i(xmax, ymax);
		glVertex2i(xmin, ymax);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	cohenSuth();

	glFlush();
}

int main(int argc, char** argv)
{     printf("Enter window coordinates (x_min y_min x_max y_max): ");
      scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
       printf("Enter line segment coordinates (x1 y1 x2 y2): "); 
	scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
       code();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Line Clipping");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
   return 0;

}

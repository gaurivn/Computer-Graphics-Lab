#include <stdio.h>
#include <GL/glut.h>

int xmin, ymin, xmax, ymax;
int x1, y11, x2, y2, x3, y3;


int rej = 0;
int code1[4] = { 0, 0, 0, 0 };
int code2[4] = { 0, 0, 0, 0 };
int code3[4] = { 0, 0, 0, 0 };



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
	if (y > ymax)
		code2[0] = 1;
	if (y < ymin)
		code2[1] = 1;
	if (x > xmax)
		code2[2] = 1;
	if (x < xmin)
		code2[3] = 1;

	int codeRes2 = code2[0] * 1000 + code2[1] * 100 + code2[2] * 10 + code2[3];

	return codeRes2;
}

int getcode3(int x, int y) {
	if (y > ymax)
		code3[0] = 1;
	if (y < ymin)
		code3[1] = 1;
	if (x > xmax)
		code3[2] = 1;
	if (x < xmin)
		code3[3] = 1;

	int codeRes3 = code3[0] * 1000 + code3[1] * 100 + code3[2] * 10 + code3[3];

	return codeRes3;
}



void drawLine(int x0, int y0, int x1, int y11)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y11);
	glEnd();
}

void cohenSuth()
{
	// 1 2
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

		if (rej)
		{

			printf("both points lie outside");
		}
		else
		{
			int _y11 = y11, _x1= x1, _y2= y2, _x2 = x2;

			for (int i = 0; i < 4; i++)
			{
				
				if (code1[i] == 1)
				{
					switch (i)
					{

					case 0:_y11 = ymax;
							break;
					case 1:_y11 = ymin;
							break;
					case 2:_x1 = xmax;
							break;
					case 3:_x1 = xmin;
						break;
					}
				}

				if (code2[i] == 1)
				{
					switch (i)
					{
					case 0:_y2 = ymax;
						break;
					case 1:_y2 = ymin;
						break;
					case 2:_x2 = xmax;
						break;
					case 3:_x2 = xmin;
						break;
					}
				}



			}

			drawLine(_x1, _y11, _x2, _y2);
                      printf("Accept from (%d, %d) to (%d, %d)\n", _x1, _y11, _x2, _y2);
		}
	}
	rej = 0;


	// 2 3
	if (getcode1(x2, y2) == 0 && getcode2(x3, y3) == 0 && rej == 0)
	{
		drawLine(x2, y2, x3, y3);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (code2[i] == code3[i] && code2[i] == 1)
			{
				rej = 1;
				break;
			}


		}

		if (rej)
		{

			printf("both points lie outside");
		}
		else
		{	int _y2 = y2, _x2= x2, _y3= y3, _x3 = x3;

			for (int i = 0; i < 4; i++)
			{
				

				if (code2[i] == 1)
				{
					switch (i)
					{

					case 0:_y2 = ymax;
							break;
					case 1:_y2 = ymin;
							break;
					case 2:_x2 = xmax;
							break;
					case 3:_x2 = xmin;
						break;
					}
				}

				if (code3[i] == 1)
				{
					switch (i)
					{
					case 0:_y3 = ymax;
						break;
					case 1:_y3 = ymin;
						break;
					case 2:_x3 = xmax;
						break;
					case 3:_x3 = xmin;
						break;
					}
				}



			}

			drawLine(_x2, _y2, _x3, _y3);
                       printf("Accept from (%d, %d) to (%d, %d)\n", _x2, _y2, _x3, _y3);
		}
	}
	 rej = 0;


	//1 3 
	if (getcode1(x1, y11) == 0 && getcode2(x3, y3) == 0 && rej == 0)
	{
		drawLine(x1, y11, x3, y3);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (code1[i] == code3[i] && code3[i] == 1)
			{
				rej = 1;
				break;
			}


		}

		if (rej)
		{

			printf("Both points lie outside");
		}
		else
		{
			int _y11 = y11, _x1= x1, _y3= y3, _x3 = x3;
			for (int i = 0; i < 4; i++)
			{

				
				if (code1[i] == 1)
				{
					switch (i)
					{

					case 0:_y11 = ymax;
							break;
					case 1:_y11 = ymin;
							break;
					case 2:_x1 = xmax;
							break;
					case 3:_x1 = xmin;
						break;
					}
				}

				if (code3[i] == 1)
				{
					switch (i)
					{
					case 0:_y3 = ymax;
						break;
					case 1:_y3 = ymin;
						break;
					case 2:_x3 = xmax;
						break;
					case 3:_x3 = xmin;
						break;
					}
				}



			}

			drawLine(_x1, _y11, _x3, _y3);
                        printf("Accept from (%d, %d) to (%d, %d)\n", _x1, _y11, _x3, _y3);
                        
		}
	}



}
void code() 
{
	getcode1(x1, y11);
	getcode2(x2, y2);
	getcode3(x3, y3);
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


void display(void)
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

	
	cohenSuth();

	glFlush();
}

/*void drawString(float x, float y, float z, char *string) {
  glRasterPos3f(x, y, z);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);  // Updates the position
  }
}*/

int main(int argc, char** argv)
{   
     printf("Enter window coordinates (x_min y_min x_max y_max): ");
      scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
	printf("Enter triangle coordinates (x1 y1 x2 y2 x3 y3): ");
	scanf("%d %d %d %d %d %d", &x1, &y11, &x2, &y2, &x3, &y3);
       
	//drawString(0 , 0,0, "cohen");
        //glutInit(&argc, argv);
	code();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Triangle Clipping ");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
   return 0;

}

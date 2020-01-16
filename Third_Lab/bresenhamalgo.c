#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int x01, y01, x02, y02;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x01, int x02, int y01, int y02) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x02-x01;
	dy = y02-y01;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x02 < x01) incx = -1;
	incy = 1;
	if (y02 < y01) incy = -1;
	x = x01; y = y01;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	draw_line(x01, x02, y01, y02);
	glFlush();
}

void main(int argc, char **argv) {

	printf( "Enter (x1, y1, x2, y2)\n");
	scanf("%d %d %d %d", &x01, &y01, &x02, &y02);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}














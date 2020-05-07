#include <freeglut.h>
#include <glut.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
int A = 250, B = 500, C = 100, D = 150, E = 200, F = 300 ,G = 350, H = 400;
float korX = 250, korY=250;
bool done = false;


void write(float x, float y, float z, void* font, const char* string)
{
	glColor3f(1, 1, 1);
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
	exit(0);
}

void portal()
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(500, 0);
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex2f(0, 0);
	glEnd();


	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex2f(500, 250);
	glVertex2f(0, 250);
	glVertex2f(50, 500);
	glVertex2f(350, 0);
	glVertex2f(400, 0);
	glVertex2f(450, 0);
	glVertex2f(300, 0);
	glVertex2f(250, 0);
	glVertex2f(300, 500);
	glEnd();

	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex2f(250, 500);
	glVertex2f(100, 500);
	glVertex2f(50, 0);
	glVertex2f(100, 0);
	glVertex2f(150, 0);
	glVertex2f(200, 0);
	glVertex2f(150, 500);
	glVertex2f(200, 500);
	glVertex2f(350, 500);
	glVertex2f(400, 500);
	glVertex2f(450, 500);

	glEnd();

	glColor3f(0.1f, 0.0f, 0.1f);
	glBegin(GL_POINTS);
	glVertex2f(0, 50);
	glVertex2f(0, 100);
	glVertex2f(500, 200);
	glVertex2f(0, 200);
	glVertex2f(0, 300);
	glVertex2f(500, 400);
	glVertex2f(500, 450);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(500, 50);
	glVertex2f(500, 100);
	glVertex2f(500, 150);
	glVertex2f(0, 150);
	glVertex2f(500, 300);
	glVertex2f(500, 350);
	glVertex2f(0, 350);
	glVertex2f(0, 400);
	glVertex2f(0, 450);

	glEnd();
	
	glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(korX, korY);
	glEnd();

}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 'd':
	case 'D':
		korX += 5;
		break;
	}

	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 'a':
	case 'A':
		korX -= 5;
		break;
	}

	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 'w':
	case 'W':
		korY += 5;
		break;
	}

	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 's':
	case 'S':
		korY -= 5;
		break;
	}

	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 'd':
	case 'D':
		korX += 5;
		break;
	}

	if (korX == 500 && korY == A)
	{
		korX = 0, korY = 250;
	}

	else if (korX > 500)
	{
		korX = 250, korY = 250;
	}

	else if (korY > 500 && korX == A)
	{
		korX = 0, korY = 450;
	}

	else if (korY > 500 && korX == F)
	{
		korX = 0, korY = 150;
	}

	else if (korY < 0 && korX == F)
	{
		korX = 0, korY = 200;
	}

	else if (korY < 0 && korX == A)
	{
		korX = 0, korY = 250;
	}

	else if (korY > 500)
	{
		korX = 250, korY = 250;
	}

	else if (korX < 0)
	{
		korX = 250, korY = 250;
	}

	else if (korY < 0)
	{
		korX = 250, korY = 250;
	}

	else if (korX == 100 && korY == B) done = true;

	glutPostRedisplay();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	portal();
	if (done) write(0, 25.0f, 0, GLUT_BITMAP_HELVETICA_18, "You Won, press enter to exit");
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Exit The Game");
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return EXIT_SUCCESS;
}
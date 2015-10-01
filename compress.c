#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int verts[10][2];
int wd;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		for(int i = 0; i < 10; i++) {
			verts[i][0] = i;
			verts[i][1] = 5;
			glVertex2iv((GLint *) verts[i]);
		}
	glEnd();
	glFlush();
}

void kbd(unsigned char key, int x, int y)
{
  switch((char)key) {
  case 'q':
  case 27:
    glutDestroyWindow(wd);
    exit(0);
  default:
    break;
  }
}


int main(int argc, char** argv) {
	printf("Hello World!\n");

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 500);

	wd = glutCreateWindow("Main window");

	glutDisplayFunc(display);

	glutKeyboardFunc(kbd);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);

	glutMainLoop();

	exit(0);
}
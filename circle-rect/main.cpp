
#include <gl/glut.h>
#include <math.h>


void circle()
{	
	glColor3f (1,0,0);
	glBegin (GL_POLYGON);
	for (int i = 0; i < 20; i++) 
		glVertex2d (cos(i*6.28/20), sin(i*6.28/20));
	glEnd();
}

double cx,cy;
void display()
{
	glClear (GL_COLOR_BUFFER_BIT);
	
	glColor3f (1,1,0);
	glLineWidth (4.0);
	glBegin (GL_LINE_LOOP);
	glVertex2i (-6,6); glVertex2i (-6,-6); glVertex2i (6,-6); glVertex2i (6,6); 
	glEnd();

	glPushMatrix();
		glTranslated (cx,cy,0);
		circle();
	glPopMatrix();
	
	glutSwapBuffers();
}

extern bool CircleRectCD (double, double, double, double[2], double[2]);

void passive (int mx, int my)
{
		cx = -10+mx/20.;
		cy = 10 - my/20.;
		
		double min[2] = {-6,-6};
		double max[2] = {6,6};
		if (CircleRectCD (cx, cy, 1, min, max)) {
			glPolygonMode (GL_FRONT, GL_FILL);
		}
		else {
			glPolygonMode (GL_FRONT, GL_LINE);
		}

		glutPostRedisplay();
}


void main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize (400,400);
	glutCreateWindow ("circ-rect");
	glutDisplayFunc (display);

	glutPassiveMotionFunc (passive);

	glViewport (0,0,400,400);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity(); gluOrtho2D (-10,10,-10,10);
	glMatrixMode (GL_MODELVIEW); glLoadIdentity();
	glutMainLoop();
}

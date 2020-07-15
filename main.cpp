/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button,int state,int x,int y);
void mouseMotion(int x,int y);
float xrot=0.0f;
float yrot=0.0f;
float xdiff=0.0f;
float ydiff=0.0f;
bool mouseDown=false;
int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 80);
	glutCreateWindow("ONG WILLIAM RAVEN WIJAYA - 672018070");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_PROJECTION);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{glPushMatrix();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClear(GL_COLOR_BUFFER_BIT);
gluLookAt(0,10,20,0,0,0,0,1,0);
glRotatef(xrot,1.0f,0.0f,0.0f);
glRotatef(yrot,0.0f,1.0f,0.0f);

	//depan

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-20.0, -10.0, -10.0);
	glVertex3f(-20.0, 10.0, -10.0);
	glVertex3f(20.0, 10.0, -10.0);
	glVertex3f(20.0, -10.0, -10.0);
	glEnd();



	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, -10.0, -35.0);
	glVertex3f(-30.0, 10.0, -35.0);
	glVertex3f(5.0, 10.0, -35.0);
	glVertex3f(5.0, -10.0, -35.0);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.0, -10.0, -34.9);
	glVertex3f(-0.0, 0.0, -34.9);
	glVertex3f(3.0, 0.0, -34.9);
	glVertex3f(3.0, -10.0, -34.9);
	glEnd();
	    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.0, -10.0, -35.1);
	glVertex3f(-0.0, 0.0,-35.1);
	glVertex3f(3.0, 0.0, -35.1);
	glVertex3f(3.0, -10.0,-35.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(5.0, -10.0, -35.0);
	glVertex3f(5.0, 10.0, -35.0);
	glVertex3f(5.0, 10.0, -50.0);
	glVertex3f(5.0, -10.0, -50.0);
	glEnd();


//wc
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(23.0, -10.0, -35.0);
	glVertex3f(23.0, 10.0, -35.0);
	glVertex3f(23.0, 10.0, -50.0);
	glVertex3f(23.0, -10.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(23.0, -10.0, -35.0);
	glVertex3f(23.0, 10.0, -35.0);
	glVertex3f(30.0, 10.0, -35.0);
	glVertex3f(30.0, -10.0, -35.0);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(24.0, -10.0, -35.1);
	glVertex3f(26.0, -10.0,-35.1);
	glVertex3f(26.0, 0.0, -35.1);
	glVertex3f(24.0, 0.0,-35.1);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(24.0, -10.0, -34.9);
	glVertex3f(26.0, -10.0,-34.9);
	glVertex3f(26.0, 0.0, -34.9);
	glVertex3f(24.0, 0.0,-34.9);
	glEnd();


	//depan tjl1

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, -10.0, 0.0);
	glVertex3f(-30.0, 10.0, 0.0);
	glVertex3f(-20.0, 10.0, 0.0);
	glVertex3f(-20.0, -10.0, 0.0);
	glEnd();
	//kanan tjl1

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -10.0, 0.0);
	glVertex3f(-20.0, 10.0, 0.0);
	glVertex3f(-20.0, 10.0, -10.0);
	glVertex3f(-20.0, -10.0, -10.0);
	glEnd();
	//kiri tjl3

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, -10.0, 0.0);
	glVertex3f(5.0, 10.0, 0.0);
	glVertex3f(5.0, 10.0, -10.0);
	glVertex3f(5.0, -10.0, -10.0);
	glEnd();
	//kanan tjl3

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -10.0, 0.0);
	glVertex3f(-5.0, 10.0, 0.0);
	glVertex3f(-5.0, 10.0, -10.0);
	glVertex3f(-5.0, -10.0, -10.0);
	glEnd();
	//depan tjl3

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-5.0, -10.0, 0.0);
	glVertex3f(-5.0, 10.0, 0.0);
	glVertex3f(5.0, 10.0, 0.0);
	glVertex3f(5.0, -10.0, 0.0);
	glEnd();

	//pintud1

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(-18.0, -10.0, -9.9);
	glVertex3f(-18.0, 4.0, -9.9);
	glVertex3f(-13.0, 4.0, -9.9);
	glVertex3f(-13.0, -10.0, -9.9);
	glEnd();

	//pintub1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(-18.0, -10.0, -10.1);
	glVertex3f(-18.0, 4.0, -10.1);
	glVertex3f(-13.0, 4.0, -10.1);
	glVertex3f(-13.0, -10.0, -10.1);
	glEnd();
	//pintud2

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(21.0, -10.0, 0.1);
	glVertex3f(21.0, 4.0, 0.1);
	glVertex3f(26.0, 4.0, 0.1);
	glVertex3f(26.0, -10.0, 0.1);
	glEnd();

	//pintub2
glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(21.0, -10.0, -0.1);
	glVertex3f(21.0, 4.0, -0.1);
	glVertex3f(26.0, 4.0, -0.1);
	glVertex3f(26.0, -10.0, -0.1);
	glEnd();

	//jendelad2
    glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(27.0, -8.0, 0.1);
	glVertex3f(27.0, 4.0, 0.1);
	glVertex3f(29.0, 4.0, 0.1);
	glVertex3f(29.0, -8.0, 0.1);
	glEnd();

	//jendelab2
    glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(27.0, -8.0, -0.1);
	glVertex3f(27.0, 4.0, -0.1);
	glVertex3f(29.0, 4.0, -0.1);
	glVertex3f(29.0, -8.0, -0.1);
	glEnd();
//jendela1d
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-29.0, -8.0, 0.1);
	glVertex3f(-29.0, 4.0, 0.1);
	glVertex3f(-21.0, 4.0, 0.1);
	glVertex3f(-21.0, -8.0, 0.1);
	glEnd();
	//jendela1b
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-28.0, -8.0, -0.1);
	glVertex3f(-28.0, 4.0, -0.1);
	glVertex3f(-20.0, 4.0, -0.1);
	glVertex3f(-20.0, -8.0, -0.1);
	glEnd();


	//jendela2d
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-12.0, -8.0, -9.9);
	glVertex3f(-12.0, 4.0, -9.9);
	glVertex3f(-7.0, 4.0, -9.9);
	glVertex3f(-7.0, -8.0, -9.9);
	glEnd();
	//jendela2b
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-12.0, -8.0, -10.1);
	glVertex3f(-12.0, 4.0, -10.1);
	glVertex3f(-7.0, 4.0, -10.1);
	glVertex3f(-7.0, -8.0, -10.1);
	glEnd();
	//jendela3d
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-3.0, -8.0, 0.1);
	glVertex3f(-3.0, 4.0, 0.1);
	glVertex3f(3.0, 4.0, 0.1);
	glVertex3f(3.0, -8.0, 0.1);
	glEnd();
	//jendela3b
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-3.0, -8.0, -0.1);
	glVertex3f(-3.0, 4.0, -0.1);
	glVertex3f(3.0, 4.0, -0.1);
	glVertex3f(3.0, -8.0, -0.1);
	glEnd();


	//pintu tengah
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(-3.0, -10.0,-9.9);
	glVertex3f(-3.0, 4.0, -9.9);
	glVertex3f(3.0, 4.0, -9.9);
	glVertex3f(3.0, -10.0, -9.9);
	glEnd();
	//pintu tengah
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.2, 0.0);
	glVertex3f(-3.0, -10.0,-10.1);
	glVertex3f(-3.0, 4.0, -10.1);
	glVertex3f(3.0, 4.0, -10.1);
	glVertex3f(3.0, -10.0, -10.1);
	glEnd();

	//jendelad4
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(7.0, -8.0, -9.9);
	glVertex3f(7.0, 4.0, -9.9);
	glVertex3f(18.0, 4.0, -9.9);
	glVertex3f(18.0, -8.0, -9.9);
	glEnd();

	//jendelab4
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(7.0, -8.0, -10.1);
	glVertex3f(7.0, 4.0, -10.1);
	glVertex3f(18.0, 4.0, -10.1);
	glVertex3f(18.0, -8.0, -10.1);
	glEnd();



	//depan tjl2

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(30.0, -10.0, 0.0);
	glVertex3f(30.0, 10.0, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(20.0, -10.0, 0.0);
	glEnd();
//marmer
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.8, 0.8);
	glVertex3f(-30.0, -10.0, 10.0);
	glVertex3f(30.0, -10.0, 10.0);
	glVertex3f(30.0, -10.0, 0.0);
	glVertex3f(-30.0, -10.0, 0.0);
	glEnd();

	//tembokpager2
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(30.0, -10.0, 10.0);
	glVertex3f(30.0, 0.0, 10.0);
	glVertex3f( 10.0, 0.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();
	//tembokpager1
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, -10.0, 10.0);
	glVertex3f(-30.0, 0.0, 10.0);
	glVertex3f( -10.0, 0.0, 10.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glEnd();
	//tembokpager1
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, -6.0, 10.0);
	glVertex3f( 10.0, -6.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-10.0, -4.0, 10.0);
	glVertex3f(-10.0, -3.0, 10.0);
	glVertex3f( 10.0, -3.0, 10.0);
	glVertex3f(10.0, -4.0, 10.0);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-10.0, -1.0, 10.0);
	glVertex3f(-10.0, -0.0, 10.0);
	glVertex3f( 10.0, -0.0, 10.0);
	glVertex3f(10.0, -1.0, 10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-2.0, -10.0, 10.0);
	glVertex3f(-2.0, -0.0, 10.0);
	glVertex3f( 2.0, -0.0, 10.0);
	glVertex3f(2.0, -10.0, 10.0);
	glEnd();



	//kanan tjl2

	glBegin(GL_QUADS);
	glColor3f(1.0, 1, 1);
	glVertex3f(20.0, -10.0, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(20.0, 10.0, -10.0);
	glVertex3f(20.0, -10.0, -10.0);
	glEnd();



	//belakang

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, -10.0, -50.0);
	glVertex3f(-30.0, 15.0, -50.0);
	glVertex3f(30.0, 15.0, -50.0);
	glVertex3f(30.0, -10.0, -50.0);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(30.0, 10.0, 10.0);
	glVertex3f(30.0, -10.0, 10.0);
	glVertex3f(30.0, -10.0, -50.0);
	glVertex3f(30.0, 10.0, -50.0);
	glEnd();

	//kanan segitiga
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(30.0, 10.0, 10.0);
	glVertex3f(30.0, 10.0, -50.0);
	glVertex3f(30.0, 15.0, -50.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, 10.0, 10.0);
	glVertex3f(-30.0, -10.0, 10.0);
	glVertex3f(-30.0, -10.0, -50.0);
	glVertex3f(-30.0, 10.0, -50.0);
	glEnd();
	//kiri segitiga
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.9, 0.8);
	glVertex3f(-30.0, 10.0, 10.0);
	glVertex3f(-30.0, 10.0, -50.0);
	glVertex3f(-30.0, 15.0, -50.0);

	glEnd();
	//atas==========================================================================
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-30.0, 10.0, 10.0);
	glVertex3f(30.0, 10.0, 10.0);
	glVertex3f(30.0, 10.0, -50.0);
	glVertex3f(-30.0, 10.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-30.0, 10.0, 12.0);
	glVertex3f(30.0, 10.0, 12.0);
	glVertex3f(30.0, 15.0, -50.0);
	glVertex3f(-30.0, 15.0, -50.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-30.0, -10.0, 0.0);
	glVertex3f(30.0, -10.0, 0.0);
	glVertex3f(30.0, -10.0, -50.0);
	glVertex3f(-30.0, -10.0, -50.0);
	glEnd();
//meja
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-25.0, -10.0, -50.0);
	glVertex3f(-25.0, -10.0, -45.0);
	glVertex3f(-25.0, -5.0, -45.0);
	glVertex3f(-25.0, -5.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-20.0, -10.0, -50.0);
	glVertex3f(-20.0, -10.0, -45.0);
	glVertex3f(-20.0, -5.0, -45.0);
	glVertex3f(-20.0, -5.0, -50.0);
	glEnd();

		glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-20.0, -5.0, -50.0);
	glVertex3f(-25.0, -5.0, -50.0);
	glVertex3f(-25.0, -5.0, -45.0);
	glVertex3f(-20.0, -5.0, -45.0);
	glEnd();

	//laptop
		glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-21.0, -4.9, -47);
	glVertex3f(-23.0, -4.9, -47.0);
	glVertex3f(-23.0, -4.9, -45.0);
	glVertex3f(-21.0, -4.9, -45.0);
	glEnd();
	//keyboard
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-21.1, -4.8, -46.8);
	glVertex3f(-22.9, -4.8, -46.8);
	glVertex3f(-22.9, -4.8, -45.5);
	glVertex3f(-21.1, -4.8, -45.5);
	glEnd();



    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-21.0, -4.9, -47);
	glVertex3f(-23.0, -4.9, -47.0);
	glVertex3f(-23.0,- 3, -47.0);
	glVertex3f(-21.0, -3, -47.0);
	glEnd();
	//kursi
    glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-24.0, -10.0, -42.0);
	glVertex3f(-22.0, -10.0, -42.0);
	glVertex3f(-22.0, -5.0, -42.0);
	glVertex3f(-24.0, -5.0, -42.0);
	glEnd();

	  glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-24.0, -10.0, -44.0);
	glVertex3f(-22.0, -10.0, -44.0);
	glVertex3f(-22.0, -7.0, -44.0);
	glVertex3f(-24.0, -7.0, -44.0);
	glEnd();
	  glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-24.0, -7.0, -42.0);
	glVertex3f(-22.0, -7.0, -42.0);
	glVertex3f(-22.0, -7.0, -44.0);
	glVertex3f(-24.0, -7.0, -44.0);
	glEnd();

	//cermin
    glBegin(GL_QUADS);
	glColor3f(0.9, 0.5, 0.0);
	glVertex3f(-19.0, -10.0, -49.9);
	glVertex3f(-15.0, -10.0, -49.9);
	glVertex3f(-15.0, 0.0, -49.9);
	glVertex3f(-19.0, 0.0, -49.9);
	glEnd();
	 glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-18.5, -9.0, -49.8);
	glVertex3f(-15.5, -9.0, -49.8);
	glVertex3f(-15.5, -1.0, -49.8);
	glVertex3f(-18.5, -1.0, -49.8);
	glEnd();



	//lukisan
    glBegin(GL_QUADS);
	glColor3f(0.9, 0.5, 0.0);
	glVertex3f(-10.0, -3.0, -49.9);
	glVertex3f(-0.0, -3.0, -49.9);
	glVertex3f(-0.0, 4.0, -49.9);
	glVertex3f(-10.0, 4.0, -49.9);
	glEnd();

	  glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-9.5, -2.5, -49.8);
	glVertex3f(-0.5, -2.5, -49.8);
	glVertex3f(-0.5, 3.5, -49.8);
	glVertex3f(-9.5, 3.5, -49.8);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1, -1.5, -49.7);
	glVertex3f(-0.5, -1.5, -49.7);
	glVertex3f(-0.5, 3.5, -49.7);
	glVertex3f(-1, 3.5, -49.7);
	glEnd();


	 glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1, -2, -49.7);
	glVertex3f(-8, -2, -49.7);
	glVertex3f(-4, 3.5, -49.7);

	glEnd();






//r2==========================================================

	glPopMatrix();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case '6':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}


void idle(){
if(!mouseDown){
xrot+=0.3f;
yrot+=0.4f;
}glutPostRedisplay();
}
void mouse(int button,int state,int x,int y){
if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
    mouseDown=true;
    xdiff=x-yrot;
    ydiff=-y+xrot;
}else
mouseDown=false;
}
void mouseMotion(int x,int y){
if(mouseDown){
    yrot=x-xdiff;
    xrot=y+ydiff;
glutPostRedisplay();
}
}
void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}



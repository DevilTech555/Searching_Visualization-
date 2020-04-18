#include <GL/glut.h>
#include <cstdio>

void init(){
    

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,0.0,0.0,1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("test");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

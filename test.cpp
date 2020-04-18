#include <GL/glut.h>
#include <cstdio>

int x1 = 10,
    y2 = 10;
const int max = 18;
int array[max];
int start = 10;
int sidelength = 25;

void init()
{

}

void draw()
{
    double halfside = sidelength / 2;
    for (int i = 0; i < max; i++)
    {
        glColor3f(0, 1, 0);
        //GL_LINE_LOOP
    //     glBegin(GL_POLYGON);
    //     // glVertex2(x1, y1);
    //     // glVertex2(x2, y1);
    //     // glVertex2(x2, y2);
    //     // glVertex2(x1, y2);

    //     // glVertex2d(x1,y1);
    //     // glVertex2d(x1+20, y1);
    //     // glVertex2d(x1+20, y2);
    //     // glVertex2d(x1, y2);

    //     glVertex2d(x1,y1);
    //     glVertex2d(x1+20, y1);
    //     glVertex2d(x1+20, array[1]);
    //     glVertex2d(x1, 460);
    //     x1 += 25;
    //     y1 += 25;
    //     glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(x1+20,array[i]);
        glVertex2d(x1, array[i]);
        glVertex2d(x1, y2);
        glVertex2d(x1+20, y2);
        x1 += 25;
        glEnd();
        // glRectd(10,10,460,460);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    draw();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    for (int r = 0; r < max; r++)
    {
        array[r] = (int)(rand() % (460 - 100 + 1) + 100);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("test");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

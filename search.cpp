#include <GL/freeglut.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "search.h"
#include "button.h"

extern int found;
extern int place;
extern int resetValue;

const int max = 18;
int array[max];
const int X = 18, Y = 468;
char key[16];

void drawFrame()
{
    glColor3f(1, 1, 1);
    Font(GLUT_BITMAP_9_BY_15, (char *)"States & Info", 500, 30);
    glColor3f(1, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(480, 530);
    glVertex2i(480, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(10, 70);
    glVertex2i(470, 70);
    glVertex2i(10, 470);
    glVertex2i(470, 470);
    glVertex2i(10, 10);
    glVertex2i(10, 470);
    glVertex2i(470, 10);
    glVertex2i(470, 470);
    glVertex2i(10, 10);
    glVertex2i(470, 10);
    glEnd();
}

void drawText()
{
    if (found == 1)
    {
        glColor3f(0, 1, 0);
        Font(GLUT_BITMAP_HELVETICA_12, (char *)key, 508, 50);
        Font(GLUT_BITMAP_HELVETICA_12, (char *)"Key Found", 508, 70);
    }
    if (resetValue == 1)
    {
        glColor3f(1, 0, 0);
        Font(GLUT_BITMAP_HELVETICA_12, (char *)"Please Reset", 508, 90);
    }
}

void drawArray(int f, int p)
{
    int x1 = X, y2 = Y, start = 16;
    for (int i = 0; i < max; i++)
    {
        int n = Y - array[i];
        char num[4];
        sprintf(num, "%d", n);
        if (f == 1 && i == p)
        {
            glColor3f(0, 1, 0);
        }
        else
        {
            glColor3f(1, 1, 1);
        }
        Font(GLUT_BITMAP_HELVETICA_12, ((char *)num), x1, 485);
        if (f == 1 && i == p)
        {
            glColor3f(0, 1, 0);
        }
        else
        {
            glColor3f(1, 1, 0);
        }
        glBegin(GL_POLYGON);
        glVertex2d(x1 + 20, array[i]);
        glVertex2d(x1, array[i]);
        glVertex2d(x1, y2);
        glVertex2d(x1 + 20, y2);
        x1 += 25;
        glEnd();
        drawText();
    }
}

void linerSearch(int arr[], int n)
{
    if (resetValue == 0)
    {
        int x1 = X, y2 = Y, start = 16;
        drawArray(0, 0);
        glutSwapBuffers();
        int x = (int)(rand() % ((max)-1 - 0 + 1) + 0);
        int m = Y - array[x];
        glColor3f(1, 1, 1);
        sprintf(key, "Random Key : %d", m);
        Font(GLUT_BITMAP_HELVETICA_12, ((char *)key), 508, 50);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            glColor3f(0, 0, 1);
            glBegin(GL_POLYGON);
            glVertex2d(x1 + 20, array[i]);
            glVertex2d(x1, array[i]);
            glVertex2d(x1, y2);
            glVertex2d(x1 + 20, y2);
            glEnd();
            glutSwapBuffers();
            usleep(100000);
            if (arr[i] == arr[x])
            {
                glColor3f(0, 1, 0);
                glBegin(GL_POLYGON);
                glVertex2d(x1 + 20, array[i]);
                glVertex2d(x1, array[i]);
                glVertex2d(x1, y2);
                glVertex2d(x1 + 20, y2);
                glEnd();
                glutPostRedisplay();
                glutSwapBuffers();
                found = 1;
                place = i;
                usleep(1000000);
                break;
            }
            glColor3f(1, 0, 0);
            glBegin(GL_POLYGON);
            glVertex2d(x1 + 20, array[i]);
            glVertex2d(x1, array[i]);
            glVertex2d(x1, y2);
            glVertex2d(x1 + 20, y2);
            glEnd();
            x1 += 25;
            glutSwapBuffers();
            usleep(100000);
        }
    }
    resetValue = 1;
}

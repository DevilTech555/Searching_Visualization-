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
    Font(GLUT_BITMAP_9_BY_15, (char *)"States & Info", 490, 30);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Graph Color Code", 490, 120);
    glColor3f(1,1,0);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Array Element", 490, 140);
    glColor3f(0,0,1);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Key Comparision", 490, 160);
    glColor3f(1,0,0);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Key Not Matched", 490, 180);
    glColor3f(0,1,0);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Key Matched", 490, 200);
    glColor3f(1,1,1);
    Font(GLUT_BITMAP_9_BY_15, (char *)"  Project By : ", 490, 230);
    Font(GLUT_BITMAP_9_BY_15, (char *)"   Dhanya HM", 490, 250);
    Font(GLUT_BITMAP_9_BY_15, (char *)"( 1SK18CS408 )", 490, 270);
    // Font(GLUT_BITMAP_9_BY_15, (char *)"  Project By : ", 490, 280);
    // Font(GLUT_BITMAP_9_BY_15, (char *)"   Naveen PM", 490, 300);
    // Font(GLUT_BITMAP_9_BY_15, (char *)"( 1SK18CS413 )", 490, 320);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Keyboard Shortcut", 490, 415);
    Font(GLUT_BITMAP_9_BY_15, (char *)"Spacebar - Search", 490, 435);
    Font(GLUT_BITMAP_9_BY_15, (char *)"r - reset", 490, 453);
    Font(GLUT_BITMAP_9_BY_15, (char *)"g - Random", 490, 470);
    glColor3f(1, 0, 0.6);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(480, 530);
    glVertex2i(480, 0);
    glVertex2i(480,100);
    glVertex2i(650,100);
    glVertex2i(480,210);
    glVertex2i(650,210);
    glVertex2i(480,280);
    glVertex2i(650,280);
    glVertex2i(480,400);
    glVertex2i(650,400);
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
        Font(GLUT_BITMAP_9_BY_15, (char *)key, 490, 50);
        Font(GLUT_BITMAP_9_BY_15, (char *)"Key Found", 490, 70);
    }
    if (resetValue == 1)
    {
        glColor3f(1, 0, 0);
        Font(GLUT_BITMAP_9_BY_15, (char *)"Please Reset", 490, 90);
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
            glColor3f(1, 0.9, 0);
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
        Font(GLUT_BITMAP_9_BY_15, ((char *)key), 490, 50);
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

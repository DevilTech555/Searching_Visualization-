#include <GL/freeglut.h>
#include <cstdio>
#include <unistd.h>
#include "search.h"
#include "button.h"

const int max = 46;
const int wl = 5;
int array[max];
extern int found;
extern int place;

void drawFrame(){
    glColor3f(1,0,0);
    //25, 4, 159
    //glColor3ub(25,4,159);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(480,530);
    glVertex2i(480,0);
    glColor3f(0.0,0.0,1.0);
    glVertex2i(10,70);
    glVertex2i(470,70);
    glVertex2i(10,470);
    glVertex2i(470,470);
    glVertex2i(10,10);
    glVertex2i(10,470);
    glVertex2i(470,10);
    glVertex2i(470,470);
    glVertex2i(10,10);
    glVertex2i(470,10);
    glEnd();
}

void drawArray(int f,int p){
    int start=16;
    for (int i = 0; i < max; i++)
    {
        glLineWidth(5);
        if(f == 1 && i == p){
            glColor3f(0,1,0);
        }else{
            glColor3f(1,1,0);
        }
        glBegin(GL_LINES);
        glVertex2f(start,468);
		glVertex2f(start,array[i]);
        glEnd();
        start+=10;
    }
}

void linerSearch(int arr[], int n) 
{  
    found = place = 0;
    drawArray(0,0);
    glutSwapBuffers();
    int x =(int)(rand()%(46-0+1)+0);
    int start = 16;
    int j=0;
    for (int i = 0; i < n; i++) {
        glLineWidth(5);
        glColor3f(0,0,1);
        glBegin(GL_LINES);
        glVertex2f(start,468);
		glVertex2f(start,array[i]);
        glEnd();
        glutSwapBuffers();
        usleep(100000);
        if (arr[i] == arr[x]) {
            printf("Found");
            glLineWidth(5);
            glColor3f(0,1,0);
            glBegin(GL_LINES);
            glVertex2f(start,468);
		    glVertex2f(start,array[i]);
            glEnd();
            glutPostRedisplay();
            glutSwapBuffers();
            found = 1;
            place =  i;
            usleep(1000000);
            break;
        }
        glLineWidth(5);
        glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex2f(start,468);
		glVertex2f(start,array[i]);
        glEnd();
        start+=10;
        glutSwapBuffers();
        usleep(100000);
    }
    printf("%d\n",x);
}

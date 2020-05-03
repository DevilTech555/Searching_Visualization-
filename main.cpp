#include <iostream>
#include <GL/glut.h>
#include "button.h"
#include "search.h"

extern int xPress,yPress;
extern int array[];

const int max = 18;

int X = 650;
int Y = 510;
int fontx,fonty;
int found = 0;
int nfound = 0;
int place = 0;
int resetValue = 0;

void lS(){
    found = place = 0;
    linerSearch(array,max);
}

void Random(){
    for(int r=0;r<max;r++){
        array[r]=(int)(rand()%(460-100+1)+100);
    }
    found = place = nfound = 0;
}

void reset(){
    found = place = resetValue = nfound = 0;
}

void init(){
    Random();
    glClearColor(0.0f/255.0f, 0.0f/255.0f, 15.0f/255.0f,1.0);
    CreateButton("Search",lS,512,290,100,30);
    CreateButton("Random",Random,512,326,100,30);
    CreateButton("Reset",reset,512,362,100,30);
}


void display(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable(GL_MULTISAMPLE_ARB);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,X,Y,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glColor3f(1,1,1);
    fontx = 10 + (460 - glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24,(const unsigned char *)"Linear Search")) / 2 ;
	fonty = 10 + (70+10)/2;
    Font(GLUT_BITMAP_TIMES_ROMAN_24,(char *)"Linear Search",fontx,fonty);
    drawFrame();
    drawButton();
    drawArray(found,place);
    glutSwapBuffers();
}

void reshape(int x,int y){
	glViewport(0, 0, (GLsizei) x, (GLsizei) y);
    glutReshapeWindow(X,Y);
}


void MouseButton(int button,int state,int x, int y)
{
	if (state == GLUT_DOWN) 
	{
        xPress = x;
        yPress = y;
		switch(button) 
		{
		case GLUT_LEFT_BUTTON:
            ButtonPress(x,y);
            break;
		}
	}
	else 
	{
		switch(button) 
		{
		case GLUT_LEFT_BUTTON:;
            ButtonRelease(x,y);
			break;
	}
	}
	glutPostRedisplay();
}

void tasten (unsigned char key, int xmouse, int ymouse)
{	
	switch (key){
        case 32:
            lS();
            break;
        case 'r':
            reset();
            break;
        case 'g':
            Random();
            break;
		default:
         break;
	}
   glutPostRedisplay(); //request display() call ASAP
}

int main(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(X,Y);
    glutCreateWindow("Searching Visualization");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(MouseButton);
    glutKeyboardFunc(tasten);
    init();
    glutMainLoop();
    return 0;
}

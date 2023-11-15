#include <GL/gl.h>
#include <GL/glut.h>

#include "display.h"

#define windowWidth 1024
#define windowHeight 768

quad* quads;
tri* tris;

//called when window init and needs to be re-painted
void display()
{
    glutWarpPointer(windowWidth / 2, windowHeight / 2);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    
    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glEnd();

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

#include "display.h"
#include "parse.h"

#include <string.h>

#define windowWidth 1024
#define windowHeight 768

void keyboardUp(unsigned char key, int x, int y)
{

}

void mouse(int button, int state, int x, int y)
{

}

void initDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void reshape(GLsizei width, GLsizei height)
{
    // Compute aspect ratio of the new window
    if (height == 0)
    {
        height = 1;
    }
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    
    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);
    
    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset

    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void passiveMotion(int x, int y)
{
    printf("posX: %i posY: %i\n", x, y);
}

int main(int argc, char* argv[])
{
    parse("levels/map.lvl");
    return 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    //init window
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("p3d");

    //callback functions
    glutDisplayFunc(display);
    glutKeyboardUpFunc(keyboardUp);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passiveMotion);

    initDisplay();
    glutMainLoop();
    return 0;
}
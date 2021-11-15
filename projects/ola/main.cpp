#include <GL/glut.h>
#include <iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
const std::pair<int, int> SQUARE1 = std::make_pair(4, 3);
const std::pair<int, int> SQUARE2 = std::make_pair(2, 1);
const std::pair<int, int> SQUARE3 = std::make_pair(0, -1);
const std::pair<int, int> SQUARE4 = std::make_pair(-2, -3);
const std::pair<int, int> SQUARE5 = std::make_pair(-4, -5);

/* COMMANDS:
  UP: "q w e r t"
  DOWN: "a s d f g"
 */

static GLfloat v[10]={ // Square coordinates (Y-Axis)
        0,  2,
        0,  2,
        0,  2,
        0,  2,
        0,  2
};

// Rendering squares
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.6);
    glVertex2f(SQUARE1.first, v[0]);
    glVertex2f(SQUARE1.second, v[0]);
    glVertex2f(SQUARE1.second,v[1]);
    glVertex2f(SQUARE1.first, v[1]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.5, 0.0);
    glVertex2f(SQUARE2.first, v[2]);
    glVertex2f(SQUARE2.second, v[2]);
    glVertex2f(SQUARE2.second,v[3]);
    glVertex2f(SQUARE2.first, v[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 0.4);
    glVertex2f(SQUARE3.first, v[4]);
    glVertex2f(SQUARE3.second, v[4]);
    glVertex2f(SQUARE3.second,v[5]);
    glVertex2f(SQUARE3.first, v[5]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.1, 0.3);
    glVertex2f(SQUARE4.first, v[6]);
    glVertex2f(SQUARE4.second, v[6]);
    glVertex2f(SQUARE4.second,v[7]);
    glVertex2f(SQUARE4.first, v[7]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.3, 0.1);
    glVertex2f(SQUARE5.first, v[8]);
    glVertex2f(SQUARE5.second, v[8]);
    glVertex2f(SQUARE5.second,v[9]);
    glVertex2f(SQUARE5.first, v[9]);
    glEnd();

    glFlush();
}

// Changing square positions
void keyboard(unsigned char key, int x, int y) {
    if (key == 't') {
        v[0] += 2;
        v[1] += 2;
        display();
    } else if (key == 'r') {
        v[2] += 2;
        v[3] += 2;
        display();
    } else if (key == 'e') {
        v[4] += 2;
        v[5] += 2;
        display();
    } else if (key == 'w') {
        v[6] += 2;
        v[7] += 2;
        display();
    } else if (key == 'q') {
        v[8] += 2;
        v[9] += 2;
        display();
    } else if (key == 'g') {
        v[0] -= 2;
        v[1] -= 2;
        display();
    } else if (key == 'f') {
        v[2] -= 2;
        v[3] -= 2;
        display();
    } else if (key == 'd') {
        v[4] -= 2;
        v[5] -= 2;
        display();
    } else if (key == 's') {
        v[6] -= 2;
        v[7] -= 2;
        display();
    } else if (key == 'a') {
        v[8] -= 2;
        v[9] -= 2;
        display();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("CG - Ola");

    glClearColor(0.05, 0.05, 0.10, 1.0); // background color
    glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, -1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
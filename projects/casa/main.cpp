#include <GL/glut.h>
#include <cstdlib>

// ALUNO: Ascânio Sávio
// COMANDOS:
// Girar casa em 360 graus: "r"
// Mudar perspectiva e desfazer mudança - "p, o"

void init();
void display();
void displayCubo();
void displayTelhado();
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

#define BLUE     0.2, 0.0, 1.0
#define RED 1.0, 0.1, 0.3
#define YELLOW  1.0, 1.0, 0.4
#define GREEN    0.3, 1.0, 0.3
#define BROWN    0.8, 0.4, 0.3

static GLfloat vertices[27] = {
        0.0,  30.0, 30.0, // 0
        30.0, 30.0, 30.0, // 1
        30.0,  0.0, 30.0, // 2
        0.0,   0.0, 30.0, // 3
        0.0,  30.0,  0.0, // 4
        30.0, 30.0,  0.0, // 5
        30.0,  0.0,  0.0, // 6
        0.0,   0.0,  0.0, // 7
        15.0, 45.0, 15.0  // 8
};

static GLubyte frenteIndices[]    = {0,3,2,1};
static GLubyte trasIndices[]      = {5,6,7,4};
static GLubyte esquerdaIndices[]  = {4,7,3,0};
static GLubyte direitaIndices[]   = {1,2,6,5};
static GLubyte topoIndices[]      = {4,0,1,5};
static GLubyte fundoIndices[]     = {6,2,3,7};

static GLubyte telhadoFrente[]     = {1,8,0,0};
static GLubyte telhadoEsquerda[]   = {1,5,8,0};
static GLubyte telhadoDireita[]    = {5,4,8,0};
static GLubyte telhadoTras[]       = {4,0,8,0};

static int axisy, axisx;
int width, height;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutCreateWindow("Casa - Representacao 3D");
    glutInitWindowPosition (100, 100);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init()
{
    glClearColor(0.0, 0.05, 0.10, 1.0); // cor do background
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void display()
{
    glPushMatrix();
    glRotatef ((GLfloat) axisy, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) axisx, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    displayCubo();

    displayTelhado();

    glDisableClientState (GL_VERTEX_ARRAY);

    glPopMatrix();
    glutSwapBuffers();
}

void displayCubo()
{
    glColor3f(BLUE); /* frente */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frenteIndices);

    glColor3f(YELLOW); /* esquerda */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

    glColor3f(RED); /* tras */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, trasIndices);

    glColor3f(GREEN); /* direita */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, direitaIndices);

    glColor3f(BLUE); /* topo */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topoIndices);

    glColor3f(BLUE); /* fundo */
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundoIndices);
}

void displayTelhado()
{
    glColor3f(BROWN); /* frente */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, telhadoFrente);

    glColor3f(BROWN); /* esquerda */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, telhadoEsquerda);

    glColor3f(BROWN); /* direita */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, telhadoDireita);

    glColor3f(BROWN); /* tras */
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, telhadoTras);
}

void keyboard(unsigned char key, int x, int y)
{
    GLfloat aspect = (GLfloat) width/(GLfloat) height;

    switch (key) {
        case 27:
            exit(0);
        case 'r':
            axisy = (axisy + 5) % 360;
            glutPostRedisplay();
            break;
        case 'p':
            glLoadIdentity();
            gluPerspective(65.0, aspect, 20.0, 120.0);
            gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
            glutPostRedisplay();
            break;
        case 'o':
            glLoadIdentity();
            glOrtho (-50, 50, -50, 50, -50 , 50);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    width = w;
    height = h;
}
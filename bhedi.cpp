#include <GLUT/glut.h>

int colorIndex = 0;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(250, 300, 0);

    // Set text color
    switch (colorIndex % 3)
    {
    case 0:
        glColor3f(1.0, 0.0, 0.0); // Red
        break;
    case 1:
        glColor3f(0.0, 1.0, 0.0); // Green
        break;
    case 2:
        glColor3f(0.0, 0.0, 1.0); // Blue
        break;
    }

    // Set font and size
    void *font = GLUT_BITMAP_TIMES_ROMAN_24;

    // Draw "BHEDI" text
    glRasterPos2f(-100, 0);
    glutBitmapCharacter(font, 'B');
    glRasterPos2f(-50, 0);
    glutBitmapCharacter(font, 'H');
    glRasterPos2f(0, 0);
    glutBitmapCharacter(font, 'E');
    glRasterPos2f(50, 0);
    glutBitmapCharacter(font, 'D');
    glRasterPos2f(100, 0);
    glutBitmapCharacter(font, 'I');

    glPopMatrix();
    glutSwapBuffers();
}

void timer(int value)
{
    colorIndex++;
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Text Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
#include <GLUT/glut.h>

bool isAnimating = true;
float secondRectScale = 1.0;
float secondRectYPos = 300.0;
float secondRectSpeed = 0.5;

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

    // Draw main square
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(100, 100);
    glVertex2f(100, 500);
    glVertex2f(700, 500);
    glVertex2f(700, 100);
    glEnd();

    // Draw partition rectangles
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(200, 300);
    glVertex2f(200, 500);
    glVertex2f(300, 500);
    glVertex2f(300, 300);

    glVertex2f(350, secondRectYPos);
    glVertex2f(350, 350 * secondRectScale + secondRectYPos);
    glVertex2f(450, 450 * secondRectScale + secondRectYPos);
    glVertex2f(450, secondRectYPos);

    // Animated rectangle with scaling on the y-axis
    glVertex2f(500, 500);
    glVertex2f(500, 500);
    glVertex2f(600, 500);
    glVertex2f(600, 600);

    glVertex2f(650, 300);
    glVertex2f(650, 500);
    glVertex2f(700, 500);
    glVertex2f(700, 300);
    glEnd();

    // Draw duplicate rectangle
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(500, 500);
    glVertex2f(500, 500);
    glVertex2f(600, 500);
    glVertex2f(600, 500);
    glEnd();

    glutSwapBuffers();
}

void timer(int value)
{
    // Animation for the second rectangle
    if (isAnimating)
    {
        secondRectScale += 0.01;
        if (secondRectScale > 1.0)
            secondRectScale = 1.0;

        secondRectYPos += secondRectSpeed;
        if (secondRectYPos > 500 || secondRectYPos < 300)
            secondRectSpeed *= -1;
    }

    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Division Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
#include <GLUT/glut.h>
#include <math.h>

void init()
{
    glClearColor(0.0, 0.2, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void myDisplay(void)
{
    float x, y;
    float a = 150, b = 150;
    float r = 50, t = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5.0f);
    glBegin(GL_LINE_STRIP);
    for (t = 0; t <= 2 * M_PI; t += 0.01)
    {
        x = a + (r * cos(t));
        y = b + (r * sin(t));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.0, 1.4, 1.3);
    glBegin(GL_POLYGON);
    for (t = 0; t < 2 * M_PI; t += 0.01)
    {
        x = a + (r * cos(t));
        y = b + (r * sin(t));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(150, 100);
    glVertex2f(150, 0);
    glEnd();

    float m, n;
    float c = 300, d = 300;
    float s = 70, u = 0;
    glColor3f(0.6, 0.4, 0.7);
    glLineWidth(5.0f);
    glBegin(GL_LINE_STRIP);
    for (u = 0; u <= 2 * M_PI; u += 0.01)
    {
        m = c + (s * cos(u));
        n = d + (s * sin(u));
        glVertex2f(m, n);
    }
    glEnd();

    glColor3f(0.98, 0.04, 0.7);
    glBegin(GL_POLYGON);
    for (u = 0; u < 2 * M_PI; u += 0.01)
    {
        m = c + (s * cos(u));
        n = d + (s * sin(u));
        glVertex2f(m, n);
    }
    glEnd();

    glColor3f(0.6, 0.4, 0.7);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(150, 100);
    glVertex2f(150, 0);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dandelion");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
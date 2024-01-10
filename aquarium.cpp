#include <GLUT/glut.h>

void drawFish()
{
    // Body
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, -0.05);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, 0.0);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.2, 0.05);
    glEnd();

    // Fins
    glColor3f(1.0, 0.6, 0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.07);
    glVertex2f(0.05, -0.02);
    glVertex2f(0.05, -0.12);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.05);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.2, -0.05);
    glEnd();

    // Eye
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.15, 0.02);
    glEnd();

    // Mouth
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.15, -0.02);
    glVertex2f(-0.1, -0.03);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the aquarium boundary
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.9, -0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(0.9, 0.9);
    glVertex2f(-0.9, 0.9);
    glEnd();

    // Draw the water
    glColor3f(0.2, 0.4, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.8);
    glVertex2f(0.8, -0.8);
    glVertex2f(0.8, 0.8);
    glVertex2f(-0.8, 0.8);
    glEnd();

    // Draw fish
    glPushMatrix();
    glTranslatef(0.3, 0.3, 0.0);
    glScalef(0.5, 0.5, 1.0);
    drawFish();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Aquarium");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
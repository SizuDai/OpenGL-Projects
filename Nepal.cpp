#include <GLUT/glut.h> // Include the GLUT header file
#include <cmath>
const float PI = 3.14159;

void drawFootball()
{
    int latitudeBands = 30;
    int longitudeBands = 30;
    float radius = 0.5f;

    for (int latNumber = 0; latNumber <= latitudeBands; latNumber++)
    {
        float theta1 = latNumber * PI / latitudeBands;
        float theta2 = (latNumber + 1) * PI / latitudeBands;

        for (int longNumber = 0; longNumber <= longitudeBands; longNumber++)
        {
            float phi1 = longNumber * 2 * PI / longitudeBands;
            float phi2 = (longNumber + 1) * 2 * PI / longitudeBands;

            float x1 = radius * sin(theta1) * cos(phi1);
            float y1 = radius * cos(theta1);
            float z1 = radius * sin(theta1) * sin(phi1);

            float x2 = radius * sin(theta1) * cos(phi2);
            float y2 = radius * cos(theta1);
            float z2 = radius * sin(theta1) * sin(phi2);

            float x3 = radius * sin(theta2) * cos(phi2);
            float y3 = radius * cos(theta2);
            float z3 = radius * sin(theta2) * sin(phi2);

            float x4 = radius * sin(theta2) * cos(phi1);
            float y4 = radius * cos(theta2);
            float z4 = radius * sin(theta2) * sin(phi1);

            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f); // Set color to white

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);

            glEnd();
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    drawFootball();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Football");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
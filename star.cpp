#include <GLUT/glut.h>
#include <math.h>

void drawStar(float cx, float cy, float radius, int numPoints)
{
    // Calculate the angle between each point
    float angle = 2.0 * M_PI / numPoints;

    // Set the color to yellow
    glColor3f(1.0f, 1.0f, 0.0f);

    // Begin drawing the star
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numPoints; i++)
    {
        // Calculate the current angle
        float currentAngle = angle * i;

        // Calculate the outer point of the star
        float outerX = cx + radius * sin(currentAngle);
        float outerY = cy + radius * cos(currentAngle);
        glVertex2f(outerX, outerY);

        // Calculate the inner point of the star
        float innerX = cx + (radius / 2.0) * sin(currentAngle + angle / 2.0);
        float innerY = cy + (radius / 2.0) * cos(currentAngle + angle / 2.0);
        glVertex2f(innerX, innerY);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int screenWidth = glutGet(GLUT_WINDOW_WIDTH);
    int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);

    // Set the viewport to cover the entire window
    glViewport(0, 0, screenWidth, screenHeight);

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, screenWidth, 0, screenHeight);

    // Draw the star at the center of the window
    float starRadius = 100.0f;
    float starCenterX = screenWidth / 2.0f;
    float starCenterY = screenHeight / 2.0f;
    int numStarPoints = 5;
    drawStar(starCenterX, starCenterY, starRadius, numStarPoints);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Star");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
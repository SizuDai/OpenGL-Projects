#include <GLUT/glut.h>

void drawDog()
{
    // Draw the dog's body
    glColor3f(0.8f, 0.4f, 0.1f); // Brown color
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);
    glScalef(1.0f, 0.6f, 1.0f);
    glutSolidSphere(0.3, 50, 50); // Body
    glPopMatrix();

    // Draw the dog's head
    glColor3f(0.4f, 0.2f, 0.1f); // Dark brown color
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f);
    glutSolidSphere(0.15, 50, 50); // Head
    glPopMatrix();

    // Draw the dog's ears
    glColor3f(0.4f, 0.2f, 0.1f); // Dark brown color
    glPushMatrix();
    glTranslatef(-0.1f, 0.4f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glutSolidCone(0.08, 0.2, 50, 50); // Left ear
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glutSolidCone(0.08, 0.2, 50, 50); // Right ear
    glPopMatrix();

    // Draw the dog's eyes
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glPushMatrix();
    glTranslatef(-0.05f, 0.35f, 0.15f);
    glutSolidSphere(0.02, 50, 50); // Left eye
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f, 0.35f, 0.15f);
    glutSolidSphere(0.02, 50, 50); // Right eye
    glPopMatrix();

    // Draw the dog's nose
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.15f);
    glutSolidSphere(0.02, 50, 50); // Nose
    glPopMatrix();

    // Draw the dog's mouth
    glColor3f(0.8f, 0.2f, 0.2f); // Red color
    glPushMatrix();
    glTranslatef(0.0f, 0.25f, 0.15f);
    glScalef(1.0f, 0.3f, 1.0f);
    glutSolidSphere(0.04, 50, 50); // Mouth
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set the camera position
    gluLookAt(0.0f, 0.0f, 1.0f,   // eye position
              0.0f, 0.0f, 0.0f,   // look-at position
              0.0f, 1.0f, 0.0f);  // up direction

    // Draw the dog
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5f);
    drawDog();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Dog");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
   glutMainLoop();
    return 0;
}
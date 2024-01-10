#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstring>
#include <vector>

float xt = 1.0, yt = 1.0;        // For interactive Keyboard
float x = 1.0, y = 1.0, z = 1.0; // For Movement
float angle = 0;                 // For Function animation
bool flipSprite = false;

void animation(void)
{
    if (angle >= 0 && angle < 10)
        angle = angle + 0.5;
    else
        angle = 0;
    glutPostRedisplay();
}

void settings(void)
{
    glClearColor(0.529, 0.808, 0.922, 0.0);
    glPointSize(5.0);
    glLineWidth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1020.0, 0.0, 720.0);
}

// Define a structure to represent a fish
struct Fish
{
    float x;          // x-coordinate of the fish
    float y;          // y-coordinate of the fish
    float dx;         // x-direction speed of the fish
    float dy;         // y-direction speed of the fish
    float bodyRadius; // radius of the fish's body
    float tailWidth;  // width of the fish's tail
    float tailHeight; // height of the fish's tail
    float red;        // red color component of the fish
    float green;      // green color component of the fish
    float blue;       // blue color component of the fish
};

std::vector<Fish> fishes; // Vector to store the fishes

void InitializeFishes()
{
    // Initialize the fishes with random positions, speeds, and colors
    for (int i = 0; i < 10; i++)
    {
        Fish fish;
        fish.x = rand() % 1000 + 30;
        fish.y = rand() % 100 + 100;
        fish.dx = static_cast<float>(rand() % 5 + 1);
        fish.dy = static_cast<float>(rand() % 3 - 1);
        fish.bodyRadius = static_cast<float>(rand() % 10 + 10);
        fish.tailWidth = static_cast<float>(rand() % 5 + 10);
        fish.tailHeight = static_cast<float>(rand() % 5 + 5);
        fish.red = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        fish.green = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        fish.blue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        fishes.push_back(fish);
    }
}

void UpdateFishes()
{
    // Update the positions and movements of the fishes
    for (int i = 0; i < fishes.size(); i++)
    {
        fishes[i].x += fishes[i].dx;
        fishes[i].y += fishes[i].dy;

        // Randomly change the fish's direction every 5 frames
        if (rand() % 1 == 0)
        {
            fishes[i].dx = static_cast<float>(rand() % 5 + 1);
            fishes[i].dy = static_cast<float>(rand() % 3 - 1);
        }

        // Wrap the fishes around the screen when they go out of bounds
        if (fishes[i].x > 1050)
            fishes[i].x = -50;
        if (fishes[i].y > 750)
            fishes[i].y = -50;
        if (fishes[i].x < -50)
            fishes[i].x = 1050;
        if (fishes[i].y < -50)
            fishes[i].y = 750;
    }
}
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw brown rectangle
    glColor3f(0.545, 0.271, 0.075); // Brown color for rectangle
    glViewport(0, 0, 1020, 720);    // Set the viewport to cover the entire window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1020.0, 0.0, 720.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(510.0, 670.0, 0.0); // Translate to the top center of the viewport
    glScalef(200.0, 50.0, 1.0);      // Scale the rectangle
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    // Draw text inside the rectangle
    glColor3f(1.0, 1.0, 1.0);    // White color for text
    glViewport(0, 0, 1020, 720); // Set the viewport to cover the entire window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1020.0, 0.0, 720.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(510.0, 670.0, 0.0); // Translate to the top center of the viewport
    glScalef(1.0, 1.0, 1.0);         // Scale the text
    glRasterPos2f(-45.0, -10.0);     // Position the text inside the rectangle
    const char *text = "Fishy Bro";
    for (int i = 0; i < strlen(text); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
    glPopMatrix();

    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();

    glPushMatrix();
    glTranslatef(xt, yt, 0.0); // For Move    NEWS/QDZC  each Position.
    glScalef(-1.0, 1.0, 1.0);  // Flip the fish sprite horizontally
    glTranslatef(-100, 0, 0);  // Adjust translation back to original position
    if (flipSprite)
    {
        glTranslatef(100.0, 0.0, 0.0); // Adjust translation to center of the fish
        glScalef(-1.0, 1.0, 1.0);      // Flip the fish sprite horizontally
        glTranslatef(-100.0, 0.0, 0.0);
    }
    glBegin(GL_POLYGON); // draw body
    glColor3f(255.0, 241.0, 180.0);
    glVertex2i(40, 200);
    glColor3f(255.0, 241.0, 180.0);
    glVertex2i(120, 280);
    glColor3f(127.0, 254.0, 0.0);
    glVertex2i(320, 200);
    glColor3f(127.0, 254.0, 0.0);
    glVertex2i(100, 160);
    glEnd();

    // Eye
    glPushMatrix();
    glTranslatef(120, 250, 0); // Set the eye position
    glColor3f(0.0, 0.0, 0.0);  // Set the eye color (white)
    glBegin(GL_POLYGON);
    float radius = 8.0; // Eye radius
    for (float angle = 0; angle <= 2 * M_PI; angle += 0.01)
    {
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON); // draw tail
    glColor3f(255.0, 241.0, 180.0);
    glVertex2i(320, 200);
    glColor3f(255.0, 241.0, 180.0);
    glVertex2i(360, 240);
    glColor3f(255.0, 241.0, 180.0);
    glVertex2i(340, 200);
    glColor3f(127.0, 254.0, 0.0);
    glVertex2i(360, 160);
    glColor3f(127.0, 254.0, 0.0);
    glVertex2i(320, 200);
    glEnd();

    glBegin(GL_POLYGON); // draw Top Key
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(120, 280);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(140, 300);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(280, 216);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(120, 280);
    glEnd();

    glBegin(GL_POLYGON); // draw Buttom Key
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 160);
    glVertex2i(140, 200);
    glVertex2i(120, 164);
    glVertex2i(100, 160);
    glRotatef(angle, 0.0, 0.0, 0.0);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    srand(time(NULL));
    glColor3f(0.545, 0.271, 0.075); // Brown color for dotted
    for (int i = 0; i < 20; i++)
    {
        glPushMatrix();
        float x = rand() % 1000 + 20;
        float y = rand() % 200 + 20;
        glTranslated(x, y, 0.0); // Randomly position the stone
        glScalef(1.0, 0.5, 1.0); // Scale it to make it oval-shaped
        glBegin(GL_POLYGON);
        for (float theta = 0; theta < 2 * M_PI; theta += 0.1)
        {
            float rx = 10 * cos(theta);
            float ry = 5 * sin(theta);
            glVertex2f(rx, ry);
        }
        glEnd();
        glPopMatrix();
    }
    // Draw the fishes in the background
    for (int i = 3; i < fishes.size(); i++)
    {
        glPushMatrix();
        glTranslatef(fishes[i].x, fishes[i].y, 0.0);
        glColor3f(fishes[i].red, fishes[i].green, fishes[i].blue); // Set fish color
        // Draw fish body (oval)
        glBegin(GL_POLYGON);
        for (float theta = 0; theta < 2 * 3.14159; theta += 0.1)
        {
            float x = fishes[i].bodyRadius * cos(theta);
            float y = fishes[i].bodyRadius * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();
        // Draw fish tail (rectangle)
        glBegin(GL_POLYGON);
        glVertex2f(-fishes[i].bodyRadius - fishes[i].tailHeight, -fishes[i].tailWidth / 2);
        glVertex2f(-fishes[i].bodyRadius - fishes[i].tailHeight, fishes[i].tailWidth / 2);
        glVertex2f(-fishes[i].bodyRadius, 0.0);
        glEnd();
        glPopMatrix();
    }

    // Draw green plants
    glColor3f(0.0, 0.392, 0.0); // Green color for plants
    for (int i = 0; i < 50; i++)
    {
        glPushMatrix();
        float x = rand() % 1000 + 30;
        float y = rand() % 100 + 30;
        glTranslated(x, y, 0.0); // Randomly position the plant
        glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(-20.0, -50.0);
        glVertex2f(0.0, -200.0);
        glVertex2f(20.0, -50.0);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
    glFlush();
}
void Idle(void)
{
    UpdateFishes();      // Update fish positions and movements
    glutPostRedisplay(); // Call Display function to redraw the scene
}
void keyboard(GLubyte key, int x, int y) // For keyboard interactive
{
    switch (key)
    {
    case 'd':
        xt += 10.0;         // Move thuea la 10.0 picel step by step
        flipSprite = false; // Reset flipSprite flag
        glColor3f(0.0, 1.0, 0.0);
        glutPostRedisplay();
        break;

    case 'a':
        xt -= 10.0;
        flipSprite = true; // Reset flipSprite flag
        glColor3f(1.0, 0.0, 0.0);
        glutPostRedisplay();
        break;

    case 's':
        yt -= 10.0;
        glColor3f(0.0, 0.0, 0.0);
        glutPostRedisplay();
        break;

    case 'w':
        yt += 10.0;
        glColor3f(0.0, 0.0, 1.0);
        glutPostRedisplay();
        break;

    case 'e':
        angle += 5;
        xt += 10.0;
        yt += 10.0;
        glColor3f(1.0, 0.0, 1.0);
        glutPostRedisplay();
        break;

    case 'q':
        xt -= 10.0;
        yt += 10.0;
        glColor3f(0.0, 1.0, 1.0);
        glutPostRedisplay();
        break;
    case 'c':
        xt += 10.0;
        yt -= 10.0;
        glColor3f(1.0, 0.0, 1.0);
        glutPostRedisplay();
        break;
    case 'z':
        xt -= 10.0;
        yt -= 10.0;
        glColor3f(0.0, 0.0, 1.0);
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

int main(int a, char **b)
{
    glutInit(&a, b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 50); // 200 Lelt 50 Height
    glutInitWindowSize(1020, 720);
    glutCreateWindow("Fish Animation");
    settings();
    glutDisplayFunc(Display);
    glutIdleFunc(animation);
    InitializeFishes();
    glutKeyboardFunc(keyboard);
    glutIdleFunc(Idle);
    glutMainLoop();
}
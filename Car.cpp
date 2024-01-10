// Car.cpp
#include "./Car.h"

Car::Car(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height)
{
    carPositionX = positionX;
    carPositionY = positionY;
    carWidth = width;
    carHeight = height;
}

void Car::draw()
{
    glPushMatrix();
    glTranslatef(carPositionX, carPositionY, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red

    glBegin(GL_QUADS);
    glVertex2f(-carWidth / 2, -carHeight / 2);
    glVertex2f(carWidth / 2, -carHeight / 2);
    glVertex2f(carWidth / 2, carHeight / 2);
    glVertex2f(-carWidth / 2, carHeight / 2);
    glEnd();

    glPopMatrix();
}
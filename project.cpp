// main.cpp

#include <GLUT/glut.h>
#include "./Car.h"

int main(int argc, char **argv)
{
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Car Project");

    // Create an instance of the Car class
    Car myCar(0.0f, 0.0f, 100.0f, 50.0f);

    // Set the display function to draw the car
    glutDisplayFunc([]()
                    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
        glClear(GL_COLOR_BUFFER_BIT);

        // Call the draw method of the Car class
        myCar.draw();

        glFlush(); });

    // Start the main loop
    glutMainLoop();

    return 0;
}
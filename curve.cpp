#include <GLUT/glut.h>
#include<math.h>

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);

}

void myDisplay(void)
{
    /* Function to be called to determine what is displayed. */
    float x, y;
    float a = 100.0, b= 100.0;
    /*the center point of the circle*/
    float r = 100, t;
    /*r is the radius of the circle*/
    glClear (GL_COLOR_BUFFER_BIT);
    /* Clear the screen (colour) buffer. */ glColor3d (0.235,0.702,0.443);
    /*set the colour of the circle*/
    glBegin(GL_POLYGON);
    for(t=0; t<1000; t++)
    { x = a + (r* cos(t)); y = b + (r* sin(t)); 
    glVertex2f(x,y);
    }
        glEnd(); 
    glFlush();
    /* Flush the screen buffer to ensure it is displayed. */
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Curve");
init ();
glutDisplayFunc(myDisplay);
glutMainLoop();
}
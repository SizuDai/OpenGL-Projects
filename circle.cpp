#include <GLFW/glfw3.h>
#include <cmath>

// Callback function for handling window resize events
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Circle Example", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Set the window context
    glfwMakeContextCurrent(window);

    // Set the viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Set the framebuffer resize callback
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a circle
        int numSegments = 100;
        float radius = 0.5f;
        float centerX = 0.0f;
        float centerY = 0.0f;
        float angleIncrement = 2.0f * M_PI / numSegments;

        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(centerX, centerY);
        for (int i = 0; i <= numSegments; ++i) {
            float angle = i * angleIncrement;
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up GLFW
    glfwTerminate();

    return 0;
}
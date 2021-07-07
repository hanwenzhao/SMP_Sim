#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800


void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error: %s\n", description);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // --------------- GLFW Initialization ---------------//
    // GLFW initialize
    if (!glfwInit()) {
        fprintf(stderr, "GLFW Error: GLFW initialization failed."); // initialization failed
    }
    glfwSetErrorCallback(glfw_error_callback); // set GLFW error callback

    // GLFW Window Creation
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* glfWwindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SMP Simulation", NULL, NULL);
    if (!glfWwindow) {
        fprintf(stderr, "Failed to create GLFW window."); // window or opengl context creation failed
        glfwTerminate();
        return -1;
    }

    // GLFW API Enable
    glfwMakeContextCurrent(glfWwindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        fprintf(stderr, "GLAD initialization failed.");
    }

    // GLFW Callbacks
    glfwSetKeyCallback(glfWwindow, glfw_key_callback);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(glfWwindow)) {
        // loop that keep running
        glfwSwapBuffers(glfWwindow);
        glfwPollEvents();
    }


    glfwDestroyWindow(glfWwindow);
    glfwTerminate(); // Terminate GLFW
    return 0;
}

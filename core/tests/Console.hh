#ifndef TEST_HH
#define TEST_HH

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

class Console
{
public:
    Console();
    virtual ~Console();
    bool points();
    bool glfwWindow();
    bool test2D();
protected:

private:
};



#endif // TEST_HH

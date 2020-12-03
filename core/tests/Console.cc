#include <iostream>
#include <Entities.hh>


#include "Console.hh"



bool Console::points()
{
    std::cout << "Testing Point and Vector.. " << std::endl;

    cobani::core::Point p1;
    cobani::core::Point p2;
    p1[COBANI_PX] = 12;
    p1[COBANI_PY] = 23;
    p1[COBANI_PZ] = 9;
    p2[COBANI_PX] = 95;
    p2[COBANI_PY] = 39;
    p2[COBANI_PZ] = 26;

    COBANI_TYPE_DECIMAL lp1p2 = p1.lengthTo(p2);
    if(fabs(lp1p2 - 86.2206) >= COBANI_EPSILON)
    {
        std::cout << "p1.lengthTo(p2) != " << lp1p2 <<  " | " << std::to_string(fabs(lp1p2 - 88.2206)) << std::endl;
    }

    cobani::core::Vector vec1(p1,p2);
    COBANI_TYPE_DECIMAL lenvec1 = vec1.length();
    if(lenvec1  - 118.465 >= COBANI_EPSILON)
    {
        std::cout << "vec1.length() != " << lenvec1 << std::endl;
    }

    vec1.getDirection().normalize();
    COBANI_TYPE_DECIMAL lenveca = vec1.length();
    if(fabs(lenveca  - 1.0) < COBANI_EPSILON)
    {
        std::cout << "|a| = " << lenveca << std::endl;
    }

    cobani::core::Point p3;
    cobani::core::Point p4;
    p3[COBANI_PX] = 0;
    p3[COBANI_PY] = 0;
    p3[COBANI_PZ] = 0;
    p4[COBANI_PX] = 1;
    p4[COBANI_PY] = 0;
    p4[COBANI_PZ] = 0;
    cobani::core::Vector vec2(p3,p4);
    COBANI_TYPE_DECIMAL lenvecu = vec1.length();
    if(lenvecu  - 1.0 < COBANI_EPSILON)
    {
        std::cout << "|u| = " << lenvecu << std::endl;
    }

    return true;
}


Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

bool Console::glfwWindow()
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    return true;
}


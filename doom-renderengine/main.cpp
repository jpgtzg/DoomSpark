//
//  main.cpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 07/03/23.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <GLUT/GLUT.h>

#include "render.hpp"
#include "player.hpp"

int main(void)
{
    //Init GLFW
    glfwInit();
    
    //Setup glfw window settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* Window = glfwCreateWindow(800, 600, "Doom-like Render engine", nullptr, nullptr);

    glfwMakeContextCurrent(Window);
    
    //Init GLEW
    glewInit();
    
    glViewport(0, 0, 800, 600);
    
    std::cout << "Created by Juan Pablo Gutiérrez" << std::endl;
    
    std::cout << "GL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GL vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "GL renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    //Game loop
    while(!glfwWindowShouldClose(Window))
    {
        glClearColor(0.2f, 0.65f, 0.154f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
               
        glfwSwapBuffers(Window);
               
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

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

#define res         1
#define sWidth      160*res
#define sHeight     120 * res
#define sWidth2     (sWidth / 2)
#define sHeight2    (sHeight / 2)
#define pixelScale  4/res
#define GLSW        (sWidth * pixelScale)
#define GLSH        (sHeight * pixelScale)}

typedef struct{
    int fr1, fr2;
}xtime; xtime T;

typedef struct{
    int w, s, a, d;
    int s1, sr;
}keys; keys K;

int main(void)
{
    //Init GLFW
    glfwInit();

    //Setup glfw window settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* Window = glfwCreateWindow(800, 600, "macOS OpenGL engine", nullptr, nullptr);

    glfwMakeContextCurrent(Window);
    
    //init GLEW
    glewInit();
    
    glViewport(0, 0, 800, 600);
    
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

//Handles pixel drawing according to the color
void pixel(int x, int y, int c){
    int rgb[3];
    
    if(c == 0) {rgb[0] = 255; rgb[1] = 255; rgb[2] = 0;} //Yellow
    if(c == 1) {rgb[0] = 160; rgb[1] = 160; rgb[2] = 0;} //Darker Yellow
    if(c == 2) {rgb[0] = 0; rgb[1] = 255; rgb[2] = 0;} //Green
    if(c == 3) {rgb[0] = 0; rgb[1] = 160; rgb[2] = 0;} //Darker Green
    if(c == 4) {rgb[0] = 0; rgb[1] = 255; rgb[2] = 255;} //Cyan
    if(c == 5) {rgb[0] = 0; rgb[1] = 160; rgb[2] = 160;} //Darker Cyan
    if(c == 6) {rgb[0] = 160; rgb[1] = 100; rgb[2] = 0;} //Brown
    if(c == 7) {rgb[0] = 110; rgb[1] = 50; rgb[2] = 0;} //Darker brown
    if(c == 8) {rgb[0] = 0; rgb[1] = 60; rgb[2] = 130;} //Background
    if(c == 9) {rgb[0] = 160; rgb[1] = 0; rgb[2] = 0;} //Red
    if(c == 8) {rgb[0] = 255; rgb[1] = 0; rgb[2] = 130;} //Darker red
    
    glColor3ub(rgb[0], rgb[1], rgb[2]);
    glBegin(GL_POINT);
    glVertex2i(x * pixelScale + 2, y * pixelScale + 2);
    glEnd();
}

//Handles player input and movement
void movePlayer(){
    if(K.a == 1) {std::cout <<"left";}
    if(K.d == 1) {std::cout <<"right";}
    if(K.w == 1) {std::cout <<"up";}
    if(K.s == 1) {std::cout <<"down";}
    
    if(K.sr == 1) {std::cout <<"strafe left";}
    if(K.s1 == 1) {std::cout <<"strafe right";}
}

void clearBackground(){
    int x, y;
    for (y = 0; y < sHeight; y++) {
        for (x = 0; x < sWidth; x++) {
            pixel(x, y, 8);
        }
    }
}


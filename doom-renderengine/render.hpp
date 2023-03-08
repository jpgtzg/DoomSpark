//
//  render.hpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 08/03/23.
//

#ifndef render_hpp
#define render_hpp

#include <stdio.h>

#include <stdio.h>
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

void pixel(int x, int y, int c);

void clearBackground();

void display();

void draw3D();

#endif /* render_hpp */

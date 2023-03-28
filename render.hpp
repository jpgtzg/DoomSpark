//
//  render.hpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 12/03/23.
//

#ifndef render_hpp
#define render_hpp

#include <SDL.h>
#include <stdio.h>

void drawPixel(int x, int y, int color, SDL_Renderer& renderer);

#endif /* render_hpp */
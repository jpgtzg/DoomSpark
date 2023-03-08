//
//  player.hpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 08/03/23.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>

void movePlayer();

void handleKeysDown(unsigned char key, int x, int y);

void handleKeysUp(unsigned char key, int x, int y);

#endif /* player_hpp */

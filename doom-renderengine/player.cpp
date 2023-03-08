//
//  player.cpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 07/03/23.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

typedef struct{
    int w, s, a, d;
    int s1, sr;
}keys; keys K;

//Handles player input and movement
void movePlayer(){
    if(K.a == 1) {std::cout <<"left";}
    if(K.d == 1) {std::cout <<"right";}
    if(K.w == 1) {std::cout <<"up";}
    if(K.s == 1) {std::cout <<"down";}
    
    if(K.sr == 1) {std::cout <<"strafe left";}
    if(K.s1 == 1) {std::cout <<"strafe right";}
}

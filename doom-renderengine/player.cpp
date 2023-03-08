//
//  player.cpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 08/03/23.
//

#include "player.hpp"

#include <iostream>
#include <math.h>
#include <stdio.h>

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

void handleKeysDown(unsigned char key, int x, int y){
    if(key == 'w' == 1) {K.w = 1;}
    if(key == 's' == 1) {K.s = 1;}
    if(key == 'a' == 1) {K.a = 1;}
    if(key == ',' == 1) {K.sr = 1;}
    if(key == '.' == 1) {K.s1 = 1;}
}

void handleKeysUp(unsigned char key, int x, int y){
    if(key == 'w' == 1) {K.w = 0;}
    if(key == 's' == 1) {K.s = 0;}
    if(key == 'a' == 1) {K.a = 0;}
    if(key == ',' == 1) {K.sr = 0;}
    if(key == '.' == 1) {K.s1 = 0;}
}


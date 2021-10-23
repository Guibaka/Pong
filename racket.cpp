#include "racket.h"

Racket::Racket(int w, int h, float x, float y){
    racket_width = w;
    racket_height = h;
    racket_speed = 5;
    position_x = x;
    position_y = y;
}

int Racket::get_height(){
    return racket_height;
}

int Racket::get_width(){
    return racket_width;
}

int Racket::get_speed(){
    return racket_speed;
}

int Racket::get_position_x(){
    return position_x;
}

int Racket::get_position_y(){
    return position_y;
}

void Racket::move_up(){
    position_y += racket_speed;
}

void Racket::move_down(){
    position_y -= racket_speed;
}
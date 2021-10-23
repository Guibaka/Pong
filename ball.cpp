#include "ball.h"
#include "math.h"

Ball::Ball(int r, float x, float y, float dir_x, float dir_y){
    ball_rayon = r;
    position_x = x;
    position_y = y;
    direction_x = dir_x;
    direction_y = dir_y;
    ball_speed = 8;
}

float Ball::get_position_x(){
    return position_x;
}

float Ball::get_position_y(){
    return position_y;
}

float Ball::get_direction_x(){
    return direction_x;
}

float Ball::get_direction_y(){
    return direction_y;
}

int Ball::get_rayon(){
    return ball_rayon;
}

void Ball::update_direction(float dir_x, float dir_y){
    direction_x = dir_x;
    direction_y = dir_y;
    vec2_norm(direction_x, direction_y);
}

void Ball::update_position(){
    position_x += direction_x * ball_speed;
    position_y += direction_y * ball_speed;
    vec2_norm(position_x, position_y);
}

void Ball::vec2_norm(float x, float y) {
    // sets a vectors length to 1 (which means that x + y == 1)
    float length = sqrt((x * x) + (y * y));
    if (length != 0.0f) {
        length = 1.0f / length;
        x *= length;
        y *= length;
    }
}
#include "score.h"

Score::Score(int w, int h){
    width = w;
    height = h;
    score_left = 0;
    score_right = 0;
}

int Score::get_width(){
    return width;
}
int Score::get_height(){
    return height;
}

int Score::get_score_left(){
    return score_left;
}

int Score::get_score_right(){
    return score_right;
}

void Score::plus_one(bool isRight){
    if(isRight){
        score_right++;
    }else{
        score_left++;
    }
}
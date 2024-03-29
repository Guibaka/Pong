#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "math.h"
#include "score.h"
#include "racket.h"
#include "ball.h"

/*Global varibale*/
const int WIDTH = 800;
const int HEIGHT = 400;
const int RACKET_WIDTH = 10;
const int RACKET_HEIGHT = 80;

Score *score = NULL;
Racket *racket_left = NULL;
Racket *racket_right = NULL;
Ball *ball = NULL;

void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());
}

void drawRect(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void draw() {
    // clear (has to be done at the beginning)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Draw Score
    drawText(score->get_width(), score->get_height(),
    std::to_string(score->get_score_left()) + " : " + std::to_string(score->get_score_right()));

    // Draw Racket left and Racket right
    drawRect(racket_left->get_position_x(), racket_left->get_position_y(), 
    racket_left->get_width(), racket_left->get_height());
    drawRect(racket_right->get_position_x(), racket_right->get_position_y(), 
    racket_right->get_width(), racket_right->get_height());

    // Draw Ball 
    drawCircle(ball->get_position_x(), ball->get_position_y(), ball->get_rayon(), 100);

    // swap buffers (has to be done at the end)
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key=='z'){
        racket_left->move_up();
    }
    if (key=='s'){
        racket_left->move_down();
    }
}

void processSpecialKeys(int key, int x, int y){
    if (key == 101){
        racket_right->move_up();
    }
    if (key == 103){
        racket_right->move_down();
    } 
}

void checkReboud(){
    // hit left racket
    if (ball->get_position_x() < racket_left->get_position_x() + RACKET_WIDTH &&
        ball->get_position_x() > racket_left->get_position_x() &&
        ball->get_position_y() < racket_left->get_position_y() + RACKET_HEIGHT &&
        ball->get_position_y() > racket_left->get_position_y())
    {
            //maybe use random when it hits ?
            float dir_y = ((ball->get_position_y() - racket_left->get_position_y())/RACKET_HEIGHT) - 0.5f;
            ball->update_direction(fabs(ball->get_direction_x()), dir_y);
    }
   
    // hit right racket
    if (ball->get_position_x() < racket_right->get_position_x() + RACKET_WIDTH &&
        ball->get_position_x() > racket_right->get_position_x() &&
        ball->get_position_y() < racket_right->get_position_y() + RACKET_HEIGHT &&
        ball->get_position_y() > racket_right->get_position_y())
    {
            //maybe use random when it hits ?
            float dir_y = ((ball->get_position_y() - racket_right->get_position_y())/RACKET_HEIGHT) - 0.5f;
            ball->update_direction(-fabs(ball->get_direction_x()), dir_y);
    }

    // hit left wall
    if (ball->get_position_x() < 0) {
        score->plus_one(false);
        ball = new Ball(5, WIDTH/2, HEIGHT/2, -1.0f, 0.0f);
        ball->update_direction(fabs(ball->get_direction_x()), 0);
    }

    // hit right wall
    if (ball->get_position_x() > WIDTH) {
        score->plus_one(true);
        ball = new Ball(5, WIDTH/2, HEIGHT/2, -1.0f, 0.0f);
        ball->update_direction(-fabs(ball->get_direction_x()), 0);
    }

    // hit top wall
    if (ball->get_direction_y() >= HEIGHT){
        ball->update_direction(ball->get_direction_x(), -fabs(ball->get_direction_y()));
    }

    // hit bottom wall
    if (ball->get_direction_y() < 0){
        ball->update_direction(ball->get_direction_x(), fabs(ball->get_direction_y()));
    }
}


void update(int value) {
    // Call update() again in 'interval' milliseconds
    glutTimerFunc(100, update, 0);
    
    ball->update_position();  
    checkReboud();  

    // Redisplay frame
    glutPostRedisplay();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("PongGame");

    //Initialize all items
    score = new Score(WIDTH/2 -10, HEIGHT - 15);
    racket_left = new Racket(RACKET_WIDTH, RACKET_HEIGHT, 10.0f, HEIGHT/2 - 40.0f);
    racket_right = new Racket(RACKET_WIDTH, RACKET_HEIGHT, WIDTH - 10.0f, HEIGHT/2 - 40.0f);
    ball = new Ball(5, WIDTH/2, HEIGHT/2, -1.0f, 0.0f);

    // Register callback functions  
    glutDisplayFunc(draw);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    enable2D(WIDTH, HEIGHT);
    glColor3f(1.0, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
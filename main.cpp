#include<iostream>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include"score.h"

/*Global varibale*/
const int WIDTH = 1280;
const int HEIGHT = 800;
Score *score = NULL;

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

void draw() {
    // clear (has to be done at the beginning)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ToDo: draw our scene
    drawText(score->get_width(), score->get_height(),
    std::to_string(score->get_score_left()) + " : " + std::to_string(score->get_score_right()));

    // swap buffers (has to be done at the end)
    glutSwapBuffers();
}

void update(int value) {
   // Call update() again in 'interval' milliseconds
   glutTimerFunc(100, update, 0);

   // Redisplay frame
   glutPostRedisplay();
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("PongGame");

    //Initialize Score 
    score = new Score(WIDTH/2 -10, HEIGHT - 15);

    // Register callback functions  
    glutDisplayFunc(draw);
    glutTimerFunc(100, update, 0);

    enable2D(WIDTH, HEIGHT);
    glColor3f(1.0, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
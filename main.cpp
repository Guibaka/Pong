#include<iostream>
#include<GL/glut.h>

const int WIDTH = 1280;
const int HEIGHT = 800;

void draw() {
    // clear (has to be done at the beginning)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ToDo: draw our scene

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

    // Register callback functions  
    glutDisplayFunc(draw);
    glutTimerFunc(100, update, 0);

    glutMainLoop();
    return 0;
}
#include<GL/glut.h>
#include<iostream>
using namespace std;

int frameno = 0;

void doFrame(int v) {
    frameno++;
    glutPostRedisplay();
    glutTimerFunc(10, doFrame, 0);
}

void draw() {

}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, 1024, 0, 768, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("ASSIGNMENT 8 Windmill Animation");
    init();
    glutDisplayFunc(draw);
    glutTimerFunc(200, doFrame, 0);
    glutMainLoop();
    return 0;
}
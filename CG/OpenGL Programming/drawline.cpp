#include<GL/glut.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-4, 4, -4, 4, -4, 4);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, 3);
    glVertex2i(0, -3);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Just Checking");
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(100, 500);
    glutDisplayFunc(display);
    glutMainLoop();
}
#include<GL/glut.h>

void renderGraphics() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(100, 0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF00F);
    glBegin(GL_LINES);
    glVertex2i(0, -100);
    glVertex2i(0, 100);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(-100, 100);
    glVertex2i(100, -100);
    glVertex2i(100, 100);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(800, 400);
    glutCreateWindow("Assignment 1 Lines");
    glutDisplayFunc(renderGraphics);
    glutMainLoop();
    return 0;
}
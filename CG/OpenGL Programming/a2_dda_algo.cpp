#include<GL/glut.h>

void ddaAlgo(float x1, float y1, float x2, float y2) {
    float xinc, yinc, dx, dy, x, y, step;
    dy = y2 - y1;
    dx = x2 - x1;
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    xinc = dx / step;
    yinc = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    for (int i = 1;i <= step;i++) {
        x += xinc;
        y += yinc;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }
    glFlush();
}

void draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, 1200, 1200, 0, -1, 1);
    glColor3f(1.0, 0.0, 0.0);
    ddaAlgo(100, 200, 300, 200);
    ddaAlgo(100, 200, 100, 400);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1200, 1200);
    glutCreateWindow("Assignment 2 DDA");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}


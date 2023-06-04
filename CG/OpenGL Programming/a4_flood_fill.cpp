#include<GL/glut.h>
#include<iostream>
using namespace std;

struct pixel {
    float r, g, b;
}fc, bc;

void dda(float x1, float y1, float x2, float y2) {
    float xinc, yinc, dx, dy, step;
    dx = x2 - x1;
    dy = y2 - y1;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xinc = dx / step;
    yinc = dy / step;
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    for (int i = 0;i < step;i++) {
        x1 += xinc;
        y1 += yinc;
        glVertex2f(x1, y1);
    }
    glEnd();
    glFlush();
}

void floodfill(int x, int y) {
    pixel c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    glBegin(GL_POINTS);
    if (c.r == bc.r && c.g == bc.g && c.b == bc.b) {
        glColor3f(fc.r, fc.g, fc.b);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        floodfill(x + 1, y);
        floodfill(x - 1, y);
        floodfill(x, y + 1);
        floodfill(x, y - 1);

        // floodfill(x + 1, y + 1);
        // floodfill(x + 1, y - 1);
        // floodfill(x - 1, y + 1);
        // floodfill(x - 1, y - 1);
    }
    glFlush();
}

void draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    dda(200, 200, 400, 200);
    dda(200, 200, 200, 400);
    dda(200, 400, 400, 400);
    dda(400, 400, 400, 200);
    fc.r = 0.0;
    fc.g = 0.0;
    fc.b = 1.0;
    bc.r = 0.0;
    bc.g = 0.0;
    bc.b = 0.0;
    floodfill(205, 205);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glOrtho(0, 1024, 0, 768, -1, 1);
    gluOrtho2D(0, 1024, 0, 768);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Assignment 4 Flood Fill");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
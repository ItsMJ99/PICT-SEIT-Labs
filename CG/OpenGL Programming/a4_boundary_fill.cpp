#include<iostream>
#include<GL/glut.h>
using namespace std;

//double x1, y1, x2, y2;

struct pixel {
    float r, g, b;
}fc, bc;

void dda(double x1, double y1, double x2, double y2) {
    float xi, yi, dy, dx, step;
    dx = x2 - x1;
    dy = y2 - y1;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / step;
    yi = dy / step;
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(x1, y1);
    for (int i = 0;i <= step;i++) {
        x1 += xi;
        y1 += yi;
        glVertex2i(x1, y1);
    }
    glEnd();
    glFlush();
}

void boundaryfill(int x, int y) {
    pixel c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    if ((c.r != bc.r || c.g != bc.g || c.b != bc.b) && (c.r != fc.r || c.g != fc.g || c.b != fc.b)) {
        glBegin(GL_POINTS);
        glColor3f(fc.r, fc.g, fc.b);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundaryfill(x + 1, y);
        boundaryfill(x - 1, y);

        boundaryfill(x, y - 1);
        boundaryfill(x, y + 1);

        // boundaryfill(x + 1, y + 1);
        // boundaryfill(x - 1, y + 1);
        // boundaryfill(x + 1, y - 1);
        // boundaryfill(x - 1, y - 1);
    }
    glFlush();
}

void draw() {
    //outer body
    glClearColor(0.0, 0.0, 0.0, 0.0);
    dda(320, 480, 680, 480);
    dda(320, 480, 320, 220);
    dda(680, 480, 680, 220);
    dda(320, 220, 450, 220);
    dda(680, 220, 550, 220);

    //stand
    dda(450, 220, 400, 180);
    dda(550, 220, 600, 180);
    dda(400, 180, 600, 180);

    //inner screen
    dda(340, 460, 660, 460);
    dda(340, 460, 340, 240);
    dda(660, 460, 660, 240);
    dda(340, 240, 660, 240);

    fc.r = 1.0f;
    fc.g = 0.0f;
    fc.b = 0.0f;
    bc.r = 0.0f;
    bc.g = 0.0f;
    bc.b = 1.0f;
    boundaryfill(500, 200);

    //mountains
    dda(340, 240, 430, 380);
    dda(430, 380, 500, 240);
    dda(500, 240, 580, 420);
    dda(580, 420, 660, 240);
    fc.r = 0.0f;
    fc.g = 1.0f;
    fc.b = 0.0f;
    boundaryfill(341, 241);
    boundaryfill(501, 241);
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
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(800, 200);
    glutCreateWindow("Assignment 4 BoundaryFilling");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
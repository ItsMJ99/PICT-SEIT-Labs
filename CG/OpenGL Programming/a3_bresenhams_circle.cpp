//edit the comments a bit and check the logic, it can work for both with mouse & keyboard or without both just enter values in function

#include<iostream>
#include<GL/glut.h>
using namespace std;

//int cx, cy, radius;

void plotPoints(int cx, int cy, int x, int y) {
    glColor3f(1.0, 0.4, 0.7);
    glBegin(GL_POINTS);
    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);
    glVertex2i(cx + y, cy + x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy - x);
    glEnd();
    glFlush();
}

void drawCircle(int cx, int cy, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    plotPoints(cx, cy, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d += 4 * (x - y) + 10;
        }
        else {
            d += 4 * x + 6;
        }
        plotPoints(cx, cy, x, y);
    }
}

// void keyboardFunc(unsigned char key, int x, int y) {
//     cout << "Circle Center : (" << cx << " , " << cy << ")" << endl;
//     cout << "Radius : " << key << endl;
//     radius = (key - '0') * 25;
//     drawCircle();
// }

// void mouseFunc(int button, int state, int x, int y) {
//     cout << "Mouse Coordinates : (" << x << ", " << y << ")" << endl;
//     cout << "Enter Radius : ";
//     cx = x;
//     cy = y;
//     glutKeyboardFunc(keyboardFunc);
// }

void draw() {
    //glutMouseFunc(mouseFunc);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1024, 768, 0);
    drawCircle(200, 200, 100);
    drawCircle(300, 200, 100);
}

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0);
//     glClear(GL_COLOR_BUFFER_BIT);
//     gluOrtho2D(0, 1024, 768, 0);
// }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Assignment 3 Bresenham's Circle Algorithm");
    //init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
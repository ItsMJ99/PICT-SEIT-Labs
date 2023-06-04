#include<iostream>
#include<cmath>
#include<GL/glut.h>
using namespace std;
#define radian (3.14/180)
int iterations = 0;

void koch_curve(float x1, float y1, float x2, float y2, int n) {
    float xa, xb, ya, yb, mx, my;
    xa = (2 * x1 + x2) / 3;
    ya = (2 * y1 + y2) / 3;
    xb = (2 * x2 + x1) / 3;
    yb = (2 * y2 + y1) / 3;

    mx = xa + ((xb - xa) * cos(60 * radian)) + ((yb - ya) * sin(60 * radian));
    my = ya - ((xb - xa) * sin(60 * radian)) + ((yb - ya) * cos(60 * radian));
    if (n > 0) {
        koch_curve(x1, y1, xa, ya, n - 1);
        koch_curve(xa, ya, mx, my, n - 1);
        koch_curve(mx, my, xb, yb, n - 1);
        koch_curve(xb, yb, x2, y2, n - 1);
    }
    else {
        glVertex2f(x1, y1);
        glVertex2f(xa, ya);

        glVertex2f(xa, ya);
        glVertex2f(mx, my);

        glVertex2f(mx, my);
        glVertex2f(xb, yb);

        glVertex2f(xb, yb);
        glVertex2f(x2, y2);
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        iterations++;
        glutPostRedisplay();
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        iterations--;
        if (iterations < 0)
            iterations = 0;
        glutPostRedisplay();
    }
}

void draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    koch_curve(300, 400, 500, 100, iterations);
    koch_curve(500, 100, 700, 400, iterations);
    koch_curve(700, 400, 300, 400, iterations);
    glutMouseFunc(mouse);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0, 1024, 0, 768, -1, 1);
    //gluOrtho2D(0, 1024, 0, 768);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(600, 400);
    glutCreateWindow("Assignment 7 Koch Curve");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
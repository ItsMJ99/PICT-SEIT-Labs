#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct pixel { float r, g, b; } pixel;

pixel B, F;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void boundaryfill(int x, int y) {
    pixel C;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &C);

    if ((C.r != F.r || C.g != F.g || C.b != F.b) && (C.r != B.r || C.g != B.g || C.b != B.b)) {
        plot(x, y);

        boundaryfill(x - 1, y);
        boundaryfill(x + 1, y);
        boundaryfill(x, y - 1);
        boundaryfill(x, y + 1);
    }
}

void line(double x1, double y1, double x2, double y2)
{
    double dx, dy, steps;
    float xi, yi;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / (float)steps;
    yi = dy / (float)steps;
    int i;
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(x1, y1);
    for (i = 0;i < steps;i++)
    {
        x1 += xi;
        y1 += yi;
        glVertex2d(x1, y1);
    }
    glEnd();
    glFlush();
}

void dda(int x1, int y1, int x2, int y2) {
    int dx, dy, xinc = 1, yinc = 1, p, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    xinc = x2 < x1 ? -1 : 1;
    yinc = y2 < y1 ? -1 : 1;

    x = x1;
    y = y1;
    plot(x, y);

    if (dx >= dy) {
        p = 2 * dy - dx;
        int calc1 = 2 * (dy - dx);
        int calc2 = 2 * dy;
        for (int i = 0; i <= dx; i++) {
            if (p >= 0) {
                y += yinc;
                p += calc1;
            }
            else p += calc2;
            x += xinc;
            plot(x, y);
        }
    }
    else {
        p = 2 * dx - dy;
        int calc1 = 2 * (dx - dy);
        int calc2 = 2 * dx;
        for (int i = 0; i <= dy; i++) {
            if (p >= 0) {
                x += xinc;
                p += calc1;
            }
            else p += calc2;
            y += yinc;
            plot(x, y);
        }
    }
    glFlush();
}

void display() {
    B.r = 0;
    B.g = 0;
    B.b = 0;
    glColor3f(B.r, B.g, B.b);
    line(100, 100, 100, 500);
    line(200, 100, 200, 500);
    line(100, 100, 200, 100);
    line(100, 500, 200, 500);
    F.r = 1;
    F.g = 0;
    F.b = 0;
    glColor3f(F.r, F.g, F.b);
    cout << F.r << endl;
    boundaryfill(150, 150);
    glFlush();
}

void mousehandle(int state, int button, int x, int y) {
    if (state == GLUT_DOWN && button == GLUT_LEFT)
        boundaryfill(105, 105);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Boundary Fill");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 800, 0, 800);
    glutDisplayFunc(display);
    glutMouseFunc(mousehandle);
    glutMainLoop();
    return 0;
}
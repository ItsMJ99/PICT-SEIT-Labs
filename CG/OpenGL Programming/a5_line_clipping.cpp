#include<GL/glut.h>
#include<iostream>
using namespace std;
#define xmax 700
#define ymax 700

int xl = 200, yl = 200, xh = 500, yh = 500;
int flag = 0;
float u1, v1, u2, v2;

struct code {
    int t, b, r, l;
};

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

code getcode(int x, int y) {
    code c = { 0,0,0,0 };
    if (x < xl)
        c.l = 1;
    if (x > xh)
        c.r = 1;
    if (y < yl)
        c.b = 1;
    if (y > yh)
        c.t = 1;
    return c;
}

void dda(float x1, float y1, float x2, float y2) {
    float xi, yi, step, dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / step;
    yi = dy / step;
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    for (int i = 0;i < step;i++) {
        x1 += xi;
        y1 += yi;
        glVertex2f(x1, y1);
    }
    glEnd();
    glFlush();
}

void drawWindow() {
    glColor3f(1, 1, 1);
    dda(xl, yl, xh, yl);
    dda(xh, yl, xh, yh);
    dda(xh, yh, xl, yh);
    dda(xl, yh, xl, yl);
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    glColor3f(1, 1, 1);
    if (state == GLUT_DOWN && flag == 0) {
        u1 = x;
        v1 = ymax - y;
        flag = 1;
    }
    else if (state == GLUT_DOWN && flag == 1) {
        u2 = x;
        v2 = ymax - y;
        flag = 2;
        dda(u1, v1, u2, v2);
    }
    cout << "Mouse Coordinates : " << x << " " << y << endl;
}

void lineClipping() {
    code c, c1, c2;
    int xi, yi, flag;
    float m;

    m = (v2 - v1) / (u2 - u1);

    c1 = getcode(u1, v1);
    c2 = getcode(u2, v2);

    while (1) {
        if (c1.l == 0 && c2.l == 0 && c1.r == 0 && c2.r == 0 && c1.b == 0 && c2.b == 0 && c1.t == 0 && c2.t == 0) {
            break;
        }

        else if (((c1.l && c2.l) || (c1.r && c2.r) || (c1.b && c2.b) || (c1.t && c2.t)) != 0) {
            u1 = v1 = u2 = v2 = 0;
            break;
        }
        else {
            if (c1.l == 1 || c2.l == 1) {
                xi = xl;
                yi = v1 + m * (xl - u1);
                if (c1.l == 1)
                    flag = 0;
                else
                    flag = 1;
            }
            else if (c1.r == 1 || c2.r == 1) {
                xi = xh;
                yi = v1 + m * (xh - u1);
                if (c1.r == 1)
                    flag = 0;
                else
                    flag = 1;
            }
            else if (c1.b == 1 || c2.b == 1) {
                xi = u1 + (1 / m) * (yl - v1);
                yi = yl;
                if (c1.b == 1)
                    flag = 0;
                else
                    flag = 1;
            }
            else if (c1.t == 1 || c2.t == 1) {
                xi = u1 + (1 / m) * (yh - v1);
                yi = yh;
                if (c1.t == 1)
                    flag = 0;
                else
                    flag = 1;
            }

            c = getcode(xi, yi);

            if (flag == 0) {
                u1 = xi;
                v1 = yi;
                c1 = c;
            }
            else if (flag == 1) {
                u2 = xi;
                v2 = yi;
                c2 = c;
            }
        }
    }
    drawWindow();
    dda(u1, v1, u2, v2);
}

void keyboard(char unsigned key, int x, int y) {
    if (key == 'c') {
        init();
        lineClipping();
    }
    if (key == 'r') {
        init();
        drawWindow();
        flag = 0;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(xmax, ymax);
    glutCreateWindow("ASSIGNMENT 5 Line Clipping");
    gluOrtho2D(0, xmax, 0, ymax);
    init();
    glutDisplayFunc(drawWindow);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
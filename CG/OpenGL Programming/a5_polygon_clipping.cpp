#include<iostream>
#include<GL/glut.h>
using namespace std;
#define xmax 1024
#define ymax 768

float xl = 200, yl = 200, xh = 600, yh = 600;
float u1, v1, u2, v2;
const int maxpoints = 20;
int numpoints = 0;

struct code {
    int l, r, b, t;
};

struct points {
    float x, y;
};

points polygon[maxpoints];

code getCode(float x, float y) {
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

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void clippedPolygon(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
}

void drawPolygon() {
    glColor3f(1, 1, 1);
    for (int i = 0;i < numpoints;i++) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(polygon[i].x, polygon[i].y);
    }
    glEnd();
    glFlush();
}

void drawWindow() {
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xl, yl);
    glVertex2f(xh, yl);
    glVertex2f(xh, yh);
    glVertex2f(xl, yh);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    glColor3f(1, 1, 1);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (numpoints < maxpoints) {
            polygon[numpoints].x = x;
            polygon[numpoints].y = ymax - y;
            numpoints++;
            drawPolygon();
        }
    }
}

void polygonClipping() {
    float xi, yi, m;
    code c, c1, c2;
    int flag = 0;

    for (int i = 0;i < numpoints;i++) {
        u1 = polygon[i].x;
        v1 = polygon[i].y;
        u2 = polygon[(i + 1) % numpoints].x;
        v2 = polygon[(i + 1) % numpoints].y;

        c1 = getCode(u1, v1);
        c2 = getCode(u2, v2);
        m = (v2 - v1) / (u2 - u1);
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
                c = getCode(xi, yi);
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
        if (u1 != 0 && v1 != 0 && u2 != 0 && v2 != 0) {
            clippedPolygon(u1, v1, u2, v2);
        }
    }
    drawWindow();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'c') {
        init();
        polygonClipping();
    }
    if (key == 'r') {
        numpoints = 0;
        init();
        drawWindow();
    }
}

void display() {
    init();
    drawWindow();
    drawPolygon();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(xmax, ymax);
    glutCreateWindow("Line Clipping");
    gluOrtho2D(0, xmax, 0, ymax);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
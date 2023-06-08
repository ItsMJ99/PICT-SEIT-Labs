#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

double xi, yi;
int length;
double d[3][3] = { 1 }, ans[3][3] = { 0 };

void matrix3x3(double m1[3][3], double m2[3][3]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            int sum = 0;
            for (int k = 0;k < 3;k++) {
                sum += m1[i][k] * m2[k][j];
            }
            ans[i][j] = sum;
        }
    }
}

void draw(double temp[3][3]) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0;i < 3;i++) {
        glVertex2d(temp[i][0], temp[i][1]);
    }
    glEnd();
    glFlush();
}

void drawLines() {
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2d(-400, 0);
    glVertex2d(400, 0);
    glVertex2d(0, -400);
    glVertex2d(0, 400);
    glEnd();
    glFlush();
}

void translation() {
    double tx = -100, ty = 0;
    double temp[3][3] = { 0 };

    // cout << "Enter tx : ";
    // cin >> tx;
    // cout << "Enter ty : ";
    // cin >> ty;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void scaling() {
    double sx = 2, sy = 1, temp[3][3] = { 0 };

    // cout << "Enter sx : ";
   // cin >> sx;
   // cout << "Enter sy : ";
   // cin >> sy;

    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void rotation() {
    double rx = 0, ry = 0, angle = 45, temp[3][3] = { 0 };
    // cout << "Enter arbiratary x point: ";
    // cin >> rx;
    // cout << "Enter arbitratiry y point: ";
    // cin >> ry;
    // cout << "Enter rotation angle: ";
    // cin >> angle;

    angle = angle * (M_PI / 180);

    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);
    temp[1][0] = -sin(angle);
    temp[1][1] = cos(angle);
    temp[2][0] = (-(rx * cos(angle)) + (ry * sin(angle)) + rx);
    temp[2][1] = (-(rx * sin(angle)) - (ry * cos(angle)) + ry);
    temp[2][2] = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void xreflection() {
    double temp[3][3] = { 0 };
    temp[0][0] = 1;
    temp[1][1] = -1;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void yreflection() {
    double temp[3][3] = { 0 };
    temp[0][0] = -1;
    temp[1][1] = 1;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void xyreflection() {
    double temp[3][3] = { 0 };
    temp[0][1] = 1;
    temp[1][0] = 1;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}
void originreflection() {
    double temp[3][3] = { 0 };
    temp[0][0] = -1;
    temp[1][1] = -1;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void xshearing() {
    double shx = 0.5, temp[3][3] = { 0 };

    // cout << "shx : ";
    // cin >> shx;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[1][0] = shx;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void yshearing() {
    double shy = 0.5, temp[3][3] = { 0 };

    // cout << "shx : ";
    // cin >> shx;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[0][1] = shy;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 1, 0);
    draw(ans);
}

void menu(GLint c) {
    switch (c) {
    case 1:
        translation();
        break;
    case 2:
        scaling();
        break;
    case 3:
        rotation();
        break;
    case 4:
        xreflection();
        break;
    case 5:
        yreflection();
        break;
    case 6:
        xyreflection();
        break;
    case 7:
        originreflection();
        break;
    case 8:
        xshearing();
        break;
    case 9:
        yshearing();
        break;
    }
}

void display() {
    glColor3f(1, 0, 0);
    draw(d);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-400, 400, -400, 400);
}

int main(int argc, char** argv) {

    // cout << "Enter x coordinate : ";
    // cin >> xi;
    // cout << "Enter y coordinate : ";
    // cin >> yi;
    // cout << "Enter length : ";
    // cin >> length;

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            d[i][j] = 1;
        }
    }

    xi = 100, yi = 100;
    length = 200;

    d[0][0] = xi;
    d[0][1] = yi;
    d[1][0] = xi + length;
    d[1][1] = yi;
    d[2][0] = length / 2 + xi;
    d[2][1] = (sqrt(3) / 2 * length) + yi;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Assignment 6 Transformation");
    init();
    drawLines();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Translation", 1);
    glutAddMenuEntry("Scaling", 2);
    glutAddMenuEntry("Rotation", 3);
    glutAddMenuEntry("X-Reflection", 4);
    glutAddMenuEntry("Y-Reflection", 5);
    glutAddMenuEntry("XY-Reflection", 6);
    glutAddMenuEntry("Origin-Reflection", 7);
    glutAddMenuEntry("X-Shearing", 8);
    glutAddMenuEntry("Y-Shearing", 9);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
#include<GL/glut.h>
#include<cmath>
#include<iostream>
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
    //horizontal
    glVertex2f(-400, 0);
    glVertex2f(400, 0);

    //vertical
    glVertex2f(0, 400);
    glVertex2f(0, -400);
    glEnd();
    glFlush();
}

void translation() {
    double tx = -50, ty = 20;
    double temp[3][3] = { 0 };

    // cout << "Enter tx = ";
    // cin >> tx;
    // cout << "Enter ty = ";
    // cin >> ty;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0.0, 0.0, 1.0);
    draw(ans);
}

void scaling() {
    double sx = 2, sy = 1;
    double temp[3][3] = { 0 };

    // cout << "Enter sx = ";
    // cin >> sx;
    // cout << "Enter sy = ";
    // cin >> sy;

    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);
}

void rotation() {
    double rx = -100, ry = 0, angle = 45, temp[3][3] = { 0 };
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
    temp[2][0] = rx - (rx * cos(angle)) + (ry * sin(angle));
    temp[2][1] = ry - (rx * sin(angle)) - (ry * cos(angle));
    temp[2][2] = 1;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);
}

void reflectX() {
    double temp[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0,1} };

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);
}

void reflectY() {
    double temp[3][3] = { {-1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);
}

void reflectXY() {
    double temp[3][3] = { {0, 1, 0}, {1, 0, 0}, {0, 0, 1} };

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);
}


void xshearing() {
    double shx = 0.5, temp[3][3] = { 0 };

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[1][0] = shx;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
    draw(ans);

}

void yshearing() {
    double shy = 0.5, temp[3][3] = { 0 };

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[0][1] = shy;

    glClear(GL_COLOR_BUFFER_BIT);
    drawLines();
    matrix3x3(d, temp);
    glColor3f(0, 0, 1);
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
        reflectX();
        break;
    case 5:
        reflectY();
        break;
    case 6:
        reflectXY();
        break;
    case 7:
        xshearing();
        break;
    case 8:
        yshearing();
        break;
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-400, 400, -400, 400);
}

void display() {
    glColor3f(0.0, 1.0, 0.0);
    draw(d);
}

int main(int argc, char** argv) {

    // cout << "Enter X Cordinate = ";
    // cin >> xi;
    // cout << "Enter Y Cordinate = ";
    // cin >> yi;
    xi = 50, yi = 50, length = 200;

    for (int i = 0;i < 3;i++) {
        for (int k = 0;k < 3;k++) {
            d[i][k] = 1;
        }
    }

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
    glutCreateWindow("ASSIGNMENT 6 TRANSFORMATION");
    init();
    drawLines();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("TRANSLATION", 1);
    glutAddMenuEntry("SCALING", 2);
    glutAddMenuEntry("ROTATION", 3);
    glutAddMenuEntry("X-REFLECTION", 4);
    glutAddMenuEntry("Y-REFLECTION", 5);
    glutAddMenuEntry("X=Y-REFLECTION", 6);
    glutAddMenuEntry("X-SHEARING", 7);
    glutAddMenuEntry("Y-SHEARING", 8);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

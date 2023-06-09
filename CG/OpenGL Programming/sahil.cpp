#include <stdlib.h>
#include <bits/stdc++.h>

#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

double et[3][3] = { 1 }, ans[3][3] = { 0 };
float xi, yi;
int length;

void drawET(double temp[3][3]) {
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for (int i = 0;i < 3;i++) {
        glVertex2i(temp[i][0], temp[i][1]);
    }
    glEnd();
    glFlush();
}

void multi3x3(double m1[3][3], double m2[3][3]) {

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

void translation() {
    double tx, ty;
    double temp[3][3] = { 0 };

    cout << "Enter the value of tx: ";
    cin >> tx;
    cout << "Enter the value of ty: ";
    cin >> ty;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    multi3x3(et, temp);
    glColor3f(1, 1, 0);
    drawET(ans);
}

void scaling() {
    double sx = 2, sy = 1;
    double temp[3][3] = { 0 };

    // cout << "Enter the value of sx: ";
    // cin >> sx;
    // cout << "Enter the value of sy: ";
    // cin >> sy;

    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    multi3x3(et, temp);
    glColor3f(1, 0, 1);
    drawET(ans);
}

void rotation() {
    double rx, ry, angle, temp[3][3] = { 0 };

    cout << "Enter the value of rx: ";
    cin >> rx;
    cout << "Enter the value of ry: ";
    cin >> ry;
    cout << "Enter the rotation angle: ";
    cin >> angle;

    angle = angle * (M_PI / 180);

    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);
    temp[1][0] = -sin(angle);
    temp[1][1] = cos(angle);
    temp[2][0] = rx - (rx * cos(angle)) + (ry * sin(angle));
    temp[2][1] = ry - (ry * sin(angle)) - (ry * cos(angle));
    temp[2][2] = 1;

    multi3x3(et, temp);
    glColor3f(0, 1, 1);
    drawET(ans);
}

void shearing() {
    int ch = 2;
    double shx = 0.5, shy = 0.5, temp[3][3] = { 0 };

    // cout << "Enter 1 for shx and 2 for shy: ";
    // cin >> ch;

    if (ch == 1) {
        // cout << "Enter the shx factor: ";
        // cin >> shx;
        temp[0][0] = 1;
        temp[1][1] = 1;
        temp[2][2] = 1;
        temp[1][0] = shx;
    }
    else {
        // cout << "Enter the shy factor: ";
        // cin >> shy;
        temp[0][0] = 1;
        temp[1][1] = 1;
        temp[2][2] = 1;
        temp[0][1] = shy;
    }

    multi3x3(et, temp);
    glColor3f(0, 1, 0);
    drawET(ans);
}

void menu(int item) {
    switch (item) {
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
        shearing();
        break;
    default:
        break;
    }
}

void display() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-300, 0);
    glVertex2i(300, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, 300);
    glVertex2i(0, -300);
    glEnd();
    glFlush();

    glColor3f(0, 0, 1);
    drawET(et);
}

void initialize() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    // cout << "Enter the x coordinate: ";
    // cin >> xi;
    // cout << "Enter the y coordinate: ";
    // cin >> yi;
    // cout << "Enter the length: ";
    // cin >> length;

    xi = 30, yi = 10;
    length = 100;

    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            et[i][j] = 1;
        }
    }

    et[0][0] = xi;
    et[0][1] = yi;
    et[1][0] = xi + length;
    et[1][1] = yi;
    et[2][0] = length / 2 + xi;
    et[2][1] = (sqrt(3) / 2 * length) + yi;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Transformation");

    initialize();

    glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry("1. Translation", 1);
    glutAddMenuEntry("2. Scaling", 2);
    glutAddMenuEntry("3. Rotation", 3);
    glutAddMenuEntry("4. Shearing", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
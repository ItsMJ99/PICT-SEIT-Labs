#include<GL/glut.h>

void plotPoints(int cx, int cy, int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(cx + x, cy + y);
    glVertex2f(cx - x, cy + y);
    glVertex2f(cx + x, cy - y);
    glVertex2f(cx - x, cy - y);
    glVertex2f(cx + y, cy + x);
    glVertex2f(cx - y, cy + x);
    glVertex2f(cx + y, cy - x);
    glVertex2f(cx - y, cy - x);
    glEnd();
    glFlush();
}

void bresenhamCircle(int cx, int cy, int rad) {
    int x = 0;
    int y = rad;
    int p = 3 - 2 * rad;
    plotPoints(cx, cy, x, y);
    while (y >= x) {
        x++;
        if (p >= 0) {
            y--;
            p += 4 * (x - y) + 10;
        }
        else {
            p += 4 * (x)+6;
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
    glColor3f(1, 1, 1);
    bresenhamCircle(400, 500, 100);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1000, 0, 1000);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Assignment 3 Bresenham's Circle Algorithm");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
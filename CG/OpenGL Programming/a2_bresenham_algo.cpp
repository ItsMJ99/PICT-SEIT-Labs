#include<GL/glut.h>

void bresenham(float x1, float y1, float x2, float y2) {
    float x, y, xi, yi, p, dx, dy;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    dx = dx < 0 ? -dx : dx;
    dy = dy < 0 ? -dy : dy;

    xi = x1 > x2 ? -1 : 1;
    yi = y1 > y2 ? -1 : 1;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    if (dx >= dy) {
        p = 2 * dy - dx;
        glVertex2f(x, y);
        for (int i = 0;i < dx;i++) {
            if (p >= 0) {
                y += yi;
                p += 2 * dy - 2 * dx;
            }
            else {
                p += 2 * dy;
            }
            x += xi;
            if ((i % 10) != 0 && ((i + 1) % 10) != 0) {
                glVertex2f(x, y);
            }
        }
    }
    else {
        p = 2 * dy - dx;
        glVertex2f(x, y);
        for (int i = 0;i < dy;i++) {
            if (p >= 0) {
                x += xi;
                p += 2 * dx - 2 * dy;
            }
            else {
                p += 2 * dx;
            }
            y += yi;
            if ((i % 10) != 0 && ((i + 1) % 10) != 0) {
                glVertex2f(x, y);
            }
        }
    }
    glEnd();
    glFlush();
}

void draw() {
    glColor3f(1, 1, 1);
    bresenham(0, 500, 500, 500);
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
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}
#include<GL/glut.h>

void bresenhamAlgo(float x1, float y1, float x2, float y2) {
    float dx, dy, x, y, xc, yc, p;
    dy = abs(y2 - y1);
    dx = abs(x2 - x1);
    x = x1;
    y = y1;
    dy = dy < 0 ? -dy : dy;
    dx = dx < 0 ? -dx : dx;

    xc = x1 > x1 ? -1 : 1;
    yc = y1 > y2 ? -1 : 1;

    if (dx == 0) {
        glBegin(GL_POINTS);
        for (int i = 0;i < dy;i++) {
            y += yc;
            glVertex2f(x, y);
        }
        glEnd();
    }

    if (dy == 0) {
        glBegin(GL_POINTS);
        for (int i = 0;i < dx;i++) {
            x += xc;
            glVertex2f(x, y);
        }
        glEnd();
    }

    glBegin(GL_POINTS);
    if (dx > dy) {
        p = 2 * dy - dx;
        for (int i = 0;i < dx;i++) {
            if (p > 0) {
                y += yc;
                p = p + 2 * (dy - dx);
            }
            else {
                p = p + 2 * dy;
            }
            x += xc;
            glVertex2f(x, y);
        }
    }
    else {
        p = 2 * dx - dy;
        for (int i = 0;i < dy;i++) {
            if (p > 0) {
                x += xc;
                p = p + 2 * (dx - dy);
            }
            else {
                p = p + 2 * dx;
            }
            y += yc;
            glVertex2f(x, y);
        }
    }
    glEnd();
    glFlush();
}

void draw() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1024, 768, 0);
    glColor3f(0.0, 1.0, 0.0);
    bresenhamAlgo(100, 100, 500, 100);
    bresenhamAlgo(100, 100, 500, 200);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Assignment 2 Bresenham");
    glutDisplayFunc(draw);
    glutMainLoop();
}
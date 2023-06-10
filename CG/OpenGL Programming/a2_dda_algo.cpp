#include<GL/glut.h>

void dda(float x1, float y1, float x2, float y2) {
    float xi, yi, step, dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / step;
    yi = dy / step;
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    // for (int i = 0; i < step; i++) {
    //     x1 += xi;
    //     y1 += yi;
    //     if ((i % 10) != 0 && ((i + 1) % 10) != 0) {
    //         glVertex2f(x1, y1);
    //     }
    // }
    int pattern = 0;
    for (int i = 0;i < step;i++) {
        x1 += xi;
        y1 += yi;
        if (pattern < 10) {
            glVertex2f(x1, y1);
            pattern++;
        }
        else {
            i += 8;
            x1 += 4 * xi;
            y1 += 4 * yi;
            glVertex2f(x1, y1);
            x1 += 4 * xi;
            y1 += 4 * yi;
            pattern = 0;
        }
    }
    glEnd();
    glFlush();
}

void draw() {
    glColor3f(1.0, 1.0, 1.0);
    dda(300, 200, 800, 200);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1024, 0, 768);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(800, 200);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Line Stipple");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}